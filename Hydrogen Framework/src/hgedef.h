
#ifndef HGE_VARIABLE_HEADER_INCLUDE
#define HGE_VARIABLE_HEADER_INCLUDE

#include "hpch.h"

namespace HGE {
	//big stoof
	const int HGE_NULL = 0;

#ifdef _DEBUG
	const std::string HGE_RES = "../Hydrogen Framework/res/";
	const std::string HGE_SCRIPTS = "../Hydrogen Framework/scripts/";
#else
	const std::string HGE_RES = "res/";
	const std::string HGE_RES = "scripts/";
#endif

	//for byte buffer and other buffers
	const int HGE_UNSIGNED = 0;
	const int HGE_SIGNED = 1;

	//for GUI
	const int HGE_PIXEL_SIZE = 0;
	const int HGE_SCREEN_SPACE_SIZE = 1;

	//for read as string and other things
	const int HGE_NORMAL_READ = 1;
	const int HGE_BINARY_READ = 2;
	const int HGE_NORMAL_WRITE = 3;
	const int HGE_BINARY_WRITE = 4;
	
	//dimension types
	const int HGE_2D = 2;
	const int HGE_3D = 3;

	//gui drawing types
	const int HGE_RECTANGLE = 1;
	const int HGE_RECTANGLE_ROUNDED = 2;
	const int HGE_RADIAL_REVEAL_RENDER = 3;

	//light modes
	const int HGE_PER_PIXEL_LIGHT = 0;
	const int HGE_PER_VERTEX_LIGHT = 1;

	//ecs codes
	const int HGE_ECS_REMOVE_COMPONENT = 0;
	const int HGE_ECS_GET_COMPONENT = 1;
	const int HGE_ECS_ADD_COMPONENT = 2;

	//mouse types
	const bool HGE_MOUSE_DISABLED = true;
	const bool HGE_MOUSE_NORMAL = true;
}

//keycodes
namespace HGE {

