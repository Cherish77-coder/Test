#include"SeqList.h"
#include"TeleBook.h"
void TeleBookInit(Telebook* con)
{
	SLInit(con);
}
void TeleBookDesTroy(Telebook* con)
{
	SLDestroy(con);
}
void TeleBookAdd(Telebook* con) 
{
	printf("请输入要添加的联系人：姓名 性别 年龄 电话 地址\n");
	Personinfo info;
	scanf("%s", info.name);
	scanf("%s", info.gender);
	scanf("%d", &info.age);
	scanf("%s", info.phone);
	scanf("%s", info.address);
	SLCheckCapacity(con);
	SLPushBack(con,info);
	printf("添加成功！\n");
}
int Find(Telebook*con)
{
	char name[NAME] = {0};
	scanf("%s", name);
	for (int i = 0; i < con->size; i++)
	{
		if (0==strcmp(con->arr[i].name,name))
		{
			return i;
		}
	}
	printf("不存在此联系人\n");
	return -1;
}
void TeleBookDel(Telebook* con)
{
	printf("请输入要删除的联系人\n");
	int find=Find(con);
	if (find < 0)
	{
		printf("删除失败,不存在此人\n");
		return;
	}
	SLErase(con, find);
	printf("删除成功！\n");
}
void TeleBookModify(Telebook* con)
{
	printf("请输入要修改的联系人\n");
	int find = Find(con);
	if (find < 0)
	{
		printf("修改失败,不存在此人\n");
		return;
	}
	printf("请输入新的内容：姓名 性别 年龄 电话 地址\n");
	Personinfo info = { 0 };
	scanf("%s", info.name);
	scanf("%s", info.gender);
	scanf("%d", &info.age);
	scanf("%s", info.phone);
	scanf("%s", info.address);
	con->arr[find] = info;
}
void TeleBookShow(Telebook* con)
{
	printf("姓名       性别      年龄       电话           地址          \n");
	for (int i = 0; i < con->size; i++)
	{
		printf("%-10s %-10s %-10d %-14s %-14s\n", 
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].phone,
			con->arr[i].address);
	}
}
void TeleBookFind(Telebook* con)
{
	printf("请输入要查找的联系人\n");
	int find = Find(con);
	if (find < 0)
	{
		printf("查找失败,不存在此人\n");
		return;
	}
	printf("姓名       性别      年龄       电话           地址          \n");
	printf("%-10s %-10s %-10d %-14s %-14s\n",
		con->arr[find].name,
		con->arr[find].gender,
		con->arr[find].age,
		con->arr[find].phone, 
		con->arr[find].address);
}