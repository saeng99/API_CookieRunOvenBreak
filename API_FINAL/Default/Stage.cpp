#include "stdafx.h"
#include "Stage.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "ScrollMgr.h"
#include "TileMgr.h"
#include "Monster.h"


CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize(void)
{

	/*for (int i = 0; i < 5; ++i)
	{
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(rand() % WINCX, rand() % WINCY));
	}*/
	//CLineMgr::Get_Instance()->Initialize();

	//CTileMgr::Get_Instance()->Load_Tile();

	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	//CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create());
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Oven22.bmp", L"Ground");

}	


void CStage::Update(void)
{
	CObjMgr::Get_Instance()->Update();	
	//CTileMgr::Get_Instance()->Update();

}

void CStage::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
	//CTileMgr::Get_Instance()->Late_Update();

}

void CStage::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Ground");
	
	BitBlt(hDC, iScrollX, 0, 1619, WINCY, hGroundMemDC, 0, 0, SRCCOPY);
	/*BitBlt(hDC,							// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		0,								// 7, 8인자 : 비트맵을 출력할 시작 좌표, X,Y
		0,
		SRCCOPY);*/						// 출력효과, 그대로 복사 출력
	
	//CTileMgr::Get_Instance()->Render(hDC);

	//CLineMgr::Get_Instance()->Render(hMemDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
	CTileMgr::Get_Instance()->Destroy_Instance();

	CObjMgr::Get_Instance()->Delete_ID(OBJ_MONSTER);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BULLET);
}
