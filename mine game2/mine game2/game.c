#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char board[ROWS][COLS], int rows, int cols, char ret)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = ret;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0; int j = 0;
	printf("--------------------扫雷游戏--------------------\n");
	printf("------------坐标输入含0（x或y=0）插旗-----------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d ", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}
void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = easy_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int static get_mine_count(char mine[ROWS][COLS], int x, int y)
{

	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0, win = 0;
	while (win < row * col - easy_count)
	{
		printf("请输入坐标：>");
		scanf("%d %d", &x, &y);
		if (x < row && x >0 && y > 0 && y < col)
		{
		    if (show[x][y] == 'f')
		    {
			printf("该位置已插旗，请重新输入坐标\n");
		     }
			else if (mine[x][y] == '1')
			{
				printf("你被炸死了，游戏结束\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';

				Displayboard(show, ROW, COL);
				win++;
			}
		}

		else if (x == 0 || y == 0)
		{
				FlagMine( show, ROW, COL);
		}
		else
		{
			printf("坐标有误，请重新输入\n");
		}
	}
	if (win == row * col - easy_count)
	{
		printf("恭喜你，排雷成功！\n");
		Displayboard(mine, ROW, COL);
	}
}
static void FlagMine( char show[ROWS][COLS], int row , int col)
{
	while (1)
	{
		int x, y;
		printf("请输入要插旗的坐标：>");
		scanf("%d %d", &x, &y);
		if (x > row || x <=0 || y <= 0 || y >col)
		{
			printf("坐标非法\n");
			continue;
		}
		if (show[x][y] == '*')
		{
			show[x][y] = 'f';
			Displayboard(show, ROW, COL);
			printf("已成功插旗,退出插旗模式\n");
			return 0;
		}
		else if (show[x][y] == 'f')
		{
			show[x][y] = '*';
			printf("已取消插旗，退出插旗模式\n");
			Displayboard(show, ROW, COL);
			return 0;
		}
		else
		{
			printf("该位置已探索，请重新输入\n");
		}
	}
}
//int ExpandMine(char mine[ROW][COL], char show[ROW][COL], int x, int y, int count)
//{
//	for (int i = x - 1; i <= x + 1; i++)
//	{
//		for (int j = y - 1; j <= y + 1; j++)
//		{
//			if (get_mine_count(mine, i, j) == 0)
//			{
//				show[x][y] == '0';
//				count++;
//			}
//		}
//	}
//	return count;
//}