	const enum : uint16_t
	{
		// From glfw3.h
		HGE_KEY_SPACE = 32,
		HGE_KEY_APOSTROPHE = 39, /* ' */
		HGE_KEY_COMMA = 44, /* , */
		HGE_KEY_MINUS = 45, /* - */
		HGE_KEY_PERIOD = 46, /* . */
		HGE_KEY_SLASH = 47, /* / */

		HGE_KEY_D0 = 48, /* 0 */
		HGE_KEY_D1 = 49, /* 1 */
		HGE_KEY_D2 = 50, /* 2 */
		HGE_KEY_D3 = 51, /* 3 */
		HGE_KEY_D4 = 52, /* 4 */
		HGE_KEY_D5 = 53, /* 5 */
		HGE_KEY_D6 = 54, /* 6 */
		HGE_KEY_D7 = 55, /* 7 */
		HGE_KEY_D8 = 56, /* 8 */
		HGE_KEY_D9 = 57, /* 9 */

		HGE_KEY_SEMICOLON = 59, /* ; */
		HGE_KEY_EQUAL = 61, /* = */

		HGE_KEY_A = 65,
		HGE_KEY_B = 66,
		HGE_KEY_C = 67,
		HGE_KEY_D = 68,
		HGE_KEY_E = 69,
		HGE_KEY_F = 70,
		HGE_KEY_G = 71,
		HGE_KEY_H = 72,
		HGE_KEY_I = 73,
		HGE_KEY_J = 74,
		HGE_KEY_K = 75,
		HGE_KEY_L = 76,
		HGE_KEY_M = 77,
		HGE_KEY_N = 78,
		HGE_KEY_O = 79,
		HGE_KEY_P = 80,
		HGE_KEY_Q = 81,
		HGE_KEY_R = 82,
		HGE_KEY_S = 83,
		HGE_KEY_T = 84,
		HGE_KEY_U = 85,
		HGE_KEY_V = 86,
		HGE_KEY_W = 87,
		HGE_KEY_X = 88,
		HGE_KEY_Y = 89,
		HGE_KEY_Z = 90,

		HGE_KEY_LEFT_BRACKET = 91,  /* [ */
		HGE_KEY_BACKSLASH = 92,  /* \ */
		HGE_KEY_RIGHT_BRACKET = 93,  /* ] */
		HGE_KEY_GRAVE_ACCENT = 96,  /* ` */

		HGE_KEY_WORLD_1 = 161, /* non-US #1 */
		HGE_KEY_WORLD_2 = 162, /* non-US #2 */

		/* Function keys */
		HGE_KEY_ESCAPE = 256,
		HGE_KEY_ENTER = 257,
		HGE_KEY_TAB = 258,
		HGE_KEY_BACKSPACE = 259,
		HGE_KEY_INSERT = 260,
		HGE_KEY_DELETE = 261,
		HGE_KEY_RIGHT = 262,
		HGE_KEY_LEFT = 263,
		HGE_KEY_DOWN = 264,
		HGE_KEY_UP = 265,
		HGE_KEY_PAGE_UP = 266,
		HGE_KEY_PAGE_DOWN = 267,
		HGE_KEY_HOME = 268,
		HGE_KEY_END = 269,
		HGE_KEY_CAPS_LOCK = 280,
		HGE_KEY_SCROLL_LOCK = 281,
		HGE_KEY_NUM_LOCK = 282,
		HGE_KEY_PRINT_SCREEN = 283,
		HGE_KEY_PAUSE = 284,
		HGE_KEY_F1 = 290,
		HGE_KEY_F2 = 291,
		HGE_KEY_F3 = 292,
		HGE_KEY_F4 = 293,
		HGE_KEY_F5 = 294,
		HGE_KEY_F6 = 295,
		HGE_KEY_F7 = 296,
		HGE_KEY_F8 = 297,
		HGE_KEY_F9 = 298,
		HGE_KEY_F10 = 299,
		HGE_KEY_F11 = 300,
		HGE_KEY_F12 = 301,
		HGE_KEY_F13 = 302,
		HGE_KEY_F14 = 303,
		HGE_KEY_F15 = 304,
		HGE_KEY_F16 = 305,
		HGE_KEY_F17 = 306,
		HGE_KEY_F18 = 307,
		HGE_KEY_F19 = 308,
		HGE_KEY_F20 = 309,
		HGE_KEY_F21 = 310,
		HGE_KEY_F22 = 311,
		HGE_KEY_F23 = 312,
		HGE_KEY_F24 = 313,
		HGE_KEY_F25 = 314,

		/* Keypad */
		HGE_KEY_KP_0 = 320,
		HGE_KEY_KP_1 = 321,
		HGE_KEY_KP_2 = 322,
		HGE_KEY_KP_3 = 323,
		HGE_KEY_KP_4 = 324,
		HGE_KEY_KP_5 = 325,
		HGE_KEY_KP_6 = 326,
		HGE_KEY_KP_7 = 327,
		HGE_KEY_KP_8 = 328,
		HGE_KEY_KP_9 = 329,
		HGE_KEY_KP_DECIMAL = 330,
		HGE_KEY_KP_DIVIDE = 331,
		HGE_KEY_KP_MULTIPLY = 332,
		HGE_KEY_KP_SUBTRACT = 333,
		HGE_KEY_KP_ADD = 334,
		HGE_KEY_KP_ENTER = 335,
		HGE_KEY_KP_EQUAL = 336,

		HGE_KEY_LEFT_SHIFT = 340,
		HGE_KEY_LEFT_CONTROL = 341,
		HGE_KEY_LEFT_ALT = 342,
		HGE_KEY_LEFT_SUPER = 343,
		HGE_KEY_RIGHT_SHIFT = 344,
		HGE_KEY_RIGHT_CONTROL = 345,
		HGE_KEY_RIGHT_ALT = 346,
		HGE_KEY_RIGHT_SUPER = 347,
		HGE_KEY_MENU = 348
	};

}

//mouse codes
namespace HGE {

