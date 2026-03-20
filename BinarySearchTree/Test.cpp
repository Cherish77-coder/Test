#include"BsTree.h"
int main()
{
	BSTree<int> s;
	int a[]= {8, 3, 1, 10, 1, 6, 4, 7, 14, 13}; 
	for (auto e : a)
	{
		s.insert(e);
	}
	s.Inorder();
	//s.erase(8);
	//s.Inorder();
	for (auto e : a)
	{
		s.erase(e);
		s.Inorder();
	}
	//cout << s.find(0) << endl;
	return 0;
}