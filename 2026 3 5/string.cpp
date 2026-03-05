#include"string.h"
namespace my
{
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}
	}
	void string::push_back(char ch)
	{
		if (_size == _capacity)//À©ÈÝ
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (len + _size >= _capacity)
		{
			reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
			strcpy(_str + _size, str);
			_size += len;
			
		}
		else
		{
			strcpy(_str + _size, str);
			_size += len;
		}
	}
	string& string::operator+=(char ch)
	{ 
		if (_size == _capacity)//À©ÈÝ
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		size_t len = strlen(str);
		if (_size+len >= _capacity)//À©ÈÝ
		{
			reserve(_size+len>_capacity*2?_size+len:_capacity*2);
		}
		strcpy(_str + _size, str);
		_size += len;
		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size&&pos>=0);
		if (_size == _capacity)
		{
		  reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		//µ÷ÕûÎ»ÖÃ
		size_t end = _size+1;
		while (end>pos)//&&end!=npos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = ch;
		++_size;
		_str[_size] = '\0';
	}
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size && pos >= 0);
		size_t len = strlen(str);
		if (_size+len >= _capacity)//À©ÈÝ
		{
			reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
		}
		size_t end = _size+1;
		while (end > pos)//&&end!=npos)
		{
			_str[end+len] = _str[end];
			--end;
		}
		strncpy(_str + pos, str,len);
		_size += len;
	}
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		size_t i = pos;
		while (i<_size)
		{
			_str[i] = _str[i+ 1];
			++i;
		}
		--_size;
	}
	size_t string::find(char ch, size_t pos)
	{
		assert(pos < _size);
		for (size_t i = pos;i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return 1;
			}
		}
		return npos;
	}
	size_t string:: find(const char* str, size_t pos )
	{ 
		assert(pos < _size);
		char* ptr = strstr(_str, str);
		if (ptr == nullptr)
			return npos;
		else
		{
			return ptr - _str;
		}
	}
	/*string string::substr(size_t pos , size_t len )
	{
		assert(pos < _size);
		if (len > _size - pos)
		{
			len = _size - pos;
		}
		string sub;
		size_t i = pos;
		while (len--)
		{
			sub += _str[i++];
		}
		return sub;
	}*/
	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len > _size-pos)
			len = _size - pos;
		string sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; ++i)
		{
			sub += _str[i + pos];
		}
		return sub;
	}
	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str())<0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0 || (s1<s2);
	}
	bool operator>(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) > 0;
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) > 0 || strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(),s2.c_str())==0;
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(strcmp(s1.c_str(), s2.c_str()));
	}
}