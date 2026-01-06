#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void count(char*p,int len)
{
	int ncount = 0;
	int wcount = 0;
	int scount = 0;
	int icount = 0;
	for (int i = 0; i<len; i++)
	{
		if (*(p + i) == ' ')
			scount++;
		else if (48 <= (int)*(p + i) &&(int)*(p + i) <= 57)
			ncount++;
		else if (65 <=(int)*(p + i)&& (int)*(p + i) <= 90 || 97 <=(int)*(p + i)&& (int)*(p + i) <= 122)
			wcount++;
		else
			icount++;
		if (*(p + i) == '\0')
			break;
	}
	printf("数字个数：%d\n字母个数：%d\n空格个数：%d\n其他个数：%d\n", ncount, wcount, scount, icount);
	
}
int main()
{
	char s[100] = { 0 };
	gets(s);
	int len = strlen(s);
	count(s,len);
	return 0;
}
//float numerator(int x,int n)
//{
//	float num = 1.0;
//	for (int i = 0; i < n; i++)
//	{
//		num *= x;
//	}
//	return num;
//}
//float denominator(int n)
//{
//	int i = 1;
//	float num = 1;
//	for (i = 1; i <= n; i++)
//	{
//		num *= i;
//	}
//	return num;
//}
//int main()
//{
//	float x = 0;
//	scanf("%f", &x);
//	float e = 1;
//	int i = 0;
//	for (i = 1; i <= 20; i++)
//	{
//		float ret = numerator(x,i) / denominator(i);
//		e += ret;
//	}
//	printf("e^%.2f =%.6f", x, e);
//	return 0;
//}