#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
 using namespace std;
 class A
 {
 public:
	 A(int a = 0)
		 : _a(a)
	 {
		 cout << "A():" << this << endl;
	 }
	 ~A()
	 {
		 cout << "~A():" << this << endl;
	 }
 private:
	 int _a;
 };
 // 定位new/replacement new
 int main()
 {
	 // p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没
	// 有执行
		 A* p1 = (A*)malloc(sizeof(A));
	 new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
	 p1->~A();
	 free(p1);
	 A* p2 = (A*)operator new(sizeof(A));
	 new(p2)A(10);
	 p2->~A();
	operator delete(p2);
	 return 0;
 }
 //class A
 //{
 //public:
	// A(int a = 0)
	//	 : _a(a)
	// {
	//	 cout << "A():" << this << endl;
	// }
	// ~A()
	// {
	//	 cout << "~A():" << this << endl;
	// }
 //private:
	// int _a;
 //};
 //int main()
 //{
	// // new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
	// //还会调用构造函数和析构函数
	//	 A* p1 = (A*)malloc(sizeof(A));
	// A* p2 = new A(1);
	// free(p1);
	// delete p2;
	// // 内置类型是几乎是一样的
	// int* p3 = (int*)malloc(sizeof(int)); // C
	// int* p4 = new int;
	// free(p3);
	// delete p4;
	// A* p5 = (A*)malloc(sizeof(A) * 10);
	// A* p6 = new A[10];
	// free(p5);
	// delete[] p6;
	// return 0;
 //}
 //int main()
 //{
	// cout << "hello world" << endl;
	// return 0;
 //}
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}