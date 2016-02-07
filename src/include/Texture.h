#ifndef __TEXTURE_H
#define __TEXTURE_H

#include "SOIL.h"
#include "GL/glew.h"

namespace Renderer {
	GLuint TextureFromFile(const char* fName, const char* currentDir);
}

#endif
