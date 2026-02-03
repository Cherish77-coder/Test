
#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
#include<time.h>
void HeapSort(int* arr, int n);
void test3()
{
	int k = 0;
	scanf("%d", &k);
	FILE* pfout = fopen("test.txt", "r");
	if (pfout == NULL)
	{
		perror("fopen:");
		return;
	}
	int* arr = (int*)malloc(k * sizeof(int));
	if (arr == NULL)
	{
		perror("malloc fail:");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(pfout, "%d", &arr[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustup(arr, i);//建堆
	}
	int temp = 0;
	while (fscanf(pfout, "%d", &temp) != EOF)
	{
		if (temp > arr[0])
			arr[0] = temp;
		AdjustDown(arr, k, 0);
	}
	fclose(pfout);
	pfout = NULL;
	HeapSort(arr, k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
}
void createnumbers(int n)
{
	srand((unsigned int)time);
	const char* pf = "test.txt";
	FILE* pfin= fopen(pf, "w");
	if (pfin == NULL)
	{
		perror("fopen:");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 100000;
		fprintf(pfin, "%d\n",x );
	}
	fclose(pfin);
	pfin == NULL;

}
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
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}
	//向下调整建堆O（N）
	int end = n - 1;
	while (end)//从后往前排就是小堆
	{
		swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
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
	//createnumbers(100000);
	test3();
	return 0;
}