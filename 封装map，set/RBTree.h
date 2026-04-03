#pragma once
using namespace std;
// 枚举值表示颜色
enum Colour
{
	RED,
	BLACK
};
// 这里我们默认按key/value结构实现
template<class T>
struct RBTreeNode
{
	// 这里更新控制平衡也要加入parent指针
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col;
	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{
	}
};
template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T,Ref, Ptr> self;
	Node* _node;
	Node* _root;
	RBTreeIterator(Node* node, Node* root)
		:_root(root),
		_node(node)
	{
	}
	self operator++()
	{
		if (_node->_right)//右边存在,访问右边的最左节点
		{
			Node* min = _node->_right;
			while (min&&min->_left)
			{
				min = min->_left;
			}
			_node = min;
		}
		else//右边不存在，说明已经访问完了
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent)
			{
				if (parent->_left == cur)
				{
					_node = parent;
					break;
				}
				else 
				{
					cur = parent;
					parent = cur->_parent;
				}
			}
			_node = parent;
		}
		return *this;
	}
	self operator--()
	{
		if (_node == nullptr)//找最大的节点
		{
			Node* ret = _root;
			while (ret&&ret->_right)
			{
				ret = ret->_right;
			}
			_node = ret;
		}
		else if (_node->_left)//右边存在就找左边的最右边节点
		{
			_node = _node->_left;
			while (_node && _node->_right)
			{
				_node = _node->_right;
			}
		}
		else//左边不存在就找父亲
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent)
			{
				if (parent->_left == cur)
				{
					cur = parent;
					parent = cur->_parent;
				}
				else//parent->right==cur
				{
					break;
				}
			}
			_node = parent;
		}
		return *this;
	}
	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}
	bool operator == (const self& s ) const 
	{
		return _node == s._node;
	}
	bool operator != (const self & s) 
	{
		return _node != s._node;
	}

};
template<class K, class T,class KOfT>
class RBTree
{
public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;
	typedef RBTreeNode<T> Node;
	Iterator begin()
	{
		Node* ret = _root;
		while (ret&&ret->_left)
		{
			ret = ret->_left;
		}
		return {ret,_root};
	}
	Iterator end()
	{
		Iterator it{ nullptr, _root };
		return it;
	}
	ConstIterator begin() const
	{
		Node* ret = _root;
		while (ret && ret->_left)
		{
			ret = ret->_left;
		}
		return ConstIterator( ret, _root );
	}
	ConstIterator end() const
	{
		return ConstIterator(nullptr, _root );
	}
	int height()
	{
		return _height(_root);
	}
	int size()
	{
		return _size(_root);
	}
	Node* find(const K data)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data == data)
			{
				return cur;
			}
			else if (cur->_data>data)
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		return nullptr;
	}
	pair<Iterator, bool> Insert(const T& data) 
	{
		if(_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return { {_root,_root},true };
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while(cur)
		{
			KOfT kot;
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return { {cur,_root},false};;
			}
		}
		cur = new Node(data);
		cur->_col = RED;
		if (parent->_data > data)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;
		Node* ret = cur;
		//调整红黑树
		while (parent&&parent->_col==RED)
		{
			Node* grandparent = parent->_parent;
			if (grandparent->_left == parent)
			{
				Node* uncle = grandparent->_right;
				if (uncle && uncle->_col == RED)//叔叔存在且为红
				{
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)//叔叔不存在或者存在且为黑//旋转加变色
					{
						RotateR(grandparent);
						parent->_col = BLACK;
						grandparent->_col  = RED;
						break;
					}
					else//叔叔不存在或者存在且为黑//双旋转加变色
					{
						RotateL(parent);
						RotateR(grandparent);
						cur->_col = BLACK;
						grandparent->_col = parent->_col = RED;
						break;
					}
				}
			}
			else
			{
				Node* uncle = grandparent->_left;
				if (uncle && uncle->_col == RED)//叔叔存在且为红
				{
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)//叔叔不存在或者存在且为黑//旋转加变色
					{
						RotateL(grandparent);
						parent->_col = BLACK;
						grandparent->_col  = RED;
						break;
					}
					else//叔叔不存在或者存在且为黑//双旋转加变色
					{
						RotateR(parent);
						RotateL(grandparent);
						cur->_col = BLACK;
						grandparent->_col = parent->_col = RED;
						break;
					}
				}
			}
			
		}
		_root->_col = BLACK;
		return { {ret,_root},true };
	}
	bool IsBalance()
	{
		if (_root == nullptr)
			return true;
		if (_root->_col == RED)
			return false;
		// 参考值
		int refNum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++refNum;
			}
			cur = cur->_left;
		}
		return Check(_root, 0, refNum);
	}
private:
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		//Node* parentLR = parentL->_right;
		Node* pparent = parent->_parent;
		subL->_right = parent;
		parent->_left = subLR;
		parent->_parent = subL;

		if (subLR)
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
		//subL->_bf = 0;
		//parent->_bf = 0;
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
		//subR->_bf = 0;
		//parent->_bf = 0;
	}
	int _height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftheight = _height(root->_left);
		int rightheight = _height(root->_right);
		return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
	}
	int _size(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		return _size(root->_left) + _size(root->_right) + 1;
	}
	bool Check(Node* root, int blackNum, const int refNum)
	{
		if (root == nullptr)
		{
			// 前序遍历走到空时，意味着一条路径走完了
			//cout << blackNum << endl;
			if (refNum != blackNum)
			{
				cout << "存在黑色结点的数量不相等的路径" << endl;
				return false;
			}
			return true;
		}
		// 检查孩子不太方便，因为孩子有两个，且不一定存在，反过来检查父亲就方便多了
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "存在连续的红色结点" << endl;
			return false;
		}
		if (root->_col == BLACK)
		{
			blackNum++;
		}return Check(root->_left, blackNum, refNum)
			&& Check(root->_right, blackNum, refNum);
	}
	Node* _root=nullptr;
};