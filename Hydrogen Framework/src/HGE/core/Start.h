
#ifndef HGE_START_HEADER_INCLUDE
#define HGE_START_HEADER_INCLUDE

#if _WIN64

int main(int argc, char** argv) {
#ifndef HGE_SCRIPT
	auto program = HGE::createProgram();

	HGE::Engine::startEngine();
	program->create();
	program->start();
	HGE::Engine::stopEngine();

	delete program;
#endif
}

#endif

#endif
