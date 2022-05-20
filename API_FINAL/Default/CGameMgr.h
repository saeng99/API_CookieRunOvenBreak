#pragma once
#include "Include.h"
#include "Obj.h"
#include "CNumber.h"

class CGameMgr
	:public CObj
{
private:
	CGameMgr();
	~CGameMgr();

public:
	static CGameMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CGameMgr;

		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	virtual void Initialize(void) override;
	virtual int	Update(void) override;
	virtual	void Late_Update(void);
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	void	PlusJelly() { m_iScore += 5; };
	void	PlusBearJelly() { m_iScore += 50; };
	void	PlusSilverCoin() { m_iCoin += 1; };
	void	PlusGoldenCoin() { m_iCoin += 10; };
	void	Update_ScoreVector();
	void	Update_CoinVector();

private:
	int		m_iScore;
	int		m_iCoin;
	vector<CNumber*> m_vecScoreNumber;
	vector<CNumber*> m_vecCoinNumber;

	static CGameMgr* m_pInstance;
};

