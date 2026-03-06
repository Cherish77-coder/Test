#include"stack.h"
void STInit(ST* pst)
{
	pst->arr = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
void STDestory(ST* pst)
{
	assert(pst);
	pst->capacity = 0;
	pst->top = 0;
	free(pst->arr);
	pst->arr = NULL;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top>0);
	pst->top--;
}
void STPush(ST* pst,DataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int Newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		DataType* p1 = (DataType*)realloc(pst->arr, Newcapacity*sizeof(DataType));
		if (p1 == NULL)
		{
			perror("STPush::realloc");
			return;
		}
		pst->capacity = Newcapacity;
		pst->arr = p1;
	}
	pst->arr[pst->top++] = x;
}
DataType STTop(ST* pst)
{
	assert(pst);
	return pst->arr[pst->top - 1];
}
int STValidsize(ST* pst)
{
	return pst->top;
}
bool STEmpty(ST* pst)
{
	return pst->top == 0;
}