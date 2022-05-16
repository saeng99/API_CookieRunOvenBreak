#include "stdafx.h"
#include "CHPPotion.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

CHPPotion::CHPPotion()
{
}

CHPPotion::~CHPPotion()
{
	Release();
}

void CHPPotion::Initialize(void)
{
	m_tInfo.fCX = 36.f;
	m_tInfo.fCY = 36.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Item/Booster2.bmp", L"HPPotion");
	m_pFrameKey = L"HPPotion";
	m_eRender = RENDERID::RENDER_GAMEOBJECT;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iMotion = 3;
	m_tFrame.dwSpeed = 180;
	m_tFrame.dwTime = GetTickCount();
}

int CHPPotion::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CHPPotion::Late_Update(void)
{
	m_tInfo.fX -= 4.f;

	Move_Frame();
}

void CHPPotion::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC,
		int(m_tRect.left + iScrollX),
		int(m_tRect.top + iScrollY),
		36,
		36,
		hMemDC,
		m_tFrame.iFrameStart * 36,
		m_tFrame.iMotion * 36,
		36,
		36,
		RGB(255, 0, 255));
}

void CHPPotion::Release(void)
{
}
