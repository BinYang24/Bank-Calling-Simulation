/*
log.c
*/
#include "Header.h"
#include<stdio.h>

bool Log(FILE *fp)//������ļ��� 
{
	int i = 0;
	fprintf(fp, "��ǰʱ��:%d\n", CurTime);
	fprintf(fp, "�����ͨ�ͻ�����:%d\n", SeqOrdCus.front - 1);//���Ŀǰ������ͨ�ͻ�����
	fprintf(fp, "���Vip�ͻ�����:V%d\n", SeqVipCus.front - 1); //���Ŀǰ����Vip�ͻ�����
	fprintf(fp, "��ǰ��ͨ�û��Ŷ���Ŀ:%d\n", CurOrdCus);
	fprintf(fp, "��ǰVip�û��Ŷ���Ŀ��%d\n", CurVipCus);
	for (; i < 6; i++)//��ͨ���ڵ�״̬
	{
		switch (OrdCou[i].state)
		{
		case WORK:
			fprintf(fp, "%d����ͨ���ڣ�����Ӫҵ %d\n", i+1, OrdCou[i].CusID); 
			break;
		case FREE:
			fprintf(fp, "%d�Ŵ��ڣ����ڵȴ� %d\n", i+1, SeqOrdCus.rear);//����ȴ��ͻ��к�����С�Ŀͻ����룬����ͷ����
			break;
		case OFF:
			fprintf(fp, "%d�Ŵ��ڣ�������Ϣ\n",i+1);
			break;
		}
	}
	for (i = 0; i < 2; i++)//Vip����
	{
		switch (VipCou[i].state)
		{
		case WORK:fprintf(fp, "%d��Vip���ڣ�����Ӫҵ %d\n", i+1, VipCou[i].CusID); break;
		case FREE:fprintf(fp, "%d��Vip���ڣ����ڵȴ� %d\n", i+1, SeqVipCus.rear); break;
		case OFF:fprintf(fp, "%d��Vip���ڣ�������Ϣ\n",i+1); break;
		}
	}
	switch (BankState)
	{
	case WORK:fprintf(fp, "��������Ӫҵ\n"); break;
	case OFF:fprintf(fp, "�������°�\n"); break;
	}
	fprintf(fp, "-------------------------------------\n\n");
	return true;
}
