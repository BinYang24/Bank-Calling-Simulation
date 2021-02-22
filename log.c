/*
log.c
*/
#include "Header.h"
#include<stdio.h>

bool Log(FILE *fp)//输出到文件中 
{
	int i = 0;
	fprintf(fp, "当前时间:%d\n", CurTime);
	fprintf(fp, "最大普通客户号码:%d\n", SeqOrdCus.front - 1);//输出目前最大的普通客户号码
	fprintf(fp, "最大Vip客户号码:V%d\n", SeqVipCus.front - 1); //输出目前最大的Vip客户号码
	fprintf(fp, "当前普通用户排队数目:%d\n", CurOrdCus);
	fprintf(fp, "当前Vip用户排队数目：%d\n", CurVipCus);
	for (; i < 6; i++)//普通窗口的状态
	{
		switch (OrdCou[i].state)
		{
		case WORK:
			fprintf(fp, "%d号普通窗口：正在营业 %d\n", i+1, OrdCou[i].CusID); 
			break;
		case FREE:
			fprintf(fp, "%d号窗口：正在等待 %d\n", i+1, SeqOrdCus.rear);//输出等待客户中号码最小的客户号码，即队头号码
			break;
		case OFF:
			fprintf(fp, "%d号窗口：正在休息\n",i+1);
			break;
		}
	}
	for (i = 0; i < 2; i++)//Vip窗口
	{
		switch (VipCou[i].state)
		{
		case WORK:fprintf(fp, "%d号Vip窗口：正在营业 %d\n", i+1, VipCou[i].CusID); break;
		case FREE:fprintf(fp, "%d号Vip窗口：正在等待 %d\n", i+1, SeqVipCus.rear); break;
		case OFF:fprintf(fp, "%d号Vip窗口：正在休息\n",i+1); break;
		}
	}
	switch (BankState)
	{
	case WORK:fprintf(fp, "银行正在营业\n"); break;
	case OFF:fprintf(fp, "银行已下班\n"); break;
	}
	fprintf(fp, "-------------------------------------\n\n");
	return true;
}
