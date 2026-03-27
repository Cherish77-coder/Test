#define _CRT_SECURE_NO_WARNINGS
#include"RBTree.h"
#include<vector>
#include"AVLTree.h"
void TestTree2()
{
	const int N = 100000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
	}size_t begin2 = clock();
	size_t begin22 = clock();
	RBTree<int, int> t;
	AVLTree<int, int>a;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
		a.insert(make_pair(e, e));
	}
	size_t end2 = clock();
	size_t end22 = clock();
	cout << "RBTreeInsert:" << end2 - begin2 << endl;
	cout << t.IsBalance() << endl;
	cout << "RBTreeHeight:" << t.height() << endl;
	cout << "RBTreeSize:" << t.size() << endl;
	cout << "AVLTreeInsert:" << end2 - begin2 << endl;
	cout << a.IsBalanceTree() << endl;
	cout << "AVLHeight:" << a.height() << endl;
	cout << "AVLSize:" << a.size() << endl;
	size_t begin1 = clock();
	size_t begin11 = clock();
	 //确定在的值
	for (auto e : v)
	{
	t.find(e);
	}
	// 随机值
	/*for (size_t i = 0; i < N; i++)
	{
		t.find((rand() + i % 100));
	}*/
	size_t end1 = clock();
	size_t end11 = clock();
	cout << "RBTreeFind:" << end1 - begin1 << endl;
	cout << "AVLTreeFind:" << end11 - begin11 << endl;

}
int main()

{
	TestTree2();
	return 0;
}
//int main()
//{
//	RBTree<int, int> t;
//	t.Insert({1,1});