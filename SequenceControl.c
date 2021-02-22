/*
SequenceControl.c
*/
#include "Header.h"
#include <stdio.h>

bool AddOrdCus(int TypeBus) //加入一名普通客户
{
	if (SeqOrdCus.Size >= MaxSeqLen) return false;//队列已满
	if (TypeBus > SumBus) return false;//无该业务
	struct Cus p = { ORD, TypeBus, 0 };
	SeqOrdCus.Size++;//队列长度增加1
	SeqOrdCus.queue[SeqOrdCus.front++] = p;//加入普通客户，队尾后移
}

struct Cus PopOrdCus()	//弹出一名普通客户
{
	SeqOrdCus.Size--;
	return SeqOrdCus.queue[SeqOrdCus.rear++];//弹出普通客户，队头加一
}

bool AddVipCus(int TypeBus,int ID) //加入一名VIP客户
{
	if (SeqVipCus.Size >= MaxSeqLen) return false;
	if (TypeBus > SumBus) return false;
	struct Cus p = { VIP, TypeBus, ID };
	SeqVipCus.Size++;
	SeqVipCus.queue[SeqVipCus.front++] = p;
}

struct Cus PopVipCus()	//弹出一名VIP客户
{
	SeqVipCus.Size--;
	return SeqVipCus.queue[SeqVipCus.rear++];
}

