
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

		bool empty() {
			return (data == NULL || data[0] == '\0');
		}

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
			if (source.data) {
				//copy length from source length
				length = source.length;

				//no memory leaks here
			//	if (data != NULL)
			//		delete[] data;

				//stupid warnings
				unsigned long sourceLength = strlen(source.data) + 1;

				//create new list of data (+1 because of the \0 ending)
				data = new char[sourceLength];

				//copy the source data over using my own library :)
				strcpy(data, source.data);
			}
			else {

				//no memory leaks here
			//	if (data != NULL)
			//		delete[] data;

				//create using basic constructor
				data = new char[1];
				data[0] = '\0';

			}

		}

		/*
		* Copies a string from another one
		*
		* @param The source string to copy from
		*
		* @author Salmoncatt
		*/
		string& operator=(const string& source) {
			
			unsigned long sourceLength = strlen(source.data) + 1;
			data = new char[sourceLength];
			length = source.length;

			strcpy(data, source.data);

			return *this;
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
			if (source) {

				//no memory leaks here
			//	if (data != NULL)
				//	delete[] data;

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
				//if (data != NULL)
			//		delete[] data;

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
		string& operator=(char* source) {

			//have to check otherwise we copy data from null object
			if (source) {

				//no memory leaks here
			//	if (data != NULL)
				//	delete[] data;

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
				//if (data != NULL)
			//		delete[] data;

				//create using basic constructor
				data = new char[1];
				data[0] = '\0';
				length = 0;

			}

			return *this;
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
			if (source) {

				//no memory leaks here
				//if (data != NULL)
				//	delete[] data;

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
				//if (data != NULL)
			//		delete[] data;

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
		string& operator=(const char* source) {

			//have to check otherwise we copy data from null object
			if (source) {

				//no memory leaks here
				//if (data != NULL)
				//	delete[] data;

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
				//if (data != NULL)
			//		delete[] data;

				//create using basic constructor
				data = new char[1];
				data[0] = '\0';
				length = 0;
			}

			return *this;
		}

		/*
		* Creates a string from a character
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string(const char& source) : length(1) {

			//have to check otherwise we copy data from null object
			if (source != '\0') {

				//no memory leaks here
				//if (data != NULL)
				//	delete[] data;

				//do it here so we dont have to do it twice
				unsigned long size = 2;

				//create new list of data (+1 because of the \0 ending)
				data = new char[size];

				data[0] = source;
				data[1] = '\0';
			}
			else {

				//no memory leaks here
			//	if (data != NULL)
			//		delete[] data;

				//create using basic constructor
				data = new char[1];
				data[0] = '\0';

			}

		}

		/*
		* Creates a string from a character
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string& operator=(const char& source) {

			//have to check otherwise we copy data from null object
			if (source != '\0') {

				//no memory leaks here
				//if (data != NULL)
				//	delete[] data;

				//do it here so we dont have to do it twice
				unsigned long size = 2;

				//create new list of data (+1 because of the \0 ending)
				data = new char[size];

				data[0] = source;
				data[1] = '\0';
			}
			else {

				//no memory leaks here
			//	if (data != NULL)
			//		delete[] data;

				//create using basic constructor
				data = new char[1];
				data[0] = '\0';

				length = 0;

			}

			return *this;
		}

		char& at(const unsigned long& index) {
			return data[index];
		}

		unsigned long find(const string& delimiter) {

		}

		string substr(const unsigned long& index, const unsigned long& length) {
			const unsigned long size = length + 1;
			string out = string();

			//delete then resize
			//if(out.data != NULL)
			//	delete[] out.data;

			out.data = new char[size];

			for (unsigned long i = index; i < (index + length); i += 1) {
				out.data[i] = data[i];
			}

			out.data[length] = '\0';
			out.length = length;

			return out;
		}

		const char* c_str() {
			return data;
		}

		//string[] split(const string& stringToSplit) {
		//
		//}

		~string() {
			if(data != nullptr && data[length] == '\0')
				delete data;
		}


	};



}


#endif
