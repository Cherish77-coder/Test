#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void int_print(void* p, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ",*((int*)p+i));
	}
}
int  int_cmp(const void* p1,const void* p2)
{
	return *((int*)p1) - *((int*)p2);
}
void swap(const void* p1,const void* p2,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char temp = *((char*)p2+i);
		*((char*)p2+i) =*((char*) p1+i);
		*((char*)p1+i) = temp;
	}
}
void my_qsort(void*p,int len,int size,int(* fun)(void*,void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len-1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (fun((char*)p + j * size, (char*)p + (j+1) * size)>0)
				swap((char*)p + j * size, (char*)p + (j+1) * size, size);
		}
	}
}
int main()
{
	int arr[] = { 18,4,7,5,3,2,5,7,8,54,34 };
	my_qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	int_print(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}