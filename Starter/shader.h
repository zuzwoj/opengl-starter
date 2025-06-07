#pragma once
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

class Shader
{
public:
	GLuint createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);

private:
	GLuint compileShader(GLenum type, const std::string& source);
	std::string loadShaderSource(const std::string& filepath);
};
