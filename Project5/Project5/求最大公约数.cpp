#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);
	int min = x;
	if (min > y)
		min = y;
	for (int i = min; i >= 1; i--)
	{
		if (x % i == 0 && y % i == 0)
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}