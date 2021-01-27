#version 400 core
out vec4 fragColor;

in vec2 passTextureCoords;

uniform sampler2D textureSampler;

uniform bool hasTexture;
uniform vec3 color;

uniform int drawmode;

//for rounded rectangle
uniform float radius;
uniform float smoothness;
uniform vec2 uiSize;

//for radial reveal
uniform float angle;
const float PI = 3.1415926;
const float TWO_PI = 6.2831852;
uniform bool flipped;
uniform float offset;

float getAngle(vec2 v1, vec2 v2) {

	return atan(v1.y - v2.y, v1.x - v2.x) + PI;

}

float getTargetAngle(float number) {

	return clamp(number, 0.0, TWO_PI);

}





float getRoundedRectangle(vec2 position) {

	float maxX = uiSize.x - radius;
	float maxY = uiSize.y - radius;
	float alpha = 1;

	if (position.x < radius && position.y < radius)
		alpha = 1 - smoothstep(radius - smoothness, radius + smoothness, length(position - vec2(radius, radius)));
	else if (position.x < radius && position.y > maxY)
		alpha = 1 - smoothstep(radius - smoothness, radius + smoothness, length(position - vec2(radius, maxY)));
	else if (position.x > maxX && position.y < radius)
		alpha = 1 - smoothstep(radius - smoothness, radius + smoothness, length(position - vec2(maxX, radius)));
	else if (position.x > maxX && position.y > maxY)
		alpha = 1 - smoothstep(radius - smoothness, radius + smoothness, length(position - vec2(maxX, maxY)));

	return alpha;
}







void main() {

	vec2 pixelPosition = passTextureCoords * uiSize;
	vec4 tempColor = vec4(0, 0, 0, 1);
	float alpha = 1;

	if (hasTexture)
		tempColor = texture(textureSampler, passTextureCoords);
	else
		tempColor = vec4(color, 1);



	if (drawmode == 2) {

		alpha = getRoundedRectangle(pixelPosition);

	}
	else if (drawmode == 3) {

		float pixelAngle = getAngle(passTextureCoords, vec2(0.5, 0.5));

		if(flipped){

		if (pixelAngle > getTargetAngle(angle + offset))
			alpha = 1;
		else
			alpha = 0;

		}else{

		if (pixelAngle < getTargetAngle(angle + offset))
			alpha = 1;
		else
			alpha = 0;

		}

	}

	fragColor = vec4(tempColor.xyz, alpha);

}
