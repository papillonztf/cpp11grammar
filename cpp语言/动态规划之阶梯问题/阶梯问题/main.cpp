/*
		1.��̬�滮�ķ������Զ����£���ʵ�������Ե����ϡ�ʹ�õ�������list.push_back(),list.pop_front(),���list.back()�����
		2.�ݹ��㷨�ķ������Ե����ϣ�ʵ�������Զ����¡�ʹ��ջ���ݴ����ݣ����ʱ�䣬�ڴ濪���ܴ󡣵�n�ܴ�ʱ�����Ӷȷǳ���
		3.�׶Σ�ÿһ�����ݾ���һ���׶Σ�
		4.״̬��״̬���̣�f(n)=f(n-1)+f(n-2),n>2
		5.�߽磺n=0,1,2ʱ����<=��󲽳���״̬�����оٳ�����������ͨ��״̬�������
		6.�洢�õ��Ľ׶ε����ݣ��׶ε������Ե�����),ʹ��sizeΪ��󲽳���������д洢Ҫ�õ��Ľ׶ε�����
*/
#include<iostream>
#include<list>
using namespace std;
int main()
{	//�洢����
	list<int> twoNodeList;
	//�߽�
	twoNodeList.push_back(1);
	twoNodeList.push_back(2);
	int n = 4;
	
	
	list<int> ::iterator iter = twoNodeList.begin();
	//�׶�
	for (int i = 3; i <= n; i++)
	{
		iter = twoNodeList.begin();
		//��̬�滮���Ե����ϡ�
			//״̬ת�Ʒ���
		twoNodeList.push_back(*(iter++)+1 + *(iter)+1);//�ȼ�����++iter��iter++
		twoNodeList.pop_front();
	}
	cout << twoNodeList.back();
	
	

	system("pause");
	return 0;

}