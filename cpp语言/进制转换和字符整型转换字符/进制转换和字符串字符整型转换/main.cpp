//1.任意进制到十进制转换
//
//2.十进进制到任意进制转换
//char buff[33];
//int j = 100;
//_itoa_s(j, buff, 2);//只保存有效位
//str1=buff;
//
//3.字符串到整型转换:
//		string--->char*:str.c_str()或str.data();
//		string--->int:atoi(str.c_str()); stdlib.h, atoi（char*）。
//		string--->int:atol(str.c_str()); stdlib.h, atoi（char*）。
//		string--->int:atof(str.c_str()); stdlib.h, atoi（char*）。
//4.整型到字符串转换
//		str1=to_string(int i);str1.size()等于i的位数，str[>=size]输出乱码
// 5.浮点型到字符串转换
//		str2=to_string(float i);截取字符串前八位，不够补0，float 3.14--->3.140000;float3.14159123->3.141591
//5.字符到整型转换
//A---Z:65---90;a----z:97---122,0---9:48--57
//'0'---'9':-'0'
//(int)'A'=65 ，强制转换为对应的ascii码
//6.整型到字符转换
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
//int SumAllDigital(string str)
//{
//	int sum = 0;
//	for (int j = 0; j < str.size(); j++)//str.size()不包含结束字符。
//	{
//		sum += str[j] - '0';
//	}
//	return sum;
//}


int allDigitalSum(int a, int b)
{
	int sum = 0;
	if (b >= 2)
	{
		while (a != 0)
		{
			sum += a % b;
			a = a / b;
		}
		//cout << sum << ' ';
		return sum;
	}
	else
	{
		exit(0);
	}
}
bool IsLuckyNum(int i)
{
	//i的十进制转换后个位数之和。
		//转换为string后，调用SumAllDigital（）计算
	int sumInt = 0; 
	int sumBin = 0;
	/*string strInt = to_string(i);
	
	string strBin;*/
	//sumInt = SumAllDigital(strInt);

	//////i的二进制进制转换后个位数之和。
	//	//十进制转二进制
	//char buff[33];
	//_itoa_s(i, buff, 2);//只讲转换后的有效位存入buff，buff空余区，全部填'/0'
	//strBin = buff;//strBin。size()=转换后的位数
	//sumBin = SumAllDigital(strBin);
	//return sumInt == sumBin;
	return allDigitalSum(i, 10) == allDigitalSum(i, 2);

}

int main()
{
	float n;
	while (cin >> n)
	{
		int sum = 0;
		if((n - (int)(n)) != 0)
		{
			continue;
		}
		int N = (int)(n);
		for (N; N>0;N--)
		{
			if (IsLuckyNum(N)==true)
			{
				sum +=1 ;
			}
		}
		cout << sum;

	}

	
	


	//cout << sizeof(i);
	/*while (cin>>i)
	{*/
	/*	j = i - '0';
		cout << (int) i<< ' ';*/
	/*}*/
		system("pause");





	////---->字符串
	// while (cin >> i)
	//{
	//
	//	str1=to_string(i);
	//	cout <<str1<< str1[5] <<' '<<str1.size()<< ' ';
	//}



	//字符串到整型？仅限于int，float
	//while (cin >> str1)
	//{
	//	//i = atoi(str1.c_str);
	//	i = atof(str1.data());
	//	cout << i << ' ';
	//}
	
	
}