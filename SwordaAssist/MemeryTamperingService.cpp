#include "stdafx.h"
#include "MemeryTamperingService.h"
#include "Spirit.h"
#include "GameControlThread.h"

HANDLE hThread;
HANDLE monitorThread;
extern UINT curEsi;
extern SpiritAutoProtect autoProtect;

MemeryTamperingService::MemeryTamperingService()
{
}


MemeryTamperingService::~MemeryTamperingService()
{
}

//������Ϸ
BOOL MemeryTamperingService::startGameAndDebug(LPWSTR gamePath) {
	//������Ϸ�����߳�
	DWORD dwThread;
	hThread = CreateThread(NULL, 0, RunGameThread, gamePath, 0, &dwThread);
	if (hThread == NULL) {
		return FALSE;
	}

	//��������̣߳��û��������������������������
	DWORD dwMonitorThread;
	monitorThread = CreateThread(NULL, 0, MonitorThread, NULL, 0, &dwMonitorThread);
	return TRUE;
}

void MemeryTamperingService::setOperateState(UINT operateState) {
	this->operateState = operateState;
}

UINT MemeryTamperingService::getOperateState() {
	return this->operateState;
}

BOOL MemeryTamperingService::refreshCurrentSpiritInfo(HWND hWnd) {
	CONTEXT regs;
	regs.ContextFlags = CONTEXT_FULL | CONTEXT_DEBUG_REGISTERS;

	//�ȼ�
	UINT grade = 0;
	//������
	UINT defense = 0;
	//������
	UINT aggressivity = 0;
	//��
	UINT positioning = 0;
	//���� 
	UINT life = 0;
	//����
	UINT strength = 0;
	//����
	UINT internalforce = 0;
	//��Ǯ
	UINT money = 0;
	GetThreadContext(pi.hThread, &regs);
	ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECF8), &grade, 1, NULL);
	ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECF0), &defense, 2, NULL);
	ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECEC), &aggressivity, 2, NULL);
	ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECF4), &positioning, 2, NULL);
	ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECD8), &life, 2, NULL);
	ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECE0), &strength, 2, NULL);
	ReadProcessMemory(pi.hProcess, (LPCVOID)(curEsi + 0x004DECE8), &internalforce, 2, NULL);
	ReadProcessMemory(pi.hProcess, (LPCVOID)(0x0055d1c4), &money, 2, NULL);
	currentSpirit.setAllProperty(grade, defense, aggressivity, positioning, life,
		strength, internalforce, money);
	SetThreadContext(pi.hThread, &regs);

	HWND edit = GetDlgItem(hWnd, IDC_EDIT9);
	wchar_t graStr[10];
	_itow_s(currentSpirit.getGrade(), graStr, 10);
	SetWindowText(edit, graStr);

	edit = GetDlgItem(hWnd, IDC_EDIT5);
	wchar_t defStr[10];
	_itow_s(currentSpirit.getDefense(), defStr, 10);
	SetWindowText(edit, defStr);
	
	edit = GetDlgItem(hWnd, IDC_EDIT1);
	wchar_t aggStr[10];
	_itow_s(currentSpirit.getAggressivity(), aggStr, 10);
	SetWindowText(edit, aggStr);
	
	edit = GetDlgItem(hWnd, IDC_EDIT3);
	wchar_t posStr[10];
	_itow_s(currentSpirit.getPositioning(), posStr, 10);
	SetWindowText(edit, posStr);
	
	edit = GetDlgItem(hWnd, IDC_EDIT4);
	wchar_t lifeStr[10];
	_itow_s(currentSpirit.getLife(), lifeStr, 10);
	SetWindowText(edit, lifeStr);
	
	edit = GetDlgItem(hWnd, IDC_EDIT6);
	wchar_t strengthStr[10];
	_itow_s(currentSpirit.getLife(), strengthStr, 10);
	SetWindowText(edit, strengthStr);
	
	edit = GetDlgItem(hWnd, IDC_EDIT8);
	wchar_t internalforceStr[10];
	_itow_s(currentSpirit.getLife(), internalforceStr, 10);
	SetWindowText(edit, internalforceStr);
	
	edit = GetDlgItem(hWnd, IDC_EDIT7);
	wchar_t moneyStr[10];
	_itow_s(currentSpirit.getLife(), moneyStr, 10);
	SetWindowText(edit, moneyStr);
	
	return TRUE;
}

//�޸�������Ϣ
BOOL MemeryTamperingService::tamperingSpirit(Spirit *spirit, SpiritAutoProtect *inputAutoProtect) {
	CONTEXT regs;
	regs.ContextFlags = CONTEXT_FULL | CONTEXT_DEBUG_REGISTERS;

	autoProtect = *inputAutoProtect;
	//��������
	setOperateState(OPERATE_STATE_REQUEST_MODIFY_SPIRIT);
	if (NULL != spirit) {
		//���õȼ�
		UINT grade = spirit->getGrade();
		crackAccessGradeCode[6] = grade;

		//���÷�����
		UINT defense = spirit->getDefense();
		crackAccessDefenseCode[6] = defense & 0xff;
		crackAccessDefenseCode[7] = (defense >> 8) & 0xff;

		//���ù�����
		UINT aggressivity = spirit->getAggressivity();
		crackAccessAggressivityCode[6] = aggressivity & 0xff;
		crackAccessAggressivityCode[7] = (aggressivity >> 8) & 0xff;

		//������
		UINT positioning = spirit->getPositioning();
		crackAccessPositioningCode[6] = positioning & 0xff;
		crackAccessPositioningCode[7] = (positioning >> 8) & 0xff;

		//��������
		UINT life = spirit->getLife();
		crackAccessLifeCode[6] = life & 0xff;
		crackAccessLifeCode[7] = (life >> 8) & 0xff;

		//��������
		UINT strength = spirit->getStrength();
		crackAccessStrengthCode[6] = strength & 0xff;
		crackAccessStrengthCode[7] = (strength >> 8) & 0xff;

		//��������
		UINT internalforce = spirit->getInternalforce();
		crackAccessInternalforceCode[6] = internalforce & 0xff;
		crackAccessInternalforceCode[7] = (internalforce >> 8) & 0xff;

		//���ý�Ǯ
		UINT money = spirit->getMoney();
		crackAccessMoneyCode[6] = money & 0xff;
		crackAccessMoneyCode[7] = (money >> 8) & 0xff;
    }

	//��ϵ�
	GetThreadContext(pi.hThread, &regs);
	regs.Dr0 = ACCESS_GRADE_ADDRESS;
	regs.Dr7 = 0x101;
	SetThreadContext(pi.hThread, &regs);

	return TRUE;
}
