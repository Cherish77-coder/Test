#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
using namespace std;
class A
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
		cout << _a << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	p->Print();
	return 0;
}
//class Date
//{
//public:
//	// void Init(Date* const this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		// 编译报错：error C2106: “=”: 左操作数必须为左值
//		// this = nullptr;
//		// this->_year = year;
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	// 这里只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d;
//	d.Init(2026, 3, 2);
//	d.Print();
//	return 0;
//}
//using namespace std;
//class d
//{
//public:
//	void a()
//	{
//
//	};
//
//};
//class Stack
//{
//public:
//private:
//	int a;
//	int b;
//};
//int main()
//{
//	cout << sizeof(d) << endl;
//	cout << sizeof(Stack) << endl;
//	return 0;
//}
//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	return ret;
//}
//int main()
//{
//	// 可以通过汇编观察程序是否展开
//	// 有call Add语句就是没有展开，没有就是展开了
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}
//inline int add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int x = 1, y = 9;
//	cout << add(x, y) << endl;
//	cout << add(x, y) << endl;
//	cout << add(x, y) << endl;
//	cout << add(x, y) << endl;
//	cout << add(x, y) << endl; 
//	cout << add(x, y) << endl;
//	cout << add(x, y) << endl; 
//	cout << add(x, y) << endl;
//	cout << add(x, y) << endl;
//	return  0;
//}
//int main()
//{
//	string s1("hello world");
//	string s2(s1, 6);
//	string s3;
//	cout << s3 << endl;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	s2[4] = 'o';
//	cout << s2 << endl;
//	return 0;
//}
//template <class T>
//class Stack
//{
//public:
//	Stack(int n = 4)
//		:_arry(new T[n])
//		, _size(0)
//		, _capacity(n)
//	{}
//	~Stack()
//	{
//		delete _arry;
//		_size = _capacity = 0;
//	}
//	void Push(const T& x)
//	{
//		if (_capacity == _size)
//		{
//			T* tmp = new T[_capacity * 2];
//			memcpy(tmp, _arry, sizeof(T)*_capacity);
//			delete _arry;
//			_arry = tmp;
//			_capacity *= 2;
//		}
//		_arry[_size++] = x;
//	}
//private:
//	T* _arry;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack<int> st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	st.Push(5);
//	return 0;
//}
//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int x = 10;
//	double y = 9.9;
//	cout << Add((double)x, y) << endl;
//	return 0;
//}
//template<class T>
//T Add(const T& x,const T& y)
//{
//	return x + y;
//}
//template<class T1,class T2>
//T1 Add(const T1& x, const T2& y)
//{
//	return x + y;
//}
//int main()
//{
//	int x = 12; int y = 19;
//	double m = 3.3;
//	cout << Add(m, x) << endl;
//	cout << Add(x, y) << endl;
//	return 0;
//}
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int x = 10, y = 20;
//	double m = 1.0, n = 3.3;
//	/*Swap(x, y);
//	cout << x << ' ' << y<< endl;
//	Swap(m, n);
//	cout << m << ' ' << n << endl;*/
//	return 0;
//}