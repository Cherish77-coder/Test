#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Mymap.h"
#include"Myset.h"
#include"RBtree.h"
#include<vector>
//int main()
//{
//	my::set<int> s;
//	vector<int> v({3,2,1,7,5,87,91,13,78});
//	for (auto &e : v)
//	{
//		s.insert(e);
//	}
//	for (auto& it : s)
//	{
//		cout << it << " ";
//	}
//	cout << endl;
//	auto it = s.end();
//	while (it != s.begin())
//	{
//		--it;
//		cout << *it <<" ";
//	}
//	cout << endl;
//
//	return 0;
//}
void test01()
{
	vector<int> v({ 3,2,1,7,5,87,91,13,78 });
	my::map<int, int> s;
	for (auto& e : v)
	{
		s.insert({e,e});
	}
	for (auto& e : s)
	{
		cout << e.first << ":" << e.second << endl;;
	}
	cout << endl;
}
void test02()
{
	my::map<string, string> dict;
	dict.insert({ "hehe","ºÇºÇ" });
	dict["hehe"] = "¹þ¹þ";
}
void test_map()
{
	my::map<string,  string> dict;
	dict.insert({ "sort", "ÅÅÐò" });
	dict.insert({ "left", "×ó±ß" });
	dict.insert({ "right", "ÓÒ±ß" });
	dict["left"] = "×ó±ß£¬Ê£Óà";
	dict["insert"] = "²åÈë";
	dict["string"];
	my::map<string, string>::const_iterator it = dict.cbegin();
	while (it != dict.cend())
	{
		// ²»ÄÜÐÞ¸Äfirst£¬¿ÉÒÔÐÞ¸Äsecond
		//it->first += 'x';
		//it->second += 'x';
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
int main()
{
	test_map();
	return 0;
}