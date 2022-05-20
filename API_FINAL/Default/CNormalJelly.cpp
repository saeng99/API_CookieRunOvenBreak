#include "stdafx.h"
#include "CNormalJelly.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"
#include "Scene.h"
#include "CGameMgr.h"

CNormalJelly::CNormalJelly()
{
}

CNormalJelly::~CNormalJelly()
{
    Release();
}

void CNormalJelly::Initialize(void)
{
	m_tInfo.fCX = 24.f;
	m_tInfo.fCY = 24.f;

	m_eRender = RENDER_GAMEOBJECT;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Item/Jelly.bmp", L"Jelly");

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Item/Effect2.bmp", L"Effect");
	m_pFrameKey = L"Effect";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 180;
	m_tFrame.dwTime = GetTickCount();


}

int CNormalJelly::Update(void)
{
	
	Update_Rect();

	return OBJ_NOEVENT;
}

void CNormalJelly::Late_Update(void)
{
	m_tInfo.fX -= 4.f;

	Move_Frame();
}

void CNormalJelly::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (m_bDead)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC,
			int(m_tRect.left - 100 + iScrollX),
			int(m_tRect.top + iScrollY),
			56,
			30,
			hMemDC,
			m_tFrame.iFrameStart * 56,
			m_tFrame.iMotion * 30,
			56,
			30,
			RGB(255, 255, 255));
	}

	else
	{
		HDC		hJellyMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Jelly");

		// 젤리 업그레이드의 경우 바뀌게 설정필요

		GdiTransparentBlt(hDC,
			int(m_tRect.left - 3 + iScrollX),
			int(m_tRect.top - 3 + iScrollY),
			30,
			30,
			hJellyMemDC,
			0,
			0,
			30,
			30,
			RGB(255, 0, 255));

		//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));

	}
}

void CNormalJelly::Release(void)
{
}

void CNormalJelly::OnCollision(CObj* other)
{
	Set_Dead();
	CGameMgr::Get_Instance()->PlusJelly();
	CSoundMgr::Get_Instance()->PlaySoundW(L"SoundEff_GetJelly.wav", SOUND_JELLYEFFECT, g_fSound);
}
