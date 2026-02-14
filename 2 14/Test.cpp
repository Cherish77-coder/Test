#include<iostream>
using namespace std;
//class D
//{
//public:
//	bool operator== (D&d2)
//	{
//		return this->_year == d2._year && this->_month == d2._month;
//	}
//	D(int year=0,int month=0)
//	{
//		_year = year;
//		_month = month;
//	}
//private:
//	int _year;
//	int _month;
//
//};
//int main()
//{
//	D s1(2025,7);
//	D s2;
//	s1 == s2;
//	return 0;
//}
//class Stack
//{
//public:
//	void StackPush(Stack&p)
//	{
//
//	}
//	Stack(int n=4)
//	{
//		int* p = (int*)malloc(sizeof(int)*n);
//		if (p == nullptr)
//		{
//			perror("Stack::malloc fail");
//			return;
//		}
//		this->a = p;
//		this->top = 0;
//		this->capacity = n;
//	}
//	~Stack()
//	{
//		free(this->a);
//		this->a = nullptr;
//	}
//	void StackPush(int x)
//	{
//		if (this->capacity == top)
//		{
//			int newcapacity = 2 * this->capacity;
//			int* p = (int*)realloc(this->a,sizeof(int) *newcapacity);
//			if (p == nullptr)
//			{
//				perror("StackPush::realloc fail");
//				return;
//			}
//			this->capacity = newcapacity;
//		}
//		this->a[this->top++] = x;
//	}
//	bool StackEmpty()
//	{
//		return this->top == 0;
//	}
//	
//	void StackPop()
//	{
//		this->top--;
//	}
//	int StackTop()
//	{
//		return this->a[this->top-1];
//		this->top--;
//	}
//private:
//	int* a;
//	int top;
//	int capacity;
//};
//void Stackprint(Stack& st)
//{
//	while (!st.StackEmpty())
//	{
//		cout << st.StackTop() << " ";
//		st.StackPop();
//	}
//	cout << endl;
//}
//int main()
//{
//	Stack st;
//	st.StackPush(1);
//	st.StackPush(2);
//	st.StackPush(3);
//	st.StackPop();
//	st.StackPush(4);
//	st.StackPush(5);
//	Stackprint(st);
//	return 0;
//}
//class A
//{
//public:
//	void print()
//	{
//		cout << "void print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A *a = nullptr;
//	a->print();
//	return 0;
//}
//class date
//{
//public:
//	void Dateprint()
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//	//date()
//	//{
//	//	_year = 0;
//	//	_month = 0;
//	//	_day = 0;
//	//}
//	date(int year=0,int month=0,int day=0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~date()
//	{
//		_year = _month = _day = 0;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	date r(2024, 5, 6);
//	r.Dateprint();
//	//date* pr = nullptr;
//	//pr->Dateprint();
//	return 0;
//}