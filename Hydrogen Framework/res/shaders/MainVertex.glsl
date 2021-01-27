#version 400 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoords;
layout (location = 2) in vec3 normal;

out vec2 passedTextureCoords;
out vec3 passNormal;

uniform mat4 projectionViewTransform;
uniform mat4 projectionTransform;

uniform int lightMode;
out float passedLight;
out int passLightMode;

void main() {

	gl_Position = projectionViewTransform * vec4(position, 1.0);
	passedTextureCoords = textureCoords;

	passNormal = normalize((projectionTransform * vec4(normal, 1)).xyz);

	passLightMode = lightMode;

	if(lightMode == 1){
	float intensity = dot(vec3(0, 1, 0), passNormal);

	passedLight = max(intensity, 0.2);
	}

}