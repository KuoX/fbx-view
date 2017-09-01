//-----------------------------------------------------------------------
#ifndef _SoD3DCameraBase_h_
#define _SoD3DCameraBase_h_
//-----------------------------------------------------------------------
#include "SoD3DInclude.h"
//-----------------------------------------------------------------------
class SoD3DCameraBase
{
public:
	SoD3DCameraBase();
	~SoD3DCameraBase();

	void SetPosition(float x, float y, float z);
	void SetPitch(float fPitch);
	void SetYaw(float fYaw);
	void SetPitchYaw(float fPitch, float fYaw);
	//ƽ�ơ�
	//--fDeltaByRightDir ��Right�����ϵ�ƫ����
	//--fDeltaByLookDir ��Look�����ϵ�ƫ����
	void SetDeltaMove(float fDeltaByRightDir, float fDeltaByLookDir);
	void SetDeltaPitch(float deltaPitch);
	void SetDeltaYaw(float deltaYaw);
	void SetDeltaPitchYaw(float deltaPitch, float deltaYaw);

	//����Frustum��������ͶӰ����
	//--fTopDownFOVAngle �����ӳ��ĽǶȣ�����ֵ��
	//--fAspect �ݺ�ȣ����ڿ���Դ��ڸߡ�
	//--fNearZ ���ü���ľ��롣
	//--fFarZ Զ�ü���ľ��롣
	void SetFrustum(float fTopDownFOVAngle, float fAspect, float fNearZ, float fFarZ);
	//���������λ�û��߳������仯����Ҫִ�б����������¹���View����
	void UpdateViewMatrix();

	const XMFLOAT3& GetPosition() const;
	float GetPitch() const;
	float GetYaw() const;
	const XMFLOAT3& GetRight() const;
	const XMFLOAT3& GetUp() const;
	const XMFLOAT3& GetLook() const;
	XMMATRIX GetMatView() const;
	XMMATRIX GetMatProj() const;
	XMMATRIX GetMatViewProj() const;

protected:
	//������������
	void MakeRotate();

protected:
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//����������Ա�������Ǽ���������������������Ԫ�ء�
	//��������ϵ�ڵ�λ�����ꡣ
	XMFLOAT3 m_kPosition;
	//ŷ���ǣ��Ի���ֵ��ʾ����X��������Ϊ��������ת��
	float m_fPitch;
	//ŷ���ǣ��Ի���ֵ��ʾ����Z��������Ϊ��������ת��
	float m_fYaw;
	//��¼��������Ԫ���Ƿ����˱仯��
	bool m_bShouldUpdateViewMatrix;
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	XMFLOAT3 m_kRight;
	XMFLOAT3 m_kUp;
	XMFLOAT3 m_kLook;
	XMFLOAT4X4 m_matView;
	XMFLOAT4X4 m_matProjection;
	XMFLOAT4X4 m_matViewProj;
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
};
//-----------------------------------------------------------------------
inline const XMFLOAT3& SoD3DCameraBase::GetPosition() const
{
	return m_kPosition;
}
//-----------------------------------------------------------------------
inline float SoD3DCameraBase::GetPitch() const
{
	return m_fPitch;
}
//-----------------------------------------------------------------------
inline float SoD3DCameraBase::GetYaw() const
{
	return m_fYaw;
}
//-----------------------------------------------------------------------
inline const XMFLOAT3& SoD3DCameraBase::GetRight() const
{
	return m_kRight;
}
//-----------------------------------------------------------------------
inline const XMFLOAT3& SoD3DCameraBase::GetUp() const
{
	return m_kUp;
}
//-----------------------------------------------------------------------
inline const XMFLOAT3& SoD3DCameraBase::GetLook() const
{
	return m_kLook;
}
//-----------------------------------------------------------------------
inline XMMATRIX SoD3DCameraBase::GetMatView() const
{
	return XMLoadFloat4x4(&m_matView);
}
//-----------------------------------------------------------------------
inline XMMATRIX SoD3DCameraBase::GetMatProj() const
{
	return XMLoadFloat4x4(&m_matProjection);
}
//-----------------------------------------------------------------------
inline XMMATRIX SoD3DCameraBase::GetMatViewProj() const
{
	return XMLoadFloat4x4(&m_matViewProj);
}
//-----------------------------------------------------------------------
#endif //_SoD3DCameraBase_h_
//-----------------------------------------------------------------------
