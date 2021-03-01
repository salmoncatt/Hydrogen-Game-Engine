#version 400 core
out vec4 fragColor;

in vec2 passTextureCoords;

uniform vec3 color;
uniform float alpha;
uniform vec2 uiSize;

void main() {
	vec2 pixelPosition = passTextureCoords * uiSize;	

	fragColor = vec4(color, alpha);
}
