#include"ConstTest.h"
#include<iostream>
using namespace std;
//const ������Թ��̳������ʱ��������
//1.���ڱ���
int iGlobVar=1;//ͷ�ļ���Ӧ������������Ӧ��������
const int CONSTINT = 1;
const int* CONSTINTPRT = &iGlobVar;
int * const INTCONSTPRT = &iGlobVar;
const int*const CONSTINTCONSTPRT = &iGlobVar;
const int & CONSTINTREF = iGlobVar;
//2.���ں���
void Fun1(const int i)//�β�i�ڸú����ڲ����޸�
{}
const int Fun2()//�ú�����������ֵ
{}
//3.���ں������ء������������ͬ�����Կ��Ժ�������
void Fun(int i)
{
}
void Fun(const int i)
{
}

//const ������Զ���������ʱ,���塣


ConstTest::ConstTest(int i, int j) :m_Intvar(i), m_ConstIntVar(j)
{}//���캯�����ڸ�������̬���ݳ�Ա֮�⣩�������ݳ�Ա��ʼ����
//~StatTest();//�ͷű�����ռ�ڴ�
//StatTest(const StatTest & original);//����
//const StatTest & operator =(const StatTest & rightValue);//���������


	//2.���ڳ�Ա����
void ConstTest::m_Fun()
{}
void ConstTest::m_FunConst() const //�ó�Ա�����˲������޸��κ����ݳ�Ա��Ҳ���ɷ��ʷ�const������Ա
{}
	//3.���ڳ�Ա�������ء�
void ConstTest::m_OverrideFun()
{}
void ConstTest::m_OverrideFun() const
{}

ConstTest Object;
