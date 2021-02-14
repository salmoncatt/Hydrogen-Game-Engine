
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