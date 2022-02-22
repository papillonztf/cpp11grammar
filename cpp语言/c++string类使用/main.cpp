#include<iostream>
#include<string>
using namespace std;

int main()
{
   string string1;
   cout<<"string默认构造函数-创建一个size=0 capacity=15的空字符串："<<string1.size()<<" "<<string1.capacity()<<endl;
   cout<<string1.data()<<endl<<string1.c_str()<<endl;
    
  cout<<(int)(string1[0])<<endl; 
   cout<<(int)(string1[1])<<endl; 
    return 0;
}
