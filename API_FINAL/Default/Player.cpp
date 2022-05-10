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

float	g_fSound = 1.f;

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
	m_tInfo.fX = 100.f;
	m_tInfo.fY = 300.f;

	m_tInfo.fCX = 150.f;
	m_tInfo.fCY = 150.f;

	m_fSpeed = 5.f;

	m_fDiagonal = 100.f;

	m_bJump = false;
	m_fBeforeJump = false;
	m_fJumpPower = 10.f;
	m_fGravity = 9.8f;

	m_eRender = RENDER_GAMEOBJECT;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bright Cookie2.bmp", L"Player");

	m_pFrameKey = L"Player";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();

	//CSoundMgr::Get_Instance()->PlaySoundW(L"Success.wav", SOUND_EFFECT, g_fSound);

}

int CPlayer::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	// 연산을 진행
	Key_Input();
	Jumping();
	OffSet();

	

	// 모든 연산이 끝난 뒤에 최종적인 좌표를 완성
	Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update(void)
{
	CObj::UpdateGravity(m_fGravity);

	if (m_bJump)
	{
		m_tInfo.fY -= m_fJumpPower * sinf((90.f * PI) / 180.f);
	}
	
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

	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
			int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
			int(m_tRect.top + iScrollY),
			int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
			int(m_tInfo.fCY),
			hMemDC,							// 비트맵을 가지고 있는 DC
			m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// 비트맵 출력 시작 좌표, X,Y
			m_tFrame.iMotion * (int)m_tInfo.fCY,
			(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
			(int)m_tInfo.fCY,
			RGB(0, 128, 255));			// 제거하고자 하는 색상
				
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

	else if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
		m_pFrameKey = L"Player";
		m_eCurState = WALK;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
		m_pFrameKey = L"Player";
		m_eCurState = WALK;
	}

	else if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
	{
		if (!m_bJump)
		{
			m_bJump = true;
			m_fJumpPower = 10.f;
			//m_fGTime = 0.f;
			m_pFrameKey = L"Player";
			m_eCurState = JUMP;
			//CSoundMgr::Get_Instance()->PlaySound(L"Success.wav", SOUND_EFFECT, g_fSound);
		}

		else if (m_bJump && !m_fBeforeJump)
		{
			m_fJumpPower = 10.f;
			m_fGTime = 0.f;
			m_fBeforeJump = true;
			m_pFrameKey = L"Player";
			m_eCurState = JUMP;
		}

		return;
	}

	else if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		m_pFrameKey = L"Player";
		m_eCurState = SLIDE;
		//CSoundMgr::Get_Instance()->PlaySound(L"Success.wav", SOUND_EFFECT, g_fSound);

		return;
	}

	else
		m_eCurState = WALK;

}

void CPlayer::Jumping(void)
{
	float		fY = 0.f;

	bool		bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &fY);

	if (m_bJump)
	{
		m_tInfo.fY -= m_fJumpPower * m_fJumpTime - 9.8f * m_fJumpTime * m_fJumpTime * 0.3f;
		m_fJumpTime += 0.1f;

		if (bLineCol && (fY < m_tInfo.fY))
		{
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

void CPlayer::OnCollision(DIRECTION eDir, CObj* other)
{
	switch (eDir)
	{
	case DIR_UP:

		/*if (other->CompareTag("Monster"))
		{
			m_fJumpPower *= 0.9f;
			m_fGTime = 0.f;
			m_fGravity = 9.8f;
		}
		else
		{
			m_bOnBlock = true;
			m_bJump = false;
			m_fGravity = 9.8f;
		}
		break;*/

	case DIR_DOWN:
		m_fJumpPower = 0.f;
		break;

	case DIR_LEFT:
		/*if (other->CompareTag("Monster"))
		{

		}*/
		break;

	case DIR_RIGHT:
		/*if (other->CompareTag("Monster"))
		{
			//PostQuitMessage(0);
		}*/
		break;

	default:
		break;
	}
}
