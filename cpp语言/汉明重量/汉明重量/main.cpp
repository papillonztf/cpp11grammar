/*
���⣺
	�������룺������ͬ�����ֵĲ�ͬλ����򣩵ĸ���
	�������������������1�ĸ���

�����
	1.ת��Ϊ�����Ƽ�������1�ĸ���
	2.���Ʒ�������x&ox1����x>>1;
	3.ȥ1����ѭ��x&��x-1����ֱ��xΪ0��x&(x-1)��ȥ��x���ұߵ�1��
	4.����Ч���㷨:����
*/

#include<iostream>
using namespace std;

int fun1(int i)
{
	int count = 0;

	while (i)
	{
		
		if (i%2==1)
			count++;
		i = i / 2;
	}
	return count;
}
int fun2(int i)
{
	int count = 0;
	while (i)
	{
		if (i&0x1)//�ж����ұߵ�����λ�Ƿ�Ϊ1��������һλ
			count++;
		i = i >> 1;

	}
	return count;
}
int fun3(int i)
{
	int count = 0;
	while (i)
	{
		count++;
		i = i&(i - 1);//ȥ�����ұߵ�1
	}
	return count;
}

int main()
{
	int i;
	cin >> i;
	cout << fun1(i) << endl;
	cout << fun1(i) << endl;
	cout << fun1(i) << endl;
	
	return 0;
}