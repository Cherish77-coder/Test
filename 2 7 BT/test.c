#include"queue.h"
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* BuyNode(BTDataType x)
{
	BTNode* ret = malloc(sizeof(BTNode));
	if (ret == NULL)
	{
		perror("malloc fail:");
		return NULL;
	}
	ret->_data = x;
	ret->_left = ret->_right = NULL;
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
	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6; 
	node6->_left = node7;
	return node1;
}

void InsertOrder(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end=i;
		int temp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > arr[end + 1])
			{
				
				arr[end + 1] = arr[end];
				arr[end] = temp;
				end--;
			}
			else
				break;
		}
		arr[end+1] = temp;
	}
	
}
void LevelOrder(BTNode* root)
{
	Queue* q = malloc(sizeof(Queue));
	if (q == NULL)
	{
		perror("malloc fail:");
		exit(1);
	}
	QueueInit(q);
	if(root)
	QueuePush(q, root);
	while (!QueueEmpty(q))
	{
		
		BTNode* n = QueueFront(q);
		printf("%d ", n->_data);
		QueuePop(q);
		if (n->_left)
		{
			QueuePush(q, n->_left);
		}
		if (n->_right)
			QueuePush(q, n->_right);
	}
	QueueDestory(q);
}
bool BinaryTreeComplete(BTNode* root)
{
	Queue* q = malloc(sizeof(Queue));
	if (q == NULL)
	{
		perror("malloc fail:");
		exit(1);
	}
	QueueInit(q);
	if (root)
		QueuePush(q, root);
	while (!QueueEmpty(q))
	{

		BTNode* n = QueueFront(q);
		QueuePop(q);
		if (n == NULL)
			break;
			QueuePush(q, n->_left);
			QueuePush(q, n->_right);
	}
	while (!QueueEmpty(q))
	{
		BTNode* front = QueueFront(q);
		QueuePop(q);
		if (front)
		{
			QueueDestory(q);
			return false;
		}
	}
	QueueDestory(q);
	return true;
}
int main()
{
	BTNode* root = CreatBinaryTree();
	LevelOrder(root);
	printf("\n");
	if (BinaryTreeComplete(root))
	{
		printf("true\n");
	}
	else
		printf("false\n");
	return 0;
}
//int main()
//{
//	int a[] = { 90,23,43,12,4,5,6,5,2,3,1 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	InsertOrder(a, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}