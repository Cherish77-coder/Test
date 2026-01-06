#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
void SLInit(SL* ps)
{
	ps->arr = NULL;
	(ps->size) = 0;
	ps->capacity = 0;	
}
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->size = 0;
		ps->capacity = 0;
	}
	
}
void SLPrint(SL* ps)
{
	assert(ps->arr);
	for(int i=0;i<ps->size;i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}
void SLCheckCapacity(SL* ps)
{
	typeSeq Newcapacity = ps->capacity ==0 ? 4 : ps->capacity * 2;
	if (ps->size == ps->capacity)
	{
		
		SL* temp = (SL*)realloc(ps->arr, Newcapacity*sizeof(typeSeq));
		if (temp == NULL)
		{
			perror("realloc");
			return;
		}
		ps->arr = temp;
		ps->capacity = Newcapacity;
	}
	
}
void SLPushBack(SL* ps, typeSeq x)//Î²²¿²åÈëº¯Êý
{
	SLCheckCapacity(ps);
	ps->arr[ps->size++ ] = x;	
}
void SLPushFront(SL* ps, typeSeq x)
{
	SLCheckCapacity(ps);
	for (int i = ps->size-1; i>=0 ; i--)
	{
		ps->arr[i+1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->size++;
}
void SLPopBack(SL* ps)
{
	assert(ps->arr);
	assert(ps);
	ps->size--;
}
void SLPopFront(SL* ps)
{
	assert(ps->arr);
	assert(ps);
	for (int i = 0; i<ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//
