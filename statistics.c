/*
statistics.c
*/
#include "Header.h"
#include <stdio.h>
#include <Windows.h>

bool Statistics(FILE *fp) //统计银行情况，输出到文件中
{
	int i = 0;
	int Ordall = 0;
	int Vipall = 0;
	while (i < 6)//普通窗口
	{
		fprintf(fp, "第%d号普通窗口 客户总数:%d, ", i+1, OrdCou[i].SumCus);//各窗口客户总数
		fprintf(fp, "服务总时长:%d, ", OrdCou[i].SumTime);//各窗口服务总时长
		float Ordsingle = 0;
		if (OrdCou[i].SumCus)
		{
			Ordsingle = (float)OrdCou[i].SumTime / OrdCou[i].SumCus;//计算单笔业务办理时长
		}
		else Ordsingle = 0;
		fprintf(fp, "平均单笔业务办理时长:%f\n", Ordsingle);
		Ordall += OrdCou[i].SumCus;
		i++;
	}
	i = 0;
	while (i < 2)//Vip窗口
	{
		fprintf(fp, "第%d号Vip窗口 客户总数:%d, ", i+1, VipCou[i].SumCus);
		fprintf(fp, "服务总时长:%d, ", VipCou[i].SumTime);
		float Vipsingle = 0;
		if (VipCou[i].SumCus)
		{
			Vipsingle = (float)VipCou[i].SumTime / VipCou[i].SumCus;
		}
		else Vipsingle = 0;
		fprintf(fp, "平均单笔业务办理时长:%f\n", Vipsingle);
		Vipall += VipCou[i].SumCus;
		i++;
	}
	fprintf(fp, "营业厅受理普通客户总数：%d\n", Ordall);//普通客户总数
	fprintf(fp, "营业厅受理Vip客户总数：%d\n", Vipall);//Vip客户总数
#if DEBUG
	printf("in sta\n");
	system("PAUSE");
#endif
	return true;
}
