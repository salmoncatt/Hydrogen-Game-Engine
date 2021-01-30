
#ifndef HGE_FILE_IO_HEADER_INCLUDE
#define HGE_FILE_IO_HEADER_INCLUDE

#include <fcntl.h>
#include <sys/stat.h>
//#include <sys/mman.h>

//#include <stdlib.h>
//#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

namespace HGE {



	void test() {

		int fileID = open("test", O_RDONLY, (mode_t)0600);


	}



}

#endif