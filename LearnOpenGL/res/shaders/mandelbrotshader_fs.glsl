#version 460 core

out vec4 FragColor;

in vec4 fragColor;

vec4 myColors[16];

uniform int MAX_ITERATIONS;
uniform float zoom;
uniform float center_x;
uniform float center_y;

int get_numeration() {
	int iterations;
	double cReal = (gl_FragCoord.x / 1080.0f - 1.3) * zoom + (center_x);
	double cImag = (gl_FragCoord.y / 1080.0f - 0.5) * zoom + (center_y);
	double zReal;
	double zImg;
	double zRealTemp;

	while (iterations < MAX_ITERATIONS) {
		zRealTemp = (zReal * zReal) - (zImg * zImg) + cReal;
		zImg = 2 * zReal * zImg + cImag;
		zReal = zRealTemp;

		if(zReal * zReal + zImg * zImg >= 4) {
			break;
		}
		iterations++;
	}
	return iterations; 
}

vec4 return_color() {
	int iter = get_numeration();
	if (iter == MAX_ITERATIONS) {
		return vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	if(mod(iter, 16) == 0) {
		return vec4(0.258, 0.078, 0.058, 1.0f);
	} else if(mod(iter, 16) == 1) {
		return vec4(0.098, 0.027, 0.101, 1.0f);
	} else if(mod(iter, 16) == 2) {
		return vec4(0.035, 0.003, 0.184, 1.0f);
	} else if(mod(iter, 16) == 3) {
		return vec4(0.015, 0.015, 0.286, 1.0f);
	} else if(mod(iter, 16) == 4) {
		return vec4(0, 0.027, 0.392, 1.0f);
	} else if(mod(iter, 16) == 5) {
		return vec4(0.047, 0.172, 0.541, 1.0f);
	} else if(mod(iter, 16) == 6) {
		return vec4(0.094, 0.321, 0.694, 1.0f);
	} else if(mod(iter, 16) == 7) {
		return vec4(0.223, 0.490, 0.819, 1.0f);
	} else if(mod(iter, 16) == 8) {
		return vec4(0.525, 0.709, 0.898, 1.0f);
	} else if(mod(iter, 16) == 9) {
		return vec4(0.827, 0.925, 0.972, 1.0f);
	} else if(mod(iter, 16) == 10) {
		return vec4(0.945, 0.913, 0.749, 1.0f);
	} else if(mod(iter, 16) == 11) {
		return vec4(0.972, 0.788, 0.372, 1.0f);
	} else if(mod(iter, 16) == 12) {
		return vec4(1, 0.666, 0, 1.0f);
	} else if(mod(iter, 16) == 13) {
		return vec4(0.8, 0.501, 0, 1.0f);
	} else if(mod(iter, 16) == 14) {
		return vec4(0.6, 0.341, 0, 1.0f);
	} else if(mod(iter, 16) == 15) {
		return vec4(0.415, 0.203, 0.011, 1.0f);
	}

	float iterations = float(iter) / MAX_ITERATIONS;
	return vec4(0.0f, 0.0f, iterations, 1.0f);
}

void main() {
	FragColor = return_color();
}