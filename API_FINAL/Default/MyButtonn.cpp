#include "stdafx.h"
#include "MyButtonn.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"

CMyButtonn::CMyButtonn()
    : m_iDrawID(0)
{
	Initialize();
}

CMyButtonn::~CMyButtonn()
{
    Release();
}

void CMyButtonn::Initialize(void)
{
    m_tInfo.fCX = 200.f;
	m_tInfo.fCY = 70.f;

    m_eRender = RENDER_UI;
}

int CMyButtonn::Update(void)
{
    if (m_bDead)
        return OBJ_DEAD;

    Update_Rect();

    return OBJ_NOEVENT;
}

void CMyButtonn::Late_Update(void)
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			 if (!lstrcmp(L"Playbutton", m_pFrameKey))
			{
				 CSoundMgr::Get_Instance()->PlaySoundW(L"SoundEff_Button.wav", SOUND_BUTTON, g_fSound);
				 CSceneMgr::Get_Instance()->Scene_Resur(SC_TUTORIAL);
				CSoundMgr::Get_Instance()->StopSound(SOUND_MENU);
			}
			return;
		}

		m_iDrawID = 1;
	}

	else
		m_iDrawID = 0;


}

void CMyButtonn::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		int(m_tInfo.fCX) * m_iDrawID,	// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 0, 255));			// �����ϰ��� �ϴ� ����
}

void CMyButtonn::Release(void)
{
}
