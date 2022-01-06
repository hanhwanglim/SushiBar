/*
 * Code was sourced and modified from OpenGL tutorial
 *
 * http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
 */

#ifndef MODEL_H
#define MODEL_H

#include <glm/glm.hpp>

#include <string>
#include <vector>

class Model {
 public:
  Model(const std::string& path);

  std::vector<glm::vec3> vertices() { return _vertices; }
  std::vector<glm::vec3> normals() { return _normals; }
  std::vector<glm::vec2> texCoord() { return _texCoord; }

  std::vector<unsigned int> vertexIndices() { return _vertexIndices; }
  std::vector<unsigned int> normalIndices() { return _normalIndices; }
  std::vector<unsigned int> textureIndices() { return _textureIndices; }

 private:
  std::vector<glm::vec3> _vertices;
  std::vector<glm::vec3> _normals;
  std::vector<glm::vec2> _texCoord;

  std::vector<unsigned int> _vertexIndices;
  std::vector<unsigned int> _normalIndices;
  std::vector<unsigned int> _textureIndices;

  void parseObj(FILE* file);

  void saveVertex(FILE* file);
  void saveNormal(FILE* file);
  void saveTexCoord(FILE* file);
  void saveFace(FILE* file);
};

#endif
