
#ifndef HFL_VECTOR_HEADER_INCLUDE
#define HFL_VECTOR_HEADER_INCLUDE



namespace HGE {

	template <typename T> class vector {
	private:

		T* data;

		size_t capacity;
		size_t currentSize;

		void __cleanup__() {
			if (data != nullptr)
				delete[] data;
			capacity = 0;
			currentSize = 0;
		}

	public:

		vector() {
			data = new T[1];
			capacity = 1;
			currentSize = 0;
		}

		vector(const vector& source) {
			data = new T[source.capacity];
			capacity = source.capacity;
			currentSize = source.currentSize;

			//copy over data
			for (size_t i = 0; i < capacity; ++i) {
				data[i] = source.data[i];
			}

		}

		vector& operator=(const vector& source) {
			__cleanup__();

			data = new T[source.capacity];
			capacity = source.capacity;
			currentSize = source.currentSize;

			//copy over data
			for (size_t i = 0; i < capacity; ++i) {
				data[i] = source.data[i];
			}

			return *this;
		}

		void reserve(const size_t& size) {
			if (size > capacity) {
				//create temp array with new size
				T* temp = new T[size];

				//copy over data
				for (size_t i = 0; i < capacity; ++i) {
					temp[i] = data[i];
				}

				//delete current data
				delete[] data;

				//set the data with the new memory adress
				data = temp;
				capacity = size;
			}
		}

		void resize(const size_t& size) {
			if (size > capacity)
				reserve(size);
			
			if (size > currentSize) {
				for (size_t i = currentSize; i < size; ++i) {
					data[i] = T();
				}
			}
			currentSize = size;
		}

		void push_back(const T& value) {
			if (currentSize + 1 > capacity)
				reserve(capacity * 2);

			data[currentSize] = value;
			currentSize += 1;
		}

		T& operator[](const size_t& index) {
			return data[index];
		}

		size_t size() {
			return currentSize;
		}

		~vector() {
			__cleanup__();
		}

	};


}


#endif
