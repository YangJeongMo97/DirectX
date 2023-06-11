#pragma once
#include <iostream>

using namespace std;

enum TYPE {
	ENUM_CITIZEN = 1000,
	ENUM_HUMAN = 2000,
	ENUM_ORC = 3000,
	ENUM_ELF = 4000,
	ENUM_MAX = 30
};

enum TURN {
	HUMAN_TURN = 0,
	ORC_TURN,
	ELF_TURN
};

#define TRIBE_COUNT 3

class CBasicSet
{
public:
	CBasicSet();
	~CBasicSet();

	void setHP(int nTemp) { m_nHP = nTemp; }
	int getHP() const { return m_nHP; }

	void setAttack(int nTemp) { m_nAttack = nTemp; }
	int getAttack() const { return m_nAttack; }

	void setArmor_mod(int nTemp) { m_nArmor_mod = nTemp; }
	int getArmor_mod() const {return m_nArmor_mod;}

	void setArmor_base(int nTemp) { m_nArmor_base = nTemp; }
	int getArmor_base() const { return m_nArmor_base; }

	int getAttackType() const { return m_nAttackType; }

	bool getLive() const { return m_bLive; }

	char* getTribe() const { return m_pTribe; }

	int getType() const { return m_nType; }

	int remainHP(int nAttack = 1, int nArmor = 0);
	void cantSurvival();

	const CBasicSet& operator=(const CBasicSet& pTemp);
	CBasicSet* operator+(CBasicSet& pTribe);
	CBasicSet& operator+=(const CBasicSet& pTemp);

	friend CBasicSet* operator+(int nTemp, CBasicSet& pTribe);
	friend int operator==(const char* pTribe, const CBasicSet& pTemp);

	virtual void Display() = 0;

	virtual void balanceDamage(int eNum) = 0;

	virtual void setDeathCount() = 0;
	virtual int getDeathCount() = 0;
	virtual void AttackTarget(CBasicSet* pTarget) = 0;

protected:
	char* m_pTribe;
	int m_nType;

private:
	int m_nHP, m_nAttack, m_nArmor_mod, m_nArmor_base, m_nAttackType;
	bool m_bLive;
};

