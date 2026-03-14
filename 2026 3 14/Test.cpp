#include<iostream>
using namespace std;
#include<vector>
#include"priority_queue.h"
namespace my
{
	void test1()
	{
		priority_queue<int> q;
		q.push(5);
		q.push(4);
		q.push(3);
		q.push(1);
		q.push(2);
		q.push(1);
		q.push(1);
		q.push(1);
		q.push(1);
		q.push(1);
		while (!q.empty())
		{
			cout << q.top() << " ";
			q.pop();
		}
	}
}
int main()
{
	my::test1();
	return 0;
}