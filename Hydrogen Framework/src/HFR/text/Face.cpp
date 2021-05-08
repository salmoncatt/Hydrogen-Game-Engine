#include "hfpch.h"
#include "Face.h"

namespace HFR {

	Face::Face() {

	}

	Face::~Face() {
		FT_Done_Face(freeTypeFace);
	}

}