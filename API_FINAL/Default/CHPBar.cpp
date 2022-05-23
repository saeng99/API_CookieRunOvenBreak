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
// �÷��̾� ü���� ���ͼ� �װɷ� �׸��� getplayer ĳ�����ؼ� �������� ��,,, update����,,,
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

	//ü�¹� ���(ȸ��)
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		m_tRect.left - 10,	// 2,3 ���� :  ������� ��ġ X, Y
		m_tRect.top,
		410,
		30,
		hMemDC,
		0,
		0,
		410,
		30,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����

	//ü�¹� ������(��Ȳ)
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		m_tRect.left + 15,	// 2,3 ���� :  ������� ��ġ X, Y
		m_tRect.top + 8,
		(int)m_fGague, //m_fGague
		(int)m_tInfo.fCY,
		hHPMemDC,
		0,
		0,
		(int)m_fGague, // m_fGague
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CHPBar::Release(void)
{
}
