#include "stdafx.h"
#include "CGoldenCoin.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

CGoldenCoin::CGoldenCoin()
{
}

CGoldenCoin::~CGoldenCoin()
{
    Release();
}

void CGoldenCoin::Initialize(void)
{
	m_tInfo.fCX = 28.f;
	m_tInfo.fCY = 28.f;

	m_eRender = RENDER_GAMEOBJECT;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Item/GoldCoin.bmp", L"GoldCoin");
	m_pFrameKey = L"GoldCoin";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 5;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 180;
	m_tFrame.dwTime = GetTickCount();
}

int CGoldenCoin::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CGoldenCoin::Late_Update(void)
{
	//m_tInfo.fX -= 4.f;
	Move_Frame();
}

void CGoldenCoin::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC,
		int(m_tRect.left - 2 + iScrollX),
		int(m_tRect.top - 2 + iScrollY),
		32,
		32,
		hMemDC,
		m_tFrame.iFrameStart * 32,
		m_tFrame.iMotion * 32,
		32,
		32,
		RGB(255, 0, 255));

	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CGoldenCoin::Release(void)
{
}
