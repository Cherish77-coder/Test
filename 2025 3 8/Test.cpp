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
		vector_print(n);
	}
}
int main()
{
	my::vector_test1();
	return 0;
}