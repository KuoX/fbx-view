//-----------------------------------------------------------------------
#ifndef _SoD3DCamera_h_
#define _SoD3DCamera_h_
//-----------------------------------------------------------------------
#include "SoD3DCameraBase.h"
//-----------------------------------------------------------------------
struct stInputEvent;
//-----------------------------------------------------------------------
class SoD3DCamera : public SoD3DCameraBase
{
public:
	enum eCameraMode
	{
		CameraMode_Free, //���������
		CameraMode_Focus, //�۽������������۽����ͻ�����������
	};

public:
	static bool CreateD3DCamera();
	static void ReleaseD3DCamera();
	static SoD3DCamera* Get();

	void SetCameraMode(eCameraMode newMode);
	eCameraMode GetCameraMode() const;

	void ProcessInputEvent(stInputEvent* pInputEvent);
	void UpdateFreeMove(float fDeltaTime);

	void SetFocusPos(float x, float y, float z);
	void SetFocusDistance(float fDistance);
	void SetFocusDeltaDistance(float deltaDistance);

private:
	SoD3DCamera();
	~SoD3DCamera();
	bool InitD3DCamera();
	void ClearD3DCamera();

private:
	static SoD3DCamera* ms_pInstance;
	eCameraMode m_CameraMode;
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//�����������ת�ĳ�Ա��
	//������Ҽ����¿�ʼ�������ƶ����ƾ�ͷ����ת��
	int m_nMouseRightKeyDown;
	int m_nLastCursorPosX;
	int m_nLastCursorPosY;
	//���λ�á��Դ������Ͻ�Ϊԭ�㡣
	int m_nLastMousePosX;
	int m_nLastMousePosY;
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//�۽�ģʽ����Ҫ�ĳ�Ա��
	//�۽�����Ŀ��λ�á�
	XMFLOAT3 m_kFocusPos;
	//�������Ŀ��λ�õľ��롣
	float m_fFocusDistance;
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
};
//-----------------------------------------------------------------------
inline SoD3DCamera* SoD3DCamera::Get()
{
	return ms_pInstance;
}
//-----------------------------------------------------------------------
inline void SoD3DCamera::SetCameraMode(SoD3DCamera::eCameraMode newMode)
{
	m_CameraMode = newMode;
}
//-----------------------------------------------------------------------
inline SoD3DCamera::eCameraMode SoD3DCamera::GetCameraMode() const
{
	return m_CameraMode;
}
//-----------------------------------------------------------------------
#endif //_SoD3DCamera_h_
//-----------------------------------------------------------------------
