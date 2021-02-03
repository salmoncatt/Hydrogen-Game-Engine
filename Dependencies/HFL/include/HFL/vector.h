
#ifndef HGE_VECTOR_HEADER_INCLUDE
#define HGE_VECTOR_HEADER_INCLUDE



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

		void reserve(size_t size) {
			if (size > capacity) {

			}
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
