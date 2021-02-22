/*
counterControl.c
���ƴ���״̬
*/
#include "Header.h"
#include <stdlib.h>


#if DEBUG
void debug()
{
	for (int i = 0; i < 2; i++)
		printf("%d,", VipCou[i].state);
	system("PAUSE");
}
#endif

int randtime(int min, int max) //���ʱ�䷢����
{
	return CurTime + rand() % (max - min + 1) + min;
}

bool add_cus(struct Cou* p) //���ڽ��ܷ���
{
	struct Cus q;
	int ID;
	//printf("goto here 1\n");
	if (p->TypeCou == VIP)//�����Vip�ͻ�
	{
		if (SeqVipCus.Size == 0) return false;
		ID = SeqVipCus.rear;//��ͷ�������ͻ�ID��
		q = PopVipCus();//����һ��Vip�ͻ�
	}
	if (p->TypeCou == ORD)//�������ͨ�ͻ�
	{
		if (SeqOrdCus.Size == 0) return false;
		ID = SeqOrdCus.rear;
		q = PopOrdCus();
	}
	//printf("goto here 2\n");
	p->CusID = ID;
	p->state = WORK;
	p->TypeBus = q.TypeBus;//������Ϣ
	p->EndTime = randtime(MinSec, MaxSec);//����ʱ��������
	p->SumCus++;
	p->SumTime += p->EndTime - CurTime;//������ʱ��
	return true;
}

static int INF = 1e9;

static void _Init() //��ʼ������״̬��һ��ʼ��3����ͨ���ڼ�1��Vip����
{
	for (int i = 0; i < MaxOrdCou / 2; i++)
	{
		OrdCou[i].state = FREE;
		OrdCou[i].EndTime = INF;
		OrdCou[i].TypeCou = ORD;
		OrdCou[i].SumTime = 0;
		OrdCou[i].SumCus = 0;
	}
		
	for (int i = MaxOrdCou / 2; i < MaxOrdCou; i++)
	{
		OrdCou[i].state = OFF;
		OrdCou[i].EndTime = INF;
		OrdCou[i].TypeCou = ORD;
		OrdCou[i].SumTime = 0;
		OrdCou[i].SumCus = 0;
	}

	for (int i = 0; i < MaxVipCou / 2; i++)
	{
		VipCou[i].EndTime = INF;
		VipCou[i].state = FREE;
		VipCou[i].TypeCou = VIP;
		VipCou[i].SumTime = 0;
		VipCou[i].SumCus = 0;
	}
		
	for (int i = MaxVipCou / 2; i < MaxVipCou; i++)
	{
		VipCou[i].EndTime = INF;
		VipCou[i].state = OFF;
		VipCou[i].TypeCou = VIP;
		VipCou[i].SumTime = 0;
		VipCou[i].SumCus = 0;
	}
}


static int _time = 0;

void maintain()	//ά�����ڸ���
{
	if (SeqVipCus.Size <= 3)//��������С��3����ʼ��ʱ
	{	
		_time = 0;
	}
	else
	{
		for (int i = 0; i < MaxVipCou; i++)//��̬����vip����
		{
			if (VipCou[i].state == OFF)
			{
				VipCou[i].state = FREE;
			}
		}
		_time++;
	}
	if (_time > VIPSERVLen)//���ʱ�䳤�����������ʱ�䣬����һ��vip����
	{
		for (int i = 0; i < MaxVipCou; i++)
		{
			if (VipCou[i].state == FREE)
			{
				try_to_rest(VIP, i);
				break;
			}
		}
	}

	if (3 * CouSum(ORD) <= SeqOrdCus.Size)//��̬������ͨ����
	{
		for (int i = 0; i < MaxOrdCou; i++)
		{
			if (OrdCou[i].state == OFF)
			{
				OrdCou[i].state = FREE;
				break;
			}
		}
	}

	if (2 * CouSum(ORD) >= SeqOrdCus.Size)//����������Ϣ
	{
		for (int i = 0; i < MaxOrdCou; i++)
		{
			if (OrdCou[i].state == FREE)
			{
				try_to_rest(ORD, i);
				break;
			}
		}
	}

	return;
}



void Control()	//�����������Ϣ
{
	static int first = 1;
	if (first == 1)
	{
		_Init();
		first = 0;
	}

	//printf("1>>");
	//debug();

	for (int i = 0; i < MaxOrdCou; i++)
	{
		if (OrdCou[i].state != FREE)
		{
			if (OrdCou[i].EndTime <= CurTime)
			{
				OrdCou[i].state = FREE;
			}
		}
	}
	for (int i = 0; i < MaxVipCou; i++)
	{
		if (VipCou[i].state != FREE)
		{
			if (VipCou[i].EndTime <= CurTime)
			{
				VipCou[i].state = FREE;
			}
		}
	}

	//printf("3>>");
	//debug();

	maintain();

	//printf("4>>");
	//debug();

	for (int i = 0; i < MaxOrdCou; i++)
	{
		if (OrdCou[i].state == FREE)
		{
			add_cus(&OrdCou[i]);
		}
	}
#if DEBUG
	printf("SeqOrdCus.Size=%d\n", SeqOrdCus.Size);
	///getchar();
#endif

	//printf("2>>");
	//debug();
	for (int i = 0; i < MaxVipCou; i++)
	{
		if (VipCou[i].state == FREE)
		{
			add_cus(&VipCou[i]);
		}
	}

}

int CouSum(int TypeCou)	//���ڷ���Ĵ��ڸ���
{
	if (TypeCou == VIP)
	{
		int cnt = 0;
		for (int i = 0; i < MaxVipCou; i++)
		{
			if (VipCou[i].state != OFF)
			{
				cnt++;
			}
		}
		return cnt;
	}
	else
	{
		int cnt = 0;
		for (int i = 0; i < MaxOrdCou; i++)
		{
			if (OrdCou[i].state != OFF)
			{
				cnt++;
			}
		}
		return cnt;
	}
	return 0;
}

bool try_to_rest(int TypeCou, int ID)	//����������Ϣ
{
	ID--;
	if (TypeCou == VIP)
	{
		if (ID > MaxVipCou||ID<0) return false;
		if (CouSum(VIP) <= 1) return false;//����һ��vip����
		if (VipCou[ID].state == FREE)
			VipCou[ID].state = OFF;
		else return false;
		VipCou[ID].EndTime = randtime(MaxRestSec, MaxRestSec);
#if DEBUG
		printf("cnt=%d\n",CouSum(VIP));
		printf("ID=%d\n",ID);
		printf("state = %d\n", VipCou[ID].state);
		printf("EndTime = %d\n", VipCou[ID].EndTime);
		system("PAUSE");
#endif
		return true;
	}
	if (TypeCou == ORD)
	{
		if (ID > MaxOrdCou || ID<0  ) return false;
		if (CouSum(ORD) <= 3) return false;//����������ͨ����
		if (OrdCou[ID].state == FREE)
			OrdCou[ID].state = OFF;
		else return false;
		OrdCou[ID].EndTime = randtime(MaxRestSec, MaxRestSec);
		return true;
	}
}

bool is_finish() //�����Ƿ���ɷ���
{
	if (BankState == WORK) return false;
	for (int i = 0; i < MaxOrdCou; i++)
	{
		if (OrdCou[i].state == WORK)
			return false;
	}
	for (int i = 0; i < MaxVipCou; i++)
	{
		if (VipCou[i].state == WORK)
			return false;
	}
	return true;
}
