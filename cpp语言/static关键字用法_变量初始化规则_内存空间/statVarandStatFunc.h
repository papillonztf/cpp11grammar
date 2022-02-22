#include<iostream>
using namespace std;
static void fun3();
int iheader=1;
extern int globalVariable;//调用未include文件中的全局变量，必须使用extern；
//extern int globalVariable=2;//全局变量不能再次被初始化
extern  int staticGlobalVariable;
void fun1()
{
	cout << globalVariable << endl;
}
void fun2()
{
	cout << staticGlobalVariable<< endl;
}
static void fun3()
{
	int i=12;
	cout << i << endl;
}
class test
{
private:
	int i = 1;
	

public:
	static int j;
	void Set()
	{
		i = 20;
	}
	static void Get()
	{
		
		//cout << i;//静态函数成员不可访问非静态数据、非静态函数成员
		cout << j;
	}
		
};
int test::j = 2;