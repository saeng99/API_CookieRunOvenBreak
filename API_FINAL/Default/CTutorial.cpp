#include "stdafx.h"
#include "CTutorial.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "SoundMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

CTutorial::CTutorial()
{
}

CTutorial::~CTutorial()
{
	Release();
}

void CTutorial::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/fix1.bmp", L"Tutorial");
	CSoundMgr::Get_Instance()->PlaySoundW(L"loading_land1.wav", SOUND_TUTO, g_fSound);
}

void CTutorial::Update(void)
{
}

void CTutorial::Late_Update(void)
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE);

		return;
	}
}

void CTutorial::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Tutorial");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CTutorial::Release(void)
{
	CSoundMgr::Get_Instance()->StopSound(SOUND_TUTO);
}
