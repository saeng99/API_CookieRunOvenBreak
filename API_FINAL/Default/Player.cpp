#include "stdafx.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "Shield.h"
#include "ScrewBullet.h"
#include "GuideBullet.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
#include "SceneMgr.h"

//float	g_fSound = 1.f;

CPlayer::CPlayer()
	: m_eCurState(IDLE), m_ePreState(END)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	//m_tInfo.fX = 150.f;
	//m_tInfo.fY = 345.f;

	m_tInfo.fCX = 60.f;
	m_tInfo.fCY = 70.f;

	m_fSpeed = 5.f;
	m_tStatInfo.iMaxHp = 100;
	m_tStatInfo.iHp = m_tStatInfo.iMaxHp;

	m_fDiagonal = 100.f;
	m_Tag = "player";

	m_bJump = false;
	m_fBeforeJump = false;
	m_fJumpPower = 9.3f;
	m_fGravity = 9.8f;
	m_fJumpTime = 0.f;

	m_bHit = false;
	m_bHitMotion = false;
	m_bHitMotionEnd = false;
	m_dwHitTime = long(0);
	m_dwHitMotionTime = long(0);


	m_eRender = RENDER_GAMEOBJECT;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bright Cookie2.bmp", L"Player");

	m_pFrameKey = L"Player";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 8;
	m_tFrame.iMotion = 1;
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();

}

int CPlayer::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	
	// 연산을 진행
	Key_Input();
	Jumping();
	OffSet();

	Hit();
		

	if (m_tStatInfo.iHp <= 0)
	{
		Set_Dead();
		m_eCurState = DEAD;
	}


	// 모든 연산이 끝난 뒤에 최종적인 좌표를 완성
	Update_Rect();
	m_tStatInfo.iHp -= 0.04f;

	m_hp = m_tStatInfo.iHp;
	m_maxhp = m_tStatInfo.iMaxHp;
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update(void)
{
	Motion_Change();
	Move_Frame();
}

void CPlayer::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);
	
	/*BitBlt(hDC,							// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top), 
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY), 
		hMemDC,							// 비트맵을 가지고 있는 DC
		0,								// 7, 8인자 : 비트맵을 출력할 시작 좌표, X,Y
		0, 
		SRCCOPY);*/						// 출력효과, 그대로 복사 출력
	if (m_eCurState == SLIDE)
	{
		GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
			int(m_tRect.left - 45 + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
			int(m_tRect.top - 104 + iScrollY),
			150,				// 4,5 인자 : 복사받을 가로, 세로 길이
			150,
			hMemDC,							// 비트맵을 가지고 있는 DC
			m_tFrame.iFrameStart * 150,								// 비트맵 출력 시작 좌표, X,Y
			m_tFrame.iMotion * 150,
			150,				// 복사할 비트맵의 가로, 세로 길이
			150,
			RGB(0, 128, 255));			// 제거하고자 하는 색상
	}
	
	else
	{
		GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
			int(m_tRect.left - 45 + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
			int(m_tRect.top - 80 + iScrollY),
			150,				// 4,5 인자 : 복사받을 가로, 세로 길이
			150,
			hMemDC,							// 비트맵을 가지고 있는 DC
			m_tFrame.iFrameStart * 150,								// 비트맵 출력 시작 좌표, X,Y
			m_tFrame.iMotion * 150,
			150,				// 복사할 비트맵의 가로, 세로 길이
			150,
			RGB(0, 128, 255));			// 제거하고자 하는 색상
	}

	//Rectangle(hDC, m_tInfo.fX - (m_tInfo.fCX * 0.5f), m_tInfo.fY - (m_tInfo.fCY * 0.5f), m_tInfo.fX + (m_tInfo.fCX * 0.5f), m_tInfo.fY + (m_tInfo.fCY * 0.5f));

}
void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	float	fY = 0.f;

	// GetKeyState
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		m_pFrameKey = L"Player";
		m_eCurState = WALK;

		if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY))
			m_tInfo.fY = fY - (m_tInfo.fCY * 0.5f);

	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
		m_pFrameKey = L"Player";
		m_eCurState = WALK;

		if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY))
			m_tInfo.fY = fY - (m_tInfo.fCY * 0.5f);
	}

	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
	{
		m_pFrameKey = L"Player";
		m_eCurState = SLIDE;
		CSoundMgr::Get_Instance()->PlaySoundW(L"Ch03slide.wav", SOUND_RUN, g_fSound);
		m_tFrame.iFrameStart = 9;
		m_tInfo.fCY = 46.f;
		return;
	}

	else if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		if (!m_bJump)
		{
			m_bJump = true;
			//m_fJumpPower = 10.f;
			//m_fGTime = 0.f;
			m_fJumpTime = 0.f;
			m_pFrameKey = L"Player";
			m_eCurState = JUMP;
			CSoundMgr::Get_Instance()->PlaySoundW(L"Ch03jump.wav", SOUND_RUN, g_fSound);
		}

		else if (m_bJump && !m_fBeforeJump)
		{
			//m_fJumpPower = 10.f;
			m_fJumpTime = 0.f;
			//m_fGTime = 0.f;
			m_fBeforeJump = true;
			//m_pFrameKey = L"Player";
			m_eCurState = JUMP;
			CSoundMgr::Get_Instance()->PlaySoundW(L"Ch03jump.wav", SOUND_RRUN, g_fSound);
		}

		return;
	}

	else
		m_eCurState = WALK;
		m_tInfo.fCY = 70.f;

}

