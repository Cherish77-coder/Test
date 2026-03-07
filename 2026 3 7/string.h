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
		const char* c_str() const
		{
			return _str;
		}
		/*string()
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{};*/
		string(const char* s = "")
		{
			//delete[]_str;
			size_t capacity = strlen(s);
			_str = new char[capacity + 1];
			strcpy(_str, s);
			_size = _capacity = capacity;
		}
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		string(string& str)
		{
			string tmp(str.c_str());
			string::Swap(tmp);
			//_str = new char[str.capacity() + 1];
			//strcpy(_str, str.c_str());
			////delete[]str._str;
			//_size = str.size();
			//_capacity = str.capacity();
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;

				_size = _capacity = 0;
			}
			//cout << "~string()" << endl;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		size_t size() const
		{
			return _size;
		}
		char& operator[](int n)
		{
			assert(n < _size);
			return _str[n];
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				Swap(tmp);
				/*delete[] _str;
				_str = new char[s.capacity()+1];
				strcpy(_str, s.c_str());
				_size = s._size;
				_capacity = s._capacity;*/
			}
				return *this;
		}
		const char& operator[](int n) const
		{
			assert(n < _size);
			return _str[n];
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);
		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);
		string substr(size_t pos = 0, size_t len = npos);
	private:
		//size和capacity默认不包含斜杠0，开空间要记得多开一个位置给\0;
		char* _str;
		size_t _size;
		size_t _capacity;
		static const int npos = -1;
	};
	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
}
//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//
//#include<iostream>
//#include<string>
//#include<assert.h>
//using namespace std;
//
//namespace bit
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		typedef const char* const_iterator;
//
//		iterator begin()
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		const_iterator begin() const
//		{
//			return _str;
//		}
//
//		const_iterator end() const
//		{
//			return _str + _size;
//		}
//
//		/*string()
//			:_str(new char[1]{'\0'})
//			,_size(0)
//			,_capacity(0)
//		{}*/
//
//		// 短小频繁调用的函数，可以直接定义到类里面，默认是inline
//		string(const char* str = "")
//		{
//			_size = strlen(str);
//			// _capacity不包含\0
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		// 深拷贝问题
//		// 
//		// s2(s1)
//		string(const string& s)
//		{
//			_str = new char[s._capacity + 1];
//			strcpy(_str, s._str);
//			_size = s._size;
//			_capacity = s._capacity;
//		}
//
//		// s2 = s1
//		// s1 = s1
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//
//				_str = new char[s._capacity + 1];
//				strcpy(_str, s._str);
//				_size = s._size;
//				_capacity = s._capacity;
//			}
//
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = _capacity = 0;
//		}
//
//		const char* c_str() const
//		{
//			return _str;
//		}
//
//		void clear()
//		{
//			_str[0] = '\0';
//			_size = 0;
//		}
//
//		size_t size() const
//		{
//			return _size;
//		}
//
//		size_t capacity() const
//		{
//			return _capacity;
//		}
//
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//
//			return _str[pos];
//		}
//
//		const char& operator[](size_t pos) const
//		{
//			assert(pos < _size);
//
//			return _str[pos];
//		}
//
//		void reserve(size_t n);
//		void push_back(char ch);
//		void append(const char* str);
//		string& operator+=(char ch);
//		string& operator+=(const char* str);
//
//		void insert(size_t pos, char ch);
//		void insert(size_t pos, const char* str);
//		void erase(size_t pos, size_t len = npos);
//
//		size_t find(char ch, size_t pos = 0);
//		size_t find(const char* str, size_t pos = 0);
//		string substr(size_t pos = 0, size_t len = npos);
//	private:
//		//char _buff[16];
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//
//		//static const size_t npos = -1;
//		static const size_t npos;
//
//		/*static const int N = 10;
//		int buff[N];*/
//	};
//
//	bool operator<(const string& s1, const string& s2);
//	bool operator<=(const string& s1, const string& s2);
//	bool operator>(const string& s1, const string& s2);
//	bool operator>=(const string& s1, const string& s2);
//	bool operator==(const string& s1, const string& s2);
//	bool operator!=(const string& s1, const string& s2);
//
//	ostream& operator<<(ostream& out, const string& s);
//	istream& operator>>(istream& in, string& s);
//}