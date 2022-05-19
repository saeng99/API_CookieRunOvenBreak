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

CLoby::CLoby()
{
}

CLoby::~CLoby()
{
	Release();
}

void CLoby::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/playbutton22.bmp", L"Playbutton");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Loby.bmp", L"Loby");
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(400.f, 250.f));


	CObj* pButton = CAbstractFactory<CMyButtonn>::Create(650.f, 370.f);
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
	// �÷��� ��ư ��� ���з� �ӽ÷� �־��
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Resur(SC_STAGE);

		return;
	}
	
	CObjMgr::Get_Instance()->Late_Update();
}

void CLoby::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Loby");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CLoby::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BUTTON);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_PLAYER);
	CSoundMgr::Get_Instance()->StopSound(SOUND_LOBY);
}
