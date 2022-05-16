#include "stdafx.h"
#include "Stage.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Player.h"
#include "ScrollMgr.h"
#include "TileMgr.h"
#include "Monster.h"
#include "CThorn.h"
#include "CFork.h"
#include "CBlock.h"
#include "CComingUpThorn.h"
#include "CNormalJelly.h"
#include "CBearJelly.h"
#include "CSilverCoin.h"
#include "CGoldenCoin.h"
#include "CHPBar.h"
#include "CHPPotion.h"

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
	CObjMgr::Get_Instance()->Add_Object(OBJ_HPBAR, CAbstractFactory<CHPBar>::Create());

	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());

	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(50.f,430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(1950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(2950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(3950.f, 430.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(550.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(1170.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(1214.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(2420.f, 346.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CComingUpThorn>::Create(1640.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CComingUpThorn>::Create(2720.f, 300.f));
										
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(800.f,160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(888.f,160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(2000.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(2178.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(3088.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(3176.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(3264.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(3362.f, 160.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(300.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(340.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(380.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(420.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(460.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(500.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(520.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(550.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(580.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(600.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(640.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(680.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(720.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(760.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(800.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(840.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(880.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(920.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(960.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1000.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1040.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1080.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1120.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1140.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1170.f, 230.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1210.f, 230.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1240.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1260.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1300.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1340.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1380.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1420.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1460.f, 350.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(200.f, 352.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(240.f, 352.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(280.f, 352.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_BOOSTER, CAbstractFactory<CHPPotion>::Create(280.f, 350.f));

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Oven222.bmp", L"Ground");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Fireplz2.bmp", L"Fire");
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
	HDC		hFireMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Fire");
	
	BitBlt(hDC, iScrollX, 0, 2428, WINCY, hGroundMemDC, 0, 0, SRCCOPY);
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
		iScrollX,	// 2,3 인자 :  복사받을 위치 X, Y
		0,
		2428,				// 4,5 인자 : 복사받을 가로, 세로 길이
		450,
		hFireMemDC,							// 비트맵을 가지고 있는 DC
		0,	// 비트맵 출력 시작 좌표, X,Y
		0,
		2428,				// 복사할 비트맵의 가로, 세로 길이
		450,
		RGB(255, 0, 255));			// 제거하고자 하는 색상

	//CTileMgr::Get_Instance()->Render(hDC);

	//CLineMgr::Get_Instance()->Render(hMemDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
	CTileMgr::Get_Instance()->Destroy_Instance();

	CObjMgr::Get_Instance()->Delete_ID(OBJ_BLOCK);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_JELLY);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_HPBAR);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BOOSTER);
}
