#pragma once
#include <Windows.h>

enum
{
	USB_DEVICE_ERROR_SUCC = 0,
	USB_DEVICE_ERROR_FAILD,
	USB_DEVICE_ERROR_INVALID_PARAMS,/* 传入的参数不对 */
	USB_DEVICE_ERROR_CANCELED
};

typedef struct _MON_IMG_DATA
{
	UINT  width;
	UINT  height;
	UINT  stride;
	PVOID pSurface;
}MON_IMG_DATA;


extern "C"
{
	/*
	*	创建MonitorDevice设备，用于对设备进行操作
	*	@return	失败返回false，成功返回true
	*	@remark 最后需要使用DestroyMonitorDevice进行销毁
	*/
	__declspec(dllexport) HANDLE CreateMonitorDevice();

	/*
	*	等待虚拟显示器屏幕数据，屏幕画面有更新才返回
	*	@param	handle[in]:CreateMonitorDevice返回的设备句柄
	*	@param	imageData[out]:用于监听画面变化
	*	@return	见返回错误码
	*	@remark
	*/
	__declspec(dllexport) int WaitforFrameChange(HANDLE handle, MON_IMG_DATA* imageData);

	/*
	*	取消等待屏幕图片，由于WaitMonitorImage是阻塞等待的，另一个线程可以取消等待，让WaitMonitorImage返回
	*	@param	handle[in]:CreateMonitorDevice返回的设备句柄
	*	@return	见返回错误码
	*	@remark
	*/
	__declspec(dllexport) int CancelWaitFrameChange(HANDLE handle);


	/*
	*	销毁MonitorDevice设备
	*	@param	handle[in]:CreateMonitorDevice返回的设备句柄
	*	@return	见返回错误码
	*	@remark
	*/
	__declspec(dllexport) int DestroyMonitorDevice(HANDLE handle);

}
