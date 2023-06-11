#pragma once
#include "CBasicSet.h"
class CNormalAttack : public virtual CBasicSet
{
public:
	CNormalAttack();
	virtual ~CNormalAttack();

	int AttackTypeNormal(CBasicSet* pTarget);
};

