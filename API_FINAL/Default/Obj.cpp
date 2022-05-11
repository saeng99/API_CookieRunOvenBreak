#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_fSpeed(0.f), m_eDir(DIR_END), m_bDead(false), m_fAngle(0.f)
	, m_pFrameKey(nullptr), m_bOnBlock(false), m_bOnAir(true), m_fGTime(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tFrame, sizeof(FRAME));
}

CObj::~CObj()
{
}

void CObj::UpdateGravity()
{
	// 1,�����̳� �ٴ��̳�

	if (m_bOnBlock)
	{// �� ����
		m_bOnAir = false;
	}
	else
	{// �����̴�
		m_bOnAir = true;
	}

	// �����̸� �߷��� �ش�.
	if (m_bOnAir)
	{
		m_tInfo.fY -= -9.8f * m_fGTime * 0.5f;
		m_fGTime += 0.1f;
	}
	else
	{
		m_fGTime = 0.f;
	}

	m_bOnBlock = false;
}

void CObj::UpdateGravity(float _fGravity)
{
	// 1,�����̳� �ٴ��̳�

	if (m_bOnBlock)
	{// �� ����
		m_bOnAir = false;
	}
	else
	{// �����̴�
		m_bOnAir = true;
	}

	// �����̸� �߷��� �ش�.
	if (m_bOnAir)
	{
		m_tInfo.fY -= -_fGravity * m_fGTime * 0.5f;
		m_fGTime += 0.1f;
	}
	else
	{
		m_fGTime = 0.f;
	}

	m_bOnBlock = false;
}

bool CObj::CompareTag(string _Tag)
{
	if (m_Tag == _Tag)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CObj::SetTag(string _Tag)
{
	m_Tag = _Tag;
}

void CObj::Update_Rect(void)
{
	m_tRect.left   = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top    = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
 	m_tRect.right  = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CObj::Move_Frame(void)
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < GetTickCount())
	{
		m_tFrame.iFrameStart++;

		m_tFrame.dwTime = GetTickCount();
		
		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			m_tFrame.iFrameStart = 0;
			
	}

}
