/*
statistics.c
*/
#include "Header.h"
#include <stdio.h>
#include <Windows.h>

bool Statistics(FILE *fp) //ͳ�����������������ļ���
{
	int i = 0;
	int Ordall = 0;
	int Vipall = 0;
	while (i < 6)//��ͨ����
	{
		fprintf(fp, "��%d����ͨ���� �ͻ�����:%d, ", i+1, OrdCou[i].SumCus);//�����ڿͻ�����
		fprintf(fp, "������ʱ��:%d, ", OrdCou[i].SumTime);//�����ڷ�����ʱ��
		float Ordsingle = 0;
		if (OrdCou[i].SumCus)
		{
			Ordsingle = (float)OrdCou[i].SumTime / OrdCou[i].SumCus;//���㵥��ҵ�����ʱ��
		}
		else Ordsingle = 0;
		fprintf(fp, "ƽ������ҵ�����ʱ��:%f\n", Ordsingle);
		Ordall += OrdCou[i].SumCus;
		i++;
	}
	i = 0;
	while (i < 2)//Vip����
	{
		fprintf(fp, "��%d��Vip���� �ͻ�����:%d, ", i+1, VipCou[i].SumCus);
		fprintf(fp, "������ʱ��:%d, ", VipCou[i].SumTime);
		float Vipsingle = 0;
		if (VipCou[i].SumCus)
		{
			Vipsingle = (float)VipCou[i].SumTime / VipCou[i].SumCus;
		}
		else Vipsingle = 0;
		fprintf(fp, "ƽ������ҵ�����ʱ��:%f\n", Vipsingle);
		Vipall += VipCou[i].SumCus;
		i++;
	}
	fprintf(fp, "Ӫҵ��������ͨ�ͻ�������%d\n", Ordall);//��ͨ�ͻ�����
	fprintf(fp, "Ӫҵ������Vip�ͻ�������%d\n", Vipall);//Vip�ͻ�����
#if DEBUG
	printf("in sta\n");
	system("PAUSE");
#endif
	return true;
}
