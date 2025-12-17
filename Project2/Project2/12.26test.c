#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void calcu(int(*pa)(int,int), int x, int y)
{
	printf("请输入两个操作数：\n");
	scanf("%d %d", &x, &y);
	int ret = (*pa)(x, y);
	printf("%d\n", ret);
}
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int multi(int x, int y)
{
	return x * y;
}
int dive(int x, int y)
{
	return x / y;
}
void menu()
{
	printf("------------calculate-------------\n");
	printf("--------1:add-------2:sub---------\n");
	printf("--------3:multi-----3:dive--------\n");
	printf("---------------0:exit  -----------\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");
}

int main()
{
	int n = 0;
	int a = 0, b = 0;
	int ret = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			calcu(add, a, b);
			break;
		case 2:
			calcu(sub, a, b);
			break;
		case 3:
			calcu(multi, a, b);
			break;
		case 4:
			calcu(dive, a, b);
			break;
		default:
			printf("请重新输入：");
		}
	} while (n);
}
//int main()
//{
//	char str1[] = "hello bit.";//可变类型
//	char str2[] = "hello bit.";//可变类型 所以str1和str2，在内存中储存位置不同访问地址不同，所以str1！=str2；
//	const char* str3 = "hello bit.";//常量类型
//	const char* str4 = "hello bit.";//常量类型字符串，所以str4和str3访问同一个地址，str3==str4;C/C++会把常量字符串存储到单独的?个内存区域，
//当?个指针指向同?个字符串的时候，他们实际会指向同?块内存。
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char* parr = "hellow world";
//	int i = 0;
//	int sz = strlen(parr);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%c", parr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int*p[3] = { arr1,arr2,arr3 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < sz; j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}