#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
void TestPushBack()
{
	// reverse 反转  逆置
	// reserve 保留、预留
	string s;
	size_t sz = s.capacity();
	s.reserve(1000);
	cout << "capacity changed: " << sz << '\n';

	cout << "making s grow:\n";
	for (int i = 0; i < 10000; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	cout << typeid(string::iterator).name() << endl;
	cout << typeid(string::reverse_iterator).name() << endl;
	cout << typeid(string::const_reverse_iterator).name() << endl;
}

void test_string3()
{
	const string s1("hello world");
	for (auto &at: s1)
	{
		cout << at;
	}
	cout << endl;
	string::const_iterator cit = s1.begin();
	while (cit != s1.end())
	{
		cout << *cit;
		++cit;
	}

}
void test_string1()
{
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.length() << endl<<endl;
	s1.reserve(100);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.length() << endl<<endl;
	s1.resize(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.length() << endl << endl;
}
void test_string2()
{
	string s1("hello world");
	for (auto &it : s1)
	{
		it += 2;
		cout << it << ' ' ;
	}
	cout << endl;
	string::iterator i = s1.begin();
	while (i != s1.end())
	{
		cout << *i << ' ';
		++i;
	}
	cout << endl;
	/*string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it+=2;
		cout << *it<<" ";
		it++;
	}
	cout << endl;*/
}
auto Pushback()
{
	return "hehehe";
}
int main()
{
	TestPushBack();
	//test_string3();
	//cout << Pushback() << endl;
	return 0;
}
//int main()
//{
//	int a[] = { 1,2,3,4,5,65,9 };
//	for (auto i : a)
//	{
//		cout << i << ' ';
//}
//	return 0;
//}
//int main()
//{
//	const string  s1 = ("hello world");
//	string::const_reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout<<endl;
//	for (auto ait : s1)
//	{
//		cout << ait << " ";
//	}
//	cout << endl;
	/*string::reverse_iterator it = s1.rbegin();
	while (it != s1.rend())
	{
		cout << *it<<" ";
		it++;
	}
	cout << endl;
	return 0;*/
//}
//int main()
//{
//	//三种字符串遍历
//	//下表访问
//	string s1("hello world");
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i];
//	}
//	cout << endl;
//	//用iterator
//	for (string::iterator it = s1.begin(); it != s1.end(); it++)
//	{
//		cout << *it;
//	}
//	cout << endl;
//	//auto局部for
//	for (auto it1 : s1)
//	{
//		cout << it1;
//	}
//	cout << endl;
//	return 0;
//}