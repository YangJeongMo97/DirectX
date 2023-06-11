#pragma once
#include "CNormalAttack.h"
#include "CVibrationAttack.h"

class CElf : public CNormalAttack, public CVibrationAttack
{
public:
	CElf();
	~CElf();

	void Display();

	void balanceDamage(int eNum);

	void setDeathCount() { m_nDeathCount++; }
	int getDeathCount() { return m_nDeathCount; }

	void AttackTarget(CBasicSet* pTarget);
private:
	static int m_nDeathCount;
};

