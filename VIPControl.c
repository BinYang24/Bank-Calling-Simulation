/*
VIPControl.c
*/
#include "Header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxVipID 1000

int VipID[MaxVipID];
int L;

void VipInit() //初始化VIP队列
{
	L = 0;
}

bool is_Vip(int ID) //检测是否为VIP
{
	for (int i = 0; i < L; i++)
		if (VipID[i] == ID) return true;
	return false;
}

void VipChange() //修改VIP信息
{
#if DEBUG
	L = 4;
	VipID[0]=0;
	VipID[1]=1;
	VipID[2]=2;
	VipID[3]=3;
	printf("L=%d\n", L);
	printf("%d %d\n",is_Vip(2),is_Vip(10));
	system("PAUSE");
#else
	int is;
	system("CLS");
	printf("请输入按键选择操作\n"
		"V+ 表示添加一个VIP客户\n"
		"V- 表示删除一个VIP客户\n"
		"V/ 表示更新一个VIP客户\n"
		"E 表示退出VIP客户维护状态\n"
		"L 查看当前VIP客户情况\n");

	char s[3], c;
	int id;

	PROMPT;
	scanf("%2s", &s);

	while (strnicmp(s,"E",1))
	{
		if (!strnicmp(s, "V+", 2))//如果输入v+队尾增加客户 
		{
			printf("输入要增加VIP ID\n");
			PROMPT;
			scanf("%d", &id);
			VipID[L++] = id;
			printf("添加成功\n");
		}
		else if (!strnicmp(s, "V-", 2))//如果输入v-队头删除客户 
		{
			printf("输入要删除VIP ID\n");
			PROMPT;
			scanf("%d", &id);
			for (int i = 0; i < L; i++)
			{
				if (VipID[i] == id)
				{
					L--;
					for (int j = i; j < L; j++)
						VipID[j] = VipID[j + 1];
					is = 1;
					break;
				}
			}
			printf("%s\n",is?"修改成功":"该用户不存在");
		}
		else if (!strnicmp(s, "V/", 2))//如果输入v/更改指定Vip信息
		{
			printf("输入需要修改的VIP ID\n");
			PROMPT;
			scanf("%d", &id);
			for (int i = 0; i < L; i++)
			{
				if (VipID[i] == id)
				{
					L--;
					for (int j = i; j < L; j++)//把数组中ID删除
						VipID[j] = VipID[j + 1];
					is = 1;
					break;
				}
			}
			if (is)
			{
				printf("输入要改为的VIP ID\n");
				PROMPT;
				scanf("%d", &id);
				VipID[L++] = id;//更新后的ID加入数组
				printf("修改成功\n");
			}
			else printf("该用户不存在\n");
		}
		else if (!strnicmp(s, "E", 1)) //用户输入e则退出维护
			break;
		else if (!strnicmp(s, "L", 1))//输入L打印客户数及信息
		{
			printf("VIP用户共有%d位\n",L);
			for (int i = 0; i < L; i++)
				printf("%d ", VipID[i]);
			printf("\n");
		}
		else 
		{
			printf("操作不存在\n");
		}
		PROMPT;
		scanf("%s", &s);
	}
#endif
}
