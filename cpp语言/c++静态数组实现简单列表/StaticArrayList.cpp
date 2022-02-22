#include"StaticArrayList.h"
#include<iostream>
#include<cxxabi.h>
#include<stdlib.h>
#define __VARNAME__(varn) #varn //宏函数-显示变量名字符串
#define __VARTYPE__(varn) abi::__cxa_demangle(typeid(varn).name(), nullptr, nullptr, nullptr) //typeid关键字 gcc需要cxa_demangle()解符号得到未修饰的符号
using namespace std;

//类成员函数定义：


StaticArrayList::StaticArrayList():m_size(0)//自定义默认构造函数(最后自己定义一个默认构造)
{

}//int m_elementArray则按照内置类型默认初始化方式。
StaticArrayList::StaticArrayList(int n,int i):m_size(n)//自定义含参构造函数
{
    int count=m_size;
    while(count--) //静态数组只能一个一个赋值。new动态数组可 new int arr[3]={1,2,3}
      m_elementArray[count]=i;

}
StaticArrayList::StaticArrayList(const StaticArrayList& other)//复制构造函数-
{
    if(other.getSize()>(CAPACITY))//静态对象只能访问其静态成员
    {
        cerr<<"fail to call copy constructor!"<<endl;
        exit(1);
    }
    else
    {
        m_size=other.getSize();
        for(int i=0;i<m_size;i++)
          m_elementArray[i]=other.m_elementArray[i];
    }
}


StaticArrayList::~StaticArrayList()//实际上,类中无动态内存则不需自定义析构函数
{
     cout<<__VARTYPE__(StaticArrayList)<<"::"<<__VARNAME__(~StaticArrayList())<<endl;
}

 /*const StaticArrayList& StaticArrayList::operator= (const StaticArrayList& other)
{
    if(this!=&other)
    {
        if(other.getSize()>CAPACITY)
        {
            cerr<<"fail to call assignment operation!"<<endl;
            exit(1);
        }

        m_size=other.getSize();
        for(int i=0;i<m_size;i++)
          m_elementArray[i]=other.m_elementArray[i];
    
    }

}
*/

Type StaticArrayList::getSize() const
{
    return m_size;
}
void StaticArrayList::showDataMember() const  //构造函数测试程序--输出类的数据成员
{
    int i=0;
    cout<<__VARTYPE__(m_size)<<" "<<__VARNAME__(m_size)<<"="<<m_size<<endl;

    cout<<__VARTYPE__(m_elementArray)<<" "<<__VARNAME__(m_elementArray)<<"="<<endl;
    cout<<"{";
    while(i<sizeof(m_elementArray))
    {
        cout<<m_elementArray[i];
        if(i<(sizeof(m_elementArray)-1));
        cout<<",";
        i++;
    }
    cout<<"}"<<endl;



}


