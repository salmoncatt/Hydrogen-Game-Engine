#version 400 core
out vec4 fragColor;

//texture things
in vec2 passedTextureCoords;
in vec3 worldPosition;
//uniform sampler2D textureSampler;
uniform bool hasTextureCoords;


//light stuff
//uniform vec3 lightDiffuse;
//uniform vec3 lightAmbient;
//uniform vec3 lightSpecular;
//uniform int lightMode;
in vec3 surfaceNormal;
//in float passedLight;
//in vec3 lightVector;
uniform vec3 cameraPosition;

//uniform vec3 diffuseColor;
//uniform vec3 ambientColor;
//uniform vec3 specularColor;
//uniform float specularExponent;
//uniform float ambientIntensity;
uniform bool useLighting;

uniform vec3 test;

vec3 max(vec3 a, vec3 b) {
  return vec3(max(a.x, a.x), max(a.y, b.y), max(a.z, b.z));
}

struct Material {
	
	//1 = map, 2 = color
	bool useDiffuseMap;
	sampler2D diffuseMap;
	vec3 diffuseColor;
	
	//1 = map, 2 = color
	bool useAmbientMap;
	sampler2D ambientMap;
	vec3 ambientColor;
	
	//1 = map, 2 = color
	bool useSpecularMap;
	sampler2D specularMap;
	vec3 specularColor;
	float specularExponent;
	
	//1 = map, 2 = color
	bool useEmissionMap;
	sampler2D emissionMap;
	vec3 emissionColor;

};

struct Light {
	
	vec3 position;
	vec3 ambientColor;
	vec3 diffuseColor;
	vec3 specularColor;

};

uniform Material material;
uniform Light light;

//lighting calcs done here
vec4 getLight(){
		
		vec3 lightVector = normalize(light.position - worldPosition); 
		float lightDot = dot(surfaceNormal, lightVector);
		lightDot = max(lightDot, 0);

		//ambient calculations (now including ambient maps)
		vec3 ambient;
		if(material.useAmbientMap)
			ambient = texture(material.ambientMap, passedTextureCoords).rgb * light.ambientColor;
		else
			ambient = material.ambientColor * light.ambientColor;

		//specular calculations
		vec3 viewDirection = normalize(cameraPosition - worldPosition);
		vec3 reflectDirection = reflect(-lightVector, surfaceNormal);

		float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), material.specularExponent);

		vec3 specular;
		if(material.useSpecularMap)
			specular = texture(material.specularMap, passedTextureCoords).rgb * spec * light.specularColor;
		else
			specular = material.specularColor * spec * light.specularColor;


		//diffuse calculations
		vec3 diffuse;
		if(material.useDiffuseMap)
			diffuse = light.diffuseColor * lightDot * texture(material.diffuseMap, passedTextureCoords).rgb;
		else
			diffuse = light.diffuseColor * lightDot * material.diffuseColor;

		//emission
		vec3 emission;
		if(material.useEmissionMap)
			emission = texture(material.emissionMap, passedTextureCoords).rgb;
		else
			emission = material.emissionColor;



		vec3 finalLight = diffuse + ambient + specular + emission;
		
		return vec4(finalLight, 1);
}









void main() {
	


	//lightMode means 1 = per pixel, 0 = per vertex
	if(useLighting)
		fragColor = getLight();
	else{

		if(hasTextureCoords && material.useDiffuseMap)
			fragColor = texture(material.diffuseMap, passedTextureCoords);
		else
			fragColor = vec4(material.diffuseColor, 1);
	}

	//fragColor = color;

	float gamma = 2.2;

	//fragColor.rgb = pow(fragColor.rgb, vec3(1 / gamma));

}