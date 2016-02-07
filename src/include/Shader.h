#ifndef __SHADER_H
#define __SHADER_H

#include <GL/glew.h>

namespace Renderer{
	class Shader
	{
	public:
		GLuint Program;
		// Constructor generates the shader on the fly
		Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
		// Uses the current shader
		void Use();
	};
}

#endif
