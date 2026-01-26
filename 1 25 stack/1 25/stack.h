#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int DataType;
typedef struct Stack
{
	DataType* arr;
	int top;
	int capacity;
}ST;
//栈的初始化，和销毁
void STInit(ST* pst);
void STDestory(ST* pst);
//栈的插入删除
void STPop(ST* pst);
void STPush(ST* pst,DataType x);
//获取栈顶元素
DataType STTop(ST* pst);
//获取栈有效元素个数
int STValidsize(ST* pst);
//检测栈是否为空
bool STIfNULL(ST* pst);