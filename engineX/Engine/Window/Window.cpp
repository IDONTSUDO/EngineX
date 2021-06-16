
#include "Window.h"

//Window* window=nullptr;

Window::Window()
{

}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//GetWindowLong(hwnd,)
	switch (msg)
	{
	case WM_CREATE:
	{
		// Событие срабатывает при создании 
		Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
		// .. а затем сохраняется для последующего поиска
		SetWindowLongPtr(hwnd, GWL_USERDATA, (LONG_PTR)window);
		window->setHWND(hwnd);
		window->onCreate();
		break;
	}

	case WM_DESTROY:
	{
		// Событие срабатывает, когда окно удаляется
		Window* window = (Window*)GetWindowLong(hwnd, GWL_USERDATA);
		window->onDestroy();
		::PostQuitMessage(0);
		break;
	}


	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}


bool Window::init()
{

	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = "MyWindowClass";
	wc.lpszMenuName = "";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	if (!::RegisterClassEx(&wc)) 
		return false;


	//создание окна
	m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "DirectX Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
		NULL, NULL, NULL, this);
 
	if (!m_hwnd)
		return false;

	//показать окно
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);




	//значение true, чтобы указать, что окно инициализировано и запущено
	m_is_run = true;



	return true;
}

bool Window::broadcast()
{
	MSG msg;


	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	this->onUpdate();

	Sleep(1);

	return true;
}


bool Window::release()
{
	//Разрушить окно
	if (!::DestroyWindow(m_hwnd))
		return false;

	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

void Window::setHWND(HWND hwnd)
{
	this->m_hwnd = hwnd;
}

RECT Window::getClienWindowRect()
{
	RECT rc;
	::GetClientRect(this->m_hwnd, &rc);
	return rc;
}

void Window::onCreate()
{
	
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{
	m_is_run = false;
}

Window::~Window()
{
}