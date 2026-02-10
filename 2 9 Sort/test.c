#include"Sort.h"
#include<assert.h>
int* createarry()
{
	int* a = (int*)malloc(sizeof(int) * 40);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}
	srand(time(0));
	for (int i = 0; i < 40; i++)
	{
		a[i] = rand()%1000;
	}
	return a;
}
void TestBubbleSorrt()
{
	int arr[] = { 9,8,7,6,4,3,5,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	Printf(arr, sz);
}
void TestHeapSorrt()
{
	int arr[] = { 9,8,7,6,4,3,5,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	Printf(arr, sz);
}
void TestInsertSorrt()
{
	int arr[] = { 9,8,7,6,4,3,5,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	Printf(arr, sz);
}
void TestShellSorrt()
{
	int arr[] = { 9,8,7,6,4,3,5,2,19,8,7,6,4,3,5,2,1,9,8,7,6,4,3,5,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	Printf(arr, sz);
}
void TestSelectSorrt()
{
	int arr[] = { 9,8,7,6,4,3,5,2,19,8,7,6,4,3,5,2,19,8,7,6,4,3,5,2,1,9,8,7,6,4,3,5,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	Printf(arr, sz);
}
void TestQuickSort()
{
	int arr[] = { 9,8,7,6,4,3,5,2,19,8,7,6,4,3,5,2,1,9,8,7,6,4,3,5,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0,sz-1);
	Printf(arr, sz);
}
void TestQuickSort02()
{
	int arr[] = { 9,8,7,6,4,8,7,6,4,3,5,2,19,8,7,6,4,3,5,2,19,8,7,6,4,3,5,2,19,8,7,6,4,3,5,2,1,9,8,7,6,4,3,5,2,1 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	Printf(arr, sz);
	QuickSort02(arr, 0, sz - 1);
	Printf(arr, sz);
}
void TestQuickSortNonR()
{
	int arr[] = { 9,8,7,6,4,3,5,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, 0, sz - 1);
	Printf(arr, sz);
}
void TestMergeSort()
{
	int arr[] = { 8,7,6,4,3,5,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, sz);
	Printf(arr, sz);
}
void TestMergeSortNonR()
{
	int* a = createarry();
	int sz = 40;
	Printf(a, sz);
	MergeSortNonR(a, sz);
	Printf(a, sz);
}

void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	assert(a1 && a2 && a3 && a4 && a5 && a6);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand()+i;
		/*a1[i] = rand()%10000+i;*/
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	/*InsertSort(a1, N);*/
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	/*SelectSort(a3, N);*/
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6); 
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}
int main()
{
	//TestQuickSortNonR();
	//TestOP();
	TestMergeSortNonR();
		return 0;
}