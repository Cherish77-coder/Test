#include<stdio.h>
int main() 
{
	int i, sum;
	i = 1;
	sum = 0;
	while (i <= 200) {
		sum += i;
		i++;
	}
	printf("1+2+.....+200=%d\n", sum);
	return 0;
}