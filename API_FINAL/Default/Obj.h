#pragma once

#include "Include.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void		Set_Dir(DIRECTION eDir) { m_eDir = eDir; }
	void		Set_Dead()				{ m_bDead = true; }
	void		Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void		Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }

	void		Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void		Set_PosY(float _fY) { m_tInfo.fY += _fY; }

	void		Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }

	bool		Get_Dead() { return m_bDead; }


	const INFO&		Get_Info(void) const { return m_tInfo; }
	const RECT&		Get_Rect(void) const { return m_tRect; }
	statInfo&		Get_StatInfo(void)	 { return m_tStatInfo; }

	const RENDERID	Get_RenderID(void) const { return m_eRender;  }

public:
	virtual		void	Initialize(void)	PURE;
	virtual		int		Update(void)		PURE;
	virtual		void	Late_Update(void)	PURE;
	virtual		void	Render(HDC hDC)		PURE;
	virtual		void	Release(void)		PURE;

public:
	virtual void	UpdateGravity();
	virtual void	UpdateGravity(float _fGravity);
	bool CompareTag(string _Tag);
	void SetTag(string _Tag);

	virtual		void	OnCollision(CObj* _pOtherObj) {};

protected:
	void		Update_Rect(void);
	void		Move_Frame(void);
	void		MoveMoment_Frame(void);

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	FRAME		m_tFrame;
	statInfo    m_tStatInfo;

	float		m_fSpeed;
	float		m_fAngle;

	DIRECTION	m_eDir;
	bool		m_bDead;
	string		m_Tag;

	CObj*		m_pTarget;
	TCHAR*		m_pFrameKey;

	RENDERID	m_eRender;

protected:
	float				m_fGTime;
	bool				m_bOnAir;
	bool				m_bOnBlock;

};

