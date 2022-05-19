#pragma once
#include "Obj.h"
class CMyButtonn :
    public CObj
{
public:
	CMyButtonn();
	virtual ~CMyButtonn();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	int			m_iDrawID;
};

