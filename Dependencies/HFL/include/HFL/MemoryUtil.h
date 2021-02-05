
#ifndef HGE_MEMORY_UTIL_HEADER_INCLUDE
#define HGE_MEMORY_UTIL_HEADER_INCLUDE

namespace HGE {


	/**
	* Copies data from one memory adress to another
	* 
	* @author Salmoncatt
	* 
	* @param Destination of data
	* @param Source of data
	* @param Length of the data
	*/
	static void* memcpy(void* destination, const void* source, size_t length) {
		char* dest = (char*)destination;
		const char* src = (const char*)source;

		//check if length is greater than 16 bytes
		if ((length - 16) < 33) {
			while (length > 15) {
				//wtf even is this, assembly in c++? am i a assembly developer too now?
				auto val = _mm_loadu_si128((__m128i*)(src));
				_mm_storeu_si128((__m128i*)dest, val);
				dest += 16;
				src += 16;
				length -= 16;
			}
		}
#ifdef __AVX512__
		else if((length - 32) < 65){
			while (length > 31) {
				//wtf even is this, assembly in c++? am i a assembly developer too now?
				auto val = _mm256_loadu_si256((__m256i*)(src));
				_mm256_storeu_si256((__m256i*)dest, val);
				dest += 32;
				src += 32;
				length -= 32;
			}
		}
		else if(length > 65 ) {
			while (length > 31) {
				//wtf even is this, assembly in c++? am i a assembly developer too now?
				auto val = _mm512_loadu_si512((__m512i*)(src));
				_mm512_storeu_si512((__m512i*)dest, val);
				dest += 32;
				src += 32;
				length -= 32;
			}
		}
#else
		else if (length > 32) {
			while (length > 31) {
				//wtf even is this, assembly in c++? am i a assembly developer too now?
				auto val = _mm256_loadu_si256((__m256i*)(src));
				_mm256_storeu_si256((__m256i*)dest, val);
				dest += 32;
				src += 32;
				length -= 32;
			}
		}

#endif

		while (length--) {
			*dest++ = *src++;
		}

		/*if (length > 16) {
			src += length - 16;
			dest += length - 16;
			auto val = _mm_loadu_si128((__m128i*)(src));
			_mm_storeu_si128((__m128i*)(dest), val);
		}
		else {
			for (; index < length; ++index) {
				*dest++ = *src++;
			}
		}*/

		return destination;
	}

	/**
	* Returns the length of a string of characters not including the termination character
	* 
	* @param the character data
	* 
	* @author Salmoncatt
	*/
	size_t strlen(const char* data) {
		size_t length = 0;

		while (data[length])
			length += 1;

		return length;
	}


	char* strcpy(char* destination, const char* source) {
		return (char*)memcpy(destination, source, strlen(source) + 1);
	}

	char* strcpy(char* destination, const char* source, const size_t& offset) {
		return (char*)memcpy(destination, source + offset, strlen(source) + 1 - offset);
	}



}




#endif