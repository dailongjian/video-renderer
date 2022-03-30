#pragma once
#include <Windows.h>

enum
{
	USB_DEVICE_ERROR_SUCC = 0,
	USB_DEVICE_ERROR_FAILD,
	USB_DEVICE_ERROR_INVALID_PARAMS,/* ����Ĳ������� */
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
	*	����MonitorDevice�豸�����ڶ��豸���в���
	*	@return	ʧ�ܷ���false���ɹ�����true
	*	@remark �����Ҫʹ��DestroyMonitorDevice��������
	*/
	__declspec(dllexport) HANDLE CreateMonitorDevice();

	/*
	*	�ȴ�������ʾ����Ļ���ݣ���Ļ�����и��²ŷ���
	*	@param	handle[in]:CreateMonitorDevice���ص��豸���
	*	@param	imageData[out]:���ڼ�������仯
	*	@return	�����ش�����
	*	@remark
	*/
	__declspec(dllexport) int WaitforFrameChange(HANDLE handle, MON_IMG_DATA* imageData);

	/*
	*	ȡ���ȴ���ĻͼƬ������WaitMonitorImage�������ȴ��ģ���һ���߳̿���ȡ���ȴ�����WaitMonitorImage����
	*	@param	handle[in]:CreateMonitorDevice���ص��豸���
	*	@return	�����ش�����
	*	@remark
	*/
	__declspec(dllexport) int CancelWaitFrameChange(HANDLE handle);


	/*
	*	����MonitorDevice�豸
	*	@param	handle[in]:CreateMonitorDevice���ص��豸���
	*	@return	�����ش�����
	*	@remark
	*/
	__declspec(dllexport) int DestroyMonitorDevice(HANDLE handle);

}
