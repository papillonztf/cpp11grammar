/*
问题：
	汉明距离：两个相同长度字的不同位（异或）的个数
	汉明重量：即异或结果中1的个数

解决：
	1.转换为二进制计算其中1的个数
	2.右移法：即先x&ox1，再x>>1;
	3.去1法：循环x&（x-1），直到x为0；x&(x-1)会去掉x最右边的1；
	4.更高效的算法:待续
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
		if (i&0x1)//判断最右边的右移位是否为1，并右移一位
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
		i = i&(i - 1);//去掉最右边的1
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