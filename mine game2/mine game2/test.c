#include"game.h"
void menu()
{
	printf("---------扫雷游戏---------\n");
	printf("---------1：play----------\n");
	printf("---------0:exit-----------\n");
	printf("--------------------------\n");
	printf("请选择：>");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	Displayboard(show, ROW, COL);
	Setmine(mine, ROW, COL);
	findmine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}
