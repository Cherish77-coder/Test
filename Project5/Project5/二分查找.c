#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int bin_search(int arr[], int left, int right, int key)
{
	int f = 0;
	int m = 0;
	while (left <= right)
	{
		int mid = (right - left) / 2 + left;
		if (arr[mid] == key)
		{
			m = mid;
			f++;
			break;
		}
		 if (arr[mid] > key)
		{
			right = mid - 1;
		}
		 if(arr[mid]<key)
		{
			left = mid +1;
		}
		
	}
	if (f==1)
		return m;
	else
	return -1;
}
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 0;
	int sz = sizeof(a) / sizeof(a[0]);
	scanf("%d", &key);
	int ret = bin_search(a, 0, sz-1, key);
		printf("%d\n", ret);
	return 0;
}