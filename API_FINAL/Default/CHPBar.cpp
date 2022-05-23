#include "stdafx.h"
#include "CHPBar.h"

#include "BmpMgr.h"
#include "SCrollMgr.h"
#include "Player.h"
#include "ObjMgr.h"

CHPBar::CHPBar()
{
}

CHPBar::~CHPBar()
{
	Release();
}

void CHPBar::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 30.f;

	m_tInfo.fCX = 380.f;
	m_tInfo.fCY = 14.f;

	m_eRender = RENDER_UI;
	//m_fGague = 0;
	//m_pTarget = nullptr;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/HeartBarBack22.bmp", L"HPBarBack");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/HeartBarFront.bmp", L"HPBar");
}
// 플레이어 체력을 얻어와서 그걸로 그린다 getplayer 캐스팅해서 가져오면 됨,,, update에서,,,
int CHPBar::Update(void)
{
	Update_Rect();

	return OBJ_NOEVENT;
}

void CHPBar::Late_Update(void)
{
	m_pTarget = CObjMgr::Get_Instance()->Get_Player();

	if (m_pTarget)
	{
		float a = dynamic_cast<CPlayer*>(m_pTarget)->Get_Hp();
		float b = dynamic_cast<CPlayer*>(m_pTarget)->Get_MaxHp();
		m_fGague = m_tInfo.fCX * (a / b);
	}
}

void CHPBar::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	/*m_pTarget = CObjMgr::Get_Instance()->Get_Player();

	if (m_pTarget)
	{
		float a = dynamic_cast<CPlayer*>(m_pTarget)->Get_Hp();
		float b = dynamic_cast<CPlayer*>(m_pTarget)->Get_MaxHp();
		m_fGague = m_tInfo.fCX * (a / b);
	}*/

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"HPBarBack");
	HDC		hHPMemDC = CBmpMgr::Get_Instance()->Find_Image(L"HPBar");

	//체력바 배경(회색)
	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		m_tRect.left - 10,	// 2,3 인자 :  복사받을 위치 X, Y
		m_tRect.top,
		410,
		30,
		hMemDC,
		0,
		0,
		410,
		30,
		RGB(255, 255, 255));			// 제거하고자 하는 색상

	//체력바 게이지(주황)
	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		m_tRect.left + 15,	// 2,3 인자 :  복사받을 위치 X, Y
		m_tRect.top + 8,
		(int)m_fGague, //m_fGague
		(int)m_tInfo.fCY,
		hHPMemDC,
		0,
		0,
		(int)m_fGague, // m_fGague
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CHPBar::Release(void)
{
}
