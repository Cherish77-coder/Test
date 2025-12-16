#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int m = 0;
	scanf("%d",&m);
	for (i = 1; i <=m ; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%-2d*%-2d=%-4d", j, i, i * j);
		}
		printf("\n");
	}
	return 0;
		
}