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

void CNumber::Release(void)
{
}

