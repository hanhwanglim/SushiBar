#ifndef MODEL_H
#define MODEL_H

#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <QOpenGLShaderProgram>
#include <assimp/Importer.hpp>
#include <string>
#include <vector>

#include "mesh.h"

class Model {
 public:
  Model(const std::string& path);

  bool loadModel(const std::string& path);

  void draw(QOpenGLShaderProgram* program);

 private:
  std::vector<Texture> textures_loaded;
  std::vector<Mesh> meshes;
  std::string directory;

  std::vector<Texture> loadMaterialTextures(aiMaterial* material,
                                            aiTextureType type,
                                            std::string typeName);
                                            
  void processNode(aiNode* node, const aiScene* scene);

  Mesh processMesh(aiMesh* mesh, const aiScene* scene);

};

#endif  // MODEL_H
