#include"Heap.h"
HeapInit(Heap* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}
void swap(Hdatatype* p1,Hdatatype* p2)
{
	assert(p1 && p2);
	Hdatatype temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
HeapDestory(Heap* php)
{
	php->capacity = php->size = 0;
	free(php->arr);
	php->arr = NULL;
}
HeapPush(Heap* php,Hdatatype x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		Hdatatype* p = realloc(php->arr, sizeof(Hdatatype) * newcapacity);
		if (p == NULL)
		{
			perror("Heapush::relloc");
			exit(1);
		}
		php->arr = p;
		php->capacity = newcapacity;
	}
	php->arr[php->size++] = x;
	Adjustup(php->arr, php->size - 1);//插入数据后要对他进行位置的调整

}
Adjustup(Hdatatype* arr, Hdatatype child)//向上调整
{
	assert(arr);
	while (child>0)
	{
		int parent = (child - 1) / 2;
		if (arr[child] > arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
		
	}
}
AdjustDown(Hdatatype* arr, int n, int parent)
{
	int child = parent * 2 + 1;//假设左孩子小
	while (child<n)
	{
		if (arr[child] < arr[child + 1]&&child+1<n)
		{
			child = child + 1;
		}
		if (arr[parent] < arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
HeapPop(Heap* php)
{
	assert(php);
	assert(php->size);
	swap(&php->arr[0],& php->arr[php->size - 1]);
	php->size--;
	AdjustDown(php->arr,php->size,0);//删除位置后也要调整因为你是直接交换到头节点所以要向下调整
}
Hdatatype HeapTop(Hdatatype* arr)
{
	assert(arr);
	return arr[0];
}
bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}