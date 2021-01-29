
#ifndef HGE_PRECOMPILED_HEADER_INCLUDE
#define HGE_PRECOMPILED_HEADER_INCLUDE

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <thread>
#include <chrono> 
#include <sstream>
#include <vector>
//#include <stdlib.h>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <array>
#include <queue>
#include <stdio.h>
#include <unordered_map>
#include <intrin.h>


#if _WIN64
#include <Windows.h>
#include <windows.h>
#include "psapi.h"

#include <direct.h>
#define HGE_Get_Directory _getcwd

#else

#include <unistd.h>
#define HGE_Get_Directory getcwd

#endif

//need to include opengl things after windows because of macro redefinition
#include "GL/glew.h"
#include "GLFW/glfw3.h"

//HGE vars n stuff
#include "hge_var.h"

//oh yea my own standard library leeeetsss goooooo
#include "HFL/HFL.h"

#endif