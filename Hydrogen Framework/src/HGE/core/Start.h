
#ifndef HGE_START_HEADER_INCLUDE
#define HGE_START_HEADER_INCLUDE

#if _WIN64

int main(int argc, char** argv) {
	auto program = HGE::createProgram();

	program->startEngine();
	program->create();
	program->start();
	program->closeEngine();

	delete program;
}

#endif

#endif
