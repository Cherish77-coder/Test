#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int arr[10];
	int max = 0;
	for (int i = 0; i <= 9; i++)
	{
		scanf("%d", &arr[i]);
		for (int n = 0; n <= 9; n++)
		{
			if (arr[n] >= max)
				max = arr[n];
		}
	}
	printf("这10个数中最大的是：%d\n", max);
	return 0;
}