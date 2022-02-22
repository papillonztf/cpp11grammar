/*
const关键字详解：
1. const本质：const本质是使得（必须）初始化后变量或函数为“只读”，即不允许有修改该变量的操作。
				c++中当const常量为全局，并且需要在其它文件中使用时，分配空间以及当使用&操作符取const常量取地址时，分配空间，其余情况都把const变量放入符号表。
				而c中const变量一定分配空间。
2.const特点：const可以使得程序更加健壮，减少bug，继承了#define的优点，解决了其缺点.
		a.相比于define，具有会进行数据类型安全检查、无边际效应、可调试。
        b.节省内存，避免不必要的内存分配：全局const变量存放在.rodata(全局只读区)运行过程中只有一份拷贝？？
		c.提供函数重载：
		d.更高的编译效率：？？
3.const应用：
		const 用于面对过程程序设计时:
			a.修饰变量、指针、引用。
				int iGlobVar=1;
				const int CONSTINT = 1;//变量值只可读且const变量必须初始化--可通过指针修改局部const变量的值

				const int &a=iGlobVar;//引用的值不变-复制构造函数的型参和赋值成员函数的型参和返回值都是常引用类型。
                                      //反向初始化不对(不可以const对象初始化非const引用)。

				const int* CONSTINTPRT = &iGlobVar;//指针指向的内容不变
				int * const INTCONSTPRT = &iGlobVar;//指针本身不变，即指向的固定的存储空间。
				const int*const CONSTINTCONSTPRT = &iGlobVar;//指针以及指针指向的内容不变
			
			b.修饰函数参数：
				void Fun1(const int i);//该参数在该函数体内不能被改变。
			d.修饰函数返回值：
				const void Fun1();//函数不能作为左值。如Fun1()=1 是错误的。
			c.修饰函数参数，以实现函数重载（函数重载：范围内，同函数名、不同参数类型。）
				void Fun(int i);
				void Fun(const int i);//由实参是int还是const int ，决定调用那个函数。

		const 用于面对对象程序设计时:
			a.修饰数据成员：必须在（和引用）构造函数初始化列表进行初始化。而不能在构造函数体内初始化（见）。
				ConstTest::ConstTest(int i, int j) :m_Intvar(i), m_ConstIntVar(j){}//见构造函数初始化列表的必要性、效率性、顺序性
			b.修饰成员函数:const（不能修饰非静态成员函数--const成员函数需要this指针访问）
              成员函数只可访问但不可有修改任何数据成员的操作，也不可访问非const函数成员
				void ConstTest::m_FunConst() const {}//const成员函数了不可有修改任何数据成员，也不可访问非const函数成员

			c.修饰类对象：不能修改该对象的任何数据成员。即也不能访问任何非const成员函数，而非const类对象可访问const与非const成员函数
				const ConstTest * p= new ConstTest(1,1);
				p->m_FunConst();
				p->m_Fun();//错误，const类对象不可访问非const成员函数
			e.修饰成员函数，以实现成员函数重载:const类对象只可访问const成员函数
				void ConstTest::m_OverrideFun();
				void ConstTest::m_OverrideFun() const;
				const ConstTest * p= new ConstTest(1,1);
				p->m_OverrideFun();//const类对象只可访问const成员函数



*/
#include<iostream>
using namespace std;

int main()
{
	//测试const用于面对过程的程序设计的情况：修饰变量、指针、引用、函数参数、函数返回值
	int iGlobVar = 1;
	
	const int &a = iGlobVar;
	a = 1;
	//测试const用于面对对象的程序设计的情况：修饰数据成员、函数成员、类对象
	//测试const用于函数重载
	//测试const_cast
}
