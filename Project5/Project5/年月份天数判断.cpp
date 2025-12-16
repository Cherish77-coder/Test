#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int is_year_leap(int x) 
{
	if (x % 4 == 0 && x % 100 != 0 || x % 100 == 0)
		return 1;
	else
		return 0;
}
int get_days_of_month(int y,int m)
{
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = a[m];
	if ((is_year_leap(y)) && m == 2)
	{
		a[m] = 29;
	}
	printf("%d", a[m]);
	return 0;
}
int main()
{
	int year, month;
	printf("ÇëÊäÈëÄêÔÂ;>");
	scanf("%d %d", &year, &month);
	get_days_of_month(year,month);
	return 0;
}