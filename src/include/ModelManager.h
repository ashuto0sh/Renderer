#ifndef __MODEL_MANAGER_H
#define __MODEL_MANAGER_H

#include "GL/glew.h"
#include <vector>
#include <string>
#include "Shader.h"
#include "glm/glm.hpp"
#include "MeshManager.h"

//Assimp related
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

namespace Renderer{
	class ModelManager {
	public:
		ModelManager(const char* modelPath){ this->loadModel(modelPath); }
		void Draw(Shader shader);
	private:
		std::vector<MeshManager> meshes;
		std::string directory;
		// std::vector<Texture> textures;
	
		void loadModel(std::string modelPath);
		void processNode(aiNode* pNode, const aiScene* pScene);
		MeshManager processMesh(aiMesh* pMesh, const aiScene* pScene);
		//std::vector<Texture> loadMaterialTexture(aiMaterial* mat, aiTextureType type, std::string typename); // Skipping for now. No texture support
	};
}

#endif
