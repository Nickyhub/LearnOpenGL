#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"

class Camera
{
public:
	Camera();
	
	//temporary
	Camera(GLFWwindow* window);

	void ProcessKeyboardInput();
	void ProcessMouseInput();

	glm::mat4 GetViewMatrix() { return m_View; }

private:
	glm::vec3 m_Position;
	glm::vec3 m_Direction;
	glm::vec3 m_Target;
	glm::vec3 m_Up;
	glm::vec3 m_Right;
	glm::mat4 m_View;

	//temporary shit
	GLFWwindow* window;

	float m_Speed = 0.05f;
};

