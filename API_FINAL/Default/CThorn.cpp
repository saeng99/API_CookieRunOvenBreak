#include "stdafx.h"
#include "CThorn.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "Player.h"

CThorn::CThorn()
{
}

CThorn::~CThorn()
{
	Release();
}

void CThorn::Initialize(void)
{
	m_tInfo.fCX = 32.f;
	m_tInfo.fCY = 48.f;

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
	//m_tInfo.fX-= 4.f;
}

void CThorn::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC,
		int(m_tRect.left - 6 + iScrollX),
		int(m_tRect.top - 11 + iScrollY),
		44,
		70,
		hMemDC,
		0,
		0,
		44,
		70,
		RGB(255, 0, 255));

	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CThorn::Release(void)
{
}

void CThorn::OnCollision(CObj* other)
{
	//if (other->CompareTag("player"))
	//{
	//	dynamic_cast<CPlayer*>(other)->DownLife();
	//}
}
