
#ifndef HFL_MEMORY_UTIL_HEADER_INCLUDE
#define HFL_MEMORY_UTIL_HEADER_INCLUDE

namespace HGE {


	/**
	* Copies data from one memory adress to another
	*
	* @author Salmoncatt
	*
	* @param Destination of data
	* @param Source of data
	* @param Size of the data in bytes
	*/
	inline void* memcpy(void* destination, const void* source, size_t size) {
		char* dest = (char*)destination;
		const char* src = (const char*)source;

		size_t length = size;

#ifdef __AVX512__
		while (size >= 64) {
			//wtf even is this, assembly in c++? am i a assembly developer too now?
			auto val = _mm512_loadu_si512((__m512i*)(src));
			_mm512_storeu_si512((__m512i*)dest, val);
			dest += 64;
			src += 64;
			size -= 64;
		}
#endif

		while (size >= 32) {
			//wtf even is this, assembly in c++? am i a assembly developer too now?
			auto val = _mm256_loadu_si256((__m256i*)(src));
			_mm256_storeu_si256((__m256i*)dest, val);
			dest += 32;
			src += 32;
			size -= 32;
		}

		while (size >= 16) {
			//wtf even is this, assembly in c++? am i a assembly developer too now?
			auto val = _mm_loadu_si128((__m128i*)(src));
			_mm_storeu_si128((__m128i*)dest, val);
			dest += 16;
			src += 16;
			size -= 16;
		}

		if (length > 16) {
			src += size - 16;
			dest += size - 16;
			auto val = _mm_loadu_si128((__m128i*)(src));
			_mm_storeu_si128((__m128i*)(dest), val);
		}

		while (size--) {
			*dest++ = *src++;
		}

		return destination;
	}

	/**
	* Returns the length of a string of characters not including the termination character
	* 
	* @param the character data
	* 
	* @author Salmoncatt
	*/
	inline size_t strlen(const char* data) {
		size_t length = 0;

		while (data[length])
			length += 1;

		return length;
	}


	inline char* strcpy(char* destination, const char* source) {
		return (char*)memcpy(destination, source, strlen(source) + 1);
	}

	inline char* strcpy(char* destination, const char* source, const size_t& offset) {
		return (char*)memcpy(destination, source + offset, strlen(source) + 1 - offset);
	}



}




#endif