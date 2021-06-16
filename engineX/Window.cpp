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
		// ������� ����������� ����� WINDOWS ���������, ���������. 
		break;
	}
	case WM_DESTROY:
	{
		// ������� ����������� ����� WINDOWS �������, ���������. 
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
	if(!::RegisterClassExW(&wc)); //   ���� ����� ����������� �� ������ 
		return false;
	// �������� ���� 
	m_hwnd=::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, MAIN_WINDOW_NAME, MAIN_WINDOW_DESCRIPRION, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);
	// ���� �������� �� �������  
	if (!m_hwnd)
		return false;
	// ���������� � ��������� ����  
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);
	return true;
}

bool Window::realese()
{
	//  �������� ���� 
	if (!::DestroyWindow(m_hwnd))
		return false;
	return true;
}
Window::~Window() 
{
}