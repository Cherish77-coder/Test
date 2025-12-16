#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int  frog(int x)
//{
//	int a = 1;
//	int b = 2;
//	int c = 1;
//	if (x == 2)
//		c = 2;
//	while (x > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		x--;
//	}
//	return c;
//}
//int main()
//{
//	//青蛙要跳上n阶台阶，青蛙每次只能跳1或2步，问有多少种跳法？
//	int n = 0;
//	scanf("%d", &n);
//	int ret = frog(n);
//	printf("%d\n", ret);
//	return 0;
//}
int static frog(int x)
{
	int a = 1;
	if (x == 2)
		a = 2;
	while(x>2)
	{
		return frog(x - 1)+frog(x - 2);
		x--;
	}
	return a;
}
int main()
{
	int n = 0;
	scanf("%d",& n);
	int ret = frog(n);
	printf("%d\n", ret);
	return 0;
}