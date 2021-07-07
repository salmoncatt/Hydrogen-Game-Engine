
#ifndef HFR_VARIABLE_HEADER_INCLUDE
#define HFR_VARIABLE_HEADER_INCLUDE

namespace HFR {
	//big stoof
	const int HFR_NULL = 0;

	//need to not duct tape fix this
#define HFR_RES std::string(Util::getWorkingDirectory() + "../../../../../Hydrogen Framework/res/")
#define HFR_SCRIPTS std::string(Util::getWorkingDirectory() + "../../../../../Hydrogen Framework/scripts/")


#define HFR_PROJECTS_PATH Util::getDirectory(HFR_FOLDER_DOCUMENTS) + R"(\Hydrogen Game Engine\)"

	//for byte buffer and other buffers
	const int HFR_UNSIGNED = 0;
	const int HFR_SIGNED = 1;

	//for GUI
	const int HFR_PIXEL_SIZE = 0;
	const int HFR_SCREEN_SPACE_SIZE = 1;

	//for read as string and other things
	const int HFR_NORMAL_READ = 1;
	const int HFR_BINARY_READ = 2;
	const int HFR_NORMAL_WRITE = 3;
	const int HFR_BINARY_WRITE = 4;
	
	//dimension types
	const int HFR_2D = 2;
	const int HFR_3D = 3;

	//gui drawing types
	const int HFR_RECTANGLE = 1;
	const int HFR_RECTANGLE_ROUNDED = 2;
	const int HFR_RADIAL_REVEAL_RENDER = 3;

	//light modes
	const int HFR_PER_PIXEL_LIGHT = 0;
	const int HFR_PER_VERTEX_LIGHT = 1;

	//ecs codes
	const int HFR_ECS_REMOVE_COMPONENT = 0;
	const int HFR_ECS_GET_COMPONENT = 1;
	const int HFR_ECS_ADD_COMPONENT = 2;

	//mouse types
	const bool HFR_MOUSE_DISABLED = true;
	const bool HFR_MOUSE_NORMAL = true;

	//debug things
	const int HFR_LOG_ON_SUCCESS = 0;
	const int HFR_DONT_LOG_ON_SUCCESS = 1;
	const int HFR_LOG_ON_FAIL = 2;
	const int HFR_DONT_LOG_ON_FAIL = 3;
}

//keycodes
namespace HFR {

