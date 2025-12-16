#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int hannuo(int x)
{
	int sum = 0;
	if (x == 1)
	{
		sum = 1;
	}
	else
	{
		x--;
		sum += 2 * hannuo(x)+1;
	}
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", & n);
	int ret = hannuo(n);
	printf("%d\n", ret);
	return 0;
}