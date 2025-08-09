#pragma once
#include <glad/glad.h> 
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include "shader.h"
#include "Maths/matrix4x4.h"
#include "Maths/quaternion.h"
#include "Maths/constants.h"
#include "camera.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

struct Transformation
{
	float scaleX = 1.0f, scaleY = 1.0f, scaleZ = 1.0f;
	Quaternion quat = Quaternion(Vector3(1.0f, 0.0f, 0.0f), 0.0f);
	float translationX = 0.0f, translationY = 0.0f, translationZ = 0.0f;
};

class Application
{
public:
	static Transformation transformation;
	static CameraMovement cameraMovement;

	bool init();
	void mainLoop();
	void cleanup();

private:
	const int WINDOW_WIDTH = 900; 
	const int WINDOW_HEIGHT = 900; 
	const unsigned char BACKGROUND_COLOUR = 30;

	Camera camera = Camera(Vector3(0.0f, 0.0f, 5.0f), 0.0f, 0.0f);
	GLFWwindow* window;
	GLuint shaderProgram, VAO, VBO, EBO, viewO, projectionO;
	Matrix4x4 view = IdentityMatrix(), projection = IdentityMatrix();
	float viewMatrix[16] = {}, projectionMatrix[16] = {};

	void setViewMatrix(Matrix4x4 matrix);
	void setProjectionMatrix(Matrix4x4 matrix);
	void renderGUI();
	void render();
};
