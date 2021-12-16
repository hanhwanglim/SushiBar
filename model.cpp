#include "model.h"

#include <QImage>
#include <QString>
#include <iostream>

static QSharedPointer<QOpenGLTexture> textureFromFile(
    const std::string& path, const std::string& directory) {
  std::string filename = "C:\\Users\\hanhw\\Desktop\\Computer Graphics\\SushiBar\\models\\cat_body.png";
  QString fileName = QString::fromStdString(filename);
  QImage image = QImage(fileName);
  QSharedPointer<QOpenGLTexture> texture(new QOpenGLTexture(image));

  texture->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);
  texture->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);
  texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
  texture->setMagnificationFilter(QOpenGLTexture::Linear);
  return texture;
}

Model::Model(const std::string& path) {
  if (loadModel(path))
    std::cout << "Load Model Failed" << std::endl;
}

void Model::draw(QOpenGLShaderProgram* program) {
  for (unsigned int i = 0; i < meshes.size(); i++) meshes[i].draw(program);
}

bool Model::loadModel(const std::string& path) {
  Assimp::Importer importer;
  const aiScene* scene = importer.ReadFile(
      path, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
                aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

  if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
      !scene->mRootNode) {
    std::cout << "Assimp import failed: " << importer.GetErrorString()
              << std::endl;
    return false;
  }
  

  directory = path.substr(0, path.find_last_of('\\'));

  processNode(scene->mRootNode, scene);
  std::cout << path << std::endl;
  return true;
}

void Model::processNode(aiNode* node, const aiScene* scene) {
  for (unsigned int i = 0; i < node->mNumMeshes; i++) {
    aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
    meshes.push_back(processMesh(mesh, scene));
  }

  for (unsigned int i = 0; i < node->mNumChildren; i++) {
    processNode(node->mChildren[i], scene);
  }
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene) {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<Texture> textures;

  for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
    Vertex vertex;
    glm::vec3 vector;

    // Save positions
    vector.x = mesh->mVertices[i].x;
    vector.y = mesh->mVertices[i].y;
    vector.z = mesh->mVertices[i].z;
    vertex.position = vector;

    // Save normals
    if (mesh->HasNormals()) {
      vector.x = mesh->mNormals[i].x;
      vector.y = mesh->mNormals[i].y;
      vector.z = mesh->mNormals[i].z;
      vertex.normal = vector;
    }

    // Save texture coordinates
    if (mesh->mTextureCoords[0]) {
      glm::vec2 tex;
      tex.x = mesh->mTextureCoords[0][i].x;
      tex.y = mesh->mTextureCoords[0][i].y;
      vertex.texCoord = tex;
    } else {
      vertex.texCoord = glm::vec2(0.0f, 0.0f);
    }

    vertices.push_back(vertex);
  }

  for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
    aiFace face = mesh->mFaces[i];

    for (unsigned int j = 0; j < face.mNumIndices; j++)
      indices.push_back(face.mIndices[j]);
  }

  if (scene->HasMaterials()) {
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

    // 1. diffuse maps
    std::vector<Texture> diffuseMaps = loadMaterialTextures(
        material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    // 2. specular maps
    std::vector<Texture> specularMaps = loadMaterialTextures(
        material, aiTextureType_SPECULAR, "texture_specular");
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    // 3. normal maps
    std::vector<Texture> normalMaps =
        loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    // 4. height maps
    std::vector<Texture> heightMaps =
        loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
  }

  return Mesh(vertices, indices, textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* material,
                                                 aiTextureType type,
                                                 std::string typeName) {
  std::vector<Texture> textures;

  for (unsigned int i = 0; i < material->GetTextureCount(type); i++) {
    aiString str;
    material->GetTexture(type, i, &str);

    bool skip = false;

    for (unsigned int j = 0; j < this->textures_loaded.size(); j++) {
      if (std::strcmp(this->textures_loaded[j].filepath.data(), str.C_Str()) ==
          0) {
        textures.push_back(this->textures_loaded[j]);
        skip = true;
        break;
      }
    }

    if (!skip) {
      Texture texture;
      texture.filepath = str.C_Str();
      texture.type = typeName;
      texture.texture = textureFromFile(str.C_Str(), directory);
      textures.push_back(texture);
      this->textures_loaded.push_back(texture);
    }
  }

  return textures;
}
