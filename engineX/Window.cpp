#include "Window.h"
const wchar_t MAIN_WINDOW_NAME[] = L"Sample Window Class";
const wchar_t MAIN_WINDOW_DESCRIPRION[] = L"Direct X Application";
Window* window = nullptr;
Window::Window() 
{

}


LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{

	switch (msg)
	{
	case WM_CREATE:
	{
		// Событие срабатывает когда WINDOWS запускает, программу. 
		break;
	}
	case WM_DESTROY:
	{
		// Событие срабатывает когда WINDOWS убивает, программу. 
		::PostQuitMessage(0);
		break;
	}
	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}
};
bool Window::init() 
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpfnWndProc = &WindProc;
	wc.lpszClassName = MAIN_WINDOW_NAME;
	if(!::RegisterClassExW(&wc)); //   если класс регистрации не вызван 
		return false;
	// создание окна 
	m_hwnd=::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, MAIN_WINDOW_NAME, MAIN_WINDOW_DESCRIPRION, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);
	// если создание не удалось  
	if (!m_hwnd)
		return false;
	// показывает и открывает окно  
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);
	return true;
}

bool Window::realese()
{
	//  Удаление окна 
	if (!::DestroyWindow(m_hwnd))
		return false;
	return true;
}
Window::~Window() 
{
}