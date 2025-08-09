#pragma once
#include <glad/glad.h> 
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include "shader.h"
#include "Maths/matrix4x4.h"
#include "camera.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class Application
{
public:
	bool init();
	void mainLoop();
	void cleanup();

private:
	const int WINDOW_WIDTH = 1536; 
	const int WINDOW_HEIGHT = 896; 
	const float MIN_SCALE = 0.5f;
	const float MAX_SCALE = 3.0f;
	const unsigned char BACKGROUND_COLOUR = 30;

	float scaleY = 1.0f;
	float scaleZ = 1.0f;
	GLFWwindow* window;
	GLuint shaderProgram;
	void renderGUI();
	void render();
};
