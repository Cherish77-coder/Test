#include"List.h"
void SLInit(SL* ps)
{
	assert(ps);
	ps->capacity = ps->size = 0;
	ps->a = NULL;
}
void SLDestroy(SL* ps)
{
	assert(ps);
	ps->capacity = ps->size = 0;
	free(ps->a);
}
void SLPrint(SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("没有元素，不可打印\n");
	}
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//扩容
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* p = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (p == NULL)
		{
			perror("SLCheckCapacity::realloc fail");
			exit(1);
		}
		ps->a = p;
		ps->capacity = newcapacity;
	}
	
}
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->a);
	if (ps->size == 0)
	{
		printf("没有元素，删除失败\n");
		return;
	}
	else
	{
		ps->size--;
	}
}
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	
	if (ps->size == 0)
	{
		SLPushBack(ps, x);
	}
	else
	{
		SLCheckCapacity(ps);
		int temp = ps->size - 1;
		assert(ps->a);
		while (temp >= 0)
		{
			ps->a[temp + 1] = ps->a[temp];
			temp--;
		}
		ps->a[0] = x;
		ps->size++;
	}
}
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->a);
	if (ps->size == 0)
	{
		printf("删除失败没有足够元素\n");
		return;
	}
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(ps->a);
	if (pos >= ps->size||pos<0)
	{
		printf("位置有误,插入失败\n");
	}
	else if (pos == 0)
	{
		SLPushFront(ps, x);
	}
	else
	{
		SLCheckCapacity(ps);
		for (int i = ps->size; i >pos ; i--)
		{
			ps->a[i] = ps->a[i-1];//a[pos+1]=a[pos]
		}
		ps->a[pos] = x;
		ps->size++;
	}
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->a);
	if (pos > ps->size - 1 || pos < 0)
	{
		printf("输入位置有误，删除失败\n");
		return;
	}
	if (ps->size == 0)
	{
		printf("删除失败\n");
		return;
	}
	else
	{
		for (int i = pos; i < ps->size-1; i++)
		{
			ps->a[i] = ps->a[i + 1];//a[size-2]=a[size-1]
		}
		ps->size--;
	}
}
int SLFind(SL* ps, SLDataType x)
{
	assert(ps && ps->a);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}