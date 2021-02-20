#version 400 core

layout (location = 0) in vec2 position;

out vec2 passTextureCoords;

uniform mat4 transform;
uniform mat4 ortho;

void main(){
	
	gl_Position = ortho * transform * vec4(position, 0, 1);
	passTextureCoords = vec2((position.x+1.0)/2.0, 1 - (position.y+1.0)/2.0);
}