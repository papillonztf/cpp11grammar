#pragma once 
#include"TestClassInterface.h"
//接口类创建工厂：create(),destroy()
class TestClassManager{
    public:
    //静态成员函数->是类的，可不生成实例就可调用。但也只能访问静态数据成员
       static  TestClassInterface* create();
       static  void destroy(TestClassInterface* p);
       
};
