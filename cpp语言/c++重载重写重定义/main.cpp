/*
		函数重载：	
			1.只能发生在内部，且函数名相同，而参数不同。如文件内部，类内部，结构体内部，若跨境进行重载则变成覆盖了。	
						如，基类定义(不论是否virtual)void fun1（），派生类定义void fun1（int i），派生类对象无法访问基类的void fun1（），只能访问void fun1（int i），因为覆盖了。

		函数重定义：跨境的
			1.在无基类virtual，基类和派生类有同函数名，不管是否同参，都是是重定义，即覆盖。如基类 void fun1（），派生类，void fun1（）--->派生类对象.fun1（），只能指向派生类的该函数
			2.有基类virtual，基类和派生类有同函数名，不同参，则是重定义，即覆盖。如基类 virtual void fun1（），派生类，void fun1（i）--->派生类对象.fun1（），错误，因为派生类对象只能指向派生类的该函数
		函数重写：跨境的。任何构造函数之外的非静态函数都可以是虚函数。虚函数是运行时确定的
			1.有基类virtual，基类和派生类有同函数名，而且同参，则是重写。可通过基类指针指向派生类还是基类实现多态。
			2.指向派生类对象的基类指针只能访问基类函数和派生类中对应的虚函数。即无法访问派生类中的非基虚函数。
			*/

#include<iostream>
using namespace std;
class Base
{
public:
	virtual void func()
	{
		cout << "Base::func()" << endl;
	}
	int  func(int i)
	{
		cout << "Base::func(int i)" << endl;
		return 1;
	}

	void  test(int i)
	{
		cout << "Base::test()" << endl;
	}
	
};

class Derived:public Base
{
public:
	void   func()
	{
		cout << "Derived::func()" << endl;
	}
	void  func(int i)
	{
		cout << "Base::func(int i)" << endl;
	}
	void  test()
	{
		cout << "Derived::test()" << endl;
	}

};


int main()
{
	//函数重载:内部，函数名相同，但参数不同,返回值不管是否相同。与是否virtual无关。跨域就变成了函数重定义。
	cout << "---------函数重载-----------" << endl;
	Base BaseClass;
	BaseClass.func();
	BaseClass.func(1);
	cout << "----------------------------" << endl;

	//函数重定义：夸域，函数名相同，参数不管是否相同（参数不同时，可不管有没有virtual，）,返回值是否相同，均被类覆盖。
	
	cout << "---------函数重定义-----------" << endl;
	////通过指向派生类对象的基类指针，只能访问基类的成员函数和派生类的虚函数。
	//Derived DerivedClass;
	//Base* Baseptr = &DerivedClass;
	//Baseptr->test();
	//函数重定义的，参数不同，也被覆盖。5
	Derived DerivedClass;
	DerivedClass.test();//函数重定义的，参数不同，也被覆盖。即不可访问DerivedClass.test(1);
	cout << "----------------------------" << endl;

	//函数重写：跨域，函数同名，参数相同，返回值也必须相同！！
	cout << "---------函数重写-----------" << endl;
	//Derived DerivedClass;
	Base* Baseptr = &DerivedClass;
	Baseptr->func();
	//Baseptr->test(1);//正确，通过指向派生类对象的基类指针，只能访问基类的成员函数和派生类的虚函数。
	Baseptr = &BaseClass;
	Baseptr->func(); 
	cout << "----------------------------" << endl;

	
	system("pause");
	return 0;
}