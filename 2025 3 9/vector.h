#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
namespace my
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
		{ }
		//vector()=default;
		vector(const vector<T>& v)
		{
			for (auto x: v)
			{
				push_back(x);
			}
		}
		vector(size_t n,const T& val=T())
		{
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
		{
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _finish = _end_of_storage;
			}
			
		}
		void swap(vector<T> v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector<T>& operator=( vector<T> v)
		{
			swap(v);
			return *this;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos+1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;

		}
		bool empty()
		{
			return _finish == _start;
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);//扩容
			}
			*_finish = x;
			_finish++;

		}
		void pop_back()
		{
			assert(_start != _finish);
			--_finish;
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos > _start && pos <= _finish);
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
		void resize(size_t n, T val = T())
		{
			if (n > size())
			{
				reserve(n);
				while (_finish < _start + n)
				{
					push_back(val);
				}
			}
			else
			{
				_finish = _start + n;
			}
		}
		void reserve(size_t n)
		{
			if (n < capacity())
				return;
			else
			{
				size_t old_size = size();
				iterator tmp = new T[n];
				for (size_t i = 0; i < old_size; ++i)
				{
					tmp[i] = _start[i];//取消使用memcpy对于自定义类型的浅拷贝
				}
				//if(_start!=nullptr)
				delete []_start;
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
	void container_print(const T& v)
	{
		//typename vector<T>::const_iterator it = v.begin();
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
		/*for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;*/
	};
}
