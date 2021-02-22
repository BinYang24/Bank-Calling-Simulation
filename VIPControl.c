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

void VipInit() //��ʼ��VIP����
{
	L = 0;
}

bool is_Vip(int ID) //����Ƿ�ΪVIP
{
	for (int i = 0; i < L; i++)
		if (VipID[i] == ID) return true;
	return false;
}

void VipChange() //�޸�VIP��Ϣ
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
	printf("�����밴��ѡ�����\n"
		"V+ ��ʾ���һ��VIP�ͻ�\n"
		"V- ��ʾɾ��һ��VIP�ͻ�\n"
		"V/ ��ʾ����һ��VIP�ͻ�\n"
		"E ��ʾ�˳�VIP�ͻ�ά��״̬\n"
		"L �鿴��ǰVIP�ͻ����\n");

	char s[3], c;
	int id;

	PROMPT;
	scanf("%2s", &s);

	while (strnicmp(s,"E",1))
	{
		if (!strnicmp(s, "V+", 2))//�������v+��β���ӿͻ� 
		{
			printf("����Ҫ����VIP ID\n");
			PROMPT;
			scanf("%d", &id);
			VipID[L++] = id;
			printf("��ӳɹ�\n");
		}
		else if (!strnicmp(s, "V-", 2))//�������v-��ͷɾ���ͻ� 
		{
			printf("����Ҫɾ��VIP ID\n");
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
			printf("%s\n",is?"�޸ĳɹ�":"���û�������");
		}
		else if (!strnicmp(s, "V/", 2))//�������v/����ָ��Vip��Ϣ
		{
			printf("������Ҫ�޸ĵ�VIP ID\n");
			PROMPT;
			scanf("%d", &id);
			for (int i = 0; i < L; i++)
			{
				if (VipID[i] == id)
				{
					L--;
					for (int j = i; j < L; j++)//��������IDɾ��
						VipID[j] = VipID[j + 1];
					is = 1;
					break;
				}
			}
			if (is)
			{
				printf("����Ҫ��Ϊ��VIP ID\n");
				PROMPT;
				scanf("%d", &id);
				VipID[L++] = id;//���º��ID��������
				printf("�޸ĳɹ�\n");
			}
			else printf("���û�������\n");
		}
		else if (!strnicmp(s, "E", 1)) //�û�����e���˳�ά��
			break;
		else if (!strnicmp(s, "L", 1))//����L��ӡ�ͻ�������Ϣ
		{
			printf("VIP�û�����%dλ\n",L);
			for (int i = 0; i < L; i++)
				printf("%d ", VipID[i]);
			printf("\n");
		}
		else 
		{
			printf("����������\n");
		}
		PROMPT;
		scanf("%s", &s);
	}
#endif
}
