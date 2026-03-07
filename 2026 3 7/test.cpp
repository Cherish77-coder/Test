#include"string.h"
namespace my
{
	void test_string()
	{
		string s1("hello wprld");
		string s2;
		s2 = s1;
		cout << s2.c_str() << endl;
		string s3(s1);
		cout << s3.c_str() << endl;
	}
}
int main()
{
	my::test_string();
	return 0;
}