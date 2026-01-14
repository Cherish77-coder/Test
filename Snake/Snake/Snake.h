#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<locale.h>
#include<time.h>
#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'
#define POS_X 24
#define POS_Y 5
typedef struct SnakeNode//贪吃蛇的每一个节点
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode,* pSnakeNode;
enum Game_Status//游戏状态
{
	OK,
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_NORMAL

};
enum Snake_Dir//蛇的方向
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
typedef struct Snake//以贪吃蛇为对象进行对象化编程
{
	pSnakeNode _pSnake;//蛇头指针
	pSnakeNode _pFood;//食物指针
	enum Game_Status _status;//游戏状态
	enum Snake_Dir _dir;//蛇的方向
	int _Food_weight;//一个食物的分数
	int _Score;//总分
	int _sleep_time;//速度
}Snake,* pSnake;
typedef struct Snake* pSnake;
void GameInit(pSnake ps);
//1打印欢迎页面，光标隐藏
//2功能介绍
//3绘制地图
//4创建蛇
//5创建食物
//6设置游戏相关信息
void SetPos(short x, short y);//设置位置；
void WellcomeGame();//游戏界面的打印
void SetMap();//地图打印
void InitSnake(pSnake ps);//蛇的初始化
void CreateFood(pSnake ps);//创建食物
void GameRun(pSnake ps);//游戏的运行
void PrintHelpInfo(pSnake ps);//游戏提示的打印
void SnakeMove(pSnake ps);//蛇的移动；
void GameEnd(pSnake ps);//游戏结束的善后工作
void SnakeDestory(pSnake ps);//贪吃蛇的链表的销毁；