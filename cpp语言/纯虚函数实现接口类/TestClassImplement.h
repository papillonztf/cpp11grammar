#pragma once 

#include"TestClassInterface.h"
class TestClassImplement :public TestClassInterface{

    public:
       TestClassImplement();
       void  setData(int i);
       int   getData();
    private:
       int m_iVar;

};
