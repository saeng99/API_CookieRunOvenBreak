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
#include "SoundMgr.h"
#include "Scene.h"
#include "CGameMgr.h"
#include "SceneMgr.h"
#include "LineMgr.h"
#include "CBlockk.h"
#include "CFlag.h"

CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize(void)
{
	CLineMgr::Get_Instance()->Initialize();

	CSoundMgr::Get_Instance()->PlaySoundW(L"BGM Map Chapter.wav", SOUND_STAGE, g_fSound);
	CObjMgr::Get_Instance()->Add_Object(OBJ_HPBAR, CAbstractFactory<CHPBar>::Create());
	CGameMgr::Get_Instance()->Initialize();

	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(150.f,345.f));
	//m_pPlayer = CObjMgr::Get_Instance()->Get_Player();
	//CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(1000.f, 345.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_FLAG, CAbstractFactory<CFlag>::Create(11600.f, 270.f));

	//지형

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
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(4050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(4150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(4250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(4350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(4650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(4750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(4850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(4950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(5050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(5150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(5250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(5350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(5450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(5550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(5650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(5750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(6050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(6350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(6450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(6550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(6650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(6750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(6850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(6950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(7050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(7150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(7650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(7750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(7850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(7950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(8050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(8150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(8250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(8350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(8450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(8550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(8650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(8750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(9750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(9850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(9950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(10950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(11950.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12050.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12150.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12250.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12350.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12450.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12550.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12650.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12750.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12850.f, 430.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlock>::Create(12950.f, 430.f));


	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlockk>::Create(7400.f, 295.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlockk>::Create(8950.f, 295.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlockk>::Create(9200.f, 265.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlockk>::Create(9450.f, 305.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CBlockk>::Create(9550.f, 305.f));


	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(550.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(1170.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(1214.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(2420.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(5550.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(5594.f, 346.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CThorn>::Create(9970.f, 346.f));


	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CComingUpThorn>::Create(2770.f, 330.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CComingUpThorn>::Create(6580.f, 330.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CComingUpThorn>::Create(7100.f, 330.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CComingUpThorn>::Create(8550.f, 330.f));


	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(800.f,160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(888.f,160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(2000.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(2184.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(3088.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(3176.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(3264.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(3352.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(4800.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(5000.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(5200.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(5288.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(6800.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(7800.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(7888.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(7976.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(8064.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(8152.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(8240.f, 160.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BLOCK, CAbstractFactory<CFork>::Create(8328.f, 160.f));
	

	//젤리

	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(300.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(340.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(380.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(420.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(460.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(500.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(520.f, 310.f));
	//곰젤리
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
	//곰젤리
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1240.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1260.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1300.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1340.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1380.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1420.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1460.f, 350.f));
	// 점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1495.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1530.f, 260.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1570.f, 260.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1600.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1620.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1660.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1820.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1860.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1900.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1940.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(1980.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2020.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2060.f, 350.f));
	// 곰젤리
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2140.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2180.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2220.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2260.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2300.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2340.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2375.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2420.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2465.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2500.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2540.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2580.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2620.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2660.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2700.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2720.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2750.f, 260.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2790.f, 260.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2820.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2840.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2880.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2920.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(2960.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(3000.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(3040.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(3410.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(3450.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(3490.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(3530.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(3570.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(3610.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4090.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4130.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4170.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4210.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4250.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4290.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4330.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4370.f, 350.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4400.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4430.f, 275.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4470.f, 245.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4510.f, 245.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4550.f, 275.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4580.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4610.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4650.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4690.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4730.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4770.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4810.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4850.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(4970.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5010.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5050.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5150.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5190.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5230.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5270.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5310.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5350.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5390.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5430.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5470.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5500.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5550.f, 260.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5590.f, 260.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5640.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5670.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5710.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5750.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5790.f, 350.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5820.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5850.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5890.f, 250.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(5970.f, 250.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6010.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6030.f, 310.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6070.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6110.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6150.f, 250.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6230.f, 250.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6270.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6300.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6320.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6360.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6400.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6440.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6480.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6520.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6520.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6660.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6700.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6740.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6780.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6820.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6860.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6900.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6940.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(6980.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7020.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7160.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7690.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7730.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7770.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7810.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7850.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7890.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7930.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(7970.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8010.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8050.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8090.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8130.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8170.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8210.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8250.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8290.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8330.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8370.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8410.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8450.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8490.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8530.f, 270.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8570.f, 270.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8605.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8640.f, 335.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8680.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8720.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8760.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8800.f, 350.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8830.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8860.f, 270.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8890.f, 240.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8930.f, 260.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(8970.f, 260.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9010.f, 235.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9045.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9080.f, 180.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9115.f, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9150.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9190.f, 235.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9230.f, 235.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9270.f, 215.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9305.f, 190.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9340.f, 210.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9375.f, 230.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9410.f, 255.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9450.f, 275.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9490.f, 275.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9530.f, 275.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9570.f, 275.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9610.f, 255.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9650.f, 225.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9690.f, 190.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9730.f, 220.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9770.f, 250.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9810.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9850.f, 305.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9890.f, 330.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9920.f, 290.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9955.f, 260.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(9995.f, 280.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(10030.f, 310.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(10070.f, 330.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(10100.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(10140.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(10180.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(10220.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(10260.f, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CNormalJelly>::Create(10300.f, 350.f));
	

	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(555.f, 282.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(1170.f, 232.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(1215.f, 232.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(2100.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3090.f, 352.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3130.f, 352.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3170.f, 352.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3210.f, 352.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3250.f, 352.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3290.f, 352.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3330.f, 352.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3370.f, 352.f));
	//하트모양 위
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3660.f, 232.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3720.f, 232.f));
	//하트모양 중간
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3640.f, 262.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3690.f, 262.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3740.f, 262.f));
	//하트모양 아래
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3665.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3690.f, 322.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3715.f, 292.f));
	//하트모양 위
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3980.f, 232.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(4040.f, 232.f));
	//하트모양 중간
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3960.f, 262.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(4060.f, 262.f));
	//하트모양 아래
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(3985.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(4010.f, 322.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(4035.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(4890.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(4930.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(5930.f, 242.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(7460.f, 257.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(7520.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(7620.f, 242.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(7670.f, 292.f));
	// 1
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10500.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10530.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10500.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10530.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10500.f, 282.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10530.f, 282.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10500.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10530.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10500.f, 342.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10530.f, 342.f));
	// 2
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10610.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10640.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10625.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10655.f, 222.f)); 
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10685.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10715.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10690.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10720.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10680.f, 282.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10710.f, 282.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10670.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10700.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10650.f, 342.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10680.f, 342.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10710.f, 342.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10740.f, 342.f));
	//9 숫자간 간격 120
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10875.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10905.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10935.f, 222.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10850.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10880.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10910.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10940.f, 252.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10875.f, 282.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10905.f, 282.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10935.f, 282.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10925.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CBearJelly>::Create(10910.f, 342.f));



	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(1700.f, 352.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(1780.f, 352.f));
	//하트모양 위
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(3820.f, 232.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(3880.f, 232.f));
	//하트모양 중간
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(3800.f, 262.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(3900.f, 262.f));
	//하트모양 아래
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(3825.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(3850.f, 322.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(3875.f, 292.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(6535.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(6565.f, 242.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(6600.f, 242.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(6630.f, 292.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(7050.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(7080.f, 242.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(7110.f, 242.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(7140.f, 292.f));
	//점프
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(7200.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(7240.f, 242.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(7325.f, 232.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CSilverCoin>::Create(7370.f, 262.f));


	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(1740.f, 352.f));
	//하트모양 중간
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(3850.f, 262.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(5080.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(5120.f, 312.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(7280.f, 212.f));
	//하트 위
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(10340.f, 232.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(10400.f, 232.f));
	//하트모양 중간												   
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(10320.f, 262.f));
	//CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(10370.f, 262.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(10420.f, 262.f));
	//하트모양 아래												  
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(10345.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(10370.f, 322.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(10395.f, 292.f));
	//하트 위
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(11060.f, 232.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(11120.f, 232.f));
	//하트모양 중간												   
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(11040.f, 262.f));
//	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(11090.f, 262.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(11140.f, 262.f));
	//하트모양 아래												  
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(11065.f, 292.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(11090.f, 322.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CGoldenCoin>::Create(11115.f, 292.f));


	CObjMgr::Get_Instance()->Add_Object(OBJ_BOOSTER, CAbstractFactory<CHPPotion>::Create(4008.f, 257.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BOOSTER, CAbstractFactory<CHPPotion>::Create(6190.f, 242.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BOOSTER, CAbstractFactory<CHPPotion>::Create(7570.f, 187.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CHPPotion>::Create(10370.f, 262.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_JELLY, CAbstractFactory<CHPPotion>::Create(11090.f, 262.f));

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Oven222.bmp", L"Ground");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Fireplz2.bmp", L"Fire");

	m_dwGameOverTime = long(0);
}	

void CStage::Update(void)
{
	CObjMgr::Get_Instance()->Update();	
	CGameMgr::Get_Instance()->Update();

	m_pPlayer = CObjMgr::Get_Instance()->Get_Player();

	if (12000 <= m_pPlayer->Get_Info().fX)
		CSceneMgr::Get_Instance()->Scene_Resur(SC_ENDING);

	if (!dynamic_cast<CPlayer*>(m_pPlayer)->Get_Hp())
	{
		if(!m_dwGameOverTime)
			m_dwGameOverTime = GetTickCount();

		if (GetTickCount() - m_dwGameOverTime > 1000)
		{
			CSceneMgr::Get_Instance()->Scene_Resur(SC_SCOREBOARD);
		}
	}
}

void CStage::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Ground");
	HDC		hFireMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Fire");
	
	BitBlt(hDC, 0, 0, 2428, WINCY, hGroundMemDC, 0, 0, SRCCOPY);
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
		0,	// 2,3 인자 :  복사받을 위치 X, Y
		0,
		2428,				// 4,5 인자 : 복사받을 가로, 세로 길이
		450,
		hFireMemDC,							// 비트맵을 가지고 있는 DC
		0,	// 비트맵 출력 시작 좌표, X,Y
		0,
		2428,				// 복사할 비트맵의 가로, 세로 길이
		450,
		RGB(255, 0, 255));			// 제거하고자 하는 색상

	//cout << "\t" << m_pPlayer->Get_Info().fX << "\t" << m_pPlayer->Get_Info().fY << "\t" << endl;

	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
	CGameMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
	CGameMgr::Get_Instance()->Destroy_Instance();
	CScrollMgr::Get_Instance()->Destroy_Instance();
	CLineMgr::Get_Instance()->Destroy_Instance();

	CObjMgr::Get_Instance()->Delete_ID(OBJ_BLOCK);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_JELLY);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_HPBAR);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BOOSTER);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_PLAYER);
	CSoundMgr::Get_Instance()->StopSound(SOUND_STAGE);

}
