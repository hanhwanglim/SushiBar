#include "mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices,
           const std::vector<unsigned int>& indices,
           const std::vector<Texture>& texture) {
  this->vertices = vertices;
  this->indices = indices;
  this->textures = texture;

  this->isInitialized = false;

  initializeOpenGLFunctions();
}

Mesh::~Mesh() {
  glDeleteBuffers(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}

void Mesh::setupMesh(QOpenGLShaderProgram* program) {
  // Initialise VAO, VBO and EBO
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  // Setup VAO
  glBindVertexArray(VAO);

  // Setup VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),
               vertices.data(), GL_STATIC_DRAW);

  // Setup EBO
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
               indices.data(), GL_STATIC_DRAW);

  // 0. Hold the position vectors
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

  // 1. Hold the normal vectors
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, normal));

  // 2. Hold the texture coordinates
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, texCoord));

  // Unbind to prevent accidental changes
  glBindVertexArray(0);
}

void Mesh::draw(QOpenGLShaderProgram* program) {
  if (!isInitialized) {
    setupMesh(program);
    isInitialized = true;
  }

  // Setup textures
  unsigned int diffuseNr = 1;
  unsigned int specularNr = 1;
  unsigned int normalNr = 1;
  unsigned int heightNr = 1;

  for (unsigned int i = 0; i < textures.size(); i++) {
    std::string number;
    std::string type = textures[i].type;

    if (type == "texture_diffuse")
      number = std::to_string(diffuseNr++);
    else if (type == "texture_specular")
      number = std::to_string(specularNr++);
    else if (type == "texture_normal")
      number = std::to_string(normalNr++);
    else if (type == "texture_height")
      number = std::to_string(heightNr++);

    // Bind the texture to shader program
    program->setUniformValue((type + number).c_str(), i);
    textures[i].texture->bind(static_cast<unsigned int>(i));
  }

  // Draw mesh
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}