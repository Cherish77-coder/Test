#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef struct BinaryTreeNode* Datatype;
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
void QueueInit(Queue* q);//гʼ
void QueueDestory(Queue* q);//
void QueuePush(Queue* q, Datatype x);//
void QueuePop(Queue* q);//г
Datatype QueueFront(Queue* q);//ضͷԪ
Datatype QueueBack(Queue* q);//ضβԪ
int Queuesize(Queue* q);//ضг
bool QueueEmpty(Queue* q);//ж϶ǷΪ