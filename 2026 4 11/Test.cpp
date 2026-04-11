#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory>
#include<atomic>
#include<functional>
using namespace std;
class Date
{
public:
	Date(int year=1,int month=1,int day=1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
	}
	~Date()
	{
		_year = _month = _day = 0;
		cout << "~Date()" << endl;
	}
	void DatePrint()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
//private:
	int _year=1;
	int _month=1;
	int _day=1;
	
};
//智能指针
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{
	}
	~SmartPtr()
	{
		delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	T& operator[](size_t i)
	{
		return _ptr[i];
	}
private:
	T* _ptr = nullptr;
};
namespace my
{
	template<class T>
	//计数拷贝的可以赋值的智能指针
	class shared_ptr
	{
	public:
		shared_ptr( T* ptr)
			:_ptr(ptr)
			,_num(new atomic<int>(1))
		{
		}
		shared_ptr(const shared_ptr& ptr)
		{
				_ptr = ptr._ptr;
				_num = ptr._num;
				++(*_num);
		}
		template<class D>
		shared_ptr(T* ptr, D del)
			: _ptr(ptr)
			, _num(new atomic<int>(1))
			, _del(del)
		{
		}
		~shared_ptr()
		{
			if (--(*_num) == 0)
			{
				//delete _ptr;
				_del(_ptr);
				delete _num;
			}
		}
		shared_ptr& operator=(shared_ptr& ptr)
		{
			if (_ptr != ptr._ptr)
			{
				if (_ptr)
				{
					//delete _ptr;
					_del(_ptr);
					delete _num;
				}
				_ptr = ptr._ptr;
				_num = ptr._num;
				++(*_num);
			}
			return *this;
		}
		T& operator*()
		{
			return _ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator[](int x)
		{
			return *_ptr[x];
		}
		int use_count()
		{
			return *_num;
		}
	private:
		T* _ptr=nullptr;
		atomic<int>* _num=nullptr;
		function<void(T*)> _del = [](T* ptr){delete ptr;};
	};
}
class Fclose
{
public:
	void operator()(FILE* ptr)
	{
		cout << "fclose:" << ptr << endl;
		fclose(ptr);
	}
};

template<class T>
void DeleteArrayFunc(T* ptr)
{
	delete[] ptr;
}
struct ListNode
{
	int _data;

	/*ListNode* _next;
	ListNode* _prev;*/
	//std::shared_ptr<ListNode> _next;
	//std::shared_ptr<ListNode> _prev;

	// 这里改成weak_ptr，当n1->_next = n2;绑定shared_ptr时
	// 不增加n2的引用计数，不参与资源释放的管理，就不会形成循环引用了
	std::weak_ptr<ListNode> _next;
	std::weak_ptr<ListNode> _prev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};
//int main()
//{
//	//Date d(2, 2, 2);
//	auto_ptr<Date> pd(new Date(2026, 11, 1));
//	SmartPtr<Date> pd(new Date[10]());
//	pd->DatePrint();
//	//pd->~Date();
//	
//	(*pd).DatePrint();
//	return 0;
//}
//int main()
//{
//	//auto_ptr拷贝时会把前面一个置空，不建议使用
//	auto_ptr<Date> p1(new Date(1,11,1));
//	auto_ptr<Date> p2 = p1;
//	unique_ptr<Date> p3(new Date(1, 1, 1));
//	//unique_ptr不支持拷贝；
//	//unique_ptr<Date> p4 = p3;
//
//	return 0;
//}
//int main()
//{
//	my::shared_ptr<Date> p1(new Date());
//	my::shared_ptr<Date> p2=p1;
//	my::shared_ptr<Date> p3 =new Date(2,2,2);
//	p3->DatePrint();
//	p3 = p1;
//	p3->_day++;
//	p3->_month++;
//	p3->DatePrint();
//	//p4 = p3;
//	return  0;
//}、
//int main()
//{
//	//my::shared_ptr<Date[]> p1(new Date[5]{{1,11,1}}); // 明确传入 new 表示变量初始化
//	//shared_ptr<Date[]> p2(new Date[5]);
//	/*my::shared_ptr<Date> p3 = new Date(2, 2, 2);
//	my::shared_ptr<Date> sp3(new Date[10], [](Date* ptr) {delete[] ptr; });
//	my::shared_ptr<FILE> sp6(fopen("Test.cpp", "r"), [](FILE* ptr) {
//		        cout << "fclose:" << ptr << endl;
//		        fclose(ptr);
//		        });*/
//	std::unique_ptr<FILE, Fclose> up3(fopen("Test.cpp", "r"));
//	    auto fcloseFunc = [](FILE* ptr) {fclose(ptr); };
//		//decltype可以推导类型
//	    std::unique_ptr<FILE, decltype(fcloseFunc)> up4(fopen("Test.cpp", "r"), fcloseFunc);
//	return 0;
//}
//int main()
//{
//    // 循环引用 -- 内存泄露
//    std::shared_ptr<ListNode> n1(new ListNode);
//    std::shared_ptr<ListNode> n2(new ListNode);
//
//    cout << n1.use_count() << endl;
//    cout << n2.use_count() << endl;
//
//    n1->_next = n2;
//    n2->_prev = n1;
//
//    cout << n1.use_count() << endl;
//    cout << n2.use_count() << endl;
//
//    return 0;
//
//}
//int main()
//{
//	std::shared_ptr<string> sp1(new string("111111"));
//	std::shared_ptr<string> sp2(sp1);
//	std::weak_ptr<string> wp = sp1;
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl;
//	// sp1和sp2都指向了其他资源，则weak_ptr就过期了
//	sp1 = make_shared<string>("222222");
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl;
//	sp2 = make_shared<string>("333333");
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl;
//	wp = sp1;
//	//std::shared_ptr<string> sp3 = wp.lock();
//	auto sp3 = wp.lock();
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl;
//	*sp3 += "###";
//	cout << *sp1 << endl;
//	return 0;
//}
#include<thread>
#include<mutex>

struct AA
{
	int _a1 = 0;
	int _a2 = 0;

	~AA()
	{
		cout << "~AA()" << endl;
	}
};

int main()
{
    my::shared_ptr<AA> p(new AA);
    const size_t n = 100000;

    mutex mtx;
    auto func = [&]()
    {
        for (size_t i = 0; i < n; ++i)
        {
            // 这里智能指针拷贝会++计数
            my::shared_ptr<AA> copy(p);
            {
                unique_lock<mutex> lk(mtx);
                copy->_a1++;
                copy->_a2++;
            }
        }
    };

    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();

    cout << p->_a1 << endl;
    cout << p->_a2 << endl;

    cout << p.use_count() << endl;

    return 0;
}