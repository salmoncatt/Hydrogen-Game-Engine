
#ifndef HGE_API_HEADER_INCLUDE
#define HGE_API_HEADER_INCLUDE


#if _WIN64
	#ifdef HGE_BUILD_DLL
		#define DLL_API __declspec(dllexport)
	#else
		#define DLL_API __declspec(dllimport)
	#endif 
#else
	#error Hydrogen Game Engine is on Windows x64 only dude.
#endif

#ifdef HGE_SUPPRESS_DLL_ERROR

#pragma warning( disable : 4251 )

#endif


#endif