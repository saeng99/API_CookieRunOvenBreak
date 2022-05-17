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
	//m_tInfo.fX -= 4.f;
}

void CBlock::Render(HDC hDC)
{
	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);
	
	//BitBlt(hDC,							// ���� ����, ���������� �׸��� �׸� DC
	//	int(m_tRect.left + iScrollX),	// 2,3 ���� :  ������� ��ġ X, Y
	//	int(m_tRect.top),
	//	int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
	//	int(m_tInfo.fCY),
	//	hMemDC,							// ��Ʈ���� ������ �ִ� DC
	//	0,								// 7, 8���� : ��Ʈ���� ����� ���� ��ǥ, X,Y
	//	0,
	//	SRCCOPY);						// ���ȿ��, �״�� ���� ���

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


