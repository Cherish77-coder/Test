#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	return 0;
}
 
// int fib(int n)
//{
//	 int fib[45];
//	 fib[1] = 1;
//	 fib[2] = 1;
//	 for (int i = 3; i <= n; i++)
//	 {
//		 fib[i] = fib[i - 1] + fib[i - 2];//利用数组存放计算过的值；
//	 }
//	 return fib[n];
//}
//int mainjjejejejej
//{
//	 int n = 40;
//     int sum = fib(n);
//	printf("%d", sum);
//	return 0;
//}

//sum_fun(int arr[], int n)
//{
//	return n == 1 ? arr[n - 1] : arr[n - 1] + sum_fun(arr, n - 1);//利用三目操作符避免了if的使用；
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int num = sum_fun(arr, sz);
//	printf("%d", num);
//	return 0;
//}
//void reverse( int n)
//{
//	if (n < 10)
//	{
//		printf("%d", n);
//		return;
//	}
//	printf("%d", n % 10);
//	reverse(n / 10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n < 0)
//	{
//		printf("-");
//		int m = -n;
//		reverse(m);
//	}
//	else
//	reverse(n);
//	return 0;
//}