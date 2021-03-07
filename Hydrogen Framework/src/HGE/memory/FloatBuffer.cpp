#include "hpch.h"

namespace HGE {

	FloatBuffer::FloatBuffer(const int& size) {
		data = new float[size];
		index = 0;
	}

	FloatBuffer::~FloatBuffer() {
		delete data;
	}

	void FloatBuffer::put(const float& value) {
		data[index] = value;
		index += 1;
	}

}
