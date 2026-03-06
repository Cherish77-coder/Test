#include"Sort.h"
#include<stdlib.h>
void BubbleSortTest()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	ArryPrint(arr, sz);
}
void HeapSortTest()
{
	int arr[] = { 2,9,6,7,8,1,4,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	/*for (int i = (sz - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, sz, i);
	}
	ArryPrint(arr, sz);*/
	HeapSort(arr, sz);
	ArryPrint(arr, sz);
}
void SelectSortTest()
{
	int arr[] = { 2,9,6,7,8,1,4,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	ArryPrint(arr, sz);
}
void InsertSortTest()
{
	int arr[] = { 2,9,6,7,8,1,4,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	ArryPrint(arr, sz);
}
void ShellSortTest()
{
	int arr[] = { 2,9,6,7,8,1,4,3,12,3,4,446,45,23,45,67,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	ArryPrint(arr, sz);
}
void QuickSortTest()
{
	int arr[] = {6,4,2,1,7,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, sz - 1);
	ArryPrint(arr, sz);
}
void QuickSortTest02()
{
	int arr[] = { 6,4,2,1,7,82,9,6,7,8,1,4,3,12,3,4,446,45,23,45,67,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort02(arr, 0, sz - 1);
	ArryPrint(arr, sz);
}
void QuickSortNonRTest()
{
	int arr[] = { 6,4,2,1,7,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, 0, sz - 1);
	ArryPrint(arr, sz);
}
void MergeSortTest()
{
	int arr[] = { 6,4,2,1,7,82,9,6,7,8,1,4,3,12,3,4,446,45,23,45,67,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, sz);
	ArryPrint(arr, sz);
}
void MergeSortNonRTest()
{
	int arr[] = { 2,9,6,7,8,1,4,3};
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSortNonR(arr, sz);
	ArryPrint(arr, sz);
}

int main()
{
	//ShellSortTest();
	//QuickSortNonRTest();
	MergeSortNonRTest();
	return 0;
}
