#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n = 0;
	int num = 0;
	scanf("%d", &n);
	int arr[n][n];
	int i, j;
	for (i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			arr[i][j] = num % 10;
			num++;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		if(i!=n-1)
		printf("\n");
	}
	return 0;
}