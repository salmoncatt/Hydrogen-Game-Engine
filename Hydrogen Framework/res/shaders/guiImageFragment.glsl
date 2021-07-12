#version 400 core
out vec4 fragColor;

in vec2 passTextureCoords;

uniform vec4 color;
uniform float alpha;
uniform float aspectRatio;
uniform vec2 uiSize;

uniform vec4 borderColor;
uniform float borderSize;

uniform float cornerRadius;
uniform float smoothness;

bool isOnEdge(vec2 position, float size){
	
	float maxX = uiSize.x - size;
	float maxY = uiSize.y - size;

	if (position.x < size || position.x > maxX)
		return true;
	else if (position.y < size || position.y > maxY)
		return true;

	return false;
}

float getRoundedRectangle(vec2 position) {

	float maxX = uiSize.x - cornerRadius;
	float maxY = uiSize.y - cornerRadius;
	float alpha = 1;

	if (position.x < cornerRadius && position.y < cornerRadius)
		alpha = 1 - smoothstep(cornerRadius - smoothness, cornerRadius + smoothness, length(position - vec2(cornerRadius, cornerRadius)));
	else if (position.x < cornerRadius && position.y > maxY)
		alpha = 1 - smoothstep(cornerRadius - smoothness, cornerRadius + smoothness, length(position - vec2(cornerRadius, maxY)));
	else if (position.x > maxX && position.y < cornerRadius)
		alpha = 1 - smoothstep(cornerRadius - smoothness, cornerRadius + smoothness, length(position - vec2(maxX, cornerRadius)));
	else if (position.x > maxX && position.y > maxY)
		alpha = 1 - smoothstep(cornerRadius - smoothness, cornerRadius + smoothness, length(position - vec2(maxX, maxY)));

	return alpha;
}

void main() {
	vec2 pixelPosition = passTextureCoords * uiSize;	
	vec4 tempColor = color;

	if(isOnEdge(pixelPosition, borderSize))
		tempColor = borderColor;
	else
		tempColor = color;

	if(cornerRadius > 0)
		tempColor.a *= getRoundedRectangle(pixelPosition); 

	fragColor = tempColor;
}
