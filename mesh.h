#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QSharedPointer>

#include <string>
#include <vector>

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 texCoord;
};

struct Texture {
  std::string type;
  std::string filepath;
  QSharedPointer<QOpenGLTexture> texture;
};

class Mesh : protected QOpenGLFunctions_3_3_Core {
 public:
  Mesh(const std::vector<Vertex>& vertices,
       const std::vector<unsigned int>& indices,
       const std::vector<Texture>& texture);

  ~Mesh();

  void draw(QOpenGLShaderProgram* program);


 private:
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<Texture> textures;

  bool isInitialized;

  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;

  void setupMesh(QOpenGLShaderProgram* program);

};

#endif  // MESH_H
