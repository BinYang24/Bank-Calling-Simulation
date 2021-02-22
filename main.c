/*
main.c
*/
#include "Header.h"
#include <stdio.h>
#include <Windows.h>

DWORD WINAPI fun(LPVOID pParaneter);
HANDLE hTicketMutex;

FILE *fp_init, *fp_log, *fp_sta; //�����ļ�����־�ļ���ͳ���ļ�ָ��
//PS��������front��ʾ��β ��rear��ʾ��ͷ
int main()
{
	if ((fp_init = fopen("_init.txt", "r")) == NULL) //�������ļ�����־�ļ���ͳ���ļ�
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

	Init(fp_init); //��ʼ�������ļ�
	VipInit(); 
	VipChange(); 
	
	hTicketMutex = CreateMutex(NULL, 0, NULL); //��������߳�
	CreateThread(NULL, 0, fun, NULL, 0, NULL); 
	while (1)  //��ѭ��
	{
		if (is_finish()) break;

		WaitForSingleObject(hTicketMutex, INFINITE);
		Control();

		Output(); //�����������

		Log(fp_log); //��¼����־�ļ�

		ReleaseMutex(hTicketMutex);

		PROMPT;
		
		Sleep(1000);
		CurTime++;
	}

	Statistics(fp_sta); //��¼��ͳ�ƽ���ļ�

	fclose(fp_init); //�ر������ļ�����־�ļ���ͳ���ļ�
	fclose(fp_log);
	fclose(fp_sta);
	return 0;
}

DWORD WINAPI fun(LPVOID pParaneter) //����߳�
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