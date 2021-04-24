#include "hfpch.h"
#include "GuiText.h"

namespace HFR {

	unsigned int GuiText::staticVBO = 0;
	unsigned int GuiText::textureCoordAttribute = 0;

	void GuiText::init() {
		staticVBO = Util::generateVBO();
		textureCoordAttribute = Renderer::textShader.getAttributeLocation("coord");
	}


}