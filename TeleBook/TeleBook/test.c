#include"SeqList.h"
//void test2()
//{
//	Telebook tbook;
//	TeleBookInit(&tbook);
//	TeleBookAdd(&tbook);
//	TeleBookAdd(&tbook);
//	TeleBookAdd(&tbook);
//	TeleBookFind(&tbook);
//	TeleBookShow(&tbook);
//	TeleBookDel(&tbook);
//	TeleBookShow(&tbook);
//	TeleBookDesTroy(&tbook);
//}
//int main()
//{
//	test2();
//	return 0;
//}
void menu()
{
	printf("*****************************************\n");
	printf("*               电话簿                  *\n");
	printf("*    1.添加联系人  2.删除联系人         *\n");
	printf("*    3.修改联系人  4.查找联系人         *\n");
	printf("*    5.打印所有联系人                   *\n");
	printf("*    0.退出                             *\n");
	printf("*****************************************\n");
}
int main()
{
	int n = 0;
	Telebook tbook;
	TeleBookInit(&tbook);
	do 
	{
		menu();
		printf("请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			TeleBookDesTroy(&tbook);
			printf("exit");
			break;
		case 1:
			TeleBookAdd(&tbook);
			break;
		case 2:
			TeleBookDel(&tbook);
			break;
		case 3:
			TeleBookModify(&tbook);
			break;
		case 4:
			TeleBookFind(&tbook);
			break;
		case 5:
			TeleBookShow(&tbook);
			break;
		default:
			printf("输入有误，请重新选择\n");
			break;
		}
	} while (n);
	return 0;
}