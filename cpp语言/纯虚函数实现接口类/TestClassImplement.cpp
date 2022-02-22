#include"TestClassImplement.h"

TestClassImplement::TestClassImplement():m_iVar(1){
}

void TestClassImplement::setData(int i){
    m_iVar=i;
}

int TestClassImplement::getData(){
    return m_iVar;
}
