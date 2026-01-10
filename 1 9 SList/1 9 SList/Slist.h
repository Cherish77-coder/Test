#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int datatype;
typedef struct SListNode 
{
	datatype Data;
	struct SList* next;
}Node;
void SLprint(Node* phead);
void SLPushBack(Node** pphead,datatype x);
void SLPushFrount(Node** pphead,datatype x);
Node* SLadd(datatype x);
void SLpopBack(Node** pphead);
void SLPopFront(Node** pphead);
//查找
Node* SLFind (Node* phead, datatype x);
//在指定位置之前插数据
void SLInsert(Node** pphead, Node* pos, datatype x);
//删除pos节点
void SLErase(Node * *pphead, Node * pos);
//在指定位置之后插?数据
void SLInsertAfter(Node* pos, datatype x);
//删除pos之后的节点
void SLEraseAfter(Node* pos);
//销毁链表
void SListDesTroy(Node** pphead);
