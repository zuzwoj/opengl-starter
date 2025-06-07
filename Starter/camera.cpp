#include "camera.h"

Camera::Camera(Vector3 position, double rotationX, double rotationY)
{
	this->position = position;
	this->rotationX = rotationX;
	this->rotationY = rotationY;
	setVectors();
}

void Camera::setVectors()
{
	forward.x = cos(rotationX) * sin(rotationY);
	forward.y = sin(rotationX);
	forward.z = cos(rotationX) * cos(rotationY);

	right.x = cos(rotationY);
	right.y = 0;
	right.z = -sin(rotationY);

	up.x = -sin(rotationX) * sin(rotationY);
	up.y = cos(rotationX);
	up.z = -sin(rotationX) * cos(rotationY);
}

Matrix4x4 Camera::getViewMatrix(float offset)
{
	Vector3 offsetPosition = position + right * offset;
	return Matrix4x4(
		right.x, right.y, right.z, -right * offsetPosition,
		up.x, up.y, up.z, -up * offsetPosition,
		-forward.x, -forward.y, -forward.z, forward * offsetPosition,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix4x4 Camera::getInvertedViewMatrix(float offset)
{
	Matrix4x4 result = Matrix4x4(
		right.x, up.x, -forward.x, 0.0f,
		right.y, up.y, -forward.y, 0.0f,
		right.z, up.z, -forward.z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	Vector4 pos = Vector4(position + right * offset);
	pos = result * pos;
	result = Matrix4x4(
		right.x, up.x, -forward.x, -pos.x,
		right.y, up.y, -forward.y, -pos.y,
		right.z, up.z, -forward.z, -pos.z,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	return result;
}

void Camera::move(CameraMovement movement)
{
	if (movement.rotating)
	{
		if (movement.goingUp)
		{
			rotationX -= ROTATION_FACTOR;
		}
		if (movement.goingDown)
		{
			rotationX += ROTATION_FACTOR;
		}
		if (movement.goingLeft)
		{
			rotationY += ROTATION_FACTOR;
		}
		if (movement.goingRight)
		{
			rotationY -= ROTATION_FACTOR;
		}
		setVectors();
	}
	else
	{
		if (movement.goingBackward)
		{
			position += MOVE_FACTOR * forward;
		}
		if (movement.goingForward)
		{
			position -= MOVE_FACTOR * forward;
		}
		if (movement.goingUp)
		{
			position += MOVE_FACTOR * up;
		}
		if (movement.goingDown)
		{
			position -= MOVE_FACTOR * up;
		}
		if (movement.goingLeft)
		{
			position -= MOVE_FACTOR * right;
		}
		if (movement.goingRight)
		{
			position += MOVE_FACTOR * right;
		}
	}
}
