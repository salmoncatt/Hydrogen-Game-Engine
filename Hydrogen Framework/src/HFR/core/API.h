
#ifndef HFR_API_HEADER_INCLUDE
#define HFR_API_HEADER_INCLUDE


#if _WIN64
	#ifdef HFR_BUILD_DLL
		#define DLL_API __declspec(dllexport)
	#else
		#define DLL_API __declspec(dllimport)
	#endif 
#else
	#error Hydrogen Game Engine is on Windows x64 only dude.
#endif

#ifdef HFR_SUPPRESS_DLL_WARNING

#pragma warning( disable : 4251 )

#endif


#endif