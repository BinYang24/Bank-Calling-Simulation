#ifndef __HEADER_H
#define __HEADER_H

#include <stdio.h>
#include <windows.h>

#define MaxOrdCou  6 //最大普通窗口数目
#define MaxVipCou  2 //最大VIP窗口数目
#define MaxOrdCus  1000 //最大普通用户排队数目
#define MaxVipCus  100 //最大VIP用户排队数目
#define InitOrdCou  3 //初始普通窗口数目
#define InitVipCou  1 //初始VIP窗口数目
#define MaxBus 10 //最大业务种类数
#define bool int
#define true 1
#define false 0
#define DEBUG 0
#define DIVIDER printf("------------------------------------------------------------\n");
#define PROMPT  printf(">>>");

int MaxSeqLen;//单队列最大允许等待长度
int SumBus; //业务种类数
//int MinSec[MaxBus], MaxSec[MaxBus];// 单业务办理时长
int MinSec, MaxSec;// 单业务办理时长
int MinRestSec, MaxRestSec;// 窗口休息最长时长	
int VIPSERVLen;
	//当在设置时长 VIPSERVLen内VIP客户数一直小于3人，则动态关闭增加的VIP窗口，恢复原来窗口数。

int CurOrdCus;// 当前普通用户排队数目
int CurVipCus;// 当前VIP用户排队数目
int CurOrdCou;// 当前普通用户窗口数目
int CurVipCou;// 当前VIP用户窗口数目

enum{ WORK, FREE, OFF };
enum{ ORD, VIP };

int BankState; //银行状态
int CurTime; //当前时间

struct Cou
{
	int ID;
	int TypeCou; //窗口类型
	int TypeBus;
	int state; //窗口状态
	int CusID; //正在服务的客户的号码 
	int EndTime; //服务结束时间
	int SumCus, SumTime;// 窗口服务客户总数，服务总时长
}OrdCou[MaxOrdCou], VipCou[MaxVipCou];

struct Cus
{
	int TypeCus; //客户类型
	int TypeBus; //申请服务的类型
	int VIPID;
};

struct Seq
{
	struct Cus queue[1000]; //客户等待队列
	int front, rear; //队尾，队头
	int Size; //（排队人数）
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
