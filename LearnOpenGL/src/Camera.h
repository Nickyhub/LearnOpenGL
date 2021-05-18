#pragma once
#include "GL/glew.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"

enum class CameraDirection {
	FORWARD,
	BACKWARD,
	LEFT, 
	RIGHT
};

class Camera
{
public:
	static void Init();
	
	static void ProcessKeyboardInput(CameraDirection direction, float deltaTime);
	static void ProcessMouseInput(GLFWwindow* window, double xpos, double ypos);

	static glm::mat4 GetViewMatrix();

private:
	static glm::vec3 m_Position;
	static glm::vec3 m_Direction;
	static glm::vec3 m_Up;
	static glm::vec3 m_Right;
	static glm::mat4 m_View;

	static bool m_FirstCamera;
	static float m_LastXPos;
	static float m_LastYPos;
	static float m_Speed;
	static float m_Sensitivity;
	static float m_Yaw;
	static float m_Pitch;
};