	const enum : uint16_t
	{
		// From glfw3.h
		HFR_KEY_SPACE = 32,
		HFR_KEY_APOSTROPHE = 39, /* ' */
		HFR_KEY_COMMA = 44, /* , */
		HFR_KEY_MINUS = 45, /* - */
		HFR_KEY_PERIOD = 46, /* . */
		HFR_KEY_SLASH = 47, /* / */

		HFR_KEY_D0 = 48, /* 0 */
		HFR_KEY_D1 = 49, /* 1 */
		HFR_KEY_D2 = 50, /* 2 */
		HFR_KEY_D3 = 51, /* 3 */
		HFR_KEY_D4 = 52, /* 4 */
		HFR_KEY_D5 = 53, /* 5 */
		HFR_KEY_D6 = 54, /* 6 */
		HFR_KEY_D7 = 55, /* 7 */
		HFR_KEY_D8 = 56, /* 8 */
		HFR_KEY_D9 = 57, /* 9 */

		HFR_KEY_SEMICOLON = 59, /* ; */
		HFR_KEY_EQUAL = 61, /* = */

		HFR_KEY_A = 65,
		HFR_KEY_B = 66,
		HFR_KEY_C = 67,
		HFR_KEY_D = 68,
		HFR_KEY_E = 69,
		HFR_KEY_F = 70,
		HFR_KEY_G = 71,
		HFR_KEY_H = 72,
		HFR_KEY_I = 73,
		HFR_KEY_J = 74,
		HFR_KEY_K = 75,
		HFR_KEY_L = 76,
		HFR_KEY_M = 77,
		HFR_KEY_N = 78,
		HFR_KEY_O = 79,
		HFR_KEY_P = 80,
		HFR_KEY_Q = 81,
		HFR_KEY_R = 82,
		HFR_KEY_S = 83,
		HFR_KEY_T = 84,
		HFR_KEY_U = 85,
		HFR_KEY_V = 86,
		HFR_KEY_W = 87,
		HFR_KEY_X = 88,
		HFR_KEY_Y = 89,
		HFR_KEY_Z = 90,

		HFR_KEY_LEFT_BRACKET = 91,  /* [ */
		HFR_KEY_BACKSLASH = 92,  /* \ */
		HFR_KEY_RIGHT_BRACKET = 93,  /* ] */
		HFR_KEY_GRAVE_ACCENT = 96,  /* ` */

		HFR_KEY_WORLD_1 = 161, /* non-US #1 */
		HFR_KEY_WORLD_2 = 162, /* non-US #2 */

		/* Function keys */
		HFR_KEY_ESCAPE = 256,
		HFR_KEY_ENTER = 257,
		HFR_KEY_TAB = 258,
		HFR_KEY_BACKSPACE = 259,
		HFR_KEY_INSERT = 260,
		HFR_KEY_DELETE = 261,
		HFR_KEY_RIGHT = 262,
		HFR_KEY_LEFT = 263,
		HFR_KEY_DOWN = 264,
		HFR_KEY_UP = 265,
		HFR_KEY_PAGE_UP = 266,
		HFR_KEY_PAGE_DOWN = 267,
		HFR_KEY_HOME = 268,
		HFR_KEY_END = 269,
		HFR_KEY_CAPS_LOCK = 280,
		HFR_KEY_SCROLL_LOCK = 281,
		HFR_KEY_NUM_LOCK = 282,
		HFR_KEY_PRINT_SCREEN = 283,
		HFR_KEY_PAUSE = 284,
		HFR_KEY_F1 = 290,
		HFR_KEY_F2 = 291,
		HFR_KEY_F3 = 292,
		HFR_KEY_F4 = 293,
		HFR_KEY_F5 = 294,
		HFR_KEY_F6 = 295,
		HFR_KEY_F7 = 296,
		HFR_KEY_F8 = 297,
		HFR_KEY_F9 = 298,
		HFR_KEY_F10 = 299,
		HFR_KEY_F11 = 300,
		HFR_KEY_F12 = 301,
		HFR_KEY_F13 = 302,
		HFR_KEY_F14 = 303,
		HFR_KEY_F15 = 304,
		HFR_KEY_F16 = 305,
		HFR_KEY_F17 = 306,
		HFR_KEY_F18 = 307,
		HFR_KEY_F19 = 308,
		HFR_KEY_F20 = 309,
		HFR_KEY_F21 = 310,
		HFR_KEY_F22 = 311,
		HFR_KEY_F23 = 312,
		HFR_KEY_F24 = 313,
		HFR_KEY_F25 = 314,

		/* Keypad */
		HFR_KEY_KP_0 = 320,
		HFR_KEY_KP_1 = 321,
		HFR_KEY_KP_2 = 322,
		HFR_KEY_KP_3 = 323,
		HFR_KEY_KP_4 = 324,
		HFR_KEY_KP_5 = 325,
		HFR_KEY_KP_6 = 326,
		HFR_KEY_KP_7 = 327,
		HFR_KEY_KP_8 = 328,
		HFR_KEY_KP_9 = 329,
		HFR_KEY_KP_DECIMAL = 330,
		HFR_KEY_KP_DIVIDE = 331,
		HFR_KEY_KP_MULTIPLY = 332,
		HFR_KEY_KP_SUBTRACT = 333,
		HFR_KEY_KP_ADD = 334,
		HFR_KEY_KP_ENTER = 335,
		HFR_KEY_KP_EQUAL = 336,

		HFR_KEY_LEFT_SHIFT = 340,
		HFR_KEY_LEFT_CONTROL = 341,
		HFR_KEY_LEFT_ALT = 342,
		HFR_KEY_LEFT_SUPER = 343,
		HFR_KEY_RIGHT_SHIFT = 344,
		HFR_KEY_RIGHT_CONTROL = 345,
		HFR_KEY_RIGHT_ALT = 346,
		HFR_KEY_RIGHT_SUPER = 347,
		HFR_KEY_MENU = 348
	};

}

//mouse codes
namespace HFR {

	const enum : uint16_t
	{
		// From glfw3.h
		HFR_MOUSE_BUTTON_0 = 0,
		HFR_MOUSE_BUTTON_1 = 2,
		HFR_MOUSE_BUTTON_2 = 1,
		HFR_MOUSE_BUTTON_3 = 3,
		HFR_MOUSE_BUTTON_4 = 4,
		HFR_MOUSE_BUTTON_5 = 5,
		HFR_MOUSE_BUTTON_6 = 6,
		HFR_MOUSE_BUTTON_7 = 7,

		HFR_MOUSE_BUTTON_LAST = HFR_MOUSE_BUTTON_7,
		HFR_MOUSE_BUTTON_LEFT = HFR_MOUSE_BUTTON_0,
		HFR_MOUSE_BUTTON_RIGHT = HFR_MOUSE_BUTTON_1,
		HFR_MOUSE_BUTTON_MIDDLE = HFR_MOUSE_BUTTON_2
	};

}

