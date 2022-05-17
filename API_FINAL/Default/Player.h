#pragma once
#include "Obj.h"
#include "Bullet.h"

class CPlayer : public CObj
{
public:
	enum STATE  { IDLE, WALK, JUMP, SLIDE, HIT, DEAD, END };

public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual int		Update(void) override;
	virtual		void	Late_Update(void);
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	int Get_Hp() { return m_hp; }
	int Get_MaxHp() { return m_maxhp; }

	void		UpLife();
	void		DownLife();

private:
	void		Key_Input(void);
	void		Jumping(void);
	void		OffSet(void);
	void		Motion_Change(void);


public:
	virtual void OnCollision(CObj* other) override;

private:
	float					m_fDiagonal;
	bool					m_bJump;		// ���� ���� Ȯ��
	float					m_fJumpPower;	// ���� ��
	float					m_fJumpTime;	// ���� �� ���� �ð�
	float					m_fGravity;
	float					m_fBeforeJump;

	STATE					m_ePreState;
	STATE					m_eCurState;
	int		m_hp;
	int		m_maxhp;

};

// 1. �÷��̾� ���� ����(�÷��̾� �߽����� �����ϴ� ���� �����ϱ�)
// 2. ��ũ�� �̻��� ����
// 3. �÷��̾ ����ٴϴ� ���� ����(���Լ� ���)


// �Լ�		: ���, Input�� Output�� ����		Y = F(X)	-> y = x + 1
// �ﰢ �Լ�  : �����ڵ��� ã�� ����, �غ�, ���� ���̿� ���踦 �ǹ�, ���� ���� �˸� �� ���̿� �������� ���踦 ������ ���� �Լ�
