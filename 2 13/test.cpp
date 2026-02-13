//#include<iostream>
//#include<assert.h>
//using namespace std;
//void swap(int* a)
//{
//	if (a == nullptr)
//	{
//		cout << "NULL" << endl;
//	}
//	else
//		cout << "NUN NULL" << endl;
//}
//
//int main()
//{
//	int a = 0;
//	int* p =&a;
//	swap(p);
//	return 0;
//}
//inline int add(int a, int b = 0)
//{
//	return a + b;
//}
//int main()
//{
//	int ret = add(1);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	cout << ret << endl;
//	return 0;
//}
//int swap(int a = 0)
//{
//	return a;
//}
//int main()
//{
//	int a = 0;
//	int b = 2;
//	int* pa = &a;
//	*pa = 8;
//	double q = 1.1231422222;
//	cout << q << endl;
//	const int& c = a + b;
//	const float& ra = a;
//	cout << c << endl;
//	cout << ra<<endl;
//	const int& ret = swap();
//	cout << ret << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef struct SeqList
//{
//	int a[10];
//	int size;
//}SLT;
//// 一些主要用C代码实现版本数据结构教材中，使用C++引用替代指针传参，目的是简化程序，避开复
////杂的指针，但是很多同学没学过引用，导致一头雾水。
//void SeqPushBack(SLT& sl, int x)
//{
//}
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;
//// 指针变量也可以取别名，这里LTNode*& phead就是给指针变量取别名
//// 这样就不需要用二级指针了，相对而言简化了程序
////void ListPushBack(LTNode** phead, int x)
////void ListPushBack(LTNode*& phead, int x)
//void ListPushBack(PNode& phead, int x)
//{
//	PNode newnode = (PNode)malloc(sizeof(LTNode));
//	newnode->val = x;
//	newnode->next = NULL;
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//		//...
//	}
//}
//int main()
//{
//	SLT *st;
//	PNode newnode = NULL;
//	ListPushBack(newnode, 1);
//	return 0;
//}
//int main()
//{
//	int* p = NULL;
//	int& a = p;
//	a++;
//}
//class Stack
//{
//public:
//	void STpush(Stack* p, int x)
//	{
//		cout << "void STpush(Stack* p, int x)" << endl;
//	}
//	void STpop(Stack* p)
//	{
//		cout << "void STpop(Stack* p)" << endl;
//	}
//	void STempty(Stack* p)
//	{
//		cout << "STempty(Stack* p)" << endl;
//	}
//	
//private:
//	int* a;
//	int top;
//	int capacity;
//	
//};
//int main()
//{
//	Stack st;
//	st.STpop(&st);
//	st.STpop(&st);
//	st.STpush(&st, 1);
//	return 0;
//}