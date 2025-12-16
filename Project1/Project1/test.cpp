#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int i = 0;
	int j = 0;
	for (i = 2; i <= 200; i++)
	{
		int count = 0;
		for (j = 2; j*j<=i; j++)
		{
			if (i % j == 0)
			{
				count++;
				break;
			}
			
		}
		if (count == 0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
//int main() {
//	int year, nonth,day;
//	scanf("%d%*c%d%*c%d",&year,&nonth,&day);
//	printf("%d %d %d", year, nonth, day);
//	return 0;
//}



//int main()
//{
//	int i, j;
//	for (i = 3; i >= 1; i--)
//	{
//		for (j = 1; j <= 2; j++)
//			printf("%d", i + j);
//		printf("\n");
//	}
//	return 0;
//}





//int main()
//{
//	int a = 0;
//	int* pa = &a;
//	printf("%p\n", pa);
//	printf("%p\n", pa+1);
//	printf("%p\n", pa+4);
//	return 0;
//}