	const enum : uint16_t
	{
		// From glfw3.h
		HGE_MOUSE_BUTTON_0 = 0,
		HGE_MOUSE_BUTTON_1 = 2,
		HGE_MOUSE_BUTTON_2 = 1,
		HGE_MOUSE_BUTTON_3 = 3,
		HGE_MOUSE_BUTTON_4 = 4,
		HGE_MOUSE_BUTTON_5 = 5,
		HGE_MOUSE_BUTTON_6 = 6,
		HGE_MOUSE_BUTTON_7 = 7,

		HGE_MOUSE_BUTTON_LAST = HGE_MOUSE_BUTTON_7,
		HGE_MOUSE_BUTTON_LEFT = HGE_MOUSE_BUTTON_0,
		HGE_MOUSE_BUTTON_RIGHT = HGE_MOUSE_BUTTON_1,
		HGE_MOUSE_BUTTON_MIDDLE = HGE_MOUSE_BUTTON_2
	};

}

//CSIDL codes
namespace HGE {

	/*
	CSIDL_DESKTOP                   0x0000        // <desktop>
	CSIDL_INTERNET                  0x0001        // Internet Explorer (icon on desktop)
	CSIDL_PROGRAMS                  0x0002        // Start Menu\Programs
	CSIDL_CONTROLS                  0x0003        // My Computer\Control Panel
	CSIDL_PRINTERS                  0x0004        // My Computer\Printers
	CSIDL_PERSONAL                  0x0005        // My Documents
	CSIDL_FAVORITES                 0x0006        // <user name>\Favorites
	CSIDL_STARTUP                   0x0007        // Start Menu\Programs\Startup
	CSIDL_RECENT                    0x0008        // <user name>\Recent
	CSIDL_SENDTO                    0x0009        // <user name>\SendTo
	CSIDL_BITBUCKET                 0x000a        // <desktop>\Recycle Bin
	CSIDL_STARTMENU                 0x000b        // <user name>\Start Menu
	CSIDL_MYMUSIC                   0x000d        // "My Music" folder
	CSIDL_MYVIDEO                   0x000e        // "My Videos" folder
	CSIDL_DESKTOPDIRECTORY          0x0010        // <user name>\Desktop
	CSIDL_DRIVES                    0x0011        // My Computer
	CSIDL_NETWORK                   0x0012        // Network Neighborhood (My Network Places)
	CSIDL_NETHOOD                   0x0013        // <user name>\nethood
	CSIDL_FONTS                     0x0014        // windows\fonts
	CSIDL_TEMPLATES                 0x0015
	CSIDL_COMMON_STARTMENU          0x0016        // All Users\Start Menu
	CSIDL_COMMON_PROGRAMS           0X0017        // All Users\Start Menu\Programs
	CSIDL_COMMON_STARTUP            0x0018        // All Users\Startup
	CSIDL_COMMON_DESKTOPDIRECTORY   0x0019        // All Users\Desktop
	CSIDL_APPDATA                   0x001a        // <user name>\Application Data
	CSIDL_PRINTHOOD                 0x001b        // <user name>\PrintHood
	*/

#define HGE_FOLDER_DESKTOP CSDIDL_DESKTOP
#define HGE_FOLDER_INTERNET CSIDL_INTERNET
#define HGE_FOLDER_PROGRAMS CSIDL_PROGRAMS
#define HGE_FOLDER_CONTROL_PANEL CSIDL_CONTROLS
#define HGE_FOLDER_PRINTERS CSIDL_PRINTERS
#define HGE_FOLDER_DOCUMENTS CSIDL_PERSONAL
#define HGE_FOLDER_FAVORITES CSIDL_FAVORITES
#define HGE_FOLDER_STARTUP CSIDL_STARTUP
#define HGE_FOLDER_RECENT CSIDL_RECENT
#define HGE_FOLDER_SEND_TO CSIDL_SENDTO
#define HGE_FOLDER_RECYCLE_BIN CSIDL_BITBUCKET
#define HGE_FOLDER_START_MENU CSIDL_STARTMENU
#define HGE_FOLDER_MUSIC CSIDL_MYMUSIC
#define HGE_FOLDER_VIDEOS CSIDL_MYVIDEO
#define HGE_FOLDER_DESKTOP_DIRECTORY CSIDL_DESKTOPDIRECTORY
#define HGE_FOLDER_DRIVES CSIDL_DRIVES
#define HGE_FOLDER_NETWORK CSIDL_NETWORK
#define HGE_FOLDER_NET_HOOD CSIDL_NETHOOD
#define HGE_FOLDER_FONTS CSIDL_FONTS
#define HGE_FOLDER_TEMPLATES CSIDL_TEMPLATES
#define HGE_FOLDER_COMMON_STARTMENU CSIDL_COMMON_STARTMENU
#define HGE_FOLDER_COMMON_PROGRAMS CSIDL_COMMON_PROGRAMS
#define HGE_FOLDER_COMMON_STARTUP CSIDL_COMMON_STARTUP
#define HGE_FOLDER_COMMON_DESKTOP_DIRECTORY CSIDL_COMMON_DESKTOPDIRECTORY
#define HGE_FOLDER_APP_DATA CSIDL_APPDATA
#define HGE_FOLDER_PRINT_HOOD CSIDL_PRINTHOOD

}

