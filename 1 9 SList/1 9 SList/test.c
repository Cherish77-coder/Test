#include"Slist.h"
void test1()
{
	/*Node* node1 = (Node*)malloc(sizeof(Node));
	node1->Data = 1;
	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->Data = 2;
	Node* node3 = (Node*)malloc(sizeof(Node));
	node3->Data = 3;
	Node* node4 = (Node*)malloc(sizeof(Node));
	node4->Data = 4;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	Node* plist = node1;
	SLprint(plist);*/
}
void test2()
{
	Node* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	/*SLPushFrount(&plist, 0);*/
	SLprint(plist);
	/*SLPushFrount(&plist, 9);
	SLprint(plist);
	SLPushFrount(&plist, 2);
	SLprint(plist);
	SLPushFrount(&plist, 3);
	SLprint(plist);
	SLPushFrount(&plist, 4);
	SLprint(plist);
	SLpopBack(&plist);
	SLprint(plist);
	SLpopBack(&plist);
	SLprint(plist);
	SLprint(plist);
	SLpopBack(&plist);
	SLprint(plist);*/
	/*SLPopFront(&plist);
	SLprint(plist);
	SLPopFront(&plist);
	SLprint(plist);
	SLPopFront(&plist);
	SLprint(plist);*/
	Node*find=SLFind(plist,1);
	/*SLErase(&plist, find);
	SLprint(plist);*/
	//SLInsertAfter(find, 9);
	//SLprint(plist);
	/*SLEraseAfter(find);
	SLprint(plist);*/
	SListDesTroy(&plist);
	SLprint(plist);
}
int main()
{
	test2();
	/*test1();*/
	return 0;
}


