#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
int main()
{
	SL a;
	SLInit(&a);
	SLPushBack(&a, 0);
	SLPushBack(&a, 1);
	SLPushBack(&a, 2);
	SLPushBack(&a, 3);
	SLPushBack(&a, 3);
	SLPrint(&a);
	SLPushFront(&a,8);
	SLPrint(&a);
	SLPushFront(&a, 9);
	SLPrint(&a);
	SLPushFront(&a, 10);
	SLPrint(&a);
	SLPushFront(&a, 11);
	SLPrint(&a);
	SLPopBack(&a);//尾部删除数据
	SLPrint(&a);
    SLPopFront(&a);//头部删除数据
	SLPrint(&a);
	SLDestroy(&a);

	return 0;

}