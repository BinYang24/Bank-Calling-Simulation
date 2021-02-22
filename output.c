/*
output.c
*/
#include "Header.h"
#include <Windows.h>
#include <stdio.h>

void Output() //将信息输出到窗口中
{
	int l, r; 
	system("CLS");//清屏
	///printf("OutPut\n");
	printf("欢迎光临中国银行\n");
	printf("当前时间 ：%d\n",CurTime);//打印当前时间
	
	printf("正在等待普通客户数 ： %d\n", SeqOrdCus.Size);//正在等待的普通客户数
	l = SeqOrdCus.rear, r = SeqOrdCus.front;
	for (int i = l; i < r; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	
	printf("正在等待VIP客户数 ： %d\n", SeqVipCus.Size);//正在等待的Vip客户数
	l = SeqVipCus.rear, r = SeqVipCus.front;
	for (int i = l; i < r; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	printf("银行%s\n",BankState==WORK?"正在营业":"已关门");//银行当前状态

	for (int i = 0; i < MaxOrdCou; i++)
	{
		printf("%d号窗口 :",i+1);
		if (OrdCou[i].state == WORK)
		{
			printf("正在营业  正在服务客户ID：%d  正在进行的业务 %d", OrdCou[i].CusID,OrdCou[i].TypeBus);//普通工作窗口的状态
		}
		else
		{
			printf("%s", OrdCou[i].state==OFF?"暂不处理业务":"空闲");//非工作普通窗口的状态
		}
		printf("\n");
	}

	for (int i = 0; i < MaxVipCou; i++)
	{
		printf("V%d号窗口 :", i+1);
		if (VipCou[i].state == WORK)
		{
			printf("正在营业  正在服务客户ID：V%d  正在进行的业务 %d", VipCou[i].CusID,VipCou[i].TypeBus);
		}
		else
		{
			printf("%s", VipCou[i].state == OFF ? "暂不处理业务" : "空闲");
			//printf(">>%d", VipCou[i].state);
		}
		printf("\n");
	}

	printf("---------------------------------------\n");//打印分割线
	return;
};

