#version 400 core
out vec4 fragColor;

//texture things
in vec2 passedTextureCoords;
uniform sampler2D textureSampler;
uniform bool hasTextureCoords;
uniform vec3 color;


//light stuff
uniform vec3 lightColor;
uniform int lightMode;
in vec3 surfaceNormal;
in float passedLight;
in vec3 lightVector;

void main() {
	
	float light = passedLight;

	if(hasTextureCoords)
		fragColor = texture(textureSampler, passedTextureCoords);
	else
		fragColor = vec4(color, 1.0);


	//lightMode means 1 = per vertex, 2 = per pixel
	if(lightMode == 0){
		float intensity = dot(surfaceNormal, lightVector);

		light = max(intensity, 0.2);
	}

	vec3 diffuse = lightColor * light;
	
	fragColor *= vec4(diffuse, 1);

	float gamma = 2.2;

	//fragColor.rgb = pow(fragColor.rgb, vec3(1 / gamma));

}