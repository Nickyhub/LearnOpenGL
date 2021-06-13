#version 330 core

in vec2 TexCoord;
in vec4 frag_color;

uniform sampler2D texture1;
uniform sampler2D texture2;

out vec4 FragColor;

void main() {
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord) * frag_color, 0.8f);
};