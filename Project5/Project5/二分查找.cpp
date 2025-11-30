#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,45,66,78,89,91,99,100};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0,
		right = sz-1,
		mid = 0,
		n, f = 0;
	printf("请输入要查找的数字：");
	scanf("%d", &n);
	while (left <= right)
	{
		mid=left + (right - left) / 2;
		if (n == arr[mid])
		{
			f=1;
			break;
		}
		else if (n < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		
	}
	if (f == 1)
		printf("找到了，它储存在arr[%d]中\n", mid);
	else
		printf("它不在这个数组之中\n");
	
	return 0;
}