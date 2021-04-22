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
			auto val = _mm512_loadu_si512((__m512i*)(src));
			_mm512_storeu_si512((__m512i*)dest, val);
			dest += 64;
			src += 64;
			size -= 64;
		}
#endif

		while (size >= 32) {
			auto val = _mm256_loadu_si256((__m256i*)(src));
			_mm256_storeu_si256((__m256i*)dest, val);
			dest += 32;
			src += 32;
			size -= 32;
		}

		while (size >= 16) {
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
		size_t out = 0;

		const __m128i zeros = _mm_setzero_si128();
		__m128i* pointer = (__m128i*)(data);

		for (;; pointer++, out += 16) {
			
			const __m128i current = _mm_loadu_si128(pointer);

			const int compareMode = _SIDD_UBYTE_OPS | _SIDD_LEAST_SIGNIFICANT | _SIDD_CMP_EQUAL_EACH;

			if (_mm_cmpistrc(current, zeros, compareMode)) {
				const auto index = _mm_cmpistri(current, zeros, compareMode);

				return out + index;
			}
		}

		//const __m256i terminationCharacters = _mm256_setzero_si256();
		//const size_t shiftAmount = ((size_t)&data) & 31;
		//const __m256i* pointer = (const __m256i*) (data - shiftAmount);

		//size_t length = 0;

		////const int compareMode = _SIDD_UBYTE_OPS | _SIDD_LEAST_SIGNIFICANT | _SIDD_CMP_EQUAL_EACH;

		//for (;; length += 32, ++pointer) {
		//	const __m256i comparingData = _mm256_load_si256(pointer);
		//	const __m256i comparison = _mm256_cmpeq_epi8(comparingData, terminationCharacters);

		//	if (!_mm256_testc_si256(terminationCharacters, comparison)) {
		//		const auto mask = _mm256_movemask_epi8(comparison);

		//		return length + _tzcnt_u32(mask >> shiftAmount);
		//	}
		//}
	}

	inline char* strcpy(char* destination, const char* source) {
		return (char*)memcpy(destination, source, strlen(source) + 1);
	}

	inline char* strcpy(char* destination, const char* source, const size_t& offset) {
		return (char*)memcpy(destination, source + offset, strlen(source) + 1 - offset);
	}



}




#endif