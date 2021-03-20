#pragma once
#include "HFR/core/API.h"
#include <Windows.h>

namespace HFR {

	class DLL_API HWindow {
	protected:
		HWND m_hwnd;
	public:
		int m_x, m_y;
		int m_width, m_height;
		char* m_title;

		HWindow(const int, const int, const int, const int, const char*);
		~HWindow();

		bool create();
		bool destroy();
		bool update();


	};

}
