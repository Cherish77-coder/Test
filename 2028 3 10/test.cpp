#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
class A
{
public:
	A(int x = 0, int y = 0)
		:a(x)
		, b(y) {
		cout << "A(int x = 0, int y = 0)" << endl;
	}
	  A(const A& x)
	{
		  cout << "A(const A& x)" << endl;
		 a = x.a;
		 b = x.b;
	}
private:
	int a;
	int b;
};
void test_list1()
{
	list<int> ls;
	ls.push_back(1);
	ls.push_back(1);
	ls.push_back(1);
	ls.push_back(1);
	ls.push_back(1);
	for (auto e : ls)
	{
		cout << e << " ";
	}
	cout << endl;
	auto it = ls.begin();
	while (it!=ls.end())
	{
		cout << *it<<" ";
		++it;
	}
	cout << endl;

}
void test_list2()
{
	list<A> ls;
	A aa(2, 2);
	ls.push_back(aa);
	ls.push_back(A(2, 2));
	cout << endl;
	ls.emplace_back(aa);
	ls.emplace_back(2, 2);
}
void test_list3()
{
	list<int> ls;
	ls.push_back(1);
	ls.push_back(4);
	ls.push_back(3);
	ls.push_back(1);
	ls.push_back(6);
	ls.push_back(1);
	ls.push_back(7);
	for (auto e : ls)
	{
		cout << e << " ";
	}
	cout << endl;
	auto i = ls.begin();
	int k = 3;
	while (k-- > 0)
	{
		i++;
	}
	ls.insert(i, 9);
	for (auto e : ls)
	{
		cout << e << " ";
	}
	cout << endl;
	ls.sort();
	for (auto e : ls)
	{
		cout << e << " ";
	}
	cout << endl;
	ls.unique();
	for (auto e : ls)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test_list3();
	return 0;
}