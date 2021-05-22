#include "Camera.h"
#include "Application.h"
#include <iostream>


glm::vec3 Camera::m_Position;
glm::vec3 Camera::m_Direction;
glm::vec3 Camera::m_Up;
glm::vec3 Camera::m_Right;
glm::mat4 Camera::m_View;

bool Camera::m_FirstCamera;
float Camera::m_LastXPos;
float Camera::m_LastYPos;
float Camera::m_Speed;
float Camera::m_Sensitivity;
float Camera::m_Yaw;
float Camera::m_Pitch;

void Camera::Init()
{
	m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_Direction = glm::vec3(0.0f, 0.0f, 1.0f);
	m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
	m_Right = glm::vec3(1.0f, 0.0f, 0.0f);
	m_View = glm::mat4(1.0f);
	m_Speed = 0.01f;
	m_FirstCamera = true;
	m_LastXPos = 960;
	m_LastYPos = 540;
	m_Yaw = -90.0f;
	m_Pitch = 0.0f;
	m_Sensitivity = 0.1f;
	glfwSetCursorPosCallback(Application::GetWindow(), ProcessMouseInput);
	glfwSetInputMode(Application::GetWindow(), GLFW_STICKY_KEYS, GLFW_TRUE);
}

void Camera::ProcessKeyboardInput(CameraDirection direction, float deltaTime)
{
	if (direction == CameraDirection::FORWARD) {
		m_Position += m_Speed * m_Direction;
	}
	else if (direction == CameraDirection::BACKWARD) {
		m_Position -= m_Speed * m_Direction;
	}
	else if (direction == CameraDirection::RIGHT) {
		m_Position += glm::normalize(glm::cross(m_Direction, m_Up)) * m_Speed;
	}
	else if (direction == CameraDirection::LEFT) {
		m_Position -= glm::normalize(glm::cross(m_Direction, m_Up)) * m_Speed;
	}
	m_View = glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
}

void Camera::ProcessMouseInput(GLFWwindow* window, double xpos, double ypos)
{
	if (m_FirstCamera) {
		m_LastXPos = xpos;
		m_LastYPos = ypos;
		m_FirstCamera = false;
	}

	float xoffset = (float)xpos - m_LastXPos;
	float yoffset = m_LastYPos - (float)ypos;
	xoffset = xoffset * m_Sensitivity;
	yoffset = yoffset * m_Sensitivity;

	m_LastXPos = xpos;
	m_LastYPos = ypos;

	m_Yaw += xoffset;
	m_Pitch += yoffset;

	if (m_Pitch > 89.0f)
		m_Pitch = 89.0f;
	if (m_Pitch < -89.0f)
		m_Pitch = -89.0f;

	if (m_Yaw > 360.0f)
		m_Yaw = 0.0f;
	if (m_Yaw < -360.0f)
		m_Yaw = 0.0f;

	m_Direction.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Direction.y = sin(glm::radians(m_Pitch));
	m_Direction.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Direction = glm::normalize(m_Direction);
	m_View = glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
}

glm::mat4 Camera::GetViewMatrix()
{
	return m_View;
}