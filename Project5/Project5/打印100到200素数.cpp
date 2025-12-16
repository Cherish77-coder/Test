#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void is_prime(int x,int y)
{
	for (x = 100; x <= y; x++)
	{
		int count = 0;
		for (int n = 2; n < x / 2; n++)
		{
			if (x % n == 0)
			{
				count++;
				break;
			}
		}
		if (count == 0)
			printf("%d ", x);
	}
}
int main()
{
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);
	is_prime(x, y);
	return 0;
}