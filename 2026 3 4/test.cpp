#include"string.h"
namespace my
{
	void test_string2()
	{
		string s1("hello world");
		s1.insert(0, 'a');
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		/*std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		s1.insert(s1.size()-1, 'a');
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		s1.insert(0,"hello manba");
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		s1.insert(s1.size()-1, "*******");
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		s1.insert(0,'a');
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;*/
	}
	void test_string1()
	{
		string s1("hello");
		s1.push_back('&');
		s1.append("world");
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		s1 += 'a';
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		s1 += "hello maba";
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		s1.erase(0);
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
		s1.erase(20);
		std::cout << s1.c_str() << endl;
		std::cout << s1.size() << " " << s1.capacity() << endl;
	}
}
int main()
{
	my::test_string2();
	return 0;
}
//int main()
//{
	/*const my::string s("hello");
	printf("%s\n", s.c_str());
	for (auto a : s)
	{
		cout << a;
	}*/
	/*cout << s.size();
	cout << s.capacity();
	s.clear();
	cout << s.c_str() << endl;
	cout << s.size();
	cout << s.capacity();*/
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//using namespace std;
//void test_string1()
//{
//	string s("hello world");
//	cout << s << endl;
//	s.push_back('o');
//	cout << s << endl;
//	s.append(" hello");
//	cout << s << endl;
//	s += "hello";
//	cout << s << endl;
//	//头部删除
//	s.erase(0, 4);
//	cout << s << endl;
//	s.erase(s.begin());
//	cout << s << endl;
//	//尾部删除
//	s.erase(s.size() - 1);
//	cout << s <<endl;
//	s.erase(s.end()-1);
//	cout << s << endl;
//}
//void test_string2()
//{
//	string s2("hello world");
//	s2 += " hello man baoutxxxxx";
//	cout << s2 << endl;
//	int pos = s2.find_first_of("abcd");
//	while (pos != string::npos)
//	{
//		s2.replace(pos, 1, "**");
//		pos += 2;
//		pos = s2.find_first_of("abcd");
//	}
//	cout << s2 << endl;
//	//空间换取时间；
//	string s3;
//	for (auto a : s2)
//	{
//		if (a == ' ')
//			s3 += "%%";
//		else
//			s3+= a;
//	}
//	cout << s3 << endl;
	/*int pos = s2.find(' ');*/
	/*while (pos<s2.size())
	{
		s2.replace(pos,1,"**");
		pos += 1;
		pos = s2.find(' ');
	}
	cout << s2 << endl;*/
	/*string s1("hello world");
	int pos=s1.find("wo");
	while (pos != s1.size())
	{
		cout << s1[pos];
		++pos;
	}
	cout << endl;*/
//}
//c语言与c++的兼容
//void test_string3()
//{
//	string s3("hello world,hello hunman");
//	string filename;
//	cin >> filename;
//	FILE* fout = fopen(filename.c_str(), "r");
//	char tmp;
//	
//	while (fscanf(fout, "%c", &tmp) != EOF)
//	{
//		cout << tmp;
//	}
//	cout << endl;
//}
//void SplitFilename(const std::string& str)
//{
//	std::cout << "Splitting: " << str << '\n';
//	std::size_t found = str.find_last_of("/\\");
//	std::cout << " path: " << str.substr(0, found) << '\n';
//	std::cout << " file: " << str.substr(found + 1) << '\n';
//}
//void test_string4()
//{
//	string s1("D:\\C语言\\homework\\2026 3 4\\2026 3 4\\string.cpp");
//	string s2("/usr/bin/man");
//	SplitFilename(s1);
//	SplitFilename(s2);
//	s1.insert(s1.size()-1, "heollw");
//	cout << s1 << endl;
//}
//int main()
//{
//	test_string4();
//	return 0;
//}