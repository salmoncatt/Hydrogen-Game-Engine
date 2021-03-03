#version 400 core
out vec4 fragColor;

in vec2 passTextureCoords;

uniform vec4 color;
uniform float alpha;
uniform float aspectRatio;
uniform vec2 uiSize;

uniform vec4 borderColor;
uniform float borderSize;

bool isOnEdge(vec2 position, float size){
	
	float maxX = uiSize.x - size;
	float maxY = uiSize.y - size;

	//maxX *= aspectRatio;
	//maxY /= aspectRatio;

	if (position.x < size || position.x > maxX)
		return true;
	else if (position.y < size || position.y > maxY)
		return true;

	return false;
}

void main() {
	vec2 pixelPosition = passTextureCoords * uiSize;	


	if(isOnEdge(pixelPosition, borderSize))
		fragColor = borderColor;
	else
		fragColor = color;
}
