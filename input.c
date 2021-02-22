/*
input.c
*/
#include "Header.h"
#include <string.h>
#include <windows.h>

void Input(char *s) //���մ�������
{
	int TypeBus;
	if (BankState != WORK)
	{
		printf("�����Ѳ��ٽ����µķ���\n");
		return;
	}

	if (!strnicmp(s,"G",1))
	{
		printf("�����û�����ķ������ͣ�1~%d��\n",SumBus);
		PROMPT;
		scanf("%d", &TypeBus);
		if (TypeBus > SumBus)
		{
			printf("�޴����ͷ���\n");
		}
		else if (SeqOrdCus.Size >= MaxSeqLen)
		{
			printf("��������\n");
		}
		else 
		{
			AddOrdCus(TypeBus);
			printf("�ɹ�����������\n");
		}
	}
	else if (!strnicmp(s, "v", 1))
	{
		printf("�����û�����ķ������ͣ�1~%d��\n", SumBus - 1);
		PROMPT;
		scanf("%d", &TypeBus);
		if (TypeBus > SumBus)
		{
			printf("�޴����ͷ���\n");
		}
		else if (SeqVipCus.Size >= MaxSeqLen)
		{
			printf("��������\n");
		}
		else
		{
			int id;
			for (int i = 0; i < 4; i++)
			{
				printf("����VIP ID\n");
				PROMPT;
				scanf("%d", &id);
				if (is_Vip(id)==true)
				{
					AddVipCus(TypeBus, id);
					printf("�ɹ�����VIP�������\n");
					break;
				}
				if (i == 2)
				{
					printf("��������ʧ�ܣ�������ͨ�û������Ŷ�\n");
					AddOrdCus(TypeBus, id);
					break;
				}
				printf("VIP ID ������ ���� %d �λ���\n", 3 - i - 1);
			}
		}
	}
	else if (!strnicmp(s, "r", 1))
	{
		printf("����������Ϣ�Ĵ��ں�\n");
		PROMPT;
		scanf("%s", s);
		if (!strnicmp(s, "v", 1))
		{
			if (try_to_rest(VIP, s[1]-'0'))
			{
				printf("������Ϣ�ɹ�\n");
			}
			else
			{
				printf("������Ϣʧ��\n");
			}
		}
		else
		{
			if(try_to_rest(ORD, s[0]-'0'))
			{
				printf("������Ϣ�ɹ�\n");
			}
			else
			{
				printf("������Ϣʧ��\n");
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
		printf("���в��ٽ����µķ���");
	}

#if DEBUG
	printf("s=%s\n",s);
#endif
	Sleep(500);
	PROMPT;
};
