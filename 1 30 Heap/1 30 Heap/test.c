#include"Heap.h"
void test1()
{
	Heap h;
	HeapInit(&h);
	int a[] = { 3,8,4,2,6,7,1,9 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		HeapPush(&h, a[i]);
	}
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", HeapTop(h.arr));
		HeapPop(&h);
	}
	printf("\n");
	if (HeapEmpty(&h))
	{
		printf("empty\n");
	}
	else
		printf("not empty\n");
}
void HeapSort(int* arr, int n)
{
	//排降序,建造小堆
	//for (int i =1; i<n ; i++)//一部一部向下调整O(N*logN)
	//{
	//	AdjustDown(arr, n, i);
 //    }
	for (int i=(n-1-1)/2;i>=0;i--)
	{
		AdjustDown(arr, n, i);
	}
	//向下调整建堆O（N）
	int end = n - 1;
	while (end)//从后往前排就是小堆
	{
		swap(&arr[0], &arr[end]);
		AdjustDown(arr, end,0);
		end--;
	}
}
void test2()
{
	int arr[] = { 1,2,5,6,7,54,33,2,43,45,77,23,43,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	
}
int main()
{
	test1();
	return 0;
}