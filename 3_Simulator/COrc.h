#pragma once
#include "CNormalAttack.h"
#include "CExplosiveAttack.h"

class COrc : public CNormalAttack, public CExplosiveAttack
{
public:
	COrc();
	~COrc();

	void Display();

	void balanceDamage(int eNum);

	void setDeathCount() { m_nDeathCount++; }
	int getDeathCount() { return m_nDeathCount; }

	void AttackTarget(CBasicSet* pTarget);
private:
	static int m_nDeathCount;
};

