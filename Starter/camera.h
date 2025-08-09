#pragma once
#include "Maths/vector.h"
#include "Maths/matrix4x4.h"

struct CameraMovement
{
	bool goingUp = false, goingDown = false;
	bool goingForward = false, goingBackward = false;
	bool goingRight = false, goingLeft = false;
	bool rotating = false;
};

class Camera
{
private:
	// TODO: affects the speed or camera movement - adjust accordingly or turn into a modifiable value depending on the application
	const double MOVE_FACTOR = 0.005f;
	const double ROTATION_FACTOR = 0.001f;
	double rotationX = 0.0f, rotationY = 0.0f;

	void setVectors();

public:
	Vector3 position;
	Vector3 forward;
	Vector3 up;
	Vector3 right;

	Camera(Vector3 position, double rotationX, double rotationY);

	Matrix4x4 getViewMatrix(float offset = 0.0f);
	Matrix4x4 getInvertedViewMatrix(float offset = 0.0f);
	void move(CameraMovement movement);
};
