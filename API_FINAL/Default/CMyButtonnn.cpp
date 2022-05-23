#include "stdafx.h"
#include "CMyButtonnn.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"

CMyButtonnn::CMyButtonnn()
	: m_iDrawID(0)
{
	Initialize();
}

CMyButtonnn::~CMyButtonnn()
{
	Release();
}

void CMyButtonnn::Initialize(void)
{
	m_tInfo.fCX = 200.f;
	m_tInfo.fCY = 69.f;

	m_eRender = RENDER_UI;
}

int CMyButtonnn::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CMyButtonnn::Late_Update(void)
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			if (!lstrcmp(L"Checkbutton", m_pFrameKey))
			{
				CSoundMgr::Get_Instance()->PlaySoundW(L"SoundEff_Button.wav", SOUND_BUTTON, g_fSound);
				CSceneMgr::Get_Instance()->Scene_Resur(SC_LOBY);
				CSoundMgr::Get_Instance()->StopSound(SOUND_STAGE);
			}
			return;
		}

		m_iDrawID = 1;
	}

	else
		m_iDrawID = 0;
}

void CMyButtonnn::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		int(m_tInfo.fCX) * m_iDrawID,	// 비트맵 출력 시작 좌표, X,Y
		0,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 0, 255));			// 제거하고자 하는 색상
}

void CMyButtonnn::Release(void)
{
}
