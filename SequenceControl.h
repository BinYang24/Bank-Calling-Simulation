#ifndef __SEQUENCECONTROL_H
#define __SEQUENCECONTROL_H

bool AddOrdCus(int TypeBus);//����һ����ͨ�ͻ�

struct Cus PopOrdCus();	//����һ����ͨ�ͻ�

bool AddVipCus(int TypeBus, int ID); //����һ��VIP�ͻ�

struct Cus PopVipCus();	//����һ��VIP�ͻ�

#include "SequenceControl.c"

#endif /* __SEQUENCECONTROL_H */