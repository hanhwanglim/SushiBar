#include "model.h"

#include <string.h>

#include <QDebug>

/**
 * @brief Loads the model
 * 
 * @param path file path
 */
Model::Model(const std::string& path) {
  FILE* file = fopen(path.c_str(), "r");

  if (file == NULL) {
    qDebug() << "Cannot read file";
    return;
  }

  parseObj(file);

  fclose(file);
}

/**
 * @brief Parse the .obj file
 * 
 * @param file file
 */
void Model::parseObj(FILE* file) {
  while (true) {
    char line[128];
    int l = fscanf(file, "%s", line);
    if (l == EOF) break;

    if (strcmp(line, "v") == 0) saveVertex(file);
    else if (strcmp(line, "vn") == 0) saveNormal(file);
    else if (strcmp(line, "vt") == 0) saveTexCoord(file);
    else if (strcmp(line, "f") == 0) saveFace(file);
  }
}

/**
 * @brief Saves the vertex coordinates data
 * 
 * @param file file
 */
void Model::saveVertex(FILE* file) {
  glm::vec3 vertex;
  fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
  _vertices.push_back(vertex);
}

/**
 * @brief Saves the normal vector data
 * 
 * @param file file
 */
void Model::saveNormal(FILE* file) {
  glm::vec3 normal;
  fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
  _normals.push_back(normal);
}

/**
 * @brief Saves the texture coordinates data
 * 
 * @param file file
 */
void Model::saveTexCoord(FILE* file) {
  glm::vec2 texCoord;
  fscanf(file, "%f %f\n", &texCoord.x, &texCoord.y);
  _texCoord.push_back(texCoord);
}

/**
 * @brief Saves the face indices
 * 
 * @param file file
 */
void Model::saveFace(FILE* file) {
  unsigned int vertexIndex[3];
  unsigned int uvIndex[3];
  unsigned int normalIndex[3];

  int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", 
                       &vertexIndex[0], &uvIndex[0], &normalIndex[0], 
                       &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                       &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

  if (matches != 9) {
    qDebug() << "Parser error";
    return;
  }

  _vertexIndices.push_back(vertexIndex[0]);
  _vertexIndices.push_back(vertexIndex[1]);
  _vertexIndices.push_back(vertexIndex[2]);

  _textureIndices.push_back(uvIndex[0]);
  _textureIndices.push_back(uvIndex[1]);
  _textureIndices.push_back(uvIndex[2]);

  _normalIndices.push_back(normalIndex[0]);
  _normalIndices.push_back(normalIndex[1]);
  _normalIndices.push_back(normalIndex[2]);
}