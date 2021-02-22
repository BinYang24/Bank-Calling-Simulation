/*
init.c
*/
#include "Header.h"
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

int getNum(char s[100]) //��ò�����ʼֵ
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

void init_from_file(FILE *fp) //���ļ����ȡ��ʼ������
{
	char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100], s7[100];
	int i = 0, a, b;
	FILE * fptr;
	if ((fptr = fp) == NULL)
		printf("_log.txt can't be open\n");//���ļ�
	else{
		fgets(s1, sizeof(s1), fptr);//�����ļ���ÿһ�У��������ʼ����
		MaxSeqLen = getNum(s1);//�õ������г��ȳ�ʼֵ

		fgets(s2, sizeof(s2), fptr);//�õ�ҵ����������ʼֵ
		SumBus = getNum(s2);

		// printf("%d",SumBus);

		fgets(s3, sizeof(s3), fptr);//�õ���̰���ҵ��ʱ���ʼֵ
		MinSec = getNum(s3);

		fgets(s4, sizeof(s4), fptr);//�õ������ҵ��ʱ���ʼֵ
		MaxSec = getNum(s4);

		fgets(s5, sizeof(s5), fptr);//�õ������Ϣʱ���ʼֵ
		MinRestSec = getNum(s5);

		fgets(s6, sizeof(s6), fptr);//�õ����Ϣʱ���ʼֵ
		MaxRestSec = getNum(s6);

		fgets(s7, sizeof(s7), fptr);//Vip�ͻ���������ĳʱ���رմ��ڳ�ʼֵ
		VIPSERVLen = getNum(s7);


	}
	fclose(fptr);
	//  printf("%d",SumBus);
}

void init_from_input() //�Ӵ��������л�ȡ��ʼ������
{
	char c='\0';
	while (c!= '0')
	{
		system("CLS");//����
		printf("���������޸�ָ����Ϣ��\n"//��ӡ��ʾ��Ϣ
			   "0��ʾ�����޸�\n"
			   "1��ʾ�������������ȴ�����\n"
			   "2��ʾҵ��������\n"
			   "3��ʾ��ҵ��������ʱ��\n"
			   "4��ʾ��ҵ������ʱ��\n"
			   "5��ʾ������Ϣ���ʱ��\n"
			   "6������Ϣ�ʱ��\n"
			   "7��ʾVIP�ͻ����������ʱ��\n");
		DIVIDER;//��ӡ�ֽ���
		printf("[�������������ȴ�����] %d\n"
			   "[ҵ��������] % d\n"
			   "[��ҵ��������ʱ��] %d\n"
			   "[��ҵ������ʱ��] %d\n"
			   "[������Ϣ���ʱ��] %d\n"
			   "[������Ϣ�ʱ��] %d\n"
			   "[VIP�ͻ����������ʱ��] %d\n",
			   MaxSeqLen, SumBus, MinSec, MaxSec, MinRestSec, MaxRestSec, VIPSERVLen);
		DIVIDER;
		//scanf("%c",&c);
		PROMPT;//��ӡ<<<
		while(isspace((c = getchar())))
			;

		if (c == '1')
		{ 
			printf("����һ����:\n");//�û�������1����ĵ������������ȴ�����
			PROMPT;
			scanf("%d", &MaxSeqLen); 
#if DEBUG
			printf("here 1\n");
#endif
		}
		else if (c == '2')
		{
			printf("����һ����:\n");//�û�������2�����ҵ��������
			PROMPT;
			scanf("%d", &SumBus); 
		}
		else if (c == '3')//�û�������3�����ҵ��������ʱ��
		{ 
			printf("����һ����:\n"); 
			PROMPT;
			scanf("%d", &MinSec); 
		}
		else if (c == '4')//�û�������4�����ҵ������ʱ��
		{ 
			printf("����һ����:\n"); 
			PROMPT;
			scanf("%d", &MaxSec); 
		}
		else if (c == '5')//�û�������5��������Ϣʱ��
		{ 
			printf("����һ����:\n"); 
			PROMPT;
			scanf("%d", &MinRestSec); 
		}
		else if (c == '6'){ //�û�������6����������Ϣʱ��
			printf("����һ����:\n"); 
			PROMPT;
			scanf("%d", &MaxRestSec); 
		}
		else if (c == '7')
		{
			printf("����һ����:\n");
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
			printf("��������\n");
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
