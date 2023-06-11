#pragma once
class CharStats
{
private:
	int m_nStr, m_nInt, m_nLife, m_nArmor, m_nMagicDef, m_nJobNum, m_nLevel;

public:
	CharStats();
	CharStats(int nNum);
	~CharStats();

	void setChar(int nStrLevel, int nIntLevel, int nLifeLevel, int nArmorLevel, int nMagicDefLevel);
	void setJob(int nNum);

	void setLevel();

	int getStr() const {
		return m_nStr;
	}
	int getInt() const {
		return m_nInt;
	}
	int getLife() const {
		return m_nLife;
	}
	int getArmor() const {
		return m_nArmor;
	}
	int getMagicDef() const {
		return m_nMagicDef;
	}
	int getJobNum() const {
		return m_nJobNum;
	}
	int getLevel() const {
		return m_nLevel;
	}
};

