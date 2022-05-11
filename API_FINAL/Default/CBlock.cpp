#include "stdafx.h"
#include "CBlock.h"

#include "SCrollMgr.h"
#include "Resource.h"
#include "BmpMgr.h"

CBlock::CBlock()
{
}

CBlock::~CBlock()
{
	Release();
}

void CBlock::Initialize(void)
{
	m_tInfo.fX = 50.f;		// 중점 X
	m_tInfo.fY = 430.f;		// 중점 Y

	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 1.f;
	m_Tag = "Block";

	m_eRender = RENDER_GAMEOBJECT;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Blockk.bmp", L"Block");

	m_pFrameKey = L"Block";
}

int CBlock::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CBlock::Late_Update(void)
{
}

void CBlock::Render(HDC hDC)
{
	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);
	
	//BitBlt(hDC,							// 복사 받을, 최종적으로 그림을 그릴 DC
	//	int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
	//	int(m_tRect.top),
	//	int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
	//	int(m_tInfo.fCY),
	//	hMemDC,							// 비트맵을 가지고 있는 DC
	//	0,								// 7, 8인자 : 비트맵을 출력할 시작 좌표, X,Y
	//	0,
	//	SRCCOPY);						// 출력효과, 그대로 복사 출력

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
}

void CBlock::Release(void)
{
}


