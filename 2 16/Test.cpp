#include"Date.h"
void test1()
{
	Date d1(2026, 2, 30);
}
void test4()
{
	Date st(2026, 2, 30);
	cin >> st
		; cout << st;
}
void test5()
{
	Date d1(2026, 2, 1);
	Date d2 = d1-5;
	cout << d1 << d2;
	d2 >= d1;
}
int main()
{
	//system("chcp 65001");
	test5();
	return 0;
}
//#include<iostream>
//using namespace std;
//#include<iostream>
//using namespace std;
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack& operator=(const Stack& st)
//	{
//		if (this->_a != st._a)
//		{
//			STDataType* pa = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//			if (pa == nullptr)
//			{
//				perror("operator::malloc fail");
//				exit(1);
//			}
//			_a = pa;
//			memcpy(_a, st._a, st._top * sizeof(STDataType));
//			_top = st._top;
//			_capacity = st._capacity;
//		}
//		return *this;
//	}
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	Stack(const Stack& st)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//class Myqueue
//{
//public:
//	void MyqueuePush()
//	{
//		cout << "MyqueuePush()" << endl;
//	}
//private:
//	Stack Stpush;
//	Stack Stpop;
//};
//int main()
//{
//	Stack st1(4);
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//	st1.Push(4);
//	st1.Push(5);
//	Stack st2;
//	st2 = st1;
//	return 0;
//}
//#include<stdio.h>
//int add(int x, int y)
//{
//	return x + y;
//}
//void call(int x, int y, int(*call)(int ,int))
//{
//	printf("%d", call(x,y));
//}
//int main()
//{
//	call(1, 2, add);
//}
//#include<iostream>
//using namespace std;
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		cout << "Stack(int n = 4)" << endl;
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
	//Stack( const Stack& st)
	//{
	//	cout << "Stack(const Stack& st)" << endl;
	//	_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
	//	if (nullptr == _a)
	//	{
	//		perror("malloc申请空间失败!!!");
	//		return;
	//	}
	//	memcpy(_a, st._a, sizeof(STDataType) * st._top);
	//	_top = st._top;
	//	_capacity = st._capacity;
	//}
	//void Push(STDataType x)
	//{
	//	if (_top == _capacity)
	//	{
	//		int newcapacity = _capacity * 2;
	//		STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
	//			sizeof(STDataType));
	//		if (tmp == NULL)
	//		{
	//			perror("realloc fail");
	//			return;
	//		}
	//		_a = tmp;
	//		_capacity = newcapacity;
	//	}
	//	_a[_top++] = x;
	//}
	//~Stack()
	//{
	//	cout << "~Stack()" << endl;
	//	free(_a);
	//	_a = nullptr;
	//	_top = _capacity = 0;
	//}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//	};
//class MyQueue
//{
//public:
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	Stack st;
//	st.Push(1);
//	st.Push(1);
//	st.Push(1);
//	st.Push(1);
//	st.Push(1);
//	Stack st2(st);
//	return 0;
//}
//#include"Date.h"
//void test1()
//{
//	Date d1;
//	Date d2(2015,4,5);
//	d2 < d1;
//	Date d3(2222, 33, 1);
//	d1 <= d2;
//	d1 > d2;
//}
//void test2()
//{
//	Date d1(2026, 2, 14);
//	Date d2 = d1 - 2092;
//	d1.Print();
//	d2.Print();
//}
//void test3()
//{
//	Date d1(2026,12,28);
//	d1.Print();
//	Date& d5 = d1;
//	d5++;
//	d5++;
//	d5++;
//	d5++;
//	d1.Print();
//	//Date d2(2024,8,24);
//	//Date d3 = d1++;
//	//d1.Print();
//	//d1--;
//	//d1.Print();
//	//d3.Print();
//	//cout << d2 - d1 << endl;
//
//}
//int main()
//{
//	test3();
//	return 0;
//}