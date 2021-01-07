#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const double YAW         = -90.0;
const double PITCH       = 0.0;
const double SPEED       = 250.0;
const double SENSITIVITY = 0.2;
const double ZOOM        = 75.0;


class Camera
{
public:
	glm::dvec3 Position;
	glm::dvec3 Front;
	glm::dvec3 Up;
	glm::dvec3 Right;
	glm::dvec3 WorldUp;
	
	double Yaw;
	double Pitch;

	double MovementSpeed;
	double MouseSensitivity;
	double Zoom;

	Camera(glm::dvec3 position = glm::dvec3(0.0, 0.0, 0.0), glm::dvec3 up = glm::dvec3(0.0, 1.0, 0.0), double yaw = YAW, double pitch = PITCH) :
		Front(glm::dvec3(0.0, 0.0, -1.0)),
		MovementSpeed(SPEED),
		MouseSensitivity(SENSITIVITY),
		Zoom(ZOOM)
	{
		Position = position;
		WorldUp = up;
		Yaw = yaw;
		Pitch = pitch;
		updateCameraVectors();
	}

	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(Position, Position + Front, glm::dvec3(0.0, 1.0, 0.0));
	}

	void ProcessCamRot(double xoffset, double yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= MouseSensitivity;
		yoffset *= MouseSensitivity;

		Yaw += xoffset;
		Pitch += yoffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (Pitch > 89.0)
				Pitch = 89.0;
			if (Pitch < -89.0)
				Pitch = -89.0;
		}
		

		// update Front, Right and Up Vectors using the updated Euler angles
		updateCameraVectors();
	}

	void ProcessCamPos(Camera_Movement direction, double dt)
	{
		double velocity = MovementSpeed * dt;
		if (direction == FORWARD)
			Position += Front * velocity;
		if (direction == BACKWARD)
			Position -= Front * velocity;
		if (direction == LEFT)
			Position -= Right * velocity;
		if (direction == RIGHT)
			Position += Right * velocity;
	}

private:

	void updateCameraVectors()
	{
		glm::vec3 front;
		front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
		front.y = sin(glm::radians(Pitch));
		front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
		Front = glm::normalize(front);
		Right = glm::normalize(glm::cross(Front, WorldUp));
		Up = glm::normalize(glm::cross(Right, Front));
	}
};

