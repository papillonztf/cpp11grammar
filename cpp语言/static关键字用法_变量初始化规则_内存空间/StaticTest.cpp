#include"StaticTest.h"
#include<iostream>
using namespace std;

int iGlobVar;
static int isStatGlobVar;

void TestStatLocVar()
{
	static int isLocVar ;
	cout << ++isLocVar << endl;
}

void TestStatFunc()
{
	cout << "��̬����ֻ���ڱ��ļ��ڱ�����"<< endl;
}

void StatTest::Fun()
{
	//�ǷǾ�̬��Ա�����ɷ��ʾ�̬������Ա�;�̬������Ա
	cout << isVar<< endl;
	StatFun();

}
void StatTest::StatFun() //static�������ԵĹؼ��ʣ���̬��Ա��������ʱ������д��static
{
	//��̬��Ա����ֻ�ɷ��ʾ�̬������Ա�;�̬������Ա;��̬���ݳ�Աһ�����иġ�
	cout << ++isVar <<"  test"<< endl;

}
int StatTest::isVar ;//��̬���ݳ�Ա