#include"List.h"
void test01()
{
	SL list;
	SLInit(&list);
	SLPushBack(&list, 1);
	SLPushBack(&list, 2);
	SLPushBack(&list, 3);
	SLPushBack(&list, 4);
	SLInsert(&list, 3, 9);
	SLPrint(&list);
	SLErase(&list, -101);
	SLPrint(&list);
	SLFind(&list, 9);
	/*SLPopBack(&list);
	SLPrint(&list);
	SLPushBack(&list, 5);
	SLPrint(&list);
	SLPopBack(&list);
	SLPushFront(&list, 8);
	SLPrint(&list);
	SLPopFront(&list);
	SLPrint(&list);
	SLPopFront(&list);*/
	/*SLPrint(&list);*/

}
int main()
{
	test01();
	return 0;
}