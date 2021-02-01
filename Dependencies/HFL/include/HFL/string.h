
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

			//in case the data isn't null terminated for some reason
			if (data[length] != '\0')
				data[length] = '\0';
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

			//in case the data isn't null terminated for some reason
			if (data[length] != '\0')
				data[length] = '\0';
			
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
			out.__cleanup__();

			//set the length
			out.length = length + source.length;

			//allocate memory to the outputs data buffer
			out.data = new char[out.length + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string
			strcpy(out.data + length, source.data); //copy second string

			//in case the data isn't null terminated for some reason
			if (out.data[length] != '\0')
				out.data[length] = '\0';

			return out;
		}

		/*
		* Adds a string of characters to this string
		*
		* @param The characters to add from
		*
		* @author Salmoncatt
		*/
		string operator+(const char* source) {
			//create the output string
			string out = string();

			//delete the allocated memory
			out.__cleanup__();

			//set the length
			out.length = length + strlen(source);

			//allocate memory to the outputs data buffer
			out.data = new char[out.length + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string
			strcpy(out.data + length, source); //copy second string

			//in case the data isn't null terminated for some reason
			if (out.data[out.length] != '\0')
				out.data[out.length] = '\0';

			return out;
		}

		/*
		* Adds a string of characters to this string
		*
		* @param The characters to add from
		*
		* @author Salmoncatt
		*/
		string operator+(char* source) {
			//create the output string
			string out = string();

			//delete the allocated memory
			out.__cleanup__();

			//set the length
			out.length = length + strlen(source);

			//allocate memory to the outputs data buffer
			out.data = new char[out.length + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string
			strcpy(out.data + length, source); //copy second string

			//in case the data isn't null terminated for some reason
			if (out.data[out.length] != '\0')
				out.data[out.length] = '\0';

			return out;
		}

		/*
		* Adds a character to this string
		*
		* @param The character to add from
		*
		* @author Salmoncatt
		*/
		string operator+(char& source) {
			//create the output string
			string out = string();

			//delete the allocated memory
			out.__cleanup__();

			//set the length
			out.length = length + 1;

			//allocate memory to the outputs data buffer
			out.data = new char[out.length + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string

			out.data[length - 1] = source;

			//in case the data isn't null terminated for some reason
			if (out.data[out.length] != '\0')
				out.data[out.length] = '\0';

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

			//in case the data isn't null terminated for some reason
			if (data[length] != '\0')
				data[length] = '\0';
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

			//get length
			length = strlen(source);

			//allocate data size
			data = new char[length + 1];

			//copy the source data over using my own library :)
			strcpy(data, source);

			//in case the data isn't null terminated for some reason
			if (data[length] != '\0')
				data[length] = '\0';

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

			//in case the data isn't null terminated for some reason
			if(data[length] != '\0')
				data[length] = '\0';
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

			//set length
			length = strlen(source);

			//allocate string data into memory
			data = new char[length + 1];

			//copy the source data over using my own library :)
			strcpy(data, source);

			//in case the data isn't null terminated for some reason
			if (data[length] != '\0')
				data[length] = '\0';

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

			if (source != '\0') {
				//allocate memory for data
				data = new char[length + 1];

				//put in the character and null terminator character
				data[0] = source;
				data[1] = '\0';
			}
			else {
				//allocate memory for data
				data = new char[length];
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

			//set length to one character
			length = 1;

			if (source != '\0') {
				//allocate memory for data
				data = new char[length + 1];

				//put in the character and null terminator character
				data[0] = source;
				data[1] = '\0';
			}
			else {
				//allocate memory for data
				data = new char[length];
				data[0] = '\0';
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
