
#pragma once
#include <Windows.h>



class Window
{
public:
	Window();
	//Инициализация окна
	bool init();
	bool broadcast();
	 
	bool release();
	bool isRun();
	void setHWND(HWND hwnd);
	RECT getClienWindowRect();
	//События
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();


	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};