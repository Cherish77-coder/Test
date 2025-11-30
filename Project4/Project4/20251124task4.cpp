#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n = 0;
        scanf("%d", &n);
        int a[32767] = { 0 };
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
    }
    return 0;
}
//int main(void)
// 
//{
//    int x[] = { 1,3,5,7,2,4,6,0 }, i, j, k;
//    for (i = 0; i < 3; i++)
//        for (j = 2; j >= i; j--)
//            if (x[j + 1] > x[j]) {
//                k = x[j]; x[j] = x[j + 1]; x[j + 1] = k;
//            }
//    for (i = 0; i < 3; i++)
//        for (j = 4; j < 7 - i; j++)
//            if (x[j + 1] > x[j]) {
//                k = x[j]; x[j] = x[j + 1]; x[j + 1] = k;
//            }
//    for (i = 0; i < 3; i++)
//        for (j = 4; j < 7 - i; j++)
//            if (x[j] > x[j + 1]) {
//                k = x[j]; x[j] = x[j + 1]; x[j + 1] = k;
//            }
//    for (i = 0; i < 8; i++)
//        printf("%d", x[i]);
//    printf("\n");
//    return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	printf("hehe\n");//函数调?语句
//	int ret = Add(2, 3);//函数调?语句
//	printf("%d", ret);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//int main()
//{
//	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i <= sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i ,& arr[i]);
//	}
//	return 0;
//}
//{
//	int a[] = { -3, -2, -8, -6, -9, -12 };
//	int length = sizeof(a) / sizeof(a[0]);
//	int sum = 0, max = a[0];
//	for (int i = 0; i <= length; i++)
//	{
//		sum += a[i];
//		if (max <= sum)
//		{
//			max = sum;
//		}
//		if (sum < 0)
//			sum = 0;
//	}
//	printf("%d\n", max);
//	return 0;
//}

//{
//	int i, max = 0;
//	int a[10];
//	for (i = 0; i <=9; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	max = a[0];
//		for (i = 0; i <= 8; i++)
//		{
//			if (a[i] <= a[i + 1])
//			{
//				max += a[i + 1];
//			}
//		}
//		printf("%d", max);
//	return 0;
//}
//{
//	long float e = 1.0, a,k = 1.0;
//	scanf("%lf", &a);
//	for (int n = 1; k>a; n++)
//	{
//		k =(k/n);
//		e += k;
//	}
//	printf("%.10lf",e);
//	return 0;
//}

//int main() {
//    int s = 0, n, a, b = 1;
//    scanf("%d", &n);
//    for (a = 1; a <= n; a++) {
//        b *= a;
//        s += b;
//            printf("%d!=%d\n", a, b);
//     
//    }
//    printf("1!+2!+...n!=%d\n", s);
//    return 0;
//}
//int main() 
//{
//	int max = 0, min;
//	int arr[7] = { 1,2,545,54,87,15,545 };
//	min = arr[0];
//	for (int i = 0; i < 7; i++)
//	{
//		if (arr[i] >= max)
//			max = arr[i];
//		if (min > arr[i])
//			min = arr[i];
//	}
//	printf("max=%d\n", max);
//	printf("min=%d\n", min);
//	printf("max*min=%d\n", max * min);
//	return 0;
//}
//int main() {
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    return 0;
//}
////int main()
//{
//	int num = -8;
//	int count = 0;
//	
//	for (int i = 0; i <= 31; i++)
//	{
//		if ((num >> i) & 1 == 1)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}
//int main()
//{
//	int i = -8, count = 0;
//	while (i!=0)
//	{
//		i = i & (i - 1);
//		count++;
//	}
//	printf("%d", count);
//	return 0;
//}

//{
//	int arr[7] = { 1,5,6,4,7,7,0 };
//	printf("%d", &arr[1]);
//	return 0;
//}
//{
//	int i;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf(" %d", i);
//	}
//	return 0;
//}

//{
//	int i = 0;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf(" %d", i);
//		i++;
//	}
//	return 0;
//}
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d", i, j, i * j);
//		}
//		printf("\n");
//	}
//
//	
//
//	return 0;
//}
//{
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf(" %d", i);
//		}
//	}
//	return 0;