#include <iostream>
#include <vector>
#include <fstream>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "include/GLEWManager.h"
#include "include/WindowManager.h"
#include "include/Shader.h"
#include "include/ModelManager.h"
#include "Camera.cpp"

int main(){
	Renderer::WindowManager wManager(800, 600, "Renderer Window");
	Renderer::initGL();
	Renderer::Shader shader("/home/ashutosh/Programming/Projects/Renderer/src/Shaders/vertexShader.sf", "/home/ashutosh/Programming/Projects/Renderer/src/Shaders/fragmentShader.sf");

	Renderer::ModelManager mm("/home/ashutosh/Programming/Projects/Renderer/models/nanosuit2.obj");

	Renderer::Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

	while (!wManager.doClose()){
		Renderer::resetScreen();

		shader.Use();

		// Set up and pass MVP Matrix
		glm::mat4 projection = glm::perspective(camera.Zoom, (float)800/(float)600, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));

		// Draw the loaded model
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));

		mm.Draw(shader);

		wManager.swapBuffers();
	}

	return 0;
}
