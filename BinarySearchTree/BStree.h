#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
namespace my
{
	template<class v>
	struct BinarySearchTreeNode
	{
		BinarySearchTreeNode(v val)
			:_val(val)
		{
		}
		v _val;
		BinarySearchTreeNode* _left = nullptr;
		BinarySearchTreeNode* _right = nullptr;
	};

	template<class v>
	class BSTree
	{
	public:
		using  Node = BinarySearchTreeNode<v>;
		bool insert(const v& val)
		{
			if (_root == nullptr)
			{
				_root = new Node(val);
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				parent = cur;
				if (cur->_val <= val)
					cur = cur->_right;
				else if (cur->_val > val)
					cur = cur->_left;
			}
			if (parent->_val <= val)
			{
				parent->_right = new Node(val);
				return true;
			}
			else if (parent->_val > val)
			{
				parent->_left = new Node(val);
				return true;
			}
			return false;
		}
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
		bool find(const v& val)
		{
			if (_root == nullptr)
			{
				return false;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				if (cur->_val < val)
					cur = cur->_right;
				else if (cur->_val > val)
					cur = cur->_left;
				else
					return true;
			}
			return false;
		}
		bool erase(const v& val)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_val < val)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_val > val)
				{
					parent = cur;
					cur = cur->_left;
				}
				else//cur->_val==val
				{
					if (cur->_left == nullptr)//左边是空的
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)//cur->right==nullptr
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
						delete cur;
					}
					else//左右都不是空
					{
						//右子树的最小值

						Node* replacep = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replacep = replace;
							replace = replace->_left;
						}
						cur->_val = replace->_val;
						if (replacep->_left == replace)
						{
							replacep->_left = replace->_right;
						}
						else
							replacep->_right = replace->_right;
						delete replace;
					}
					return true;
				}
			}
			return false;
		}

	private:
		void _Inorder(Node* node)
		{
			if (node == nullptr)
			{
				return;
			}
			_Inorder(node->_left);
			cout << node->_val << " ";
			_Inorder(node->_right);
		}
		Node* _root = nullptr;
	};
}
namespace my_multi
{
	template<class v,class T>
	struct BinarySearchTreeNode
	{
		BinarySearchTreeNode(const v val,const T& size)
			:_val(val)
			,_size(size)
			,_left()
			,_right(){}
		v _val;
		T _size;
		BinarySearchTreeNode* _left = nullptr;
		BinarySearchTreeNode* _right = nullptr;
	};

	template<class v,class T>
	class BSTree
	{
	public:
		using  Node = BinarySearchTreeNode<v,T>;
		bool insert(const v& val,const T& size)
		{
			if (_root == nullptr)
			{
				_root = new Node(val,size);
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				parent = cur;
				if (cur->_val < val)
					cur = cur->_right;
				else if (cur->_val > val)
					cur = cur->_left;
				else
					break;
			}
			if (parent->_val < val)
			{
				parent->_right = new Node(val,size);
				return true;
			}
			else if (parent->_val > val)
			{
				parent->_left = new Node(val,size);
				return true;
			}
			return false;
		}
		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}
		Node* find(const v& val)
		{
			if (_root == nullptr)
			{
				return nullptr;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				if (cur->_val < val)
					cur = cur->_right;
				else if (cur->_val > val)
					cur = cur->_left;
				else
					return cur;
			}
			return nullptr;
		}
		bool erase(const v& val)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_val < val)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_val > val)
				{
					parent = cur;
					cur = cur->_left;
				}
				else//cur->_val==val
				{
					if (cur->_left == nullptr)//左边是空的
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)//cur->right==nullptr
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
						delete cur;
					}
					else//左右都不是空
					{
						//右子树的最小值

						Node* replacep = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replacep = replace;
							replace = replace->_left;
						}
						cur->_val = replace->_val;
						if (replacep->_left == replace)
						{
							replacep->_left = replace->_right;
						}
						else
							replacep->_right = replace->_right;
						delete replace;
					}
					return true;
				}
			}
			return false;
		}

	private:
		void _Inorder(Node* node)
		{
			if (node == nullptr)
			{
				return;
			}
			_Inorder(node->_left);
			cout << node->_val << ":" << node->_size << endl;;
			_Inorder(node->_right);
		}
		Node* _root = nullptr;
	};
}
