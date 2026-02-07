#include<stdio.h>
#include<stdlib.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
BTNode* BuyNode(BTDataType x)
{
	BTNode* ret = malloc(sizeof(BTNode));
	if (ret == NULL)
	{
		perror("malloc fail:");
		return NULL;
	}
	ret->data = x;
	ret->left = ret->right = NULL;
	return ret;
}
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node2->right = node7;
	return node1;
}
void Preorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
		
}
void Midorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	Midorder(root->left);
	printf("%d ", root->data);
	Midorder(root->right);
}
void Rigorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	Rigorder(root->left);
	Rigorder(root->right);
	printf("%d ", root->data);
}
// 二叉树结点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->right) + BinaryTreeSize(root->left) + 1;
}
// 二叉树叶子结点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	int left = BinaryTreeLeafSize(root->left);
	int right = BinaryTreeLeafSize(root->right);
	return left > right ? left + 1 : right + 1;
}
// 二叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* ret1 = BinaryTreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode*ret2=BinaryTreeFind(root->right, x);
	return ret2;
}
int main()
{
	BTNode* root = CreatBinaryTree();
	Rigorder(root);
	printf("\n");
	printf("%d\n", BinaryTreeSize(root));
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root, 3));
	BTNode* f = BinaryTreeFind(root, 0);
	if (f == NULL)
		printf("BinaryTreeFind:NULL\n");
	else
	printf("BinaryTreeFind: %d\n",f->data );
	return 0;
}