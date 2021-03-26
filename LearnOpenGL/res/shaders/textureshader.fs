#version 330 core

in vec4 ourColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec2 transparency;

void main()
{	
	FragColor = mix(texture(texture1, TexCoord) * ourColor, texture(texture2, TexCoord), transparency.x);
};