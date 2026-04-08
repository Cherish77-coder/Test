#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
namespace my
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)-构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;
			reserve(s._capacity);
			for (auto ch : s)
			{
				push_back(ch);
			}
		}

		void swap(string& ss)
		{
			::swap(_str, ss._str);
			::swap(_size, ss._size);
			::swap(_capacity, ss._capacity);
		}

		// 移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			// 转移掠夺你的资源
			swap(s);
		}

		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" <<
				endl;
			if (this != &s)
			{
				_str[0] = '\0';
				_size = 0;
				reserve(s._capacity);
				for (auto ch : s)
				{
					push_back(ch);
				}
			}
			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			//cout << "~string() -- 析构" << endl;
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity *
					2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};
}
class Person
{
public:
	Person(const my::string& s = "\0", const int& age = 0)
		:_name(s)
		,_age(age)
	{
	}
	Person(const Person& p) = delete;
	Person(Person&& p) = default;
	/*~Person()
	{

	}*/
private:
	my::string  _name;
	int _age;
};
//int main()
//{
//	Person s1;
//	//Person s2 = s1;
//	Person s3 = std::move(s1);
//	Person s4;
//	//s4 = std::move(s2);
//	return 0;
//}

//int main()
//{
//	auto add=[](int x, int y) { return x + y; };
//	cout << add(1, 2) << endl;
//	auto func1 = []
//		{
//			cout << "hello bit" << endl;
//			return 0;
//		};
//	func1();
//	int a = 0, b = 1;
//	auto swap1 = [](int& x, int& y)
//		{
//			int tmp = x;
//			x = y;
//			y = tmp;
//		};
//	swap1(a, b);
//	cout << a << ":" << b << endl;
//	return 0;
//}
//int main()
//{
	//int a = 0;
	//int b = 1;
	//auto swap = [=]()mutable {//取消对左值的const引用
	//	auto tmp = a;
	//	a = b;
	//	b = tmp;
	//	};
	//swap();
	//cout << a <<" "<< b << endl;
//	int a = 1; int b = 0;
//	int c = -1; int d = -4;
//	auto func = [=,&a,&b]() {
//		++a;
//		++b;
//		};
//	func();
//	cout << a << " " << b <<" " << c<<" "<<d<< endl;
//	// 局部的静态和全局变量不能捕捉，也不需要捕捉
//	int x = 0;
//	static int m = 0;
//	auto func6 = [=]
//		{
//			int ret = x + m;
//			return ret;
//		};
//	cout << func6() << endl;
//	return 0;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	Plus(int n = 10)
//		:_n(n)
//	{
//	}
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return (a + b) * _n;
//	}
//private:int _n;
//};
#include<functional>
//int main()
//{
//	function<int(int, int)> f1 = [](int x, int y) {return x + y; };
//	cout << f1(1, 2) << endl;
//	function<double(Plus*, double, double)> f5 = &Plus::plusd;
//	Plus pd;
//	cout << f5(&pd, 1.1, 1.1) << endl;
//	function<double(Plus, double, double)> f6 = &Plus::plusd;
//	cout << f6(pd, 1.1, 1.1) << endl;
//	cout << f6(pd, 1.1, 1.1) << endl;
//	function<double(Plus&&, double, double)> f7 = &Plus::plusd;
//	cout << f7(move(pd), 1.1, 1.1) << endl;
//	cout << f7(Plus(), 1.1, 1.1) << endl;
//	return 0;
//}
#include<functional>
using placeholders::_1;
using placeholders::_2;
using placeholders::_3;
int Sub(int a, int b)
{
	return (a - b) * 10;
}
int SubX(int a, int b, int c)
{
	return (a - b - c) * 10;
}
class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}
	double plusd(double a, double b)
	{
		return a + b;
	}
};
int main()
{
	//auto sub1 = bind(Sub, 100, _1);
	//cout << sub1(99) << endl;
	//auto sub2 = bind(Sub, _1, 100);
	//cout << sub2(10) << endl;
	//function<double(Plus&&, double, double)> f6 = &Plus::plusd;
	//Plus pd;
	//cout << f6(move(pd), 1.1, 1.1) << endl;
	//cout << f6(Plus(), 1.1, 1.1) << endl;
	//// bind一般用于，绑死一些固定参数
	//function<double(double, double)> f7 = bind(&Plus::plusd, Plus(), _1, _2);
	//cout << f7(1.1, 1.1) << endl;
	function<int(int)> f9 = bind(Plus::plusi, 100,_1);
	auto func1 = [](double rate, double money, int year)->double {
		double ret = money;
		for (int i = 0; i < year; i++)
		{
			ret += ret * rate;
		}
		return ret - money;
		};
	cout << f9(1) << endl;
	return 0;
}