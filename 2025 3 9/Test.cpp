#include"vector.h"
#include<vector>
void test1()
{
	vector<vector<int>> vv(5, vector<int>(5, 0));
	vv[3][3] = 30;
	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}
namespace my
{
	void vector_test1()
	{
		vector<int> n;
		n.push_back(1);
		n.push_back(2);
		n.push_back(3);
		n.push_back(4);
		n.push_back(5);
		n.insert(n.begin() + 2, 999);
		container_print(n);
		n.erase(n.end() - 1);
		n.erase(n.end());
		container_print(n);
	}
	void vector_test2()
	{
		vector<int> n;
		n.push_back(1);
		n.push_back(2);
		n.push_back(3);
		n.push_back(4);
		n.push_back(4);
		n.push_back(5);
		//n.erase(n.begin()+2);
		container_print(n);
		auto i = n.begin();
		while (i != n.end())
		{
			if ((*i) % 2 == 0)
			{
				i=n.erase(i);
			}
			else
			++i;
		}
		container_print(n);
	}
	void vector_test3()
	{
		vector<int> n;
		n.push_back(1);
		n.push_back(2);
		n.push_back(3);
		n.push_back(4);
		n.push_back(4);
		n.resize(7,91);
		container_print(n);
	}
	void vector_test4()
	{
		vector<int> n;
		n.push_back(1);
		n.push_back(2);
		n.push_back(3);
		n.push_back(4);
		n.push_back(4);
		container_print(n);
		vector<int>n2(10, 1);
		//vector<int> n2(n.begin(),n.end()-3);
		container_print(n2);
	}
	void vector_test5()
	{
		vector<int> n;
		n.push_back(1);
		n.push_back(2);
		n.push_back(3);
		n.push_back(4);
		n.push_back(4);
		vector<int> n2;
		n2 = n;
		container_print(n2);
	}
	void vector_test6()
	{
		vector<string> v4(4, "1111111");
		v4.push_back("1111111");
		container_print(v4);
	}
}
int main()
{
	my::vector_test6();
	return 0;
}