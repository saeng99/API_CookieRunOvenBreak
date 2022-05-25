#include "stdafx.h"
#include "CBlockk.h"

#include "SCrollMgr.h"
#include "Resource.h"
#include "BmpMgr.h"


CBlockk::CBlockk()
{
}

CBlockk::~CBlockk()
{
	Release();
}

void CBlockk::Initialize(void)
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 40.f;

	m_fSpeed = 1.f;
	m_Tag = "Block";

	m_eRender = RENDER_GAMEOBJECT;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Block2.bmp", L"Block2");

	m_pFrameKey = L"Block2";
}

int CBlockk::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CBlockk::Late_Update(void)
{
}

void CBlockk::Render(HDC hDC)
{
	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

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
		RGB(255, 4, 255));
}

void CBlockk::Release(void)
{
}