//CSIDL codes
namespace HFR {

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

#define HFR_FOLDER_DESKTOP CSDIDL_DESKTOP
#define HFR_FOLDER_INTERNET CSIDL_INTERNET
#define HFR_FOLDER_PROGRAMS CSIDL_PROGRAMS
#define HFR_FOLDER_CONTROL_PANEL CSIDL_CONTROLS
#define HFR_FOLDER_PRINTERS CSIDL_PRINTERS
#define HFR_FOLDER_DOCUMENTS CSIDL_PERSONAL
#define HFR_FOLDER_FAVORITES CSIDL_FAVORITES
#define HFR_FOLDER_STARTUP CSIDL_STARTUP
#define HFR_FOLDER_RECENT CSIDL_RECENT
#define HFR_FOLDER_SEND_TO CSIDL_SENDTO
#define HFR_FOLDER_RECYCLE_BIN CSIDL_BITBUCKET
#define HFR_FOLDER_START_MENU CSIDL_STARTMENU
#define HFR_FOLDER_MUSIC CSIDL_MYMUSIC
#define HFR_FOLDER_VIDEOS CSIDL_MYVIDEO
#define HFR_FOLDER_DESKTOP_DIRECTORY CSIDL_DESKTOPDIRECTORY
#define HFR_FOLDER_DRIVES CSIDL_DRIVES
#define HFR_FOLDER_NETWORK CSIDL_NETWORK
#define HFR_FOLDER_NET_HOOD CSIDL_NETHOOD
#define HFR_FOLDER_FONTS CSIDL_FONTS
#define HFR_FOLDER_TEMPLATES CSIDL_TEMPLATES
#define HFR_FOLDER_COMMON_STARTMENU CSIDL_COMMON_STARTMENU
#define HFR_FOLDER_COMMON_PROGRAMS CSIDL_COMMON_PROGRAMS
#define HFR_FOLDER_COMMON_STARTUP CSIDL_COMMON_STARTUP
#define HFR_FOLDER_COMMON_DESKTOP_DIRECTORY CSIDL_COMMON_DESKTOPDIRECTORY
#define HFR_FOLDER_APP_DATA CSIDL_APPDATA
#define HFR_FOLDER_PRINT_HOOD CSIDL_PRINTHOOD

}

//macros for include bc im lazy
#define HFR_CAMERA "HFR/camera/Camera.h"
#define HFR_CAMERA_CONTROLLER "HFR/camera/CameraController.h"
#define HFR_EDITOR_CAMERA "HFR/camera/EditorCamera.h"

#define HFR_ECS "HFR/ECS/ECS.h"
#define HFR_GAMEOBJECT "HFR/ECS/GameObject.h"
#define HFR_SCENE "HFR/ECS/Scene.h"
#define HFR_TAG "HFR/ECS/components/Tag.h"

#define HFR_MESH "HFR/mesh/Mesh.h"
#define HFR_TEXTURE "HFR/mesh/Texture.h"
#define HFR_MATERIAL "HFR/mesh/Material.h"
#define HFR_MESH_COMPONENT "HFR/mesh/MeshComponent.h"

#define HFR_NATIVE_SCRIPT "HFR/scripting/NativeScript.h"
#define HFR_SCRIPT_MANAGER "HFR/scripting/ScriptManager.h"

#define HFR_GUI_ELEMENT "HFR/gui/GuiElement.h"
#define HFR_GUI_FRAME "HFR/gui/GuiFrame.h"

#define HFR_API "HFR/core/API.h"
#define HFR_PROGRAM "HFR/core/Program.h"
#define HFR_ENGINE "HFR/core/Engine.h"
#define HFR_START "HFR/core/Start.h"

#define HFR_IMAGE "HFR/graphics/image/Image.h"
#define HFR_PIXEL "HFR/graphics/image/Pixel.h"

#define HFR_RENDERER "HFR/graphics/rendering/Renderer.h"
#define HFR_SHADER "HFR/graphics/rendering/Shader.h"

#define HFR_LIGHT "HFR/graphics/lighting/Light.h"

#define HFR_CURSOR "HFR/io/Cursor.h"
#define HFR_INPUT "HFR/io/Input.h"
#define HFR_WINDOW "HFR/io/Window.h"

#define HFR_MAT4 "HFR/math/matrixes/Mat4.h"
#define HFR_TRANSFORM "HFR/math/vectors/Transform.h"
#define HFR_VEC2 "HFR/math/vectors/Vec2.h"
#define HFR_VEC3 "HFR/math/vectors/Vec3.h"
#define HFR_VEC4 "HFR/math/vectors/Vec4.h"
#define HFR_MATH "HFR/math/HMath.h"
#define HFR_RANDOM "HFR/math/Random.h"

#define HFR_FLOAT_BUFFER "HFR/memory/FloatBuffer.h"

#define HFR_FREETYPE "HFR/text/FreeType.h"
#define HFR_CHARACTER "HFR/text/Character.h"
#define HFR_FONT "HFR/text/Font.h"

#define HFR_PROFILE "HFR/time/Profile.h"
#define HFR_PROFILER "HFR/time/Profiler.h"
#define HFR_TIME "HFR/time/Time.h"

#define HFR_DEBUG "HFR/util/Debug.h"
#define HFR_UTIL "HFR/util/Util.h"
#define HFR_GUID "HFR/util/HGUID.h"

#define HFR_STANDARD "IncludeStandard.h"
#define STB_IMAGE "HFR/graphics/image/stb_image.h"

#endif