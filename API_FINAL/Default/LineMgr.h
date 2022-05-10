#pragma once

#include "Line.h"

class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();

public:
	void		Initialize(void);
	void		Render(HDC hDC);
	void		Release(void);

	bool		Collision_Line(float& _fX, float* pY);
	void		Load_Line();

public:
	static		CLineMgr*		Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CLineMgr;
		}

		return m_pInstance;
	}

	static	void	Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CLineMgr*		m_pInstance;
	list<CLine*>			m_LineList;
};

// (���� ���� ����)�� �̿��Ͽ� ������ �����϶�
// Y = �� * sin(����) * �ð� - 1/2(�߷°��(9.8) * �ð� * �ð�)