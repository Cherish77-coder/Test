#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "输入一个整数：";
    cin >> a; // 自动读取整数到a
    cout << "你输入的是：" << a << endl;
    return 0;
}
//using namespace std;
//
//int main() {
//    int a;
//    cout << "输入一个整数：";
//    cin >> a; // 自动读取整数到a
//    cout << "你输入的是：" << a << endl;
//    return 0;
//}
//using namespace std;
//
//int main() {
//    int a = 10;
//    double b = 3.14;
//    // 无需指定类型，cout自动识别
//    cout << "整数：" << a << "，小数：" << b << endl;
//    return 0;
//}
//using  namespace std;
//
//class Tdate
//{
//public:
//    Tdate(int m, int d, int y) {
//        month = m;  day = d;  year = y;
//    }
//    int Isleapyear() 
//    {
//        return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);   // task1: 此处判断当前所给定年份year是否为闰年，若是返回真，否则返回假
//    }
//    void print() {
//        cout << month << " / " << day << "/" << year << endl;
//    }
//private:
//    int month, day, year;
//};
//
//int main()
//{
//    // task2: 创建Tdate实例d，初始化参数为1949年10月1日（注意参数顺序是月、日、年）
//    Tdate d(10, 1, 1949);
//
//    // task3: 输出d的年月日，格式为10/1/1949
//    d.print();
//
//    // task4: 调用Isleapyear()判断是否为闰年，并输出对应提示
//    if (d.Isleapyear()) {
//        cout << "date d is a leap year!" << endl;
//    }
//    else {
//        cout << "date d is not a leap year!" << endl;
//    }
//
//    return 0;
//   
//}