/*
output.c
*/
#include "Header.h"
#include <Windows.h>
#include <stdio.h>

void Output() //����Ϣ�����������
{
	int l, r; 
	system("CLS");//����
	///printf("OutPut\n");
	printf("��ӭ�����й�����\n");
	printf("��ǰʱ�� ��%d\n",CurTime);//��ӡ��ǰʱ��
	
	printf("���ڵȴ���ͨ�ͻ��� �� %d\n", SeqOrdCus.Size);//���ڵȴ�����ͨ�ͻ���
	l = SeqOrdCus.rear, r = SeqOrdCus.front;
	for (int i = l; i < r; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	
	printf("���ڵȴ�VIP�ͻ��� �� %d\n", SeqVipCus.Size);//���ڵȴ���Vip�ͻ���
	l = SeqVipCus.rear, r = SeqVipCus.front;
	for (int i = l; i < r; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	printf("����%s\n",BankState==WORK?"����Ӫҵ":"�ѹ���");//���е�ǰ״̬

	for (int i = 0; i < MaxOrdCou; i++)
	{
		printf("%d�Ŵ��� :",i+1);
		if (OrdCou[i].state == WORK)
		{
			printf("����Ӫҵ  ���ڷ���ͻ�ID��%d  ���ڽ��е�ҵ�� %d", OrdCou[i].CusID,OrdCou[i].TypeBus);//��ͨ�������ڵ�״̬
		}
		else
		{
			printf("%s", OrdCou[i].state==OFF?"�ݲ�����ҵ��":"����");//�ǹ�����ͨ���ڵ�״̬
		}
		printf("\n");
	}

	for (int i = 0; i < MaxVipCou; i++)
	{
		printf("V%d�Ŵ��� :", i+1);
		if (VipCou[i].state == WORK)
		{
			printf("����Ӫҵ  ���ڷ���ͻ�ID��V%d  ���ڽ��е�ҵ�� %d", VipCou[i].CusID,VipCou[i].TypeBus);
		}
		else
		{
			printf("%s", VipCou[i].state == OFF ? "�ݲ�����ҵ��" : "����");
			//printf(">>%d", VipCou[i].state);
		}
		printf("\n");
	}

	printf("---------------------------------------\n");//��ӡ�ָ���
	return;
};

