#pragma once
#include<iostream>
using namespace std;
template<class T1,class T2>
class s
{
public:
	s()
	{
		cout << "s<class T1,class T2> " << endl;
	}
private:
};
namespace my
{
	// 定义一个模板类型的静态数组
	template<class T, size_t N = 10>
	class array
	{
	public:
		T& operator[](size_t index) { return _array[index]; }
		const T& operator[](size_t index)const { return _array[index]; }
		size_t size()const { return _size; }
		bool empty()const { return 0 == _size; }
	private:
		T _array[N];
		size_t _size;
	};
}
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};
template<class T1>
class Data<T1, char>
{
public:
	Data() { cout << "Data<T1, char>" << endl; }
private:
	int _d1;
	char _d2;
};
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

template<class T>
T Add(const T& x, const T& y);
template int Add(const int& x, const int& y);
//T Add(const T& x, const T& y)

//template<>
//int Add(const int& x, const int& y);
//{
//	return x + y;
//}