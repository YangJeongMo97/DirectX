#pragma once
#include "CExplosiveAttack.h"
#include "CVibrationAttack.h"

class CHuman : public CExplosiveAttack, public CVibrationAttack
{
public:
	CHuman();
	~CHuman();

	void Display();

	void balanceDamage(int eNum);

	void setDeathCount() { m_nDeathCount++; }
	int getDeathCount() { return m_nDeathCount; }

	void AttackTarget(CBasicSet* pTarget);

private:
	static int m_nDeathCount;
};