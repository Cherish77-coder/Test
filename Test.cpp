#include<iostream>
using namespace std;
int main()
{
	cout << "hello " << endl;
}
//using namespace std;
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
//	rs.top = 0; rs.capacity = n;
//}
//// 栈顶
//void STPush(ST& rs, STDataType x)
//{
//	//assert(ps);
//	// 满了， 扩容
//	if (rs.top == rs.capacity)
//	{
//		printf("扩容\n");
//		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		rs.a = tmp;
//		rs.capacity = newcapacity;
//	}
//	rs.a[rs.top] = x;
//	rs.top++;
//}
//// int STTop(ST& rs)
//int STTop(ST& rs)
//{
//	//assert(rs.top > 0);
//	return rs.a[rs.top-1];
//}
//int main()
//{
//	ST st;
//	STInit(st);
//	STPush(st, 2);
//	STPush(st, 2);
//	STPush(st, 2);
//	STPush(st, 2);
//	STPush(st, 2);
//	//int top = STTop(st);
//	//cout <<  top<< endl;
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	// 编译报错：“ra”: 必须初始化引用
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// 这里并非让b引用c，因为C++引用不能改变指向，
//	// 这里是一个赋值
//	b = c;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	// 引用：b和c是a的别名
//	int& b = a;
//	int& c = a;
//	// 也可以给别名b取别名，d相当于还是a的别名
//	int& d = b;
//	++d;
//	// 这里取地址我们看到是一样的
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//	return 0;
//}
//using namespace std;
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	cout << "a==" << a <<" " << "b==" << b <<" " << endl;
//	swap(a, b);
//	cout << "a==" << a << " " << "b==" << b << " " << endl;
//	return 0;
//}
//#include"Stack.h"
//using namespace std;
//typedef struct Stack
//{
//	int a[10];
//	int top;
//}ST;
//void STInit(ST* ps) {}
//void STPush(ST* ps, int x) {}
////using namespace c;
//int main()
//{
//	ST st1;
//	STInit(&st1);
//	STPush(&st1, 1);
//	c::ST st2;
//	c::STInit(&st2);
//	c::STPush(&st2, 1);
//	c::STDestroy(&st2);
//	return 0;
//}
//using namespace std;
//void swap(int a, int b)
//{
//	printf("void swap(int a, int b)\n");
//}
//void swap(float a, float b)
//{
//	printf("void swap(float a, float b)\n");
//}
//void print(int a, int b = 1, int c = 2)
//{
//	cout << a <<" "<<b <<" "<< c << endl;
//}
//int main()
//{
//	//print();
//	print(1,10,100);
//	print(2);
//	return 0;
//}
//
//

//#include<iostream>
//#include"Stack.h"
//using namespace std;
//int main()
//{
//	c::ST st1;
//	c::STInit(&st1);
//	return 0;
//}
//namespace c
//{
//	int rand = 10;
//}
//int main()
//{
//	printf("%d ", c::rand);
//	return 0;
//}
//using namespace std;
//int main()
//{
//	std::cout << "hello world" <<std:: endl;
//	return 0;
//}