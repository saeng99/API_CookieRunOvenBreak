#include "stdafx.h"
#include "GuideBullet.h"
#include "ObjMgr.h"


CGuideBullet::CGuideBullet()
{
}


CGuideBullet::~CGuideBullet()
{
	Release();}


void CGuideBullet::Initialize(void)
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CGuideBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	m_pTarget = CObjMgr::Get_Instance()->Get_Target(OBJ_MONSTER, this);

	if (m_pTarget)
	{
		float		fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
		float		fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

		float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
		float		fRadian = acosf(fWidth / fDiagonal);

		m_fAngle = fRadian * 180.f / PI;

		if (m_tInfo.fY < m_pTarget->Get_Info().fY)
			m_fAngle *= -1.f;
	}

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
	
	Update_Rect();

	return OBJ_NOEVENT;
}

void CGuideBullet::Late_Update(void)
{
	
}

void CGuideBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CGuideBullet::Release(void)
{
	
}
