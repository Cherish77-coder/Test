#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//#define N 100 
//struct SeqList//静态顺序表
//{
//	int arr[N];
//	int size;
//};
typedef int typeSeq;
typedef struct SeqList
{
	typeSeq *arr;
	int size;
	int capacity;

}SL;//动态顺序表
void SLInit(SL* ps);//初始化
void SLDestroy(SL* ps);//销毁
void SLPrint(SL* ps);//打印顺序表
void SLCheckCapacity(SL* ps);//检查空间，若不够则申请开辟
void SLPushBack(SL* ps, typeSeq x);//数组尾部插入数据
void SLPushFront(SL* ps, typeSeq x);//数组头部插入数据
void SLPopBack(SL* ps);//尾部删除数据
void SLPopFront(SL* ps);
//