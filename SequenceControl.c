/*
SequenceControl.c
*/
#include "Header.h"
#include <stdio.h>

bool AddOrdCus(int TypeBus) //����һ����ͨ�ͻ�
{
	if (SeqOrdCus.Size >= MaxSeqLen) return false;//��������
	if (TypeBus > SumBus) return false;//�޸�ҵ��
	struct Cus p = { ORD, TypeBus, 0 };
	SeqOrdCus.Size++;//���г�������1
	SeqOrdCus.queue[SeqOrdCus.front++] = p;//������ͨ�ͻ�����β����
}

struct Cus PopOrdCus()	//����һ����ͨ�ͻ�
{
	SeqOrdCus.Size--;
	return SeqOrdCus.queue[SeqOrdCus.rear++];//������ͨ�ͻ�����ͷ��һ
}

bool AddVipCus(int TypeBus,int ID) //����һ��VIP�ͻ�
{
	if (SeqVipCus.Size >= MaxSeqLen) return false;
	if (TypeBus > SumBus) return false;
	struct Cus p = { VIP, TypeBus, ID };
	SeqVipCus.Size++;
	SeqVipCus.queue[SeqVipCus.front++] = p;
}

struct Cus PopVipCus()	//����һ��VIP�ͻ�
{
	SeqVipCus.Size--;
	return SeqVipCus.queue[SeqVipCus.rear++];
}

