#pragma once
class Spirit
{
private:
	//�ȼ�
	UINT grade;
	//������
	UINT defense;
	//������
	UINT aggressivity;
	//��
	UINT positioning;
	//���� 
	UINT life;
	//����
	UINT strength;
	//����
	UINT internalforce;
	//��Ǯ
	UINT money;
public:
	Spirit();
	~Spirit();
	void setAllProperty(UINT grade, UINT defense, UINT aggressivity, UINT positioning, UINT life,
		UINT strength, UINT internalforce, UINT money);
	void setGrade(UINT grade);
	void setDefense(UINT defense);
	void setAggressivity(UINT aggressivity);
	void setPositioning(UINT positioning);
	void setLife(UINT life);
	void setStrength(UINT strength);
	void setInternalforce(UINT internalforce);
	void setMoney(UINT money);
	UINT getGrade();
	UINT getDefense();
	UINT getAggressivity();
	UINT getPositioning();
	UINT getLife();
	UINT getStrength();
	UINT getInternalforce();
	UINT getMoney();
};

