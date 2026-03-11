#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
namespace my
{
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
		/*for (auto e : ls)
		{
			cout << e <<" ";
		}
		cout << endl;*/
	}
}
int main()
{
	my::test_list1();
	return 0;
}