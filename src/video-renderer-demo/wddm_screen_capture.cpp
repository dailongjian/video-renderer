#include "wddm_screen_capture.h"

using namespace DX;
WddmScreenCapture::WddmScreenCapture()
{

}


WddmScreenCapture::~WddmScreenCapture()
{

}

bool WddmScreenCapture::Init(int display_index)
{
	m_handle = CreateMonitorDevice();
	if (m_handle == nullptr) {
		return false;
	}
	return true;
}


void WddmScreenCapture::Destroy()
{
	if (m_handle != nullptr) {
		DestroyMonitorDevice(m_handle);
		m_handle = nullptr;
	}
}

bool  WddmScreenCapture::Capture(Image& image)
{
	MON_IMG_DATA imageData;
	memset(&imageData, 0, sizeof(MON_IMG_DATA));
	int nRet = WaitforFrameChange(m_handle, &imageData);
	if (nRet == USB_DEVICE_ERROR_SUCC) {
		image.width = imageData.width;
		image.height = imageData.height;

		image.bgra.assign((uint8_t*)imageData.pSurface, ((uint8_t*)imageData.pSurface) + imageData.stride * imageData.height);
		return true;
	}
	return false;
}