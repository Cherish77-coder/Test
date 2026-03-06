#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void ArryPrint(int* arr, int size);
void BubbleSort(int*a,int size);
void HeapSort(int* a, int n);
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void QuickSort(int* a, int left, int right);
void QuickSort02(int* a, int left, int right);//ָ�뷨
void QuickSortNonR(int* a, int left, int right);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void subMergeSortNonR(int* a, int n);