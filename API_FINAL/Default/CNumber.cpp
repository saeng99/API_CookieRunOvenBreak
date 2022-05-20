#include "stdafx.h"
#include "CNumber.h"
#include "BmpMgr.h"

CNumber::CNumber()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/number22.bmp", L"Number");
	m_pFrameKey = L"Number";
	m_iNum = 0;
}

CNumber::CNumber(float fX, float fY)
{
	m_tInfo.fX = fX;
	m_tInfo.fY = fY;

	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/number22.bmp", L"Number");
	m_pFrameKey = L"Number";
	m_iNum = 0;
}


CNumber::~CNumber()
{
}

void CNumber::Initialize(void)
{

}

int CNumber::Update(void)
{
	Update_Rect();
	return 0;
}

void CNumber::Late_Update(void)
{
}

void CNumber::Render(HDC hDC)
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
		RGB(63, 72, 204));
}

void CNumber::Release(void)
{
}

