/**
 1.c++如何实现接口类(抽象类)？--即头文件只透露操作接口，而不显示相应操作定义和数据成员的定义。
   × 分析:
        × 类的声明头文件往往包含其数据成员的声明，不符合"只透露操作接口(api)"原则
          ==>因此，该类的头文件和源文件应一同封装在库文件中。
        × 那有怎么透露只含类的操作接口(成员函数i)
          ==>多态(指向派生类对象的基类指针)+透露(不含数据成员)基类的声明头文件给开发者
        × 怎么避免直接定义并初始化指向派生类对象的基类指针时必须知道派生类声明头文件？
          ==>通过类创建工厂，间接定义并初始化该指针。这样透露的是包含基类头文件的类创建工厂声明头文件。
             而派生声明头文件被包含在类创建工厂定义源文件并封装到库文件中。
        × 怎么仅允许开发者定义初始化指向派生类对象的基类指针，而不允许定义初始化基类指针对象？(只作为接口类)
          ==>基类应是抽象类
          ! 即便某基类只有一个纯虚函数，也是抽象类。
          ! 抽象类(基类)中必须将操作接口定义为纯虚函数和定义析构函数为虚函数。抽象类只需声明纯虚函数，而对应的实现类需声明定义该纯虚函数
          ! 抽象类不可创建(抽象类)对象(自然不能值传递)，只能创建其指针或是引用(指向其实现类对象，即多态))。
          ！抽象类继承性质与正常继承一样。
   × 实现：
               |--maic.cpp
         src---|                                     
               |--TetstClassManager.h--#include"TestClassInterface.h" //声明抽象类。注意将操作接口定义为纯虚函数和定义析构函数为虚函数。

        
               |--TetstClassManager.o--TestClassManager.cpp --#include"TetstClassImplement.h"//声明实现类。
    libtest.a--|--TestClassImplement.o--TetstClassImplement.cpp

        编译：
        g++ -Wall -c TestClassManager.cpp TestClassImplement.cpp            //生成打包静态库文件所需的.o文件
        ar rcs -o libtest TestClassManager.o TestClassImplement.o           //打包生成静态库。注意参数顺序。
        g++ main.cpp -ltest -L./ -o test                                    //生成可执行程序。注意调用静态库参数及其顺序           
        
*/

#include"TestClassManager.h"
#include<iostream>
using namespace std;

int main(){

    //TestClassManager myManager;
    //多态：指向派生类(实现类)的基类(接口类)指针
    TestClassInterface* myInterface=TestClassManager::create();
    //通过指向派生类的基类指针调用派生类的成员函数
    cout<<"派生类(实现类)的数据成员-调用派生类默认构造函数:  "<<myInterface->getData()<<endl;
    myInterface->setData(10);
    
    cout<<"派生类(实现类)的数据成员-调用派生类的setData() :  "<<myInterface->getData()<<endl;

    TestClassManager::destroy(myInterface); 
    //TestClassInterface p; //不可声明纯虚函数类对象！！

return 0;
}
