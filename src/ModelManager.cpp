#include "include/ModelManager.h"
#include <iostream>

namespace Renderer {
	void ModelManager::Draw(Shader shader){
		for(int i = 0; i < this->meshes.size(); ++i)
			this->meshes[i].Draw(shader);
	}

	void ModelManager::loadModel(std::string path){
		Assimp::Importer importer;
		const aiScene* pScene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
		if(!pScene || pScene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !pScene->mRootNode){
			return;
		}
		this->directory = path.substr(0, path.find_last_of('/'));

		this->processNode(pScene->mRootNode, pScene);
	}

	void ModelManager::processNode(aiNode* pNode, const aiScene* pScene){
		for(GLuint i = 0; i<pNode->mNumMeshes; ++i){
			aiMesh* pMesh = pScene->mMeshes[pNode->mMeshes[i]];
			this->meshes.push_back(this->processMesh(pMesh, pScene));
		}
		for(GLuint i = 0; i < pNode->mNumChildren; i++){
			this->processNode(pNode->mChildren[i], pScene);
		}
	}

	MeshManager ModelManager::processMesh(aiMesh* pMesh, const aiScene* pScene){
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		// std::vector<Vertex> vertices;

		for(GLint i = 0; i < pMesh->mNumVertices; ++i){
			Vertex vtx;
			glm::vec3 vec;
			vec.x = pMesh->mVertices[i].x;
			vec.y = pMesh->mVertices[i].y;
			vec.z = pMesh->mVertices[i].z;
			vtx.Position = vec;

			if(pMesh->mNormals){
				std::cout<<"Normals Exist"<<std::endl;
				vec.x = pMesh->mNormals[i].x;
				vec.y = pMesh->mNormals[i].y;
				vec.z = pMesh->mNormals[i].z;
				vtx.Normal = vec;
			} else 
				std::cout<<"Normals Dont Exist"<<std::endl;

			if(pMesh->mTextureCoords[0])
				vtx.TexCoords = glm::vec2(pMesh->mTextureCoords[0][i].x, pMesh->mTextureCoords[0][i].y);
			else
				vtx.TexCoords = glm::vec2(0.0f, 0.0f);
			vertices.push_back(vtx);
		}
		// Now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
		for(GLuint i = 0; i < pMesh->mNumFaces; i++)
		{
			aiFace face = pMesh->mFaces[i];
			// Retrieve all indices of the face and store them in the indices vector
			for(GLuint j = 0; j < face.mNumIndices; j++)
				indices.push_back(face.mIndices[j]);
		}
		return MeshManager(vertices, indices);
	}
}
