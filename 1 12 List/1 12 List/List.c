#include"List.h"
ListNode* LTinit()
{
	ListNode* node = BuyNode(-1);
	return node;
}
ListNode* BuyNode(datatype x)
{

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		perror("mallpc");
		exit(1);
	}
	node->next = node;
	node->prev = node;
	node->data = x;
	return node;
}
void LTprint(ListNode* phead)
{
	ListNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}
void LTPushBack(ListNode* phead,datatype x)
{
	ListNode* newnode = BuyNode(x);
	newnode->next = phead;
	newnode->prev = phead->prev;
	ListNode* prev=phead->prev;
		prev->next = newnode;
		/*phead->prev->next = newnode;*///ÐÂ°æ±àÒëÆ÷±¨´í£¿
	phead->prev = newnode;
}
void LTPushFront(ListNode* phead, datatype x)
{
	ListNode* newnode = BuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	ListNode* next = phead->next;
	next->prev = newnode;
	phead->next = newnode;
}
void LTPopBack(ListNode* phead)
{
	assert(phead&&phead->next!=phead);
	ListNode* ptail = phead->prev;
	ListNode* newtail = ptail->prev;
	newtail->next = phead;
	phead->prev = newtail;
	ptail->next = phead;
	free(ptail);
	ptail = NULL;
}
void LTPopFront(ListNode* phead)
{
	assert(phead && phead->next != phead);
	ListNode* del = phead->next;
	ListNode* next = del->next;
	phead->next = next;
	next->prev = phead;
}
void LTInsert(ListNode* pos, datatype x)
{
	assert(pos);
	ListNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	ListNode* next = pos->next;
	next->prev = newnode;
	pos->next = newnode;
}
ListNode* LTFind(ListNode* phead, datatype x)
{
	assert(phead && phead->next != phead);
	ListNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}
void LTErase( ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = pos->next;
	next->prev = pos->prev;
	free(pos);
	pos = NULL;
}
void LTDestory(ListNode* phead)
{
	assert(phead);
	ListNode* pcur = phead->next;
	while (pcur != phead)
	{
		ListNode* next = pcur->next;
		next->prev = pcur->prev;
		phead->next = next;
		free(pcur);
		pcur = phead->next;
	}
}