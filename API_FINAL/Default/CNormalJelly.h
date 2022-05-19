#pragma once
#include "Obj.h"

class CNormalJelly :
	public CObj
{
public:
	CNormalJelly();
	virtual ~CNormalJelly();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual		void	OnCollision(CObj* other);
};
