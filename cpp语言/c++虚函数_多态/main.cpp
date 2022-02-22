/*
# 纯虚函数 如void virtual fun()=0;
    > 纯虚函数特点：
        × 纯虚函数肯定是成员函数
        × 纯虚函数只需在类定义中声明，无需也不可定义
        × 包含纯虚函数的类无法实例化，无论构造函数的访问权限
    > 抽象类:
        × 类只要包含纯虚函数就是抽象类，自然抽象类无法实例化
        × 通过指向子类对象(具体类)的父类(抽象类)指针可访问
          子类的重载父类的虚函数成员以及父类的public成员
    > 接口类：
        × 类只包含纯虚函数不可包含非纯虚成员函数和数据成员就是接口类
        × 接口类就是一接口，如作为提供给开发者调用库对应看得见头文件
          实现类则需对接口类的纯虚函数(接口)进行实现。
        × 通过指向子类对象(实现类)的父类(接口)指针只可访问子类的重载
          父类的虚函数成员，不可访问父类任何成员。

*/
#include<iostream>

using namespace std;

//抽象(基)类
class AbstBase{
    public:

        virtual void Func1()=0;
        void Func2();
    private:
        int i;

};
void AbstBase::Func2(){
    cout<<"调用抽象类PV的成员函数"<<endl;
    
}

class ImplDerived:public AbstBase{

    public:
        void Func1();
        void Func2();
        void Func3();

};
void ImplDerived::Fun

int main(){
    
    AbstBase objectPV;
    return 0;
}
