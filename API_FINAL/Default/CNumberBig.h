#pragma once
#include "Obj.h"

class CNumberBig :
    public CObj
{
public:
	CNumberBig();
	CNumberBig(float fX, float fY);
	virtual ~CNumberBig();

public:
	virtual void Initialize(void) override;
	virtual int	Update(void) override;
	virtual	void Late_Update(void);
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	void	Set_Num(int iNum) { m_iNum = iNum; }
	int		Get_Num() { return m_iNum; }

private:
	int m_iNum;
};

