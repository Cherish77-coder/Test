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
			return _str+_size;
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
		string(const char* s="")
		{
			size_t capacity = strlen(s);
			 _str = new char[capacity+1];
			strcpy(_str, s);
			_size = _capacity = capacity;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
			_size = _capacity = 0;
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
	private:
		//size和capacity默认不包含斜杠0，开空间要记得多开一个位置给\0;
		char* _str;
		size_t _size;
		size_t _capacity;
		static const int npos = -1;
	};
}