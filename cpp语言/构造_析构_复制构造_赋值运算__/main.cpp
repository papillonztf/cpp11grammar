/*
 
全局对象的默认初始化：
m_ivar=0
m_iaVar={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}
局部对象的默认初始化：
m_ivar=2084498368
m_iaVar={22094,2084497536,22094,-2084084976,32765,-850628608,-889641566,2084498368,22094,-9036905,32732,-112,-1,-2084084968,32765,-112,}


 * */

#include<iostream>
#include<cxxabi.h>
//#include<typeinfo>
#include"myclass.h"//自定义头文件名--指定路径
#define __INSTN__(instn) #instn //宏函数-显示变量名
#define __VARTYPE__(varn) abi::__cxa_demangle(typeid(varn).name(), nullptr, nullptr, nullptr) //typeid关键字 gcc需要cxa_demangle()解符号得到未修饰的符号
using namespace std;
MyClass g_cTest;
int main()
{
/*测试显示变量名和变量类型
MyClass cTest;
MyClass&  crTest=cTest;
MyClass*  cpTest;

int a;
cout<<__VARTYPE__(cTest)<<" "<<__INSTN__(cTest)<<endl;
cout<<__VARTYPE__(a)<<" "<<__INSTN__(a)<<endl;
cout<<__VARTYPE__(crTest)<<" "<<__INSTN__(crTest)<<endl;
cout<<__VARTYPE__(cpTest)<<" "<<__INSTN__(cpTest)<<endl;
*/

//测试类的默认初始化函数：

MyClass cTest;
cout<<"全局对象的默认初始化："<<endl;
g_cTest.display();
cout<<"局部对象的默认初始化："<<endl;
cTest.display();

return 0;
}
