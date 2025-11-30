#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() 
{
	int  i, n = -1;
	float sum = 0;
	for (i = 1; i <= 100; i++)
	{
		int k = i;
		if (k % 2 == 0) {
			k *= n;
		}
		sum += 1.0 / k;
	}
	printf("sum=%f", sum);
	return 0;
}