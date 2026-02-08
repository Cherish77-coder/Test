#include"queue.h"
void QueueInit(Queue* q)
{
	assert(q);
	q->phead = q->ptail = NULL;
	q->size = 0;
}
void QueueDestory(Queue* q)
{
	assert(q);
	while (q->phead != q->phead)
	{
		QNode* next = q->phead->next;
		free(q->phead);
		q->phead = next;
	}
	free(q->phead);
	q->phead = q->ptail = NULL;
	q->size = 0;

}
void QueuePush(Queue* q, Datatype x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("QueuePush::malloc");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;
	if (q->phead == NULL)
	{
		q->phead = q->ptail = newnode;
	}
	else
	{
		q->ptail->next = newnode;
		q->ptail = newnode;
	}
	q->size++;
}
void QueuePop(Queue* q)//Ƚȳ
{
	assert(q && q->size > 0);
	QNode* next = q->phead->next;
	free(q->phead);
	q->phead = next;
	q->size--;
	if (q->size == 0)
	{
		q->phead = q->ptail = NULL;
	}
}
Datatype QueueFront(Queue* q)
{
	assert(q);
	assert(q->phead);
	return q->phead->val;
}
Datatype QueueBack(Queue* q)
{
	assert(q);
	assert(q->size > 0);
	return q->ptail->val;
}
int Queuesize(Queue* q)
{
	assert(q);
	return q->size;
}
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0 ? true : false;
}