void CPlayer::Jumping(void)
{
	float		fY = 0.f;

	bool		bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY);

	if (m_bJump)
	{
		m_tInfo.fY -= m_fJumpPower * m_fJumpTime - 9.8f * m_fJumpTime * m_fJumpTime * 0.35f;
		m_fJumpTime += 0.1f;
		m_eCurState = JUMP;

		if (bLineCol && (fY < m_tInfo.fY))
		{
			//m_eCurState = WALK;
			m_bJump = false;
			m_fBeforeJump = false;
			m_fJumpTime = 0.f;
			m_tInfo.fY = fY - (m_tInfo.fCY * 0.5f);
		}
	}
	else if (bLineCol)
	{
		m_tInfo.fY = fY - (m_tInfo.fCY * 0.5f);
	}
}

void CPlayer::OffSet(void)
{
	int		iOffSetX = WINCX >> 1;
	int		iOffSetY = WINCY >> 1;
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	int		iItvX = 300;
	int		iItvY = 200;

	if (iOffSetX - iItvX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffSetX + iItvX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);
	
	if (iOffSetY - iItvY > m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);

	if (iOffSetY + iItvY < m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);
}

void CPlayer::Motion_Change(void)
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case IDLE:
			m_tFrame.iFrameStart = 1;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iMotion = 2;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();

			break;

		case WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 7;
			m_tFrame.iMotion = 1;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;

		case JUMP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 8;
			m_tFrame.iMotion = 0;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;

		case SLIDE:
			m_tFrame.iFrameStart = 9;
			m_tFrame.iFrameEnd = 10;
			m_tFrame.iMotion = 0;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;

		case HIT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 4;
			m_tFrame.iMotion = 4;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;

		case DEAD:
			m_tFrame.iFrameStart = 5;
			m_tFrame.iFrameEnd = 8;
			m_tFrame.iMotion = 4;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
		}

		m_ePreState = m_eCurState;
	}
}

void CPlayer::UpLife()
{
	m_tStatInfo.iHp += 10.f;
	CObjMgr::Get_Instance()->SetHPBar(m_tStatInfo.iHp);
}

void CPlayer::DownLife()
{
	m_tStatInfo.iHp -= 5.f;
	CObjMgr::Get_Instance()->SetHPBar(m_tStatInfo.iHp);
}

void CPlayer::Hit()
{
	if (m_bHit)
	{
		if (!m_dwHitTime)
			m_dwHitTime = GetTickCount();

		if (!m_dwHitMotionTime)
			m_dwHitMotionTime = GetTickCount();

		m_eCurState = WALK;

			if (m_bHitMotion && m_bHitMotionEnd)
			m_eCurState = HIT;

		if (GetTickCount() - m_dwHitMotionTime > 600)
		{
			m_eCurState = WALK;
			m_dwHitMotionTime = GetTickCount();
			m_bHitMotion = false;
		}

		if (GetTickCount() - m_dwHitTime > 1200)
		{
			m_bHit = false;
			m_bHitMotionEnd = false;
			m_dwHitTime = GetTickCount();
		}
	}
	
}

void CPlayer::OnCollision(CObj* other)
{
	if (!m_bHit)
	{
		DownLife();

		m_bHit = true;
		m_bHitMotion = true;
		m_bHitMotionEnd = true;

		m_dwHitMotionTime = GetTickCount();
		m_dwHitTime = GetTickCount();
	}
}


