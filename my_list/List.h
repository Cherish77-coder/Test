#pragma once
#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
namespace my
{
	template<class T>
	struct list_node
	{
		list_node(const T& x=T())
			:_data(x),
			_next(nullptr),
			_prev(nullptr)
		{}
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
	};
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T,Ref,Ptr> self;
		node* _node;
		list_iterator(node* node1):
			_node(node1){}
		Ref operator*()
		{
			return _node->_data;
		}
		self& operator++()
		{
			 _node=_node->_next;
			 return *this;
		}
		self operator++(int)
		{
			self ret(*this);
			_node = _node->_next;
			return ret;
		}
		self& operator--()
		{
			 _node=_node->_prev;
			 return *this;
		}
		self operator--(int)
		{
			self ret(*this);
			_node = _node->_prev;
			return ret;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator==(const self& s) const
		{
			return _node == s._node;
		}
		bool operator!=(const self& s) const
		{
			return _node != s._node;
		}

	};
	template<class T>
	class list
	{
		typedef list_node<T> node;
	public:
		typedef list_iterator<T,T&,T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;
		list()
		{
		empty_construct();
		}
		list(const list<T>& v)
		{
			empty_construct();
			for (auto& e : v)
			{
			    push_back(e);
			}
		}
		list(initializer_list<T> ls)
		{
			empty_construct();
			for (auto& e : ls)
			{
				push_back(e);
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it=erase(it);
			}
		}
		void swap( list<T>& v)
		{
			std::swap(_head, v._head);
			std::swap(_size, v._size);
		}
		void empty_construct()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			//_head->_data = 0;
			_size = 0;
		}
		void operator=(list<T> v)
		{
			swap(v);
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos._node);
			node* newnode = new node(x);
			node* next = pos._node;
			node* prev = pos._node->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			next->_prev = newnode;
			++_size;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			node* prev = pos._node->_prev;
			node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
			return next;
		}
		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail= _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
			++_size;
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		iterator& begin()
		{
			iterator it(_head->_next);
			return it;
		}
		iterator& end()
		{
			iterator it(_head);
			return it;
		}
		const_iterator& begin() const
		{
			const_iterator it(_head->_next);
			return it;
		}
		const_iterator& end() const
		{
			const_iterator it(_head);
			return it;
		}
		const size_t size()  const
		{
			return _size;
		}

	private:
		node* _head;
		size_t _size;
	};
	class AA
	{
		public:
			AA(int x=0, int y=0)
			{ 
				a = x;
				b = y;
			}
	//private:
		int a=1;
		int b=1;
	};
	template<class T>
	void print_container( const list<T>& v)
	{
		for (auto e : v)
		{
			//e += 10;
			cout <<e<<" ";
		}
		cout << endl;
	}
}
