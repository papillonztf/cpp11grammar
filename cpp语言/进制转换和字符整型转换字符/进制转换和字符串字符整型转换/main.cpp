//1.������Ƶ�ʮ����ת��
//
//2.ʮ�����Ƶ��������ת��
//char buff[33];
//int j = 100;
//_itoa_s(j, buff, 2);//ֻ������Чλ
//str1=buff;
//
//3.�ַ���������ת��:
//		string--->char*:str.c_str()��str.data();
//		string--->int:atoi(str.c_str()); stdlib.h, atoi��char*����
//		string--->int:atol(str.c_str()); stdlib.h, atoi��char*����
//		string--->int:atof(str.c_str()); stdlib.h, atoi��char*����
//4.���͵��ַ���ת��
//		str1=to_string(int i);str1.size()����i��λ����str[>=size]�������
// 5.�����͵��ַ���ת��
//		str2=to_string(float i);��ȡ�ַ���ǰ��λ��������0��float 3.14--->3.140000;float3.14159123->3.141591
//5.�ַ�������ת��
//A---Z:65---90;a----z:97---122,0---9:48--57
//'0'---'9':-'0'
//(int)'A'=65 ��ǿ��ת��Ϊ��Ӧ��ascii��
//6.���͵��ַ�ת��
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
//int SumAllDigital(string str)
//{
//	int sum = 0;
//	for (int j = 0; j < str.size(); j++)//str.size()�����������ַ���
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
	//i��ʮ����ת�����λ��֮�͡�
		//ת��Ϊstring�󣬵���SumAllDigital��������
	int sumInt = 0; 
	int sumBin = 0;
	/*string strInt = to_string(i);
	
	string strBin;*/
	//sumInt = SumAllDigital(strInt);

	//////i�Ķ����ƽ���ת�����λ��֮�͡�
	//	//ʮ����ת������
	//char buff[33];
	//_itoa_s(i, buff, 2);//ֻ��ת�������Чλ����buff��buff��������ȫ����'/0'
	//strBin = buff;//strBin��size()=ת�����λ��
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





	////---->�ַ���
	// while (cin >> i)
	//{
	//
	//	str1=to_string(i);
	//	cout <<str1<< str1[5] <<' '<<str1.size()<< ' ';
	//}



	//�ַ��������ͣ�������int��float
	//while (cin >> str1)
	//{
	//	//i = atoi(str1.c_str);
	//	i = atof(str1.data());
	//	cout << i << ' ';
	//}
	
	
}