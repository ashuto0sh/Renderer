#include "include/Texture.h"
#include "GL/glew.h"
#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>

namespace Renderer {
	GLuint TextureFromFile(const char* fName, const char* dirPath){
		std::string fPath;
		std::string tmpDirPath;

		if(dirPath == NULL){
			char path[1024];
			getcwd(path, 1024);
			tmpDirPath = std::string(path, strlen(path));
		} else {
			tmpDirPath = std::string(dirPath);
		}
		fPath = tmpDirPath + "/" + fName;

		GLuint textureId;
		glGenTextures(1, &textureId);
		int height, width;
		unsigned char* img = SOIL_load_image(fPath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
		glBindTexture(GL_TEXTURE_2D, textureId);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
		glGenerateMipmap(GL_TEXTURE_2D);

		// Parameters
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
		SOIL_free_image_data(img);

		return textureId;
	}
}
