#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
namespace my
{
	void test_list4()
	{
		list<int> ls;
		ls.push_back(1);
		ls.push_back(2);
		ls.push_back(3);
		ls.push_back(4);
		ls.insert(ls.begin(), 9);
		list<int> l2(ls);
		list<int> l3;
		l3 = ls;
		print_container(l3);
		list<int> l4({ 1,2,4 });
	}
	void test_list3()
	{
		list<int> ls;
		ls.push_back(1);
		ls.push_back(2);
		ls.push_back(3);
		ls.push_back(4);
		ls.insert(ls.begin(), 9);
		print_container(ls);
		cout << ls.size() << endl;
		list<int>::iterator it = ls.begin();
		while (it != ls.end())
		{
			if (*it % 2 == 0)
			{
				it = ls.erase(it);
			}
			else
			{
				++it;
			}
		}
		print_container(ls);
	}
	void test_list2()
	{
		list<AA> lsa;
		lsa.push_back(AA(2,2));
		lsa.push_back(AA());
		lsa.push_back(AA());
		lsa.push_back(AA());
		list<AA>::iterator it = lsa.begin();
		while (it != lsa.end())
		{
			cout << it->a << " " << it->b << endl;
			it++;
		}
		cout << endl;
		//print_container(lsa);
	}
	void test_list1()
	{
		list<int> ls; 
		ls.push_back(1);
		ls.push_back(2);
		ls.push_back(3);
		ls.push_back(4);
		ls.insert(ls.begin(), 9);
		
		for (auto e : ls)
		{
			cout << e << " ";
		}
		cout << endl;
		ls.erase(ls.begin());
		list<int>:: iterator it = ls.begin();
		while (it != ls.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		print_container(ls);
		/*for (auto e : ls)
		{
			cout << e <<" ";
		}
		cout << endl;*/
	}
}
int main()
{
	my::test_list4();
	return 0;
}