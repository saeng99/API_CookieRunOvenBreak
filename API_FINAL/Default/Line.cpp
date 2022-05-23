#include "stdafx.h"
#include "Line.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"


CLine::CLine()
	: m_tInfo()
{
}


CLine::CLine(LINEPOINT& tLeft, LINEPOINT& tRight)
	: m_tInfo(tLeft, tRight)
{

}

CLine::CLine(LINE tLine)
	: m_tInfo(tLine)
{

}

CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	if (CSceneMgr::Get_Instance()->Get_SceneID() == SC_STAGE)
	{
		MoveToEx(hDC, (int)m_tInfo.tLPoint.fX + iScrollX, (int)m_tInfo.tLPoint.fY, nullptr);
		LineTo(hDC, (int)m_tInfo.tRPoint.fX + iScrollX, (int)m_tInfo.tRPoint.fY);
	}
	else if (CSceneMgr::Get_Instance()->Get_SceneID() == SC_LOBY)
	{
		MoveToEx(hDC, (int)m_tInfo.tLPoint.fX, (int)m_tInfo.tLPoint.fY, nullptr);
		LineTo(hDC, (int)m_tInfo.tRPoint.fX, (int)m_tInfo.tRPoint.fY);
	}
}
