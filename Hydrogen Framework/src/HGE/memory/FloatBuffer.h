
#ifndef HGE_FLOAT_BUFFER_HEADER_INCLUDE
#define HGE_FLOAT_BUFFER_HEADER_INCLUDE

#include HGE_API

namespace HGE {

	class DLL_API FloatBuffer {
	public:
		float* data;
		int index;

		FloatBuffer(const int& size);
		~FloatBuffer();

		void put(const float& value);
	};

}

#endif