//macros for include bc im lazy
#define HGE_CAMERA "HGE/camera/Camera.h"
#define HGE_CAMERA_CONTROLLER "HGE/camera/CameraController.h"
#define HGE_EDITOR_CAMERA "HGE/camera/EditorCamera.h"

#define HGE_ECS "HGE/ECS/ECS.h"
#define HGE_GAMEOBJECT "HGE/ECS/GameObject.h"
#define HGE_SCENE "HGE/ECS/Scene.h"
#define HGE_TAG "HGE/ECS/components/Tag.h"

#define HGE_MESH "HGE/mesh/Mesh.h"
#define HGE_TEXTURE "HGE/mesh/Texture.h"
#define HGE_MATERIAL "HGE/mesh/Material.h"
#define HGE_MESH_COMPONENT "HGE/mesh/MeshComponent.h"

#define HGE_NATIVE_SCRIPT "HGE/scripting/NativeScript.h"
#define HGE_SCRIPT_MANAGER "HGE/scripting/ScriptManager.h"

#define HGE_GUI_ELEMENT "HGE/gui/GuiElement.h"
#define HGE_GUI_FRAME "HGE/gui/GuiFrame.h"

#define HGE_API "HGE/core/API.h"
#define HGE_PROGRAM "HGE/core/Program.h"
#define HGE_ENGINE "HGE/core/Engine.h"
#define HGE_START "HGE/core/Start.h"

#define HGE_IMAGE "HGE/graphics/image/Image.h"
#define HGE_PIXEL "HGE/graphics/image/Pixel.h"

#define HGE_RENDERER "HGE/graphics/rendering/Renderer.h"
#define HGE_SHADER "HGE/graphics/rendering/Shader.h"

#define HGE_CURSOR "HGE/io/Cursor.h"
#define HGE_INPUT "HGE/io/Input.h"
#define HGE_WINDOW "HGE/io/Window.h"

#define HGE_MAT4 "HGE/math/matrixes/Mat4.h"
#define HGE_TRANSFORM "HGE/math/vectors/Transform.h"
#define HGE_VEC2 "HGE/math/vectors/Vec2.h"
#define HGE_VEC3 "HGE/math/vectors/Vec3.h"
#define HGE_VEC4 "HGE/math/vectors/Vec4.h"
#define HGE_MATH "HGE/math/HMath.h"
#define HGE_RANDOM "HGE/math/Random.h"

#define HGE_FLOAT_BUFFER "HGE/memory/FloatBuffer.h"

#define HGE_PROFILE "HGE/time/Profile.h"
#define HGE_PROFILER "HGE/time/Profiler.h"
#define HGE_TIME "HGE/time/Time.h"

#define HGE_DEBUG "HGE/util/Debug.h"
#define HGE_UTIL "HGE/util/Util.h"
#define HGE_GUID "HGE/util/HGUID.h"

#define HGE_STANDARD "IncludeStandard.h"
#define STB_IMAGE "HGE/graphics/image/stb_image.h"

#endif