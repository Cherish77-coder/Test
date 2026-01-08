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
//void SLPrint(SL* ps)
//{
//	assert(ps->arr);
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//}
void SLCheckCapacity(SL* ps)
{
	int Newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	if (ps->size == ps->capacity)
	{

		SL* temp = (SL*)realloc(ps->arr, Newcapacity * sizeof(typeSeq));
		if (temp == NULL)
		{
			perror("realloc");
			return;
		}
		ps->arr = temp;
		ps->capacity = Newcapacity;
	}

}
void SLPushBack(SL* ps, typeSeq x)//尾部插入函数
{
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}
void SLPushFront(SL* ps, typeSeq x)
{
	SLCheckCapacity(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
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
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//顺序表的指定位置插入
void SLInsert(SL* ps, int pos, typeSeq x)
{
	SLCheckCapacity(ps);
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//arr[pos+1]=arr[pos]
	}
	ps->arr[pos] = x;
	ps->size++;
}
void SLErase(SL* ps, int pos)//指定位置删除数据
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//arr[size-2]=arr[size-1]
	}
	ps->size--;
}
//int SLFind(SL* ps, typeSeq x)//查找数据在数组中的位置
//{
//	assert(ps);
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == x)
//		{
//			printf("找到了%d的位置在下标为%d的arr数组中\n", x, i);
//			return i;
//		}
//
//
//	}
//	printf("很抱歉该数字:%d没有在数组中\n", x);
//	return -1;
//}
