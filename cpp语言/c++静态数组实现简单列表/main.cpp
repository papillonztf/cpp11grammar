#include<iostream>
#include"StaticArrayList.h"
using namespace std;

int main()
{
    SAList myList1;
    SAList myList2(5,1);
    SAList myList3(myList2);//复制构造函数
    SAList myList4=myList2;//复制构造函数
    myList1.showDataMember();
    myList2.showDataMember();
    myList3.showDataMember();    
    myList4.showDataMember(); 
    myList1=myList2;//运算符重载
    myList1.showDataMember();
    return 0;
}
