/*
���ֲ����㷨ԭ��---���Ӷ�---Ӧ�ó���
		1.�۰���ң�ֻ�������������У������ظ�ֵ�����ص����������ǵ�һ��value����������0,1,2,2,2,3,3,4,5,6,ʱ�临�Ӷ�ΪO(log n)
						�ɻ�������������飬ѭ����ݹ�ʵ�֡�
*/

//����棺
#include<iostream>
using namespace std;
int main()
{
	int array[] = { 0,1,2,3,4,5,6,7,8 };
	cout << sizeof(array)/4<< endl;
	int value = 0;
	int first = 0;
	int last = sizeof(array)/4-1;
	bool isFound = false;
	int middle = 0;
	int middleValue = 0;
	//ѭ����while(first>=0�һ�Ϊ�ҵ�
	cin >> value;
	while ((first <= last) && (isFound == false))
	{
		//ȡ[first,last]���м�ֵ��
		middle = (first + last) / 2 - (first + last) % 2;
		middleValue = array[(first + last) / 2 - (first + last) %2];
		//�жϸ��м�ֵ���ѯĿ��ıȽ�,if(array[middle]==value)
		if (value == middleValue)
		{
			//���ڣ����ҵ����˷���������return�˳�����;
			isFound = true;
			cout << middle;

		}
		else if (value > middleValue)//else if ���ڣ�����һ�������������м�ֵ���ұߣ�
		{
			// first = middle + 1��last����
			first = middle + 1;
			last = last;
		}
		
		else//elseС�ڣ�����һ�������������м�ֵ����ߣ�
		{
			//first���䣬last=middle-1
			first = first;
			last = middle - 1;
		}
		
	}
		
	system("pause");
	return 0;

}


//����汾��