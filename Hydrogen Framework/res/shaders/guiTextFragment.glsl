#version 400 core
out vec4 fragColor;

in vec2 passedTextureCoords;


uniform sampler2D textureSampler;
uniform vec4 color;

void main() {
	
	fragColor = texture(textureSampler, passedTextureCoords);
	fragColor *= color;
	//fragColor = vec4(1,1,1,1);
}