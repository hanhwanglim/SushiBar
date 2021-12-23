#include "model.h"

/**
 * @brief Loads the model
 * 
 * @param path 
 */
Model::Model(const std::string& path) {
  FILE* file = fopen(path.c_str(), "r");

  if (file == NULL) {
    std::cout << "Cannot read file" << std::endl;
    return;
  }

  while (true) {
    // Read line
    char line[128];
    int l = fscanf(file, "%s", line);
    if (l == EOF) break;  // If end of file break

    // If vertex position
    if (strcmp(line, "v") == 0) {
      glm::vec3 vertex;
      fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
      this->vertices.push_back(vertex);
    }
    // If normal
    else if (strcmp(line, "vn") == 0) {
      glm::vec3 normal;
      fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
      this->normals.push_back(normal);
    }
    // If texture coordinate
    else if (strcmp(line, "vt") == 0) {
      glm::vec2 textureCoord;
      fscanf(file, "%f %f\n", &textureCoord.x, &textureCoord.y);
      this->texCoord.push_back(textureCoord);
    }
    // If face
    else if (strcmp(line, "f") == 0) {
      unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
      int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                           &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                           &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                           &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
      if (matches != 9) {
        std::cout << "Parser error" << std::endl;
        return;
      }

      vertexIndices.push_back(vertexIndex[0]);
      vertexIndices.push_back(vertexIndex[1]);
      vertexIndices.push_back(vertexIndex[2]);

      textureIndices.push_back(uvIndex[0]);
      textureIndices.push_back(uvIndex[1]);
      textureIndices.push_back(uvIndex[2]);

      normalIndices.push_back(normalIndex[0]);
      normalIndices.push_back(normalIndex[1]);
      normalIndices.push_back(normalIndex[2]);
    }
  }
}