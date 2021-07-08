#version 400 core
out vec4 fragColor;

//texture things
in vec2 passedTextureCoords;
in vec3 worldPosition;
uniform sampler2D textureSampler;
uniform bool hasTextureCoords;


//light stuff
uniform vec3 lightDiffuse;
uniform vec3 lightAmbient;
uniform vec3 lightSpecular;
uniform int lightMode;
in vec3 surfaceNormal;
in float passedLight;
in vec3 lightVector;
uniform vec3 cameraPosition;

uniform vec3 diffuseColor;
uniform vec3 ambientColor;
uniform vec3 specularColor;
uniform float specularExponent;
uniform float ambientIntensity;
uniform bool useLighting;

uniform vec3 test;

vec3 max(vec3 a, vec3 b) {
  return vec3(max(a.x, a.x), max(a.y, b.y), max(a.z, b.z));
}

struct Material {
	
	sampler2D diffuseMap;
	vec3 diffuseColor;
	
	sampler2D ambientMap;
	vec3 ambientColor;

	sampler2D specularMap;
	vec3 specularColor;
	float specularExponent;

	sampler2D emission;
	vec3 emissionColor;

};

struct Light {
	
	vec3 position;
	vec3 ambientColor;
	vec3 diffuseColor;
	vec3 specularColor;

};

//lighting calcs done here
vec4 getLight(){
		float light = dot(surfaceNormal, lightVector);
		light = max(light, 0);

		//ambient calculations
		vec3 ambient = ambientColor * lightAmbient;

		//specular calculations
		vec3 viewDirection = normalize(cameraPosition - worldPosition);
		vec3 reflectDirection = reflect(-lightVector, surfaceNormal);

		float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), specularExponent);
		vec3 specular = specularColor * spec * lightSpecular;

		//diffuse calculations
		vec3 diffuse = lightDiffuse * light;
		vec3 finalLight = diffuse + ambient + specular;
		
		
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
	if(lightMode == 0 && useLighting)
		fragColor *= getLight();

	//fragColor = color;

	float gamma = 2.2;

	//fragColor.rgb = pow(fragColor.rgb, vec3(1 / gamma));

}