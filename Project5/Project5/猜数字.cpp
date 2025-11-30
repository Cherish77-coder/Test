#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void menu()
{
	printf("**       猜数字        **\n");
	printf("**       1:play        **\n");
	printf("**       0;end         **\n");
}
void game() 
{
	srand((unsigned int)time(NULL));
	int n = rand()%100+1;
	printf("请输入猜的数字：");
	int count = 5;
	while (count) {
		int num = 0;
		scanf("%d",&num);
		if (num < n)
		{       
			if (count - 1)
			{
				printf("猜小了，你还有%d次机会\n", count - 1);
				printf("请输入猜的数字:");
			}
		}
		else if (num > n)
		{
			if (count - 1)
			{
				printf("猜大了,你还有%d次机会\n", count - 1);
				printf("请输入猜的数字:");
			}
		}
		else 
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
		count--;
	              }
	if (count == 0)
	{
		printf("\n");
		printf("你的次数已用完，游戏失败，这个随机数是：%d\n", n);
	}
}
int main() {
	int input = 0;
	do 
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input) {
		case 1:game();
			break;
		case 0:printf("游戏结束\n");
			break;
		default:
			printf("输入有误，请重新输入：\n");
			break;
		}
	} while(input);
	return 0;
}