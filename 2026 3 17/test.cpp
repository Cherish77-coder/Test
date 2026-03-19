#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int main()
//{
//    int num = 0;
//    cin >> num;
//    int A = 0, B = 0;
//    for (int i = 0; i < num; ++i)
//    {
//        int score = 0;
//        cin >> score;
//        if (score >= 60)
//        {
//            B++;
//        }
//         if (score >= 85)
//        {
//            A++;
//        }
//    }
//    int a = (A * 100.0) / (num * 1.0) + 0.5;
//    int b = (B * 100.0) / (num * 1.0) + 0.5;
//    cout << b << "%" << endl;
//    cout << a << "%" << endl;
//    // 请在此输入您的代码
//    return 0;
//}
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//    string s;
//    cin >> s;
//    vector<int> v(26, 0);
//    for (auto e : s)
//    {
//        v[e - 'a']++;
//    }
//    int maxi = 0;
//    for (int i = 1; i < 26; i++)
//    {
//        if (v[i] > v[maxi])
//        {
//            maxi = i;
//        }
//
//    }
//    char out = 'a' + maxi;
//    cout << out << endl;
//    cout << v[maxi] << endl;
//    // 请在此输入您的代码
//    return 0;
//}
//#include <iostream>
//#include<vector>
//using namespace std;
//bool check(const vector<int>& v1, const  vector<int>& v2, int num)
//{
//    int n = v1.size();
//    for (int i = 0; i < n; ++i)
//    {
//        if (v1[i] / num != v2[i])
//        {
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//    int n = 0;
//    cin >> n;
//    vector<int>s1(n);
//    vector<int>s2(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> s1[i];
//        cin >> s2[i];
//    }
//    int max = s1[0] / s2[0];
//    for (int i = 1; i < n; ++i)
//    {
//        int tmp = s1[i] / s2[i];
//        if (tmp < max)
//        {
//            max = tmp;
//        }
//    }
//    int min = max;
//    while (check(s1, s2, min))
//    {
//        --min;
//    }
//    cout << min << ' ' << max;
//    return 0;
//}
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n = 0, ret = 0;
    
    cin >> n;
    vector<int>v2(n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (v[j] > v[i])
            {

                for (int k = j; k < n; ++k)
                {
                    if (v[k] > v[j])
                    {
                        v2[k]++;
                        break;
                    }
                }
            }
        }
    }
    for (auto e : v2)
    {
        if (e != 0)
        {
            ++ret;
        }
    }
    cout << ret;
    // 请在此输入您的代码
    return 0;
}