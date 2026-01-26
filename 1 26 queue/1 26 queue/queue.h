#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datatype;
typedef struct queueNode
{
	Datatype val;
	struct queueNode* next;
}QNode;
typedef struct
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
void QueueInit(Queue* q);//队列初始化
void QueueDestory(Queue* q);//队列销毁
void QueuePush(Queue* q,Datatype x);//队列入列
void QueuePop(Queue* q);//队列出列
Datatype QueueFront(Queue* q);//返回队列头部元素
Datatype QueueBack(Queue* q);//返回队列尾部元素
int Queuesize(Queue* q);//返回队列长度
int QueueEmpty(Queue* q);//判断队列是否为空