#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int datatype;
typedef struct ListNode
{
	datatype data;
	struct List* prev;
	struct List* next;
}ListNode;
ListNode* LTinit();//头节点的初始化
ListNode* BuyNode(datatype x);//新节点的创建；
void LTprint(ListNode* phead);//链表的打印
void LTPushBack(ListNode* phead,datatype x);//链表尾插
void LTPushFront(ListNode* phead, datatype x);//链表头插；
void LTPopBack(ListNode* phead);//尾删
void LTPopFront(ListNode* phead);//头删除
void LTInsert(ListNode* pos,datatype x);//指定位置的尾插
ListNode* LTFind(ListNode* phead, datatype x);
void LTErase(ListNode* pos);//指定位置删除
void LTDestory(ListNode* phead);

