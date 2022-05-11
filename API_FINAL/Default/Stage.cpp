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
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_THORN, CAbstractFactory<CThorn>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_FORK, CAbstractFactory<CFork>::Create());
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Oven22.bmp", L"Ground");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Fireplz.bmp", L"Fire");
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
	
	BitBlt(hDC, iScrollX, 0, 1212, WINCY, hGroundMemDC, 0, 0, SRCCOPY);
	/*BitBlt(hDC,							// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left + iScrollX),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,								// 7, 8���� : ��Ʈ���� ����� ���� ��ǥ, X,Y
		0,
		SRCCOPY);*/						// ���ȿ��, �״�� ���� ���
	
	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		iScrollX,	// 2,3 ���� :  ������� ��ġ X, Y
		0,
		1212,				// 4,5 ���� : ������� ����, ���� ����
		WINCY,
		hFireMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,	// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		1212,				// ������ ��Ʈ���� ����, ���� ����
		WINCY,
		RGB(255, 0, 255));			// �����ϰ��� �ϴ� ����

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
