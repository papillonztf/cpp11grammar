#include"ConstTest.h"
#include<iostream>
using namespace std;
//const 用于面对过程程序设计时，声明。
//1.用于变量
int iGlobVar=1;//头文件中应变量声明，不应变量定义
const int CONSTINT = 1;
const int* CONSTINTPRT = &iGlobVar;
int * const INTCONSTPRT = &iGlobVar;
const int*const CONSTINTCONSTPRT = &iGlobVar;
const int & CONSTINTREF = iGlobVar;
//2.用于函数
void Fun1(const int i)//形参i在该函数内不可修改
{}
const int Fun2()//该函数不能做左值
{}
//3.用于函数重载。由于其参数不同，所以可以函数重载
void Fun(int i)
{
}
void Fun(const int i)
{
}

//const 用于面对对象程序设计时,定义。


ConstTest::ConstTest(int i, int j) :m_Intvar(i), m_ConstIntVar(j)
{}//构造函数用于给（除静态数据成员之外）数据数据成员初始化。
//~StatTest();//释放变量所占内存
//StatTest(const StatTest & original);//用于
//const StatTest & operator =(const StatTest & rightValue);//重载运算符


	//2.用于成员函数
void ConstTest::m_Fun()
{}
void ConstTest::m_FunConst() const //该成员函数了不可有修改任何数据成员，也不可访问非const函数成员
{}
	//3.用于成员函数重载。
void ConstTest::m_OverrideFun()
{}
void ConstTest::m_OverrideFun() const
{}

ConstTest Object;
