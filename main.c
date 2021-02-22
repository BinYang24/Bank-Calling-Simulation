/*
main.c
*/
#include "Header.h"
#include <stdio.h>
#include <Windows.h>

DWORD WINAPI fun(LPVOID pParaneter);
HANDLE hTicketMutex;

FILE *fp_init, *fp_log, *fp_sta; //配置文件，日志文件，统计文件指针
//PS：程序中front表示队尾 而rear表示队头
int main()
{
	if ((fp_init = fopen("_init.txt", "r")) == NULL) //打开配置文件，日志文件，统计文件
	{
		return printf("Open _init.txt fail.");
	}
	if ((fp_log = fopen("_log.txt", "w")) == NULL)
	{
		return printf("Open log fail.");
	}
	if ((fp_sta = fopen("_statistics.txt", "w")) == NULL)
	{
		return printf("Open statistics fail.");
	}

	Init(fp_init); //初始化配置文件
	VipInit(); 
	VipChange(); 
	
	hTicketMutex = CreateMutex(NULL, 0, NULL); //创建输出线程
	CreateThread(NULL, 0, fun, NULL, 0, NULL); 
	while (1)  //主循环
	{
		if (is_finish()) break;

		WaitForSingleObject(hTicketMutex, INFINITE);
		Control();

		Output(); //输出到命令行

		Log(fp_log); //记录到日志文件

		ReleaseMutex(hTicketMutex);

		PROMPT;
		
		Sleep(1000);
		CurTime++;
	}

	Statistics(fp_sta); //记录到统计结果文件

	fclose(fp_init); //关闭配置文件，日志文件，统计文件
	fclose(fp_log);
	fclose(fp_sta);
	return 0;
}

DWORD WINAPI fun(LPVOID pParaneter) //输出线程
{
	static char order[200];
	while (1)
	{
		scanf("%1s", order);
		WaitForSingleObject(hTicketMutex, INFINITE);
		Input(order);
		ReleaseMutex(hTicketMutex);
	}
	return 0;
}