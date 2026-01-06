#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int convert_arr(char*pa,char*pb, int len)
{
	int i = 0;
	int count=0;
	char temp= *pa;
	rever:
	for (i = 0; i < len-1; i++)
	{
		*(pa + i) = *(pa + i + 1);
	}
	*(pa + len - 1) = len;
	for (i = 0; i < len; i++)
	{
		if (*pa != *pb)
			goto rever;
		count++;
	}
	if (count == len)
		return 1;
	else
	return 0;
}

int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "bcdefga";
	int len = strlen(arr1);
	int ret = convert_arr(arr1, arr2, len);
		printf("%d\n", ret);
	return 0;
}
//void buble_sort(int* pa, int len)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len-1; i++)
//	{
//		for (j = 0; j < len - i-1; j++)
//		{
//			if (*(pa + j) > *(pa + j + 1))
//			{
//				int temp = *(pa + j);
//				*(pa + j) = *(pa + j + 1);
//				*(pa + j + 1) = temp;
//			}
//		}
//	}
//}
//void print(int*pa,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(pa + i));
//	}
//}
//int main()
//{  
//	int arr[] = { 4,3,5,7,11,9,1,22,34 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	buble_sort(arr, len);
//	print(arr, len);
//	return 0;
//}
//void print(int*pa,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(pa + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}