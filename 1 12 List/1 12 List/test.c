#include"List.h"
void test01()
{
	ListNode* plist = LTinit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushFront(plist, 6);
	LTprint(plist);
	LTPopBack(plist);
	LTprint(plist);
	LTPopFront(plist);
	LTprint(plist);
	LTPopFront(plist);
	LTprint(plist);
	ListNode* find=LTFind(plist, 2);
	LTInsert(find, 99);
	LTprint(plist);
	LTErase(find);
	LTprint(plist);
	LTDestory(plist);
	LTprint(plist);
	free(plist);
	plist = NULL;
}
int main()
{
	test01();
	return 0;
}