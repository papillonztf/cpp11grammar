#include"StaticTest.h"
#include<iostream>
using namespace std;

int iGlobVar;
static int isStatGlobVar;

void TestStatLocVar()
{
	static int isLocVar ;
	cout << ++isLocVar << endl;
}

void TestStatFunc()
{
	cout << "静态函数只能在本文件内被调用"<< endl;
}

void StatTest::Fun()
{
	//非非静态成员函数可访问静态函数成员和静态变量成员
	cout << isVar<< endl;
	StatFun();

}
void StatTest::StatFun() //static是声明性的关键词，静态成员函数定义时不能再写上static
{
	//静态成员函数只可访问静态函数成员和静态变量成员;静态数据成员一改所有改。
	cout << ++isVar <<"  test"<< endl;

}
int StatTest::isVar ;//静态数据成员