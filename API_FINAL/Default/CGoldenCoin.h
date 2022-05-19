#pragma once
#include "Obj.h"

class CGoldenCoin :
    public CObj
{
public:
	CGoldenCoin();
	virtual ~CGoldenCoin();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual		void	OnCollision(CObj* other);
};

