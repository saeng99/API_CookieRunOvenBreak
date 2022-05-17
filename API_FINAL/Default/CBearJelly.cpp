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
	
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Item/Effect2.bmp", L"Effect");
	m_pFrameKey = L"Effect";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 180;
	m_tFrame.dwTime = GetTickCount();
}

int CBearJelly::Update(void)
{
	
	Update_Rect();

	return OBJ_NOEVENT;
}

void CBearJelly::Late_Update(void)
{
	//m_tInfo.fX -= 4.f;

	Move_Frame();
}

void CBearJelly::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (m_bDead)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC,
			int(m_tRect.left - 100 + iScrollX),
			int(m_tRect.top + iScrollY),
			56,
			30,
			hMemDC,
			m_tFrame.iFrameStart * 56,
			m_tFrame.iMotion * 30,
			56,
			30,
			RGB(255, 255, 255));
	}

	else
	{
		HDC		hJellyMemDC = CBmpMgr::Get_Instance()->Find_Image(L"BearJelly");

		GdiTransparentBlt(hDC,
			int(m_tRect.left - 5 + iScrollX),
			int(m_tRect.top - 5 + iScrollY),
			32,
			32,
			hJellyMemDC,
			0,
			0,
			32,
			32,
			RGB(255, 0, 255));
	}
	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CBearJelly::Release(void)
{
}
