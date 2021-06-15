#include "hfpch.h"
#include "GuiText.h"

namespace HFR {

	GuiText::GuiText() {

	}

	GuiText::~GuiText() {

	}

	GuiText::GuiText(const std::string& _text, const Font& _font, const Transform2D& _transform) {
		text = _text;
		transform = _transform;
		mesh = Mesh();
		
		font = _font;

		//prevent logging about making the font again
		/*font.logStatus = false;
		font.create();
		font.logStatus = true;*/
	}

	void GuiText::create() {
		size_t length = std::strlen(text.c_str());

		if (length > 0) {

			std::vector<float> vertices = std::vector<float>();
			std::vector<float> texturecoords = std::vector<float>();

			int vertexCount = 0;
			const unsigned char* character;
			Vec2f cursorPosition = Vec2f(transform.position.x, transform.position.y);

			
			
			for (character = (const unsigned char*)text.c_str(); *character; character++) {

				//calculate vertex position and texture coords
				Vec2f characterPosition = Vec2f(cursorPosition.x + font.characters[*character].bitmapLeftTop.x * transform.scale.x,
					-cursorPosition.y - font.characters[*character].bitmapLeftTop.y * transform.scale.y);

				Vec2f size = Vec2f(font.characters[*character].size.x * transform.scale.x,
					font.characters[*character].size.y * transform.scale.y);

				cursorPosition.x += font.characters[*character].advance.x * transform.scale.x;
				cursorPosition.y += font.characters[*character].advance.y * transform.scale.y;

				//skip if glyph has no data
				if (!size.x || !size.y)
					continue;

				vertices.push_back(characterPosition.x); vertices.push_back(-characterPosition.y);
				vertices.push_back(characterPosition.x); vertices.push_back(-characterPosition.y - size.y);
				vertices.push_back(characterPosition.x + size.x); vertices.push_back(-characterPosition.y);

				vertices.push_back(characterPosition.x + size.x); vertices.push_back(-characterPosition.y);
				vertices.push_back(characterPosition.x); vertices.push_back(-characterPosition.y - size.y);
				vertices.push_back(characterPosition.x + size.x); vertices.push_back(-characterPosition.y - size.y);

				//point

				texturecoords.push_back(font.characters[*character].textureOffset.x); texturecoords.push_back(font.characters[*character].textureOffset.y);
				texturecoords.push_back(font.characters[*character].textureOffset.x + font.characters[*character].size.x / font.atlasSize.x); texturecoords.push_back(font.characters[*character].textureOffset.y);
				texturecoords.push_back(font.characters[*character].textureOffset.x); texturecoords.push_back(font.characters[*character].textureOffset.y + font.characters[*character].size.x / font.atlasSize.y);
				
				texturecoords.push_back(font.characters[*character].textureOffset.x + font.characters[*character].size.x / font.atlasSize.x); texturecoords.push_back(font.characters[*character].textureOffset.y);
				texturecoords.push_back(font.characters[*character].textureOffset.x); texturecoords.push_back(font.characters[*character].textureOffset.y + font.characters[*character].size.x / font.atlasSize.y);
				texturecoords.push_back(font.characters[*character].textureOffset.x + font.characters[*character].size.x / font.atlasSize.x); texturecoords.push_back(font.characters[*character].textureOffset.y + font.characters[*character].size.x / font.atlasSize.y);
			}

		/*	vertices = { -0.5f, 0.5f,
	-0.5f, -0.5f,
	0.5f, -0.5f,
	0.5f, -0.5f,
	0.5f, 0.5f, 
	-0.5f, 0.5f,};*/


			mesh = Mesh(vertices, std::vector<unsigned int>(), std::vector<float>(), texturecoords);
			mesh.material.albedoTexture = font.texture;
			mesh.type = HFR_2D;
			mesh.create();
		}
		else
			Debug::systemErr("Couldn't create GuiText because the text was empty");
	}

}