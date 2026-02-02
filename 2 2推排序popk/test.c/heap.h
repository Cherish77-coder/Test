#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int Hdatatype;
typedef struct Heap {
	Hdatatype* arr;
	int size;
	int capacity;

}Heap;
HeapInit(Heap* php);
HeapDestory(Heap* php);
HeapPush(Heap* php, Hdatatype x);
HeapPop(Heap* php);
Hdatatype HeapTop(Hdatatype* arr);
Adjustup(Hdatatype* arr, Hdatatype child);
AdjustDown(Hdatatype* arr, int n, int paarent);
bool HeapEmpty(Heap* php);
void swap(Hdatatype* p1, Hdatatype* p2);