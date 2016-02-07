#include "include/WindowManager.h"

namespace Renderer {
	WindowManager::WindowManager(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share){
		glfwInit();
		setWindowHints(false, false);
		window = glfwCreateWindow(width, height, title, monitor, share);
		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, keyCallback);
	}

	void WindowManager::setWindowHints(bool isCompatibilityMode, bool isResize){
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// load compatibilty profile o/w
		glfwWindowHint(GLFW_RESIZABLE, isResize);
	}

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode){
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}

	bool WindowManager::doClose(){
		bool isClose = glfwWindowShouldClose(window);
		if (!isClose)	glfwPollEvents();
		else glfwTerminate();
		return isClose;
	}

	void WindowManager::swapBuffers(){
		glfwSwapBuffers(window);
	}
}
