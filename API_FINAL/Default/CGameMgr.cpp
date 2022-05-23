#include "stdafx.h"
#include "CGameMgr.h"
#include "BmpMgr.h"
#include "SceneMgr.h"

#include "AbstractFactory.h"

CGameMgr* CGameMgr::m_pInstance = nullptr;

int g_iCoin = 0;
int g_iScore = 0;
int g_iScoreBest = 0;
bool g_bScoreBest = false;

CGameMgr::CGameMgr()
{
}

CGameMgr::~CGameMgr()
{
	Release();
}

void CGameMgr::Initialize(void)
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 60.f;
	//m_pFrameKey = L"UI";
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/ScoreUI.bmp", L"ScoreUI");

	if (CSceneMgr::Get_Instance()->Get_SceneID() == SC_STAGE)
	{
		m_iSceneNo = 0;
		m_tInfo.fX = 20.f;
		m_tInfo.fY = 20.f;
		m_vecScoreNumber.push_back(new CNumber(m_tInfo.fX + 100, m_tInfo.fY + 5));
		m_vecCoinNumber.push_back(new CNumber(m_tInfo.fX + 100, m_tInfo.fY + 35));
		m_vecScoreNumberBig.push_back(new CNumberBig(m_tInfo.fX + 1000, m_tInfo.fY + 700));
	}
	else if (CSceneMgr::Get_Instance()->Get_SceneID() == SC_SCOREBOARD)
	{
		m_iSceneNo = 1;
		m_tInfo.fX = 400.f;
		m_tInfo.fY = 250.f;
		m_vecScoreNumber.push_back(new CNumber(m_tInfo.fX + 1000, m_tInfo.fY + 700));
		m_vecCoinNumber.push_back(new CNumber(m_tInfo.fX + 300, m_tInfo.fY + 50));
		m_vecScoreNumberBig.push_back(new CNumberBig(m_tInfo.fX + 100, m_tInfo.fY - 50));
	}

	
	
	m_iScore = 0;
	m_iCoin = 0;
}

int CGameMgr::Update(void)
{
	Update_Rect();
	Update_ScoreVector();
	Update_CoinVector();

	if (m_iSceneNo == 1)
	{
		Update_ScoreBigVector();
	}

	for (auto& iter : m_vecScoreNumber)
	{
		iter->Update();
	}

	for (auto& iter : m_vecScoreNumberBig)
	{
		iter->Update();
	}

	for (auto& iter : m_vecCoinNumber)
	{
		iter->Update();
	}
	return 0;
}

void CGameMgr::Late_Update(void)
{
}

void CGameMgr::Render(HDC hDC)
{
	if (!m_iSceneNo)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"ScoreUI");


		GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
			m_tInfo.fX,	// 2,3 인자 :  복사받을 위치 X, Y
			m_tInfo.fY,
			int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
			int(m_tInfo.fCY),
			hMemDC,							// 비트맵을 가지고 있는 DC
			0,						// 비트맵 출력 시작 좌표, X,Y
			0,
			(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
			(int)m_tInfo.fCY,
			RGB(255, 0, 255));
	}

	for (auto& iter : m_vecScoreNumber)
	{
		iter->Render(hDC);
	}

	for (auto& iter : m_vecScoreNumberBig)
	{
		iter->Render(hDC);
	}

	for (auto& iter : m_vecCoinNumber)
	{
		iter->Render(hDC);
	}
}

void CGameMgr::Release(void)
{
	g_iCoin = m_iCoin;
	g_iScore = m_iScore;
	if (m_iScore > g_iScoreBest)
	{
		g_iScoreBest = g_iScore;
		g_bScoreBest = true;
	}

	for (auto& iter : m_vecScoreNumber)
	{
		delete iter;
	}
	m_vecScoreNumber.clear();

	for (auto& iter : m_vecScoreNumberBig)
	{
		delete iter;
	}
	m_vecScoreNumberBig.clear();

	for (auto& iter : m_vecCoinNumber)
	{
		delete iter;
	}

	m_vecCoinNumber.clear();
}

void CGameMgr::Update_ScoreVector()
{
	int _iNumLong = 0;
	int saveScore = m_iScore;

	if (m_iScore == 0)
	{
		m_vecScoreNumber.front()->Set_Num(0);
		return;
	}

	while (m_iScore != 0)
	{
		++_iNumLong;
		if (_iNumLong > m_vecScoreNumber.size())
		{
			m_vecScoreNumber.push_back(dynamic_cast<CNumber*>(CAbstractFactory<CNumber>::Create(m_vecScoreNumber[m_vecScoreNumber.size() - 1]->Get_Info().fX - (m_vecScoreNumber[m_vecScoreNumber.size() - 1]->Get_Info().fCX * 0.5f) - 7.f, m_vecScoreNumber[m_vecScoreNumber.size() - 1]->Get_Info().fY)));
			m_vecScoreNumber.back()->Set_Num(m_iScore % 10);
		}
		else
		{
			m_vecScoreNumber[_iNumLong - 1]->Set_Num(m_iScore % 10);
		}

		m_iScore /= 10;
	}
	m_iScore = saveScore;
}

void CGameMgr::Update_ScoreBigVector()
{
	int _iNumLong = 0;
	int saveScore = m_iScore;

	if (m_iScore == 0)
	{
		m_vecScoreNumberBig.front()->Set_Num(0);
		return;
	}

	while (m_iScore != 0)
	{
		++_iNumLong;
		if (_iNumLong > m_vecScoreNumberBig.size())
		{
			m_vecScoreNumberBig.push_back(dynamic_cast<CNumberBig*>(CAbstractFactory<CNumberBig>::Create(m_vecScoreNumberBig[m_vecScoreNumberBig.size() - 1]->Get_Info().fX - (m_vecScoreNumberBig[m_vecScoreNumberBig.size() - 1]->Get_Info().fCX * 0.5f) - 7.f, m_vecScoreNumberBig[m_vecScoreNumberBig.size() - 1]->Get_Info().fY)));
			m_vecScoreNumberBig.back()->Set_Num(m_iScore % 10);
		}
		else
		{
			m_vecScoreNumberBig[_iNumLong - 1]->Set_Num(m_iScore % 10);
		}

		m_iScore /= 10;
	}
	m_iScore = saveScore;
}

void CGameMgr::Update_CoinVector()
{
	int _iNumLong = 0;
	int saveCoin = m_iCoin;

	if (m_iCoin == 0)
	{
		m_vecCoinNumber.front()->Set_Num(0);
		return;
	}

	while (m_iCoin != 0)
	{
		++_iNumLong;
		if (_iNumLong > m_vecCoinNumber.size())
		{
			m_vecCoinNumber.push_back(dynamic_cast<CNumber*>(CAbstractFactory<CNumber>::Create(m_vecCoinNumber[m_vecCoinNumber.size() - 1]->Get_Info().fX - (m_vecCoinNumber[m_vecCoinNumber.size() - 1]->Get_Info().fCX * 0.5f) - 7.f, m_vecCoinNumber[m_vecCoinNumber.size() - 1]->Get_Info().fY)));
			m_vecCoinNumber.back()->Set_Num(m_iCoin % 10);
		}
		else
		{
			m_vecCoinNumber[_iNumLong - 1]->Set_Num(m_iCoin % 10);
		}
		m_iCoin /= 10;
	}

	m_iCoin = saveCoin;
}
