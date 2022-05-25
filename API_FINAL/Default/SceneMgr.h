#pragma once

#include "Logo.h"
#include "MyMenu.h"
#include "MyEdit.h"
#include "Stage.h"
#include "CLoby.h"
#include "CTutorial.h"
#include "CScoreBoard.h"
#include "CEnding.h"

class CSceneMgr
{
private:
	CSceneMgr();
	~CSceneMgr();

public:
	void		Scene_Change();
	void		Scene_Change(SCENEID eID);
	void        Scene_Resur(SCENEID eID) { m_eResurScene = eID; }
	void		Update(void);
	void		Late_Update(void);
	void		Render(HDC hDC);
	void		Release(void);

	SCENEID		Get_SceneID(void) { return m_eCurScene; }
	//static void SetScene(SCENEID eScene) { m_eCurScene = eScene; }

public:
	static		CSceneMgr*		Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CSceneMgr;
		}

		return m_pInstance;
	}

	static	void	Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CSceneMgr*		m_pInstance;
	CScene*					m_pScene;

	SCENEID					m_eCurScene;
	SCENEID					m_ePreScene;

	SCENEID					m_eResurScene;

};

