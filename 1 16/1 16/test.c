#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define N 4
int ys_find(int arr[N][N],int row,int col,int key)
{
	int i = 0;
	while (row >= 0 && key != arr[i][col-1]&&col>1)
	{
		if (key > arr[i][col - 1])
			i++;
		else
			col--;
	}
	if (arr[i][col - 1] == key)
		return 1;
		return 0;
}
int main()
{
	int arr[N][N] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int ret = ys_find(arr, N, N,101);
	printf("%d\n", ret);
	return 0;
}
//int if_reverse(char* str1, char* str2)
//{
//	char aa[100] = { 0 };
//	strcpy(aa, str1);
//	char* ptail = str1;
//	char* patail = aa;
//	while (*patail)
//	{
//		patail++;
//	}
//		strcpy(patail, str1);
//	char*p=strstr(aa, str2);
//	if (p == NULL)
//		return 0;
//	else 
//		return 1;
//}
//int main()
//{
//	char a[] = "abcde";
//	char b[] = "bcdea";
//	printf("%d\n", if_reverse(a, b));
//	return 0;
//}
//void buble_sort(int*pa,int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (pa[j] > pa[j + 1])
//			{
//				int temp = pa[j];
//				pa[j] = pa[j + 1];
//				pa[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,45,3,32 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	buble_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//void print(int* p,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//}
//char* my_strcopy(char* dest, const char* sour)
//{
//	while (*sour)
//	{
//		*dest++ = *sour++;
//	}
//}
//int main()
//{
//	char a2[30] = { 0 };
//	char a3[] = "hellow world";
//	my_strcopy(a2, a3);
//	printf("%s\n", a2);
//	return 0;
//}
//void my_cat(char* dest, const char* sour)
//{
//	while (*dest!='\0')
//	{
//		dest++;
//	}
//	while (*sour)
//	{
//		*dest = *sour;
//		dest++;
//		sour++;
//	}
//	return;
//}
//int main()
//{
//	char a1[30] = "jashdsad";
//	char a2[] = "asjdh";
//	my_cat(a1, a2);
//	printf("%s\n", a1);
//}
//int MyStrlen(char* pa)
//{
//	char* ptail = pa;
//	while (*ptail!='\0')
//	{
//		ptail++;
//	}
//	return (ptail - pa);
//}
//int main()
//{
//	char a[] ="ajhksdmmmg";
//	printf("%d\n", MyStrlen(a));
//}
//nclude<time.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		int count = 0;
//		for (int j = 0; j < sz; j++)
//		{
//			if (arr[i] == arr[j] && i != j)
//			{
//				count=1;
//				break;
//			}
//				
//		}
//		if (count == 0)
//		{
//			printf("%d\n", arr[i]);
//		}
//		
//	}
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	while (scanf("%d %d", &year, &month)!=EOF) {
//		if ((month == 2) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
//		{
//			printf("%d\n", 29);
//		}
//		else
//			printf("%d\n", arr[month]);
//
//	}
//	return 0;
//}
//void swap1(int x, int y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//void swap2(int* pa, int* pb)
//{
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap1(a, b);
//	printf("a=%d b=%d\n", a, b);
//	swap2(&a, &b);
//	printf("a=%d b=%d\n", a, b);//思考两次的a，b值是否相同
//	return 0;
//}
//int main()
//{
//	int n = 2;
//	int* p = &n;
//	printf("%p", p);
//	return 0;
//}
//int main()
//{
//	int n = 100000;
//	int m = 0, i = 0,j=0;
//	int begin = clock();
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			m++;
//			/*printf("%d\n", m);*/
//		}
//	}
//	int end = clock();
//	printf("%dms\n", end - begin);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int a = 0;
//	scanf("%d", &n);
//	scanf("%d", &a);
//	int m = 0, t = 0;
//	int b = 0;
//	while (n)
//	{
//		t = n % 2;
//		m=m << 1;
//		m = m | t;
//		n = n / 2;
//	}
//	while (a)
//	{
//		t = a % 2;
//		b = 2 * b + t;
//		a = a / 2;
//	}
//	printf("%d\n", m);
//	printf("%d", b);
//	return 0;
//}