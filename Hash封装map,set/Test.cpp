#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"HashTable.h"
#include"UnorderedMap.h"
#include"UnorderedSet.h"
void test01()
{
	my::unoredered_set<int>s;
	s.insert(1);
	s.insert(2);
	s.insert(8);
	s.insert(-1);
	s.insert(-1);
	for (auto& e : s)
	{
		//不能修改
		//e += 10;
		cout << e << " ";
	}
	cout<<s.erase(2)<<endl;
	for (auto& e : s)
	{
		//不能修改
		//e += 10;
		cout << e << " ";
	}
	//cout <<(int*)(s.find(2)) << endl;
 }
void test_map1()
{
	my::unordered_map<string, string> dict;
	dict.insert({ "sort", "排序" });
	dict.insert({ "字符串", "string" });

	dict.insert({ "sort", "排序" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });

	dict["left"] = "左边，剩余";
	dict["insert"] = "插入";
	dict["string"];

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	my::unordered_map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// 不能修改first，可以修改second
		//it->first += 'x';
		it->second += 'x';
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
int main()
{
	test_map1();
	return 0;
}