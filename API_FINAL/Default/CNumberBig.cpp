#include "stdafx.h"
#include "CNumberBig.h"
#include "BmpMgr.h"

CNumberBig::CNumberBig()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 45.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bignumber2222.bmp", L"BigNumber");
	m_pFrameKey = L"BigNumber";
	m_iNum = 0;
}

CNumberBig::CNumberBig(float fX, float fY)
{
	m_tInfo.fX = fX;
	m_tInfo.fY = fY;

	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 45.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bignumber2222.bmp", L"BigNumber");
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


	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		m_tInfo.fX,	// 2,3 인자 :  복사받을 위치 X, Y
		m_tInfo.fY,
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		int(m_tInfo.fCX) * m_iNum,						// 비트맵 출력 시작 좌표, X,Y
		0,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 0, 255));
}

void CNumberBig::Release(void)
{
}

