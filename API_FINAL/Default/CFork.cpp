#include "stdafx.h"
#include "CFork.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

CFork::CFork()
{
}

CFork::~CFork()
{
	Release();
}

void CFork::Initialize(void)
{
	m_tInfo.fX = 600.f;
	m_tInfo.fY = 165.f;

	m_tInfo.fCX = 88.f;
	m_tInfo.fCY = 320.f;

	m_eRender = RENDER_GAMEOBJECT;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Fork2.bmp", L"Fork");
	m_pFrameKey = L"Fork";
}

int CFork::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CFork::Late_Update(void)
{
}

void CFork::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC,
		int(m_tRect.left + iScrollX),
		int(m_tRect.top + iScrollY),
		int(m_tInfo.fCX),
		int(m_tInfo.fCY),
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 0, 255));

	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}


void CFork::Release(void)
{
}
