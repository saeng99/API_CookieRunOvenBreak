#pragma once
#include "Scene.h"
class CLoby :
    public CScene
{
public:
	CLoby();
	virtual ~CLoby();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

};

