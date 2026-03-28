#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Mymap.h"
#include"Myset.h"
#include"RBtree.h"
#include<vector>
int main()
{
	my::set<int> s;
	vector<int> v({3,2,1,7,5,87,91,13,78});
	for (auto &e : v)
	{
		s.insert(e);
	}
	for (auto& it : s)
	{
		cout << it << " ";
	}
	cout << endl;
	auto it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it <<" ";
	}
	cout << endl;

	return 0;
}