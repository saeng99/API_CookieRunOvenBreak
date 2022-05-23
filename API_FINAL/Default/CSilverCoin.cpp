#include "stdafx.h"
#include "CSilverCoin.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"
#include "CGameMgr.h"

CSilverCoin::CSilverCoin()
{
}

CSilverCoin::~CSilverCoin()
{
    Release();
}

void CSilverCoin::Initialize(void)
{
	m_tInfo.fCX = 23.f;
	m_tInfo.fCY = 23.f;

	m_eRender = RENDER_GAMEOBJECT;
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Item/SilverCoin.bmp", L"SilverCoin");
	m_pFrameKey = L"SilverCoin";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 180;
	m_tFrame.dwTime = GetTickCount();

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Item/Effect2.bmp", L"Effect");
}

int CSilverCoin::Update(void)
{

	Update_Rect();

	return OBJ_NOEVENT;
}

void CSilverCoin::Late_Update(void)
{
	//m_tInfo.fX -= 4.f;
	Move_Frame();
}

void CSilverCoin::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (m_bDead)
	{
		HDC		hEffectMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Effect");

		GdiTransparentBlt(hDC,
			int(m_tRect.left - 100 + iScrollX),
			int(m_tRect.top + iScrollY),
			56,
			30,
			hEffectMemDC,
			0,
			0,
			56,
			30,
			RGB(255, 255, 255));
	}
	
	else
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC,
			int(m_tRect.left - 3 + iScrollX),
			int(m_tRect.top - 3 + iScrollY),
			29,
			29,
			hMemDC,
			m_tFrame.iFrameStart * 29,
			m_tFrame.iMotion * 29,
			29,
			29,
			RGB(255, 0, 255));
	}
	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CSilverCoin::Release(void)
{
}

void CSilverCoin::OnCollision(CObj* other)
{
	Set_Dead();
	CGameMgr::Get_Instance()->PlusSilverCoin();
	CSoundMgr::Get_Instance()->PlaySoundW(L"SoundEff_GetCoinJelly.wav", SOUND_COINEFFECT, g_fSound);
}
