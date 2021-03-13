
#ifndef HGE_PRECOMPILED_HEADER_INCLUDE
#define HGE_PRECOMPILED_HEADER_INCLUDE

//#define _CRT_SECURE_NO_DEPRECATE
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
#include <functional>
#include <cstring>
#include <numeric>
#include "HGE/io/dirent.h"
#include <locale>
#include <codecvt>
#include <objbase.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <shellapi.h>

//for guid
#include <Rpc.h>
#pragma comment(lib, "Rpcrt4.lib")

//for getting documents and other folders
#include <shlobj.h>

#pragma comment(lib, "shell32.lib")

//for windows notification toasts n stuff
//#include "DesktopNotificationManagerCompat.h"
//#include <NotificationActivationCallback.h>
//#include <windows.ui.notifications.h>
//
//using namespace ABI::Windows::Data::Xml::Dom;
//using namespace ABI::Windows::UI::Notifications;
//using namespace Microsoft::WRL;

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
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//HGE vars n stuff
#include "hgedef.h"

//oh yea my own standard library leeeetsss goooooo
//its nowhere near finished for now
#include "HFL/HFL.h"

//for profiling of any class
#include HGE_PROFILER
#define ProfileMethod(name) HGE::Profiler HGE_AUTO_PROFILER(name, false, true)

#include HGE_STANDARD

#endif