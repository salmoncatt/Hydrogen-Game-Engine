#version 400 core
out vec4 fragColor;

//texture things
in vec2 passedTextureCoords;
uniform sampler2D textureSampler;
uniform bool hasTextureCoords;


//light stuff
uniform vec3 lightColor;
uniform int lightMode;
in vec3 surfaceNormal;
in float passedLight;
in vec3 lightVector;


uniform vec3 diffuseColor;
uniform vec3 ambientColor;
uniform vec3 specularColor;
uniform float ambientStrength;

vec3 max(vec3 a, vec3 b) {
  return vec3(max(a.x, a.x), max(a.y, b.y), max(a.z, b.z));
}



//lighting calcs done here
vec4 getLight(){
		float light = dot(surfaceNormal, lightVector);
		light = max(light, 0);


		vec3 ambient = ambientColor * ambientStrength;

		//light = max(intensity, 0.2);
		vec3 diffuse = lightColor * light;
		vec3 finalLight = diffuse + ambient;
		
		
		return vec4(finalLight, 1);
}









void main() {
	
	//float light = passedLight;

	//vec4 color = vec4(albedoColor, 1);

	if(hasTextureCoords)
		fragColor = texture(textureSampler, passedTextureCoords);
	else
		fragColor = vec4(diffuseColor, 1);


	//lightMode means 1 = per vertex, 2 = per pixel
	if(lightMode == 0)
		fragColor *= getLight();

	//fragColor = color;

	float gamma = 2.2;

	//fragColor.rgb = pow(fragColor.rgb, vec3(1 / gamma));

}