#pragma once
#include "stdafx.h"

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT                  (UINT)1
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT        (UINT)2
#define OPERATE_STATE_MODIFYING_SPIRIT                (UINT)3
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT            (UINT)4

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_GRADE     (UINT)5                  //�޸�Ӣ�۵ȼ�����(�����)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_GRADE  (UINT)6                 //�޸�Ӣ�۵ȼ�����(��ϵ�)  
#define OPERATE_STATE_MODIFYING_SPIRIT_GRADE          (UINT)7                //�޸�Ӣ�۵ȼ�����(�޸���) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_GRADE      (UINT)8               //�޸�Ӣ�۵ȼ�����(�����)  
 

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_DEFENSE    (UINT)9                    //�޸�Ӣ�۷���������(�����)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_DEFENSE (UINT)10                   //�޸�Ӣ�۷���������(��ϵ�)
#define OPERATE_STATE_MODIFYING_SPIRIT_DEFENSE         (UINT)11                  //�޸�Ӣ�۷���������(�޸���) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_DEFENSE     (UINT)12                 //�޸�Ӣ�۷���������(�����)  
 

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_AGGRESSIVITY     (UINT)13                    //�޸�Ӣ�۹���������(�����)  
#define OPERATE_STATE_BREAKPOINT_SPIRIT_AGGRESSIVITY         (UINT)14                   //�޸�Ӣ�۹���������(��ϵ�)
#define OPERATE_STATE_MODIFYING_SPIRIT_AGGRESSIVITY          (UINT)15                  //�޸�Ӣ�۹���������(�޸���) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_AGGRESSIVITY      (UINT)16                 //�޸�Ӣ�۹���������(�����)  
 

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_POSITIONING     (UINT)17                   //�޸�Ӣ��������(�����)  
#define OPERATE_STATE_BREAKPOINT_SPIRIT_POSITIONING         (UINT)18                  //�޸�Ӣ��������(��ϵ�)
#define OPERATE_STATE_MODIFYING_SPIRIT_POSITIONING          (UINT)19                 //�޸�Ӣ��������(�޸���)  
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_POSITIONING      (UINT)20                //�޸�Ӣ��������(�����)  


#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_LIFE     (UINT)21                   //�޸�Ӣ����������(�����)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_LIFE  (UINT)22                  //�޸�Ӣ����������(��ϵ�)
#define OPERATE_STATE_MODIFYING_SPIRIT_LIFE          (UINT)23                 //�޸�Ӣ����������(�޸���) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_LIFE      (UINT)24                //�޸�Ӣ����������(�����)  
 

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_STRENGTH     (UINT)25                  //�޸�Ӣ����������(�����)  
#define OPERATE_STATE_BREAKPOINT_SPIRIT_STRENGTH         (UINT)26                 //�޸�Ӣ����������(��ϵ�)
#define OPERATE_STATE_MODIFYING_SPIRIT_STRENGTH          (UINT)27                //�޸�Ӣ����������(�޸���)
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_STRENGTH      (UINT)28               //�޸�Ӣ����������(�����)  
  

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_INTERNALFORCE     (UINT)29                  //�޸�Ӣ����������(�����)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_INTERNALFORCE  (UINT)30                 //�޸�Ӣ����������(��ϵ�) 
#define OPERATE_STATE_MODIFYING_SPIRIT_INTERNALFORCE          (UINT)31                //�޸�Ӣ����������(�޸���)  
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_INTERNALFORCE      (UINT)32               //�޸�Ӣ����������(�����)  


#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_MONEY     (UINT)33                   //�޸�Ӣ�۽�Ǯ����(�����)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_MONEY  (UINT)34                  //�޸�Ӣ�۽�Ǯ����(��ϵ�) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_MONEY      (UINT)35                 //�޸�Ӣ�۽�Ǯ����(�����)  
#define OPERATE_STATE_MODIFYING_SPIRIT_MONEY          (UINT)36                //�޸�Ӣ�۽�Ǯ����(�޸���)  


#define OPERATE_STATE_REQUEST_REFRESH           (UINT)37                 //ˢ����Ϣ(�����) 
#define OPERATE_STATE_BREAKPOINT_REFRESH        (UINT)38                 //ˢ����Ϣ(��ϵ�)
#define OPERATE_STATE_REFRESHING                (UINT)39                 //ˢ����Ϣ(ˢ����)
#define OPERATE_STATE_FINISH_REFRESH            (UINT)40                 //ˢ����Ϣ(�����)


#define ACCESS_GRADE_ADDRESS   0x004060CC             //���ʵȼ������ַ           mov edx,[esi+0x004DECF8]
#define ACCESS_DEFENSE_ADDRESS 0x00406166             //���ʷ����������ַ         mov eax,[esi+0x004DECF0]
#define ACCESS_AGGRESSIVITY_ADDRESS 0x00406154        //���ʹ����������ַ         mov edx,[esi+0x004DECEC]
#define ACCESS_POSITIONING_ADDRESS 0x00406178         //�����������ַ           mov ecx,[esi+0x004DECF4]
#define ACCESS_CURRENT_LIFE_ADDRESS 0x0040220B        //����Ӣ�۵�ǰ���������ַ   mov eax,[esi+0x004DECD4]                          
#define ACCESS_LIFE_ADDRESS  0x00402205               //�������������ַ           mov ecx,[esi+0x004DECD8]
#define ACCESS_CURRENT_STRENGTH_ADDRESS 0x0040221E    //����Ӣ�۵�ǰ���������ַ   mov edx,[esi+0x004DECDC]
#define ACCESS_STRENGTH_ADDRESS 0x00402218            //�������������ַ           mov edx,[esi+0x004DECE0]
#define ACCESS_CURRENT_INTERNALFORCE_ADDRESS 0x00402250 //����Ӣ�۵�ǰ���������ַ mov ecx,[esi+0x004DECE4]
#define ACCESS_INTERNALFORCE_ADDRESS 0x0040224A       //�������������ַ           mov eax,[esi+0x004DECE8]
#define ACCESS_MONEY_ADDRESS 0x00402FE9               //���ʽ�Ǯ�����ַ           mov eax,[0x0055d1c4]  ��Ǯ���ʵ�ַ�ǹ̶���



