#include "Spirit.h"
#include "SpiritAutoProtect.h"
#include "Common.h"
#include "Resource.h"
#include <iostream>
#include <string>

extern PROCESS_INFORMATION pi;
extern BYTE crackAccessGradeCode[];
extern BYTE crackAccessDefenseCode[];
extern BYTE crackAccessAggressivityCode[];
extern BYTE crackAccessPositioningCode[];
extern BYTE crackAccessLifeCode[];
extern BYTE crackAccessStrengthCode[];
extern BYTE crackAccessInternalforceCode[];
extern BYTE crackAccessMoneyCode[];

#pragma once
class MemeryTamperingService
{
private:
	//����״̬ 1:�޸�Ӣ������(�����)  2:�޸�Ӣ������(�����)  3:ˢ����Ϣ(�����)  4:ˢ����Ϣ(�����)
	volatile UINT operateState = NULL;
public:
	MemeryTamperingService();
	//������Ϸ
	BOOL startGameAndDebug(LPWSTR gamePath);
	//���ò���״̬
	void setOperateState(UINT operateState);
	//��ȡ����״̬
	UINT getOperateState();
	//��ȡ���ǵ�ǰ��Ϣ
	BOOL refreshCurrentSpiritInfo(HWND hWnd);
	//�޸�������Ϣ
	BOOL tamperingSpirit(Spirit *spirit, SpiritAutoProtect *inputAutoProtect);
	~MemeryTamperingService();
};

