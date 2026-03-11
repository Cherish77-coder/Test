#pragma once
#include<iostream>
#include<assert.h>
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
	template<class T>
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator<T> self;
		node* _node;
		list_iterator(node* node1):
			_node(node1){}
		T& operator*()
		{
			return _node->_data;
		}
		self& operator++()
		{
			 _node=_node->_next;
			 return *this;
		}
		self& operator--()
		{
			 _node=_node->_prev;
			 return *this;
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
		typedef list_iterator<T> iterator;
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			//_head->_data = 0;
			_size = 0;
		}
		void insert(iterator pos, const T& x)
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
		}
		void erase(iterator pos)
		{
			assert(pos != end());
			node* prev = pos._node->_prev;
			node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
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
		size_t size()
		{
			return _size;
		}

	private:
		node* _head;
		size_t _size;
	};
}
