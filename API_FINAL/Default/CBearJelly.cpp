#include "stdafx.h"
#include "CBearJelly.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

CBearJelly::CBearJelly()
{
}

CBearJelly::~CBearJelly()
{
    Release();
}

void CBearJelly::Initialize(void)
{
	m_tInfo.fCX = 26.f;
	m_tInfo.fCY = 26.f;

	m_eRender = RENDER_GAMEOBJECT;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Item/BearJelly.bmp", L"BearJelly");
	m_pFrameKey = L"BearJelly";
}

int CBearJelly::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CBearJelly::Late_Update(void)
{
	//m_tInfo.fX -= 4.f;
}

void CBearJelly::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	// 젤리 업그레이드의 경우 바뀌게 설정필요

	GdiTransparentBlt(hDC,
		int(m_tRect.left - 5 + iScrollX),
		int(m_tRect.top - 5 + iScrollY),
		32,
		32,
		hMemDC,
		0,
		0,
		32,
		32,
		RGB(255, 0, 255));

	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CBearJelly::Release(void)
{
}
