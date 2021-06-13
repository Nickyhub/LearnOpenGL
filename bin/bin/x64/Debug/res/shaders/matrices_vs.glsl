#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

out vec4 frag_color;

void main() {
	gl_Position = model * view * proj * vec4(position, 1.0f);
	frag_color = color;
	
}