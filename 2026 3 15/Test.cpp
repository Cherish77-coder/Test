#define _CRT_SECURE_NO_WARNINGS
#include"Class.h"
template<class T1,class T2>
bool Less(const T1& x,const T2& y)
{
	return x < y;
}
template<>
bool Less< int* const&>(int* const & x, int* const & y)
{
	return *x < *y;
}
//template<class T>

int main()
{
	Data<int, char> a;
	Data<char, int> a2;
	Data<char, char> a3;
	Data<int&, int&> a4(0,0);
	Data<int*, char*> a5;
	cout << Add(1, 3);
	return 0;
}

//int main()
//{
//	cout << Less(10, 39) << endl;
//	int a = 1; int b = 9;
//	cout << Less(&a, &b) << endl;
//	//s<int,int> s1;
//	//my::array<int ,10> a;
//	return 0;
//}
