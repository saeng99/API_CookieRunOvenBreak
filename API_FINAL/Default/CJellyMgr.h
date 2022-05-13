#pragma once

#include "CJelly.h"

class CJellyMgr
{
private:
	CJellyMgr();
	~CJellyMgr();

public:
	//CJellyMgr* Get_Player() { return m_ObjList[OBJ_PLAYER].front(); }
	//CJellyMgr* Get_Target(JELLYID eID, CJellyMgr* pJelly);

public:
	void		Add_Object(JELLYID eID, CJellyMgr* pJelly);
	int			Update(void);
	void		Late_Update(void);
	void		Render(HDC hDC);
	void		Release(void);

	void		Delete_ID(JELLYID eID);

private:
	list<CJellyMgr*>	m_JellyList[JELLY_END];

public:
	static		CJellyMgr* Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CJellyMgr;
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
	static CJellyMgr* m_pInstance;
	list<CJellyMgr*>				m_RenderSort[RENDER_END];

};

