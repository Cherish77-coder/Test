#include<iostream>
using namespace std;
// 枚举值表示颜色
enum Colour
{
	RED,
	BLACK
};
// 这里我们默认按key/value结构实现
template<class K, class V>
struct RBTreeNode
{
	// 这里更新控制平衡也要加入parent指针
	pair<K,V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;
	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{
	}
};
template<class K, class V >
class RBTree
{
public:
	typedef RBTreeNode<K,V> Node;
	int height()
	{
		return _height(_root);
	}
	int size()
	{
		return _size(_root);
	}
	Node* find(K key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				return cur;
			}
			else if (cur->_kv.first>key)
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
	bool Insert(const pair<K,V> kv)
	{
		if(_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while(cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;
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
		return true;
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