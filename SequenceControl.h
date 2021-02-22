#ifndef __SEQUENCECONTROL_H
#define __SEQUENCECONTROL_H

bool AddOrdCus(int TypeBus);//加入一名普通客户

struct Cus PopOrdCus();	//弹出一名普通客户

bool AddVipCus(int TypeBus, int ID); //加入一名VIP客户

struct Cus PopVipCus();	//弹出一名VIP客户

#include "SequenceControl.c"

#endif /* __SEQUENCECONTROL_H */