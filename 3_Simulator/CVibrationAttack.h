#pragma once
#include "CBasicSet.h"

class CVibrationAttack : public virtual CBasicSet
{
public:
	CVibrationAttack();
	virtual ~CVibrationAttack();

	int AttackTypeVibration(CBasicSet* pTarget);
};