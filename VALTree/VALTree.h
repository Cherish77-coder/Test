#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
template<class K, class V>
struct AVLTreeNode
{
	// 需要parent指针，后续更新平衡因子可以看到
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf; // balance factor
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{
	}
};
template<class K, class V>
class VALTree
{
public:
	using Node = AVLTreeNode<K,V>;
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kv.first < cur)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		if (parent->_kv >kv)
		{
			parent->_left = new Node(kv);
		}
		else
		{
			parent->_right = new Node(kv);
		}
		cur->_parent = parent;
		//调整平衡因子
		while (parent)
		{
			if (cur = parent->_left)
			{
				parent->_bf--;
			}
			else
				parent->_bf++;
			if (parent->_bf == 0 || parent->_bf == 2|| parent->_bf == -2)//结束条件
			{
				break;
			}
			else if(parent->_bf == 1 || parent->_bf =-1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else
			{
				assert(false);//VAl树之前就有问题的情况
			}
		}
		return true;

	}
private:
	Node* _root=nullptr;
};
