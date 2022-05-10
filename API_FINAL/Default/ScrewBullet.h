#pragma once
#include "Obj.h"
class CScrewBullet : public CObj
{
public:
	CScrewBullet();
	virtual ~CScrewBullet();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;


private:
	POINT		m_ptCenter;

	float		m_fRotAngle;
	float		m_fRotSpeed;
	float		m_fRotDistance;

	bool		m_bStart;	// �߽� �࿡ ���� ������ 1ȸ�� ���� �� ���� ������ �Բ� �̵��ϵ��� ���� �ؾ� ��.

};

