#include "hfpch.h"
#include "HWindow.h"

namespace HFR {

	HWindow::HWindow(const int x, const int y, const int width, const int height, const char* title) {
		if (x != NULL) m_x = x;
			else m_x = CW_USEDEFAULT;
		
		if (y != NULL) m_y = y;
			else m_y = CW_USEDEFAULT;

		if (width != NULL) m_width = width;
			else m_width = CW_USEDEFAULT;

		if (height != NULL) m_height = height;
			else m_height = CW_USEDEFAULT;

		m_title = const_cast<char*>(title);
		m_hwnd = NULL;
	}

	HWindow::~HWindow() {

	}

	LRESULT CALLBACK HFRWindowCallBack(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
		return DefWindowProc(hwnd, message, wparam, lparam);
	}

	bool HWindow::create() {

		//create windows window for windows using windows.h
		WNDCLASSEX window = {};
		
		window.lpszClassName = "HEF Window";
		window.cbSize = sizeof(WNDCLASSEX);
		window.hbrBackground = (HBRUSH)COLOR_WINDOW;
		window.hCursor = LoadCursor(NULL, IDC_ARROW);
		window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		window.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		window.lpfnWndProc = &HFRWindowCallBack;

		window.cbClsExtra = NULL;
		window.cbWndExtra = NULL;
		window.hInstance = NULL;
		window.style = NULL;
		window.lpszMenuName = NULL;


		//if fail, die
		if (!RegisterClassEx(&window))
			return false;

		m_hwnd = CreateWindowEx(0, "HEF Window", m_title, WS_OVERLAPPEDWINDOW, m_x, m_y, m_width, m_height, NULL, NULL, NULL, NULL);

		//if fail, die too
		if (!m_hwnd)
			return false;

		ShowWindow(m_hwnd, SW_SHOW);
		UpdateWindow(m_hwnd);

		return true;
	}

	bool HWindow::destroy() {
		if (!DestroyWindow(m_hwnd))
			return false;

		return true;
	}

}