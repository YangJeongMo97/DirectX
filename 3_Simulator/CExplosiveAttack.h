#pragma once
#include "CBasicSet.h"

class CExplosiveAttack : public virtual CBasicSet
{
public:
	CExplosiveAttack();
	virtual ~CExplosiveAttack();

	int AttackTypeExplosive(CBasicSet* pTarget);
};

