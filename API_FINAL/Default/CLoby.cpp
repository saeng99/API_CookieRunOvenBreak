#include "stdafx.h"
#include "CLoby.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "SoundMgr.h"
#include "MyButtonn.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "LineMgr.h"

CLoby::CLoby()
{
}

CLoby::~CLoby()
{
	Release();
}

void CLoby::Initialize(void)
{
	CLineMgr::Get_Instance()->Initialize();

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/PlayButtonnn.bmp", L"Playbutton");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Loby.bmp", L"Loby");
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(400.f, 250.f));

	CObj* pButton = CAbstractFactory<CMyButtonn>::Create(620.f, 390.f);
	pButton->Set_FrameKey(L"Playbutton");
	CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON, pButton);

	CSoundMgr::Get_Instance()->PlaySoundW(L"BGM Lobby Ovenbreak.wav", SOUND_LOBY, g_fSound);
}

void CLoby::Update(void)
{
	CObjMgr::Get_Instance()->Update();


}

void CLoby::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CLoby::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Loby");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
	CLineMgr::Get_Instance()->Render(hDC);

}

void CLoby::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BUTTON);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_PLAYER);
	CSoundMgr::Get_Instance()->StopSound(SOUND_LOBY);
	CLineMgr::Get_Instance()->Destroy_Instance();

}
