#include<stdio.h>
void Log(FILE *fp)//Êä³öµ½ÎÄ¼þÖÐ 
{
	int i = 1;
	fprintf(fp, "µ±Ç°Ê±¼ä:%d\n", Curtime);
	fprintf(fp, "×î´óÆÕÍ¨¿Í»§ºÅÂë:%d\n", SeqOrdCus.queue[SeqOrdCus.rear - 1]);
	fprintf(fp, "×î´óVip¿Í»§ºÅÂë:V%d\n", SeqVipCus.queue[SeqVipCus.rear - 1]);
	fprintf(fp, "µ±Ç°ÆÕÍ¨ÓÃ»§ÅÅ¶ÓÊýÄ¿:%d\n", CurOrdCus);
	fprintf(fp, "µ±Ç°VipÓÃ»§ÅÅ¶ÓÊýÄ¿£º%d\n", CurVipCus);
	for (; i <= 6; i++)
		switch (OrdCou[i].state){
	WORK:fprintf(fp, "%dºÅÆÕÍ¨´°¿Ú£ºÕýÔÚÓªÒµ %d\n", i, OrdCou[i].CusID); break;
	FREE:fprintf(fp, "%dºÅ´°¿Ú£ºÕýÔÚµÈ´ý %d\n", i, SeqOrdCus.queue[SeqOrdCus.front + 1]); break;
	OFF:fprint(fp, "%dºÅ´°¿Ú£ºÕýÔÚÐÝÏ¢\n"); break;
	}
	for (i = 1; i <= 2; i++)
		switch (VipCou[i].state){
	WORK:fprintf(fp, "%dºÅVip´°¿Ú£ºÕýÔÚÓªÒµ %d\n", i, VipCou[i].CusID); break;
	FREE:fprintf(fp, "%dºÅVip´°¿Ú£ºÕýÔÚµÈ´ý %d\n", i, SeqVipCus.queue[SeqVipCus.front + 1]); break;
	OFF:fprintf(fp, "%dºÅVip´°¿Ú£ºÕýÔÚÐÝÏ¢\n"); break;
	}
	switch (BankState)
	{
	WORK:fprintf(fp, "ÒøÐÐÕýÔÚÓªÒµ\n"); break;
	OFF:fprintf(fp, "ÒøÐÐÒÑÏÂ°à\n"); break;
	}


}