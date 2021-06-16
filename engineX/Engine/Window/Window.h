
#pragma once
#include <Windows.h>



class Window
{
public:
	Window();
	//Инициализация окна
	bool init();
	bool broadcast();
	//Release the window
	bool release();
	bool isRun();

	//События
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();


	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};