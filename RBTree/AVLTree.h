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
class AVLTree
{
public:
	using Node = AVLTreeNode<K,V>;
	int size()
	{
		return _size(_root);
	}
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
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(kv);
		if (parent->_kv.first >kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;
		//调整平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else 
				parent->_bf++;
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent=parent->_parent;
			}
			else if (parent->_bf == 2|| parent->_bf == -2)//结束条件
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);//VAl树之前就有问题的情况
			}
		}
		return true;

	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	int height()
	{
		return _Height(_root);
	}
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	int _size(Node* root)
	{
		if (root == nullptr)
			return 0;
		return _size(root->_left) + _size(root->_right) + 1;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second <<" " << root->_bf << endl;
		_InOrder(root->_right);
	}
	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftheight = _Height(root->_left);
		int rightheight = _Height(root->_right);
		return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
	}
	bool _IsBalanceTree(Node* root)
	{
		// 空树也是AVL树
		if (nullptr == root)
			return true;
		// 计算pRoot结点的平衡因子：即pRoot左右子树的高度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight; if (abs(diff) >= 2)
		{
			cout << root->_kv.first << "高度差异常" << endl;
			return false;
		}
		if (root->_bf != diff)
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}
		// pRoot的左和右如果都是AVL树，则该树一定是AVL树
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		//Node* parentLR = parentL->_right;
		Node* pparent = parent->_parent;
		subL->_right = parent;
		parent->_left = subLR;
		parent->_parent = subL;
		
		if(subLR)
		subLR->_parent = parent;
		if (pparent == nullptr)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else//parent不是根节点
		{
			subL->_parent = pparent;
			if (pparent->_left == parent)//判断是哪一边指向parent
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}
		//跟新平衡因子
		subL->_bf = 0;
		parent->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pparent = parent->_parent;
		parent->_parent = subR;
		parent->_right = subRL;
		subR->_left = parent;
		if (subRL)
			subRL->_parent = parent;
		if (pparent == nullptr)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			subR->_parent = pparent;
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
		}
		subR->_bf = 0;
		parent->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 0)
		{
			subLR->_bf = subL->_bf = parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);
		if (bf == 1)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == 0)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else
			assert(false);
	}
	Node* _root=nullptr;
};
