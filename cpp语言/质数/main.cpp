#include<iostream>
#include"./PrimeNum.h"//须指定路径
using namespace std;

int main()
{
    int num;
    cin>>num;
    //测试是否是质数
    if(isPrimeNum(num))
      cout<<num<<" is prime number"<<endl;
    else
      cout<<num<<" is not prime number"<<endl;

return 0;
}
