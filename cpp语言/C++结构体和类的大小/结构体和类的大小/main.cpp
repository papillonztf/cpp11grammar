#include<iostream>
using namespace std;
struct stru1
{
	char a;
	short b;
	double c;//��Ϊ4+4
	int* p;
};

struct stru2
{
	char a;
	short b[10];//������������洢������ǰƫ��Ϊ1����shortΪ2�����char��1
	double c;
	char d[10];
	int* p;
};

struct stru3
{
	char a;
	short b[10];//������������洢������ǰƫ��Ϊ1����shortΪ2�����char��1
	double c;
	char d[10];
	//struct stru5
	//{
	//	char a;
	//	short b[10];//������������洢������ǰƫ��Ϊ1����shortΪ2�����char��1
	//	double c;
	//	char d[10];
	//	int* p;
	//}e;//������չ��
	stru2 e;//stru2Ϊ48������ǰƫ����Ϊ42�����42+6
	int* p;//96+4=100����double 8�ı���-4=104
};


int main()
{

	cout << "stru1�Ķ���Ϊ 24-------"<<sizeof(stru1) << endl;

	cout << "stru2�Ķ���Ϊ 48-------" << sizeof(stru2) << endl;

	cout << "stru3�Ķ���Ϊ 48-------" << sizeof(stru3) << endl;
	return 0;
}