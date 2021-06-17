#pragma once
#include <d3d11.h>
#include <../../Engine/Graphics/DeviceContext/DeviceContext.h>

class SwapChain
{
public:
	SwapChain();
	bool init(HWND hwnd, UINT width, UINT height);
	bool present(bool vsync);
	bool realese();
	~SwapChain();
private:
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView* m_rtv;
private:
	friend class DeviceContext;
};

