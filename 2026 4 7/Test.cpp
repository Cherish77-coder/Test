#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"List.h"
using namespace std;
//方法1：包扩展递归形式
void Showout1()
{
	cout << endl;
}
template<class T,class ...Args>
void Showout1(T& x,const Args&...args)
{
	cout << x << " ";
	Showout1(args...);
}
//方法2：使用可变参数模板函数调用带有返回值的函数
template<class ...Args>
void  Argument(const Args&...args)
{
}
template<class T>
const T& Showout2(const T& x)
{
	cout << x << " ";
	return x;
}
template<class ...Args>
void Print( const Args&...args)
{
	//Showout1(args...);
	//cout << sizeof...(args) << endl;
	Argument(Showout2(args)...);
	cout << endl;
}
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
//int main()
//{
//	int a = 0;
//	Print(a);
//	Print(1);
//	Print(1, a);
//	Print(1, a, "ssss;s");
//	return 0;
//}
#include<list>
//int main()
//{
//	list<my::string> lt;
//	// 传左值，跟push_back一样，走拷贝构造
//	my::string s1("111111111111");
//	lt.emplace_back(s1);
//	cout << "*********************************" << endl;
//	// 右值，跟push_back一样，走移动构造
//	lt.emplace_back(move(s1));
//	cout << "*********************************" << endl;
//	// 直接把构造string参数包往下传，直接用string参数包构造string
//	// 这里达到的效果是push_back做不到的
//	lt.emplace_back("111111111111"); cout << "*********************************" << endl;
//	list<pair<my::string, int>> lt1;
//	// 跟push_back一样
//	// 构造pair + 拷贝/移动构造pair到list的节点中data上
//	pair<my::string, int> kv("苹果", 1);
//	lt1.emplace_back(kv);
//	cout << "*********************************" << endl;
//	// 跟push_back一样
//	lt1.emplace_back(move(kv));
//	cout << "*********************************" << endl;
//	////////////////////////////////////////////////////////////////////
//	// 直接把构造pair参数包往下传，直接用pair参数包构造pair
//	// 这里达到的效果是push_back做不到的
//	lt1.emplace_back("苹果", 1);
//	//lt1.emplace_back({ "苹果",1 });错误
//	cout << "*********************************" << endl;
//	return 0;
//}
//int main()
//{
//	int a = 1, b = 2;
//	auto add=[](int x, int y) -> int { return x + y; };
//	cout << add(a, b) << endl;
//	return 0;
//}
//int main()
//{
//	my::list<my::string> ls;
//	ls.emplace_back("1111");
//	my::string s("2222");
//	ls.emplace_back(s);
//	return 0;
//}
#include<algorithm>
#include<vector>
struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	// ...

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{
	}
};

struct Compare1
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct Compare2
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

int main()
{
	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3}, { "菠萝", 1.5, 4 } };
	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
	// 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了

	// 价格升序
	//sort(v.begin(), v.end(), Compare1());

	// 价格降序
	//sort(v.begin(), v.end(), Compare2());
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
		return g1._evaluate > g2._evaluate; });
	sort(v.begin(), v.end(),[](const Goods& gl1, const Goods& gl2) 
		{return gl1._evaluate < gl2._evaluate; });

	return 0;
}