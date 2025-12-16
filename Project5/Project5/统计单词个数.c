#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a[100] = { 0 };
	gets(a);
	int i = 0;
	int j = 0;
	for (i = 0; i < 99; i++)
	{
		if (a[i] ==' ')
			j++;
	}
	printf("%d\n", j+1);
	return 0;
}