#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
//int main()
//{
//	set<int> s;
//	int arr[] = { 1,2,3,4,4,4,4,67,67,7534,43,45,76 };
//	for (auto e : arr)
//	{
//		s.insert(e);
//	}
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	auto first = s.lower_bound(4);
//	auto last = s.upper_bound(67);
//	s.erase(first, last);
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}
//int main()
//{
//	set<int> s;
//	int arr[] = { 1,2,3,4,4,4,4,67,67,7534,43,45,76 };
//		for (auto e : arr)
//		{
//			s.insert(e);
//		}
//		auto ret = s.find(43);
//		if (ret != s.end())
//		{
//			s.erase(ret);
//			cout << "É¾³ý³É¹¦"<<endl;
//		}
//		else
//		{
//			cout << "É¾³ýÊ§°Ü" << endl;
//		}
//		for (auto& e : s)
//		{
//			cout << e << " ";
//		}
//		find(s.begin(),s.end(),5);
//		cout << endl;
//		cout << s.count(5) << endl;
//	return 0;
//}
int main()
{
	map<string, string> word;
	word.insert(pair<string, string>("hehe", "hehe"));
	for (auto& e : word)
	{
		cout << e.first << " " << e.second << endl;
	}
	word.insert({ "haha" ,  "¹þ¹þ" });
	word.insert({ "ee", "ßÀßÀ" });
	string f;
	//map<string, string>::iterator ret;
	while (cin >> f)
	{
		auto ret = word.find(f);
		if (ret != word.end())
			cout << ret->first << ":" << ret->second << endl;
		else
			cout << "ÕÒ²»µ½" << endl;
		
	}
	return 0;
  
}