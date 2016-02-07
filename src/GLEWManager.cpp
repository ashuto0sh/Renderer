#include "include/GLEWManager.h"

namespace Renderer {
	bool initGL(){
		glewExperimental = GL_TRUE;
		if(glewInit() != GLEW_OK){
			return false;
		}
		glViewport(0, 0, 800, 600);
		glEnable(GL_DEPTH_TEST);
		return true;
	}

	void resetScreen(){
		glClearColor(0.3f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}
