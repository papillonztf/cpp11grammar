#include<iostream>
using namespace std;
static void fun3();
int iheader=1;
extern int globalVariable;//����δinclude�ļ��е�ȫ�ֱ���������ʹ��extern��
//extern int globalVariable=2;//ȫ�ֱ��������ٴα���ʼ��
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
		
		//cout << i;//��̬������Ա���ɷ��ʷǾ�̬���ݡ��Ǿ�̬������Ա
		cout << j;
	}
		
};
int test::j = 2;