#pragma once
#include "Obj.h"

class CHPPotion :
    public CObj
{
public:
	CHPPotion();
	virtual ~CHPPotion();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
};

