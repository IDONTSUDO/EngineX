#pragma once
#include <Windows.h>

class Window
{
	public:
		Window();
		bool init();
		bool realese();
		~Window();
protected:
	HWND m_hwnd;
};

