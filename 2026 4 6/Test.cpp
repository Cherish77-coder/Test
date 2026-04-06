#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<assert.h>
#include"List.h"
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
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
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
		// 移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
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
		}char& operator[](size_t pos)
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
		}size_t size() const
		{
			return _size;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};
 }
 class Solution {
 public:
	 // 这里的传值返回拷贝代价就太大了
	 vector<vector<int>> generate(int numRows,vector<vector<int>>&vv) {
		  vv.resize(numRows);
		 for (int i = 0; i < numRows; ++i)
		 {
			 vv[i].resize(i + 1, 1);
		 }
		 for (int i = 2; i < numRows; ++i)
		 {
			 for (int j = 1; j < i; ++j)
			 {
				 vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			 }
		 }
		 return vv;
	 }
 };
//int main()
//{
//	my::list<my::string> l;
//	l.push_back("111111");
//	my::string s( "hehe");
//	l.push_back(s);
//	return 0;
//}
 //int main()
 //{
	// vector<vector<int>> ret;
	// Solution().generate(10, ret);
	////使用输出型参数返回可以减少拷贝
	// for (auto& e : ret)
	// {
	//	 for (auto& i : e)
	//	 {
	//		 cout << i << " ";
	//	 }
	//	 cout << endl;
	// }
	// return 0;
 //}
 // 由于引用折叠限定，f1实例化以后总是一个左值引用
 template<class T>
 void f1(T& x)
 {
 }
 // 由于引用折叠限定，f2实例化后可以是左值引用，也可以是右值引用
 template<class T>
 void f2(T&& x)
 {
 }
 //int main()
 //{
	// typedef int& lref;
	// typedef int&& rref;
	// int n = 0;
	// lref& r1 = n; // r1 的类型是 int&
	// lref&& r2 = n; // r2 的类型是 int&
	// rref& r3 = n; // r3 的类型是 int&
	// rref&& r4 = 1; // r4 的类型是 int&&
	// // 没有折叠->实例化为void f1(int& x)
	// f1<int>(n);
	// //f1<int>(0); // 报错
	// // 折叠->实例化为void f1(int& x)
	// f1<int&>(n);
	//// f1<int&>(0); // 报错
	// // 折叠->实例化为void f1(int& x)
	// f1<int&&>(n);
	// //f1<int&&>(0); // 报错
	// // 折叠->实例化为void f1(const int& x)
	// f1<const int&>(n);
	// f1<const int&>(0);
	// // 折叠->实例化为void f1(const int& x)
	// f1<const int&&>(n); f1<const int&&>(0);
	// // 没有折叠->实例化为void f2(int&& x)
	//// f2<int>(n); // 报错
	// f2<int>(0);
	// // 折叠->实例化为void f2(int& x)
	// f2<int&>(n);
	// //f2<int&>(0); // 报错
	// // 折叠->实例化为void f2(int&& x)
	//// f2<int&&>(n); // 报错
	// f2<int&&>(0);
	// return 0;
 //}
 //int main()
 //{
	// int a = 0;
	// //f1(1);
	// f1(a);
	// f2(1);//实例化为f2<int>
	// f2(a);//实例化为f2<int&>
	// return 0;
 //}
 template<class T>
 void Function(T&& t)
 {
	 int a = 0;
	 T x = a;
	 //x++;
	 cout << &a << endl;
	 cout << &x << endl << endl;
 }
 //int main()
 //{
	// // 10是右值，推导出T为int，模板实例化为void Function(int&& t)
	// Function(10); // 右值
	// int a;
	// // a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
	// Function(a); // 左值
	// // std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
	// Function(std::move(a)); // 右值
	// const int b = 8;
	// // a是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int& t)
	// // 所以Function内部会编译报错，x不能++
	// Function(b); // const 左值// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&t)
	// // 所以Function内部会编译报错，x不能++
	// Function(std::move(b)); // const 右值
	// return 0;
 //}
 int main()
 {
	 my::list<my::string> lt;
	 my::string s1("11111111111");
	 lt.push_back(s1);

	 my::string s2("33333333333");
	 lt.push_back(move(s2));

	 lt.push_back("22222222222");
	 my::string s;
	 s = "hehe";
	 s = s2;;
	 return 0;
 }