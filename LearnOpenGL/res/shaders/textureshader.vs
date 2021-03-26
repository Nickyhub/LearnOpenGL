#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec4 ourColor;
out vec2 TexCoord;

uniform mat4 u_MVP;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * u_MVP;
	ourColor = aColor;
	TexCoord = aTexCoord;
};