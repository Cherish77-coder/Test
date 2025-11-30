#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		int num = i;
		while (num != 0)
		{
			if (num % 10 == 9)
			{
				count++;
			}
			num/=10;
		}
	}
	printf("1到100中9的出现次数是:%d\n", count);
	return 0;
}