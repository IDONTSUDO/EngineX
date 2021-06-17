#pragma once
#include <d3d11.h>
#include <../../Engine/Graphics/SwapChain/SwapChain.h>
#include <../../Engine/Graphics/DeviceContext/DeviceContext.h>
class GraphicsEngine
{
public:
	GraphicsEngine();
	// Инициализируем GraphicsEngine и устройство DirectX 11
	bool init();
	// Освобождаем все загруженные ресурсы
	bool realease();
	~GraphicsEngine();

public:
	SwapChain * createSwapChain();
	DeviceContext* getImmediateDeviceContext();
public:
	static GraphicsEngine* get();
private:
	DeviceContext* m_imm_device_context;
private:
	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;
	ID3D11DeviceContext* m_imm_context;
private:
	IDXGIDevice* m_dxgi_device;
	IDXGIAdapter* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;
private:
	friend class SwapChain;
};

