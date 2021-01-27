
#ifndef HGE_STRING_HEADER_INCLUDE
#define HGE_STRING_HEADER_INCLUDE

#include "MemoryUtil.h"

namespace HGE {

	class string {
	private:
		//the length of the character string (useful later)
		unsigned int length;

		//the character data array
		char* data;

	public:

		/*
		* Creates a new empty string
		* 
		* @author Salmoncatt
		*/
		string() : length(0), data(nullptr) {
			data = new char[1];
			data[0] = '\0';
		}

		/*
		* Copies a string from another one
		*
		* @param The source string to copy from
		* 
		* @author Salmoncatt
		*/
		string(const string& source) : length(0) {

			//have to check otherwise we copy data from null object
			if (source.data != nullptr) {
				//copy length from source length
				length = source.length;

				//no memory leaks here
				if (data != nullptr)
					delete[] data;

				//stupid warnings
				unsigned long sourceLength = strlen(source.data) + 1;

				//create new list of data (+1 because of the \0 ending)
				data = new char[sourceLength];

				//copy the source data over using my own library :)
				strcpy(data, source.data);
			}
			else {

				//no memory leaks here
				if (data != nullptr)
					delete[] data;

				//create using basic constructor
				data = new char[1];
				data[0] = '\0';

			}

		}

		/*
		* Creates a string from character data
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string(char* source) : length(0) {

			//have to check otherwise we copy data from null object
			if (source != nullptr) {

				//no memory leaks here
				if (data != nullptr)
					delete[] data;

				//do it here so we dont have to do it twice
				unsigned long sourceLength = strlen(source) + 1;

				//create new list of data (+1 because of the \0 ending)
				data = new char[sourceLength];

				//copy length from source length
				length = sourceLength - 1;

				//copy the source data over using my own library :)
				strcpy(data, source);
			}
			else {

				//no memory leaks here
				if (data != nullptr)
					delete[] data;

				//create using basic constructor
				data = new char[1];
				data[0] = '\0';

			}

		}

		/*
		* Creates a string from character data
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string(const char* source) : length(0) {

			//have to check otherwise we copy data from null object
			if (source != nullptr) {

				//no memory leaks here
				if (data != nullptr)
					delete[] data;

				//do it here so we dont have to do it twice
				unsigned long sourceLength = strlen(source) + 1;

				//create new list of data (+1 because of the \0 ending)
				data = new char[sourceLength];

				//copy length from source length
				length = sourceLength - 1;

				//copy the source data over using my own library :)
				strcpy(data, source);
			}
			else {

				//no memory leaks here
				if (data != nullptr)
					delete[] data;

				//create using basic constructor
				data = new char[1];
				data[0] = '\0';

			}

		}

		~string() {
			//just in case
			if (data != nullptr)
				delete[] data;
		}


	};



}


#endif
