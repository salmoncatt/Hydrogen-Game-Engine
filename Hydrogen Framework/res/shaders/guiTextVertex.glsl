#version 400 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoords;

out vec2 passedTextureCoords;

void main() {

	gl_Position = vec4(position, 1);
	passedTextureCoords = textureCoords;

}
