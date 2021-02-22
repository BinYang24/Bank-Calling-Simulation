/*
init.c
*/
#include "Header.h"
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

int getNum(char s[100]) //获得参数初始值
{
	int num = 0, t = 0, i = 0;
	while (!isdigit(s[i]))i++;
	for (; s[i] != '\n'; i++)
	{
		t = s[i] - '0';
		num *= 10;
		num += t;
	}
	return num;
}

void init_from_file(FILE *fp) //从文件里获取初始化配置
{
	char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100], s7[100];
	int i = 0, a, b;
	FILE * fptr;
	if ((fptr = fp) == NULL)
		printf("_log.txt can't be open\n");//打开文件
	else{
		fgets(s1, sizeof(s1), fptr);//读入文件的每一行，分离出初始参数
		MaxSeqLen = getNum(s1);//得到最大队列长度初始值

		fgets(s2, sizeof(s2), fptr);//得到业务种类数初始值
		SumBus = getNum(s2);

		// printf("%d",SumBus);

		fgets(s3, sizeof(s3), fptr);//得到最短办理业务时间初始值
		MinSec = getNum(s3);

		fgets(s4, sizeof(s4), fptr);//得到最长办理业务时间初始值
		MaxSec = getNum(s4);

		fgets(s5, sizeof(s5), fptr);//得到最短休息时间初始值
		MinRestSec = getNum(s5);

		fgets(s6, sizeof(s6), fptr);//得到最长休息时间初始值
		MaxRestSec = getNum(s6);

		fgets(s7, sizeof(s7), fptr);//Vip客户少于三人某时间后关闭窗口初始值
		VIPSERVLen = getNum(s7);


	}
	fclose(fptr);
	//  printf("%d",SumBus);
}

void init_from_input() //从窗口输入中获取初始化配置
{
	char c='\0';
	while (c!= '0')
	{
		system("CLS");//清屏
		printf("输入数字修改指定信息：\n"//打印提示信息
			   "0表示不再修改\n"
			   "1表示单队列最大允许等待长度\n"
			   "2表示业务种类数\n"
			   "3表示单业务办理最短时间\n"
			   "4表示单业务办理最长时长\n"
			   "5表示窗口休息最短时长\n"
			   "6窗口休息最长时长\n"
			   "7表示VIP客户少于三人最长时间\n");
		DIVIDER;//打印分界线
		printf("[单队列最大允许等待长度] %d\n"
			   "[业务种类数] % d\n"
			   "[单业务办理最短时间] %d\n"
			   "[单业务办理最长时长] %d\n"
			   "[窗口休息最短时长] %d\n"
			   "[窗口休息最长时长] %d\n"
			   "[VIP客户少于三人最长时间] %d\n",
			   MaxSeqLen, SumBus, MinSec, MaxSec, MinRestSec, MaxRestSec, VIPSERVLen);
		DIVIDER;
		//scanf("%c",&c);
		PROMPT;//打印<<<
		while(isspace((c = getchar())))
			;

		if (c == '1')
		{ 
			printf("输入一个数:\n");//用户输入是1则更改单队列最大允许等待长度
			PROMPT;
			scanf("%d", &MaxSeqLen); 
#if DEBUG
			printf("here 1\n");
#endif
		}
		else if (c == '2')
		{
			printf("输入一个数:\n");//用户输入是2则更改业务种类数
			PROMPT;
			scanf("%d", &SumBus); 
		}
		else if (c == '3')//用户输入是3则更改业务办理最短时间
		{ 
			printf("输入一个数:\n"); 
			PROMPT;
			scanf("%d", &MinSec); 
		}
		else if (c == '4')//用户输入是4则更改业务办理最长时间
		{ 
			printf("输入一个数:\n"); 
			PROMPT;
			scanf("%d", &MaxSec); 
		}
		else if (c == '5')//用户输入是5则更改最长休息时间
		{ 
			printf("输入一个数:\n"); 
			PROMPT;
			scanf("%d", &MinRestSec); 
		}
		else if (c == '6'){ //用户输入是6则更改最短休息时间
			printf("输入一个数:\n"); 
			PROMPT;
			scanf("%d", &MaxRestSec); 
		}
		else if (c == '7')
		{
			printf("输入一个数:\n");
			PROMPT;
			scanf("%d", &VIPSERVLen);
		}
		else if (c == '0')
			;
		else
		{
#if DEBUG
			printf("here 2\n");
			printf("c=%c\n",c);
#endif
			printf("输入有误\n");
			system("PAUSE");
		}
	}
}

void Init(FILE *fp)
{
#if DEBUG
	printf("init\n");
#endif
	init_from_file(fp);
#if DEBUG
#else 
	init_from_input();
#endif
#if DEBUG
	printf("init finish\n");
#endif
};
