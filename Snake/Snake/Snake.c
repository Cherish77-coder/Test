#include"Snake.h"
#define KEY_PRESS(vk)  ((GetAsyncKeyState(vk)&1)?1:0)
void SetPos(short x, short y)//坐标设置
{
	COORD pos = { x,y };
	HANDLE Output = NULL;
	Output = GetStdHandle(STD_OUTPUT_HANDLE);//GetStdHandle是?个WindowsAPI
	//函数。它?于从?个特定的标准设备（标准输?、标准输出或标
    //准错误）中取得?个句柄（?来标识不同设备的数值），使?这个句柄可以操作设备。
	SetConsoleCursorPosition(Output, pos);//设置指定控制台屏幕缓冲区中的光标位置，
	//我们将想要设置的坐标信息放在COORD类型的pos中，调?SetConsoleCursorPosition函数将光标位置设置到指定的位置。
}
void InitSnake(pSnake ps)//蛇的初始化
{
	pSnakeNode pcur = NULL;
	for (int i = 0; i < 5; i++)//创建五个链表初始化蛇
	{
		pcur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (pcur == NULL)
		{
			perror("InitSnake()::malloc");
			return;
		}
		pcur->next = NULL;
		pcur->x = POS_X + 2 * i;
		pcur->y = POS_Y;
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = pcur;
		}
		else
		{
			pcur->next = ps->_pSnake;
			ps->_pSnake = pcur;
		}
	}
	pcur = ps->_pSnake;
	//打印蛇的位置
	while (pcur)
	{
		SetPos(pcur->x, pcur->y);
		wprintf(L"%lc", BODY);
		pcur = pcur->next;
	}
	//设置贪吃蛇的属性
	ps->_dir = RIGHT;
	ps->_Food_weight = 10;
	ps->_Score = 0;
	ps->_sleep_time = 250;
	ps->_status = OK;
}
void CreateFood(pSnake ps)//创建食物
{
	int x = 0, y = 0;
again:
	x = (rand() % 26 + 1) * 2;
	y = rand() % 25 + 1;
	pSnakeNode pcur = ps->_pSnake;
	while (pcur)//food坐标不可以和蛇相冲突
	{
		if (pcur->x == x && pcur->y == y)
		{
			goto again;
		}
		pcur = pcur->next;
	}
	//创建食物的节点
	pSnakeNode pfood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pfood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}
	pfood->x = x;
	pfood->y = y;
	pfood->next = NULL;
	SetPos(x, y);//坐标定位
	wprintf(L"%lc",FOOD);
	ps->_pFood = pfood;
}
void GameInit(pSnake ps)
{
	///1打印欢迎页面，光标隐藏
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//影藏光标操作
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; // 隐藏控制台光标
	SetConsoleCursorInfo(hOutput, &CursorInfo);//设置控制台光标状态
	system("title Snake");//设置窗口名字
	system(" mode con cols=100 lines=30");//设置窗口的行和列
	//2功能介绍
	WellcomeGame();//介绍游戏规则和功能
	//3绘制地图
	SetMap();
	//4创建蛇
	InitSnake(ps);
	//5创建食物//6设置游戏相关信息
	CreateFood(ps);//创造食物
	//1，生成食物的坐标，在合理坐标之内，x为偶数，
	//2，食物坐标不能与蛇的位置冲突
	//3，食物坐标设定，创建链表元素，打印食物
}
void WellcomeGame()
{
	SetPos(35, 12);
	wprintf(L"欢迎来到贪吃蛇游戏\n");
	SetPos(35, 15);
	system("pause");
	system("cls");
	SetPos(28, 12);
	wprintf(L"用键盘上的上下左右键来控制移动按，F3加速，F4减速\n");
	SetPos(28, 13);
	wprintf(L"加速可以获得更多分数\n");
	SetPos(28, 15);
	system("pause");
	system("cls");
}
void SetMap()
{
	for(int i=0;i<29;i++)
	wprintf(L"%lc", WALL);//上打印
	SetPos(0, 26);
	for (int i = 0; i < 29; i++)
		wprintf(L"%lc", WALL);//下打印
	for (int i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}//左侧打印
	for (int i = 0; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}//右侧打印
}
void GameSleep()//游戏暂停函数
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))//再按一下空格跳出死循环，游戏继续
		{
			break;
		}
	}
	return;
}
int NextIsFood(pSnakeNode newnode,pSnake ps)
{
	return (ps->_pFood->x == newnode->x && ps->_pFood->y == newnode->y);//判断下一步位置是不是食物，用坐标进行比较
}
void EatFood(pSnake ps,pSnakeNode newnode)//吃掉食物，对蛇进行头插并打印
{
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;
	free(newnode);
	newnode=NULL;//头插释放
	pSnakeNode pcur = ps->_pSnake;
	while (pcur)
	{
		SetPos(pcur->x, pcur->y);
		wprintf(L"%lc", BODY);//本地化打印
		pcur = pcur->next;
	}
	ps->_Score += ps->_Food_weight;
	CreateFood(ps);
}
void NoFood(pSnake ps, pSnakeNode pnewnode)//不是食物的情况下，生成坐标进行头插，并删除尾部
{
	pnewnode->next = ps->_pSnake;
	ps->_pSnake = pnewnode;
	pSnakeNode pcur = ps->_pSnake;
	while (pcur->next->next!=NULL)//尾删
	{
		SetPos(pcur->x, pcur->y);
		wprintf(L"%lc", BODY);
		pcur = pcur->next;
	}
	SetPos(pcur->next->x, pcur->next->y);//覆盖最后一个位置
	printf("  ");
	free(pcur->next);//释放最后一个的内存
	pcur->next = NULL;//将倒数第二个置为空

}
void KillBySelf(pSnake ps)//判断是否撞自己，如果修改游戏状态
{
	pSnakeNode pcur = ps->_pSnake->next;
	while (pcur)
	{
		if (ps->_pSnake->x == pcur->x && ps->_pSnake->y == pcur->y)
		{
			ps->_status = KILL_BY_SELF;
		}
		pcur = pcur->next;
	}
}
void KillByWall(pSnake ps)//判断是否撞墙，如果修改游戏状态
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 || ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}
void SnakeMove(pSnake ps)//蛇的移动；
{
	pSnakeNode newnode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (newnode == NULL)
	{
		perror("SnakeMove()::mallloc()");
		return;
	}
	switch (ps->_dir)//走的时候要判断是不是食物
	{
	case UP:
		newnode->x = ps->_pSnake->x;
		newnode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		newnode->x = ps->_pSnake->x;
		newnode->y = ps->_pSnake->y +1;
		break;
    case LEFT:
		newnode->x = ps->_pSnake->x-2;
		newnode->y = ps->_pSnake->y;
	    break;
	case RIGHT:
		newnode->x = ps->_pSnake->x+2;
		newnode->y = ps->_pSnake->y;
		break;
	}
	if (NextIsFood(newnode,ps))
	{
		EatFood(ps,newnode);
	}
	else
	{
		NoFood(ps, newnode);
	}
	KillBySelf(ps);//检测是否撞到自己
	KillByWall(ps);//检测是否撞墙
}
void GameRun(pSnake ps)//游戏运行
{
	PrintHelpInfo(ps);//打印帮助信息
	do
	{
		//打印游戏信息
		SetPos(65, 10);
		printf("总分数：%d", ps->_Score);
		SetPos(65, 11);
		printf("一个食物的分数:%2d", ps->_Food_weight);
		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)//对按键的反馈
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_ESCAPE) )
		{
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			GameSleep();//暂停
		}
		else if (KEY_PRESS(VK_F3))//加速有蛇的速度
		{
			if (ps->_sleep_time > 100)
			{
				ps->_sleep_time -= 30;
				ps->_Food_weight += 2;
			}
				
		}
		else if (KEY_PRESS(VK_F4))//减速蛇的速度
		{
			if (ps->_sleep_time <350)
			{
				ps->_sleep_time += 30;
				ps->_Food_weight -= 2;
			}
		
		}
		
		SnakeMove(ps);//蛇的移动；
		Sleep(ps->_sleep_time);
	} while (ps->_status==OK);//循环蛇的移动这个操作，并对键盘指令做出反馈
}
void PrintHelpInfo(pSnake ps)
{
	SetPos(65, 12);
	wprintf(L"用键盘上的上下左右键来控制移动。\n");
	SetPos(65, 13);
	wprintf(L"按，F3加速，F4减速。\n");
	SetPos(65, 14);
	wprintf(L"加速可以获得更多分数。\n");
	SetPos(65, 15);
	printf("ESC退出，space暂停/继续");
}
void GameEnd(pSnake ps)//游戏善后工作
{
	if (ps->_status == KILL_BY_SELF)
	{
		SetPos(20, 14);
		printf("你失败了，原因：蛇撞自己");
	}
	else if (ps->_status == KILL_BY_WALL)
	{
		SetPos(20, 14);
		printf("你失败了，原因：蛇撞墙");
	}
	else if (ps->_status == END_NORMAL)
	{
		SetPos(22, 14);
		printf("正常退出");
	}

	SetPos(0, 27);
	SnakeDestory(ps);//贪吃蛇链表的销毁；
	Sleep(2000);
	system("cls");
}
void SnakeDestory(pSnake ps)
{
	if (ps->_pSnake == NULL)
	{
		return;
	}
	pSnakeNode pcur = ps->_pSnake;
	while (pcur)
	{
		ps->_pSnake = pcur->next;
		free(pcur);
		pcur = ps->_pSnake;
	}

}
