#pragma once
#include "../Engine/Window/Window.h"
#include "../Engine/Graphics/GraphicsEngine.h"
#include "../Engine/Graphics/SwapChain/SwapChain.h"
#include "../Engine/Graphics/DeviceContext/DeviceContext.h"

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();

	//Унаследовано через Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
private:
	SwapChain * m_swap_chain;
};
