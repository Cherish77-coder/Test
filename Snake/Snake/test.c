#include"Snake.h"
void test01()
{
	
	char ch = 0;
	do {
		/*system("cls");*/
		Snake snake = { 0 };//创建tanchish
		GameInit(&snake);//贪吃蛇游戏的开始和初始化
		GameRun(&snake);//游戏的运行
		GameEnd(&snake);//游戏运行结束的善后工作；
		/*SetPos(65, 16);*/
		printf("是否继续游戏：Y/N\n");
		/*SetPos(65, 17);*/
		ch = getchar();
		while (getchar() != '\n');
	} while (ch == 'y' || ch == 'Y');
	

}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	test01();
	return 0;
}