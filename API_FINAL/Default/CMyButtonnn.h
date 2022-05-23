#pragma once
#include "Obj.h"
class CMyButtonnn :
    public CObj
{
public:
	CMyButtonnn();
	virtual ~CMyButtonnn();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	int			m_iDrawID;
};

