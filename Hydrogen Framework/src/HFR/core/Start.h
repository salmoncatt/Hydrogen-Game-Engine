
#ifndef HFR_START_HEADER_INCLUDE
#define HFR_START_HEADER_INCLUDE

#if _WIN64

int main(int argc, char** argv) {
	__security_init_cookie();
#ifndef HFR_SCRIPT
	auto program = HFR::createProgram();

	HFR::Engine::startEngine();
	program->create();
	program->start();
	HFR::Engine::stopEngine();

	delete program;
#endif
}

#endif

#endif
