#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[] = { 1,2,3,3,4,5,5,6,6 };
	int* pa = &a;
	int sz = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < sz;i++)
	{
		printf("%d\n",*(pa+i));
	}
	return 0;
}
//int my_strlen(char * pa)
//{
//	int count = 0;
//	while (*pa != '\0')
//	{
//		pa++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char a[] = "abcdefg";
//	int len =my_strlen(&a);
//	printf("%d\n",len);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int *const pa = &a;
//	*pa = 20;
//	printf("%d\n", a);
//	return 0;
//}
//void exchange(int* pa, int* pb)
//{
//	int num = *pa;
//	*pa = *pb;
//	*pb = num;
//}
//int main()
//{
//	int a = 0;
//	int b = 90;
//	printf("交换前a=%d,b=%d\n", a, b);
//	exchange(&a, &b);
//	printf("交换后a=%d,b=%d\n", a, b);
//	return 0;
//}
//long int Feb(int n)
//{
//	long int a = 1;
//	long int b = 1;
//	long int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	long int ret=Feb(n);
//	printf("%d", ret);
//	return 0;
//}
//int main()
//{
//	int arr[] = { 78 ,45 ,32 ,10 ,29 ,80, 92 ,8, 61 ,55 };
//	int i = 0;
//	int length = sizeof(arr) / sizeof(arr[0]);
//	for (int j = length - 1; j > 0; j--)
//	{
//		for (i = 0; i < j; i++)
//		{
//			int n = arr[i+1];
//			if (arr[i] > arr[i+1])
//			{
//				arr[i + 1] = arr[i];
//				arr[i] = n;
//				
//			}
//		}
//	}
//	for (i = 0; i < length; i++)
//	{
//		printf("%d ", arr[i]);
//}
//	return 0;
//}
//int fact(unsigned n)
//{
//	if (n == 0)
//		return 1;
//	else
//		return n*fact(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	fact(n);
//	int ret = fact(n);
//	printf("%d", ret);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 1; 
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("%d", ret);
//	return 0;
//}
//void Print(int n)
//{
//	if (n > 9)
//	{
//		Print(n / 10);
//	}
//	
//		printf("%d ", n % 10);
//}
//int main() 
//{
//	int n = 0;
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}