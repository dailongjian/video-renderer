#pragma once
#include "screen_capture.h"
#include "libVMonitor.h"
#pragma comment(lib, "libVMonitor.lib")

namespace DX {

	class WddmScreenCapture : public ScreenCapture
	{
	public:
		WddmScreenCapture();
		virtual ~WddmScreenCapture();

		virtual bool Init(int display_index = 0);
		virtual void Destroy();

		virtual bool Capture(Image& image);

	private:
		HANDLE m_handle = nullptr;
	};
}