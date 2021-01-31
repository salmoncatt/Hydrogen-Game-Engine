
#ifndef HGE_STRING_HEADER_INCLUDE
#define HGE_STRING_HEADER_INCLUDE

#include "MemoryUtil.h"

namespace HGE {

	class string {
	private:
		//the length of the character string (useful later)
		size_t length;

		//the character data array
		char* data;

		void __cleanup__() {
			if (data != nullptr)
				delete[] data;
			length = 0;
		}

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
			//set length
			length = source.length;
			
			//allocate string data into memory
			data = new char[length + 1];

			//copy the source data over using my own library :)
			strcpy(data, source.data);
		}

		/*
		* Copies a string from another one
		*
		* @param The source string to copy from
		*
		* @author Salmoncatt
		*/
		string& operator=(const string& source) {
			//cleanup if memory is allocated
			__cleanup__();

			//set length
			length = source.length;

			//allocate string data into memory
			data = new char[length + 1];

			//copy the source data over using my own library :)
			strcpy(data, source.data);
			return *this;
		}

		/*
		* Adds a strings data to current one
		*
		* @param The source string to add from
		*
		* @author Salmoncatt
		*/
		string operator+(const string& source) {
			//create the output string
			string out = string();

			//delete the allocated memory
			//out.__cleanup__();

			//set the length
			out.length = length + source.length;

			//allocate memory to the outputs data buffer
			out.data = new char[out.length + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string
			strcpy(out.data + length, source.data); //copy second string

			return out;
		}

		/*
		* Creates a string from character data
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string(char* source) : length(0) {
			//get length
			length = strlen(source);
			
			//allocate data size
			data = new char[length + 1];
			
			//copy the source data over using my own library :)
			strcpy(data, source);

			//add termination character in case data doesn't have it
			data[length] = '\0';

			//have to check otherwise we copy data from null object
			if (source) {

				//no memory leaks here
			//	if (data != NULL)
				//	delete[] data;

				//do it here so we dont have to do it twice
				size_t sourceLength = strlen(source) + 1;

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

			__cleanup__();

			//have to check otherwise we copy data from null object
			if (source) {

				//no memory leaks here
			//	if (data != NULL)
				//	delete[] data;

				//do it here so we dont have to do it twice
				size_t sourceLength = strlen(source) + 1;

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
			//set length
			length = strlen(source);

			//allocate string data into memory
			data = new char[length + 1];

			//copy the source data over using my own library :)
			strcpy(data, source);
		}

		/*
		* Creates a string from character data
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string& operator=(const char* source) {

			__cleanup__();

			//have to check otherwise we copy data from null object
			if (source) {

				//no memory leaks here
				//if (data != NULL)
				//	delete[] data;

				//do it here so we dont have to do it twice
				size_t sourceLength = strlen(source) + 1;

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
				size_t size = 2;

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

			__cleanup__();

			//have to check otherwise we copy data from null object
			if (source != '\0') {

				//no memory leaks here
				//if (data != NULL)
				//	delete[] data;

				//do it here so we dont have to do it twice
				size_t size = 2;

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

		string substr(const size_t& index, const size_t& length) {
			size_t size = length + 1;
			string out = string();

			delete[] out.data;

			out.data = new char[size];
			out.length = length;

			size_t j = 0;

			//i keeps track of second string index, j is for the first string (i do this because there is an offset involved)
			for (size_t i = index, j = 0; i < (index + length); i += 1, j += 1) {
				out.data[j] = data[i];
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
			__cleanup__();
		}


	};



}


#endif
