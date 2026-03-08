#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
namespace my
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		bool empty()
		{
			return _finish == _start;
		}
		void push_back(const T& x)
		{
			if (_start == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);//À©ÈÝ
			}
			_start[size()] = x;
			_finish++;

		}
		iterator insert(iterator pos, const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;

			++_finish;

			return pos;
		}
		/*iterator insert(iterator pos, const T& x)
		{
			size_t len = pos - _start;
			if (_start == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				_finish = _start + len;
			}
			size_t end = size();
			while (end >= len)
			{
				_start[end] = _start[end - 1];
				--end;
			}
			_start[len] = x;
			++_finish;
			return _start[len];
		}*/
		void reserve(size_t n)
		{
			if (n < capacity())
				return;
			else
			{
				size_t old_size = size();
				iterator tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * size());
				delete[]_start;
				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start + i;
		}
		 const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}
	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _end_of_storage=nullptr;
	};
	template<class T>
	void vector_print(const vector<T>& v)
	{
		//typename vector<T>::const_iterator it = v.begin();
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	};
}
