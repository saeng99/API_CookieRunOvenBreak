#include "stdafx.h"
#include "CScoreBoard.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "SoundMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "AbstractFactory.h"
#include "CMyButtonnn.h"
#include "CGameMgr.h"

CScoreBoard::CScoreBoard()
{
}

CScoreBoard::~CScoreBoard()
{
	Release();
}

void CScoreBoard::Initialize(void)
{
	CGameMgr::Get_Instance()->Initialize();
	CGameMgr::Get_Instance()->Set_iScore();

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/check_button.bmp", L"Checkbutton");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/score_board_fixed.bmp", L"ScoreBoard");
	CObj* pButton = CAbstractFactory<CMyButtonnn>::Create(400.f, 400.f);
	pButton->Set_FrameKey(L"Checkbutton");
	CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON, pButton);

	CSoundMgr::Get_Instance()->PlaySoundW(L"result_2.wav", SOUND_SCORE, g_fSound);
}

void CScoreBoard::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	CGameMgr::Get_Instance()->Update();
}

void CScoreBoard::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
	CGameMgr::Get_Instance()->Late_Update();

}

void CScoreBoard::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"ScoreBoard");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
	CGameMgr::Get_Instance()->Render(hDC);
}

void CScoreBoard::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BUTTON);
	CGameMgr::Get_Instance()->Destroy_Instance();
	CSoundMgr::Get_Instance()->StopSound(SOUND_SCORE);
}
