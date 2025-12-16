#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int is_year_leap(year)
{
	int x=0;
	if ((year % 4 == 0 )&& (year % 100 != 0 )||( year % 400 == 0))
		x++;
		return x;
}
int main()
{
	int year;
	scanf("%d", &year);
	int ret = is_year_leap(year);
	if (ret == 1)
		printf("yes\n");
	else
		printf("no");

	return 0;
}