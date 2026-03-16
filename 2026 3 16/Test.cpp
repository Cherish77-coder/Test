#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
//class Person
//{
//public:
//	// 进入校园/图书馆/实验室刷二维码等身份认证
//	void identity()
//	{
//		cout << "void identity()" << _name << endl;
//	}
//protected:
//	string _name = "张三"; // 姓名
//	string _address; // 地址
//	string _tel; // 电话
//	int _age = 18; // 年龄
//};
//class Teacher :public Person
//{
//public:
//	void teach()
//	{
//		cout << "void teach()" << endl;
//	}
//protected:
//	string _title;
//};
//class Student :private Person
//{
//	public:
//		void name()
//		{
//			cout << _name << endl;
//			//identity();
//			//this->identity();
//		}
//	void study()
//	{
//		cout << "void study()" << endl;
//	}
//protected:
//	string _idcard;
//};
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name="9999"; // 姓名
//private:
//	int _age; // 年龄
//};
//class Student : protected Person
//class Student : private Person
//class Student :  Person
//{
//public:
//	void name()
//	{
//		//cout <<_age << endl;
//		//cout << _age << endl;
//	}
//protected:
//	int _stunum; // 学号
//};
//	int main()
//{
//		Student s;
//		//s.study();
//		//s.name();
//		/*Teacher t;
//		t.teach();
//		t.identity();*/
//	return 0;
//}
//int main()
//{
//	Student s;
//	s.name();
//	return 0;
//}
//namespace my {
//	
//		/*template<class T>
//		class vector
//		{};*/
//		// stack和vector的关系，既符合is-a，也符合has-a
//		template<class T>
//		class stack : public std::vector<T>
//		{
//		public:
//			void push(const T& x)
//			{
//				vector<T>::push_back(x);
//				//push_back(x);
//			}
//			void pop()
//			{
//				vector<T>::pop_back();
//			}
//			const T& top()
//			{
//				return vector<T>::back();
//			}
//			bool empty()
//			{
//				return vector<T>::empty();
//			}
//		};
//}
//int main()
//{
//	my::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty())
//	{
//		cout << st.top()<<" ";
//		st.pop();
//	}
//	cout << endl;
//	//st.print();
//	return 0;
//}
//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//int main()
//{
//	Student sobj;
//	// 1.派生类对象可以赋值给基类的指针/引用
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	// 派生类对象可以赋值给基类的对象是通过调用后面会讲解的基类的拷贝构造完成的
//	Person pobj = sobj;
//	//2.基类对象不能赋值给派生类对象
//	//sobj = pobj;
//	return 0;
//}
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" <<Person:: _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//int main()
//{
//	Student s1;
//	s1.Print();
//	return 0;
//};
class Person
{
public:
	Person(const char* name = "peter")
		:_name(name)
	{ }
		
	Person(const Person& p)
		//this->_name = p._name;
		:_name(p._name) {

		cout << "Person(const Person & p) " <<endl;
	}
	Person& operator=(const Person & p)
	{
		if (this !=& p)
		{
			this->_name = p._name;
		}
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		:Person(name)
		,_num(num){ }
		
	Student(const Student& s)
		:Person(s)//派生类的引用可以给基类，指针也是
		,_num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator = (const Student& s)
	{
		Person::operator=(s);
		this->_num = s._num;
		cout << "Student& operator= (const Student& s)" << endl;
		
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
int main()
{
	Student s("kobe", 10);
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
	return 0;
}