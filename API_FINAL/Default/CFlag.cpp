#include "stdafx.h"
#include "CFlag.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"
#include "Scene.h"
#include "ObjMgr.h"

CFlag::CFlag()
{
}

CFlag::~CFlag()
{
	Release();
}

void CFlag::Initialize(void)
{
	m_tInfo.fCX = 200.f;
	m_tInfo.fCY = 220.f;

	m_eRender = RENDER_GAMEOBJECT;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/EndingFlag.bmp", L"Flag");

	m_eCurState = IDLE;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();

	m_pPlayer = CObjMgr::Get_Instance()->Get_Player();
}

int CFlag::Update(void)
{
	if (m_pPlayer->Get_Info().fX >= m_tInfo.fX)
		m_eCurState = HIT;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CFlag::Late_Update(void)
{
	Motion_Change();

	if(m_eCurState == IDLE)
		Move_Frame();
	else
		Move_Frame2();
}

void CFlag::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Flag");

	GdiTransparentBlt(hDC,
		int(m_tRect.left + iScrollX),
		int(m_tRect.top + iScrollY),
		200,
		220,
		hMemDC,
		m_tFrame.iFrameStart * m_tInfo.fCX,
		m_tFrame.iMotion * m_tInfo.fCY,
		200,
		220,
		RGB(255, 0, 255));
}

void CFlag::Release(void)
{
}

void CFlag::OnCollision(CObj* other)
{
}

void CFlag::Hit()
{

}

void CFlag::Motion_Change(void)
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.iMotion = 0;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();

			break;

		case HIT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 6;
			m_tFrame.iMotion = 1;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
		}

		m_ePreState = m_eCurState;
	}
}

void CFlag::Move_Frame2(void)
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < GetTickCount())
	{
		m_tFrame.iFrameStart++;

		m_tFrame.dwTime = GetTickCount();

		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			m_tFrame.iFrameStart = 3;

	}

}