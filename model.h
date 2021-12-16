#include <fstream>
#include <iostream>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class Model {
 public:
  Model(const std::string& path);

  std::vector<glm::vec3> vertices;
  std::vector<glm::vec3> normals;
  std::vector<glm::vec2> texCoord;

  std::vector<unsigned int> vertexIndices;
  std::vector<unsigned int> normalIndices;
  std::vector<unsigned int> textureIndices;
};
