#pragma once
#pragma once
#define NAME 20
#define GENDER 6
#define PHONE 20
#define ADDR 100
typedef struct Personinfo//定义一个电话本的元素
{
	char name[NAME];
	char gender[GENDER];
	int age;
	char phone[PHONE];
	char address[ADDR];

}Personinfo;
// 要用到顺序表相关的方法，对通讯录的操作实际就是对顺序表进行操作
//给顺序表改个名字，叫做通讯录
struct SeqList;
typedef struct SeqList Telebook; //
//通讯录相关的方法

//通讯录的初始化
void TeleBookInit(Telebook* con);
//通讯录的销毁
void TeleBookDesTroy(Telebook* con);
//通讯录添加数据
void TeleBookAdd(Telebook* con);
//通讯录删除数据
void TeleBookDel(Telebook* con);
//通讯录的修改
void TeleBookModify(Telebook* con);
//通讯录查找
void TeleBookFind(Telebook* con);
//展示通讯录数据
void TeleBookShow(Telebook* con);
