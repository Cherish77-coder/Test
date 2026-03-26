#define _CRT_SECURE_NO_WARNINGS
//using namespace std;
//class Solution {
//
//    class Compare
//    {
//        bool operator()(const pair<string, int>& s1, const pair<string, int>& s2) const
//        {
//            return s1.second > s2.second;
//        }
//    };
//public:
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        map<string, int> CountMap;
//        for (auto& e : words)
//        {
//            CountMap[e]++;
//        }
//        vector<pair<string, int>> vv(CountMap.begin(), CountMap.end());
//        stable_sort(vv.begin(), vv.end(), Compare());
//        vector<string> ret;
//        for (int i = 0; i < k; ++i)
//        {
//            ret.push_back(vv[i].first);
//        }
//        return ret;
//    }
//
//};
//int main()
//{
//
//}
//int main()
//{
//	map<string, int> CountMap;
//	vector<string> fruit = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜","苹果", "香蕉", "苹果", "香蕉" };
//	for (auto& e : fruit)
//	{
//		CountMap[e]++;
//	}
//	for (auto& f : CountMap)
//	{
//		cout << f.first << ":" << f.second << endl;
//	}
//	return 0;
//}
#include<vector>
#include"AVLTree.h"
void TestAVLTree1()
{
	AVLTree<int, int> t;
	// 常规的测试用例
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// 特殊的带有双旋场景的测试用例
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a)
	{
		t.insert({ e, e });
		//t.InOrder();
	}
	cout << t.height() << endl;
	t.InOrder();
	cout << t.IsBalanceTree() << endl;
	cout << t.size() << endl;
}
void TestAVLTree2()
{
	const int N = 100000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
	}size_t begin2 = clock();
	AVLTree<int, int> t;
	for (auto e : v)
	{
		t.insert(make_pair(e, e));
	}
	size_t end2 = clock();
	cout << "Insert:" << end2 - begin2 << endl;
	cout << t.IsBalanceTree() << endl;
	cout << "Height:" << t.height() << endl;
	cout << "Size:" << t.size() << endl;
	size_t begin1 = clock();
	// 确定在的值
	/*for (auto e : v)
	{
	t.Find(e);
	}*/
	// 随机值
	for (size_t i = 0; i < N; i++)
	{
		t.Find((rand()+i%100 ));
	}
	size_t end1 = clock();
	cout << "Find:" << end1 - begin1 << endl;
}
int main()
{
	TestAVLTree2();
	return 0;
}
