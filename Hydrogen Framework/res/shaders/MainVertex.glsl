#version 400 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoords;
layout (location = 2) in vec3 normal;


uniform mat4 transformMatrix;
uniform mat4 projectionViewTransformMatrix;

//light stuff
//uniform vec3 lightPosition;
//uniform int lightMode;
//out float passedLight;
//out int passLightMode;
out vec3 surfaceNormal;
//out vec3 lightVector;

out vec2 passedTextureCoords;
out vec3 worldPosition;

void main() {

	gl_Position = projectionViewTransformMatrix * vec4(position, 1.0);
	passedTextureCoords = textureCoords;

	
	
	//passLightMode = lightMode;
	worldPosition = vec3(transformMatrix * vec4(position, 1.0));
	surfaceNormal = normalize((transformMatrix * vec4(normal, 1)).xyz);
	//lightVector = normalize(lightPosition - (transformMatrix * vec4(position, 1.0)).xyz);

//	if(lightMode == 1){
//		float intensity = dot(surfaceNormal, lightVector);
//
//		passedLight = max(intensity, 0.2);
//	}

}