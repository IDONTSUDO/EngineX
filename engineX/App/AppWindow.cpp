#include "AppWindow.h"



AppWindow::AppWindow()
{
}


AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	GraphicsEngine::get() -> init();
	m_swap_chain = GraphicsEngine::get()->createSwapChain();
	RECT rc = this->  getClienWindowRect();
	m_swap_chain->init(m_hwnd, rc.right-rc.left,rc.bottom-rc.top);
}

void AppWindow::onUpdate()
{
	Window::onUpdate();

}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_swap_chain->realese();
	GraphicsEngine::get()->realease();
}