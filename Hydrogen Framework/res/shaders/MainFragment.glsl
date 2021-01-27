#version 400 core
out vec4 fragColor;

in vec2 passedTextureCoords;
in vec3 passNormal;
in float passedLight;


uniform sampler2D textureSampler;
uniform bool hasTextureCoords;
uniform vec3 color;
uniform int lightMode;

void main() {
	
	float light = passedLight;

	if(hasTextureCoords)
		fragColor = texture(textureSampler, passedTextureCoords);
	else
		fragColor = vec4(color, 1.0);


	if(lightMode == 0){
	float intensity = dot(vec3(0, 1, 0), passNormal);

	light = max(intensity, 0.2);
	}

	fragColor *= vec4(light, light, light, 1);

}