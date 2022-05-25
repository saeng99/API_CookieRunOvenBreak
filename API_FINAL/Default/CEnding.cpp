#include "stdafx.h"
#include "CEnding.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "SoundMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

CEnding::CEnding()
{
}

CEnding::~CEnding()
{
	Release();
}

void CEnding::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ending.bmp", L"Ending");
	//CSoundMgr::Get_Instance()->PlaySoundW(L"loading_land1.wav", SOUND_TUTO, g_fSound);
	CSoundMgr::Get_Instance()->PlaySoundW(L"Eff_ingame_rank_1_1017_last.wav", SOUND_ENDING, g_fSound);
}

void CEnding::Update(void)
{
}

void CEnding::Late_Update(void)
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_SCOREBOARD);

		return;
	}
}

void CEnding::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Ending");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CEnding::Release(void)
{
	CSoundMgr::Get_Instance()->StopSound(SOUND_ENDING);
}
