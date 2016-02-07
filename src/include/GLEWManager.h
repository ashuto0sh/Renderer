#ifndef __GLEW_MANAGER_H
#define __GLEW_MANAGER_H

#include "../../include/GL/glew.h"

#define GLEW_STATIC

namespace Renderer {
	bool initGL();

	void resetScreen();
}

#endif
