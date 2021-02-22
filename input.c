/*
input.c
*/
#include "Header.h"
#include <string.h>
#include <windows.h>

void Input(char *s) //接收窗口输入
{
	int TypeBus;
	if (BankState != WORK)
	{
		printf("银行已不再接受新的服务\n");
		return;
	}

	if (!strnicmp(s,"G",1))
	{
		printf("输入用户申请的服务类型（1~%d）\n",SumBus);
		PROMPT;
		scanf("%d", &TypeBus);
		if (TypeBus > SumBus)
		{
			printf("无此类型服务\n");
		}
		else if (SeqOrdCus.Size >= MaxSeqLen)
		{
			printf("队列已满\n");
		}
		else 
		{
			AddOrdCus(TypeBus);
			printf("成功进入服务队列\n");
		}
	}
	else if (!strnicmp(s, "v", 1))
	{
		printf("输入用户申请的服务类型（1~%d）\n", SumBus - 1);
		PROMPT;
		scanf("%d", &TypeBus);
		if (TypeBus > SumBus)
		{
			printf("无此类型服务\n");
		}
		else if (SeqVipCus.Size >= MaxSeqLen)
		{
			printf("队列已满\n");
		}
		else
		{
			int id;
			for (int i = 0; i < 4; i++)
			{
				printf("输入VIP ID\n");
				PROMPT;
				scanf("%d", &id);
				if (is_Vip(id)==true)
				{
					AddVipCus(TypeBus, id);
					printf("成功进入VIP服务队列\n");
					break;
				}
				if (i == 2)
				{
					printf("三次输入失败，进入普通用户队列排队\n");
					AddOrdCus(TypeBus, id);
					break;
				}
				printf("VIP ID 不存在 还有 %d 次机会\n", 3 - i - 1);
			}
		}
	}
	else if (!strnicmp(s, "r", 1))
	{
		printf("输入申请休息的窗口号\n");
		PROMPT;
		scanf("%s", s);
		if (!strnicmp(s, "v", 1))
		{
			if (try_to_rest(VIP, s[1]-'0'))
			{
				printf("申请休息成功\n");
			}
			else
			{
				printf("申请休息失败\n");
			}
		}
		else
		{
			if(try_to_rest(ORD, s[0]-'0'))
			{
				printf("申请休息成功\n");
			}
			else
			{
				printf("申请休息失败\n");
			}
		}
	}
	else if (!strnicmp(s, "x", 1))
	{
		VipChange();
	}
	else if (!strnicmp(s, "q", 1))
	{
		BankState = OFF;
		printf("银行不再接受新的服务");
	}

#if DEBUG
	printf("s=%s\n",s);
#endif
	Sleep(500);
	PROMPT;
};
