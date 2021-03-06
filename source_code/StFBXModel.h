//----------------------------------------------------------------
#ifndef _StFBXModel_h_
#define _StFBXModel_h_
//----------------------------------------------------------------
#include "StFBXDefine.h"
//----------------------------------------------------------------
class StFBXModel
{
	friend class StFBXManager;
public:
	StFBXModel();
	~StFBXModel();

	const StFBXMeshData* GetMeshData() const;
	const StFBXControlPointGroup* GetControlPointGroup() const;
	const StFBXBoneGroup* GetBoneGroup() const;
	const StFBXModelAnimation* GetAnimation() const;
	//
	const StFBXMeshData* GetAnimationMeshData(float fTime);
	//目前模型中只有一个动画。获取动画中有多少个关键帧。
	int GetKeyFrameCount() const;
	void CalculateMeshDataByKeyFrame(const int nKeyFrameIndex);
	float GetAnimTimeLength();
	//计算Mesh的包围盒。
	void CalculateMeshBoundingBox(SoMathFloat3* pMinPos, SoMathFloat3* pMaxPos);
	
protected:
	StFBXControlPointGroup* GetControlPointGroup_Modify();
	StFBXBoneGroup* GetBoneGroup_Modify();
	StFBXModelAnimation* GetAnimation_Modify();
	StFBXMeshData* GetMeshData_Modify();

private:
	StFBXControlPointGroup m_kControlPointGroup;
	StFBXBoneGroup m_kBoneGroup;
	StFBXModelAnimation m_kAnimation;
	//载入数据后，这里的Mesh数据渲染出来就是默认的Pose；
	//当执行CalculateMeshDataByKeyFrame()后，这里的Mesh数据就变成了指定帧的Pose。
	StFBXMeshData m_kMeshData;
};
//----------------------------------------------------------------
#endif
//----------------------------------------------------------------
