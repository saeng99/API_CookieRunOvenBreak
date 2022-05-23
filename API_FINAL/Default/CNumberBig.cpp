#include "stdafx.h"
#include "CNumberBig.h"
#include "BmpMgr.h"

CNumberBig::CNumberBig()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 45.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bignumber222.bmp", L"BigNumber");
	m_pFrameKey = L"BigNumber";
	m_iNum = 0;
}

CNumberBig::CNumberBig(float fX, float fY)
{
	m_tInfo.fX = fX;
	m_tInfo.fY = fY;

	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 45.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bignumber222.bmp", L"BigNumber");
	m_pFrameKey = L"BigNumber";
	m_iNum = 0;
}


CNumberBig::~CNumberBig()
{
}

void CNumberBig::Initialize(void)
{

}

int CNumberBig::Update(void)
{
	Update_Rect();
	return 0;
}

void CNumberBig::Late_Update(void)
{
}

void CNumberBig::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);


	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		m_tInfo.fX,	// 2,3 ���� :  ������� ��ġ X, Y
		m_tInfo.fY,
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		int(m_tInfo.fCX) * m_iNum,						// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 0, 255));
}

void CNumberBig::Release(void)
{
}

