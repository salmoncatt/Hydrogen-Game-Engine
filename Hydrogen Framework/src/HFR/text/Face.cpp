#include "hfpch.h"
#include "Face.h"

namespace HFR {

	Face::Face() {

	}

	Face::~Face() {
		freeTypeFace = nullptr;
		//FT_Done_Face(freeTypeFace);
	}

}