#ifndef __MESH_MANAGER_H
#define __MESH_MANAGER_H

#include "vector"
#include "GL/glew.h"
#include "glm/glm.hpp"
#include "Shader.h"

namespace Renderer {
	struct Vertex {
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	class MeshManager {
	public:
		std::vector<Renderer::Vertex> vertices;
		std::vector<GLuint> indices;

		MeshManager(std::vector<Renderer::Vertex> vertices, std::vector<GLuint> indices);

		void Draw(Shader shader);

	private:
		GLuint VAO, VBO, EBO;

		void setupMesh();

	};
}

#endif
