#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int yhtangle(int i, int j)
{
	if (i == j || j == 1)
		return 1;
	else
		return yhtangle(i - 1, j - 1) + yhtangle(i - 1, j);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			printf("  ");
		}

		for (j = 1; j <= i; j++)
		{
			int ret = yhtangle(i,j);
			printf("%4d",ret );
		}
		printf("\n");
	}
	return 0;
}
//void yhtangle(int n)
//{
//	int arr[15][15] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n - i; j++)
//		{
//			printf("  ");
//		}
//		for (j = 0; j<=i; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			else if (i == j)
//				arr[i][j] = 1;
//			else if(i>=2)
//			{
//				arr[i][j] = arr[i - 1][j-1] + arr[i - 1][j];
//			}
//			printf("%-4d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	yhtangle(n);
//	return 0;
//}