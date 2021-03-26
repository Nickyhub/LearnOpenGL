#include "Camera.h"

Camera::Camera()
	: m_Position(glm::vec3(0.0f, 0.0f, 3.0f)),
	  m_Direction(glm::vec3(0.0f, 0.0f, 0.0f)),
	  m_Target(glm::vec3(0.0f, 0.0f, 0.0f)),
	  m_Up(glm::vec3(0.0f, 0.0f, 0.0f)),
	  m_Right(glm::vec3(0.0f, 0.0f, 0.0f)),
	  m_View(glm::mat4(1.0f))
{
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	m_Direction = glm::normalize(m_Position - m_Target);
	m_Right = glm::normalize(glm::cross(m_Up, m_Direction));
	m_Up = glm::cross(m_Direction, m_Right);

	m_View = glm::lookAt(m_Position, m_Target, m_Up);
}

Camera::Camera(GLFWwindow* window)
{
	window = window;
}

void Camera::ProcessKeyboardInput()
{
	const float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;
	m_View = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0));
}

void Camera::ProcessMouseInput()
{

}
