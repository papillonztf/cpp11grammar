#include"TestClassManager.h"
#include"TestClassImplement.h"

TestClassInterface* TestClassManager::create(){
    return (new TestClassImplement());//多态：指向子类对象的父类指针
}

void TestClassManager::destroy(TestClassInterface*p){
    delete p;
}
