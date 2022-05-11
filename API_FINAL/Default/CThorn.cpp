#include "stdafx.h"
#include "CThorn.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

CThorn::CThorn()
{
}

CThorn::~CThorn()
{
	Release();
}

void CThorn::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 346.f;
	
	m_tInfo.fCX = 44.f;
	m_tInfo.fCY = 70.f;

	m_eRender = RENDER_GAMEOBJECT;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Thorn2.bmp", L"Thorn");
	m_pFrameKey = L"Thorn";
}

int CThorn::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	
	Update_Rect();

	return OBJ_NOEVENT;
}

void CThorn::Late_Update(void)
{
}

void CThorn::Render(HDC hDC)
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

void CThorn::Release(void)
{
}
