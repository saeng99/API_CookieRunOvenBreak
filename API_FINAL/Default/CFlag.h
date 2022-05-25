#pragma once
#include "Obj.h"
class CFlag :
    public CObj
{
public:
	enum STATE { IDLE, HIT, END };

public:
	CFlag();
	virtual ~CFlag();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual		void	OnCollision(CObj* other);

	void		Hit();

private:
	void		Motion_Change(void);
	void		Move_Frame2(void);

	
private:
	STATE					m_ePreState;
	STATE					m_eCurState;
	CObj* m_pPlayer;
};

