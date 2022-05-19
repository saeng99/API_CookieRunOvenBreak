#include "stdafx.h"
#include "CFork.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "Player.h"

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
	m_tInfo.fY = 160.f;

	m_tInfo.fCX = 66.f;
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
	m_tInfo.fX -= 4.f;
}

void CFork::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC,
		int(m_tRect.left - 11 + iScrollX),
		int(m_tRect.top + iScrollY),
		88,
		320,
		hMemDC,
		0,
		0,
		88,
		320,
		RGB(255, 0, 255));

	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}


void CFork::Release(void)
{
}

void CFork::OnCollision(CObj* other)
{
	//if (other->CompareTag("player"))
	//{
	//	dynamic_cast<CPlayer*>(other)->DownLife();
	//}
}
