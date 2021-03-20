
#ifndef HFR_FLOAT_BUFFER_HEADER_INCLUDE
#define HFR_FLOAT_BUFFER_HEADER_INCLUDE

#include HFR_API

namespace HFR {

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