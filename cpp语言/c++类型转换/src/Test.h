
#pragma once //防止头文件重编译
#include<string>
using namespace std;
class Test{
public:
	Test(int i, string s);
	Test(const Test& other);
    Test& operator=(const Test& other);
    Test(Test&& other);//移动构造
    Test& operator=(Test&& other);//移动赋值
    ~Test();
    void setName(string str);
private:
	//return:先返回；再(编译器)释放局部变量(对于局部类对象则是先析构内部动态内存、再释放其内部其他变量)；
	int size;
	int* arrPtr;
	string name;


};

