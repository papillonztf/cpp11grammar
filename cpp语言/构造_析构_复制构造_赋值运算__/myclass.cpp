#include"myclass.h"
#include<iostream>

using namespace std;
void MyClass::display()
{
    int i=0;
    cout<<"m_ivar="<<m_iVar<<endl;
    cout<<"m_iaVar="<<"{";
    while(i<sizeof(m_iaVar))
    {
        cout<<m_iaVar[i]<<",";
        i++;
    }
    cout<<"}"<<endl;
}
