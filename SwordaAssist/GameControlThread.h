#pragma once
#include "stdafx.h"
#include "Common.h"
#include "Spirit.h"
#include "MemeryTamperingService.h"
#include "SpiritAutoProtect.h"

extern MemeryTamperingService memeryTamperingService;  //�ڴ��޸�ҵ���߼�
extern Spirit currentSpirit;                           //��ǰ������Ϣ
extern Spirit willModifySpirit;                        //��Ҫ�޸ĵ���������Ϣ

DWORD WINAPI RunGameThread(LPVOID lpParam);
DWORD WINAPI MonitorThread(LPVOID lpParam);
