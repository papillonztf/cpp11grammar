#include<iostream>
using namespace std;
struct stru1
{
	char a;
	short b;
	double c;//分为4+4
	int* p;
};

struct stru2
{
	char a;
	short b[10];//数组必须连续存储，但当前偏移为1，而short为2，因此char加1
	double c;
	char d[10];
	int* p;
};

struct stru3
{
	char a;
	short b[10];//数组必须连续存储，但当前偏移为1，而short为2，因此char加1
	double c;
	char d[10];
	//struct stru5
	//{
	//	char a;
	//	short b[10];//数组必须连续存储，但当前偏移为1，而short为2，因此char加1
	//	double c;
	//	char d[10];
	//	int* p;
	//}e;//看做不展开
	stru2 e;//stru2为48，而当前偏移量为42，因此42+6
	int* p;//96+4=100不是double 8的倍数-4=104
};


int main()
{

	cout << "stru1的对象为 24-------"<<sizeof(stru1) << endl;

	cout << "stru2的对象为 48-------" << sizeof(stru2) << endl;

	cout << "stru3的对象为 48-------" << sizeof(stru3) << endl;
	return 0;
}