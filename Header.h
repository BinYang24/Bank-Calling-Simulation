#ifndef __HEADER_H
#define __HEADER_H

#include <stdio.h>
#include <windows.h>

#define MaxOrdCou  6 //�����ͨ������Ŀ
#define MaxVipCou  2 //���VIP������Ŀ
#define MaxOrdCus  1000 //�����ͨ�û��Ŷ���Ŀ
#define MaxVipCus  100 //���VIP�û��Ŷ���Ŀ
#define InitOrdCou  3 //��ʼ��ͨ������Ŀ
#define InitVipCou  1 //��ʼVIP������Ŀ
#define MaxBus 10 //���ҵ��������
#define bool int
#define true 1
#define false 0
#define DEBUG 0
#define DIVIDER printf("------------------------------------------------------------\n");
#define PROMPT  printf(">>>");

int MaxSeqLen;//�������������ȴ�����
int SumBus; //ҵ��������
//int MinSec[MaxBus], MaxSec[MaxBus];// ��ҵ�����ʱ��
int MinSec, MaxSec;// ��ҵ�����ʱ��
int MinRestSec, MaxRestSec;// ������Ϣ�ʱ��	
int VIPSERVLen;
	//��������ʱ�� VIPSERVLen��VIP�ͻ���һֱС��3�ˣ���̬�ر����ӵ�VIP���ڣ��ָ�ԭ����������

int CurOrdCus;// ��ǰ��ͨ�û��Ŷ���Ŀ
int CurVipCus;// ��ǰVIP�û��Ŷ���Ŀ
int CurOrdCou;// ��ǰ��ͨ�û�������Ŀ
int CurVipCou;// ��ǰVIP�û�������Ŀ

enum{ WORK, FREE, OFF };
enum{ ORD, VIP };

int BankState; //����״̬
int CurTime; //��ǰʱ��

struct Cou
{
	int ID;
	int TypeCou; //��������
	int TypeBus;
	int state; //����״̬
	int CusID; //���ڷ���Ŀͻ��ĺ��� 
	int EndTime; //�������ʱ��
	int SumCus, SumTime;// ���ڷ���ͻ�������������ʱ��
}OrdCou[MaxOrdCou], VipCou[MaxVipCou];

struct Cus
{
	int TypeCus; //�ͻ�����
	int TypeBus; //������������
	int VIPID;
};

struct Seq
{
	struct Cus queue[1000]; //�ͻ��ȴ�����
	int front, rear; //��β����ͷ
	int Size; //���Ŷ�������
}SeqOrdCus, SeqVipCus;
		
bool init(FILE *fp);

void VipInit();
void VipChange();
bool is_Vip(int ID);

void input(char *order);

bool AddOrdCus(int TypeBus);
struct Cus PopOrdCus();
bool AddVipCus(int TypeBus, int VipID);
struct Cus PopVipCus();

void Control();
bool try_to_rest(int TypeCou, int ID);
bool is_finish();

void output();

bool log(FILE *fp);

bool statistics(FILE *fp);

#endif /* __HEADER_H */
