#ifndef __WINDOW_MANAGER_H
#define __WINDOW_MANAGER_H

#include "GLFW/glfw3.h"

namespace Renderer {
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	class WindowManager{
		GLFWwindow* window;
		void setWindowHints(bool isCompatibilityMode, bool isResize);
	public:
		WindowManager(int width, int height, const char* title, GLFWmonitor* monitor = nullptr, GLFWwindow* share = nullptr);
		~WindowManager(){ glfwTerminate(); }
		bool doClose();	// check if windowShouldClose and poll events
		void swapBuffers();
	};
}

#endif
