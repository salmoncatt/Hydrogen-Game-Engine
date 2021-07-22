#version 400 core
out vec4 fragColor;

const float PI = 3.1415926;
const float TWO_PI = 6.2831852;

in vec2 passTextureCoords;

uniform sampler2D textureSampler;
uniform bool hasTextureCoords;


uniform vec4 color;
uniform vec2 uiSize;

//for radial fill
uniform float angle; //IN RADIANS
uniform float offsetAngle; //IN RADIANS
uniform vec2 radialFillOffset;
uniform bool radialFillFlipped;

float getAngle(vec2 v1, vec2 v2) {

	return atan(v1.y - v2.y, v1.x - v2.x) + PI;

}

float getTargetAngle(float number) {

	return clamp(number, 0.0, TWO_PI);

}

void main() {
	vec2 pixelPosition = passTextureCoords * uiSize;	
	
	if(hasTextureCoords)
		fragColor = texture(textureSampler, passTextureCoords);

	fragColor += color;

	float pixelAngle = getAngle(passTextureCoords, radialFillOffset);
	
	//check if there is an offset to save perfomance by not having to check twice NEED TO FIX
//	if(offsetAngle != 0){
//	if(radialFillFlipped){
//		if ((pixelAngle + offsetAngle > getTargetAngle(angle)) && ((pixelAngle < getTargetAngle(angle) - offsetAngle)))
//			fragColor.a = 1;
//		else
//			fragColor.a = 0;
//	}else{
//		if ((pixelAngle + offsetAngle < getTargetAngle(angle)) && ((-pixelAngle + offsetAngle > getTargetAngle(angle))))
//			fragColor.a = 1;
//		else
//			fragColor.a = 0;
//	}
//	
//	}else{
	
	if(radialFillFlipped){
		if (pixelAngle > getTargetAngle(angle))
			fragColor.a = 1;
		else
			fragColor.a = 0;
	}else{
		if (pixelAngle < getTargetAngle(angle))
			fragColor.a = 1;
		else
			fragColor.a = 0;
	}
	
	
	//}

}
