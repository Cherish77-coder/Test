#include"Date.h"
void test1()
{
	Date d1;
	Date d2(2015,4,5);
	d2 < d1;
	Date d3(2222, 33, 1);
	d1 <= d2;
	d1 > d2;
}
void test2()
{
	Date d1(2026, 2, 14);
	Date d2 = d1 - 2092;
	d1.Print();
	d2.Print();
}
void test3()
{
	Date d1(2026,12,28);
	d1.Print();
	//Date d2(2024,8,24);
	//Date d3 = d1++;
	//d1.Print();
	//d1--;
	//d1.Print();
	//d3.Print();
	//cout << d2 - d1 << endl;

}
int main()
{
	test3();
	return 0;
}