#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"HashTable.h"
void test01()
{
	HashTable<int, int> ht;
	int arr[] = { 19,30,5,36,13,20,21,12 };
	for (auto& e : arr)
	{
		ht.Insert({e,e});
	}
	ht.Insert({ 15,15 });
	cout << ht.Find(15) << endl;
	ht.Erase(15);
	cout << ht.Find(15) << endl;
}
int main()
{
	test01();
	return 0;
}