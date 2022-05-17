#include "stdafx.h"
#include "CComingUpThorn.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "Player.h"

CComingUpThorn::CComingUpThorn()
{
}

CComingUpThorn::~CComingUpThorn()
{
	Release();
}

void CComingUpThorn::Initialize(void)
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 140.f;

	m_eRender = RENDER_GAMEOBJECT;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/ComingUpThorn3.bmp", L"Thorn2");
	m_pFrameKey = L"Thorn2";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 180;
	m_tFrame.dwTime = GetTickCount();
}

int CComingUpThorn::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CComingUpThorn::Late_Update(void)
{
	//m_tInfo.fX -= 4.f;
	if(380 >= m_tInfo.fX - (m_tInfo.fCX * 0.5f))
	{
		MoveMoment_Frame();
	}
}

void CComingUpThorn::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC,
		int(m_tRect.left - 6 + iScrollX),
		int(m_tRect.top - 10 + iScrollY),
		62,
		160,
		hMemDC,
		m_tFrame.iFrameStart * 62,
		m_tFrame.iMotion * 160,
		62,
		160,
		RGB(255, 0, 255));

	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CComingUpThorn::Release(void)
{
}

void CComingUpThorn::OnCollision(CObj* other)
{
	if (other->CompareTag("player"))
	{
		dynamic_cast<CPlayer*>(other)->DownLife();
	}
}
