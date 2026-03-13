#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
using namespace std;
#include"Stack.h"
#include"Queue.h"
namespace my
{
	void test_stack1()
	{
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(3);
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
	}
	void test_queue1()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);
		while (!q.empty())
		{
			cout << q.top() << " ";
			q.pop();
		}

	}
}
int main()
{
	//my::test_stack1();
	my::test_queue1();
	return 0;
}