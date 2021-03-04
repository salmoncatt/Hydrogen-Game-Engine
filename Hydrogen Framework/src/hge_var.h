
#ifndef HGE_VARIABLE_HEADER_INCLUDE
#define HGE_VARIABLE_HEADER_INCLUDE

#include "hpch.h"

#define HGE_API "HGE/core/API.h"

namespace HGE {
	//big stoof
	const int HGE_NULL = 0;

#ifdef _DEBUG
	const std::string HGE_RES = "../Hydrogen Framework/res/";
#else
	const std::string HGE_RES = "res/";
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

#endif