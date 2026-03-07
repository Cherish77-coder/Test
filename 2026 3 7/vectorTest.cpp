#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
void vector_test2()
{
	vector<int> v(10, 0);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}
	vector<vector<int>> vv(10,v);
	cout << vv[1][3] << endl;
}
void Vector_test1()
{
	vector<int> v(10, 0);
	v[1] = 19;
	v.push_back(91);
	v.insert(v.begin(), 78);
	v.insert(v.begin()+3, 13);
	vector<int>::iterator it = v.begin();
	cout << v.capacity() << endl;
	for (it; it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	v.reserve(200);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	v.resize(10);
	cout << v.size() << endl;
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	int a[][3] = { 1,2,3,11,22,33,111,222,333 };
	cout << a[0][0] << ' ' << a[1][0] << " " << a[2][0];
	//vector_test2();
	return 0;
}