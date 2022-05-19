#include "stdafx.h"
#include "MyMenu.h"
#include "BmpMgr.h"
#include "AbstractFactory.h"
#include "MyButton.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "Scene.h"

CMyMenu::CMyMenu()
{
}


CMyMenu::~CMyMenu()
{
	Release();
}

void CMyMenu::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/StartRun.bmp", L"StartRun");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Menu/CookieRun2.bmp", L"Menu");

	CObj* pButton = CAbstractFactory<CMyButton>::Create(400.f, 360.f);
	pButton->Set_FrameKey(L"StartRun");
	CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON, pButton);

	CSoundMgr::Get_Instance()->PlaySound(L"BGM Lobby New Party.wav", SOUND_MENU, g_fSound);
}

void CMyMenu::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CMyMenu::Late_Update(void)
{
	/*if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE);

		return;
	}*/
	CObjMgr::Get_Instance()->Late_Update();
}

void CMyMenu::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Menu");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CMyMenu::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BUTTON);
}
