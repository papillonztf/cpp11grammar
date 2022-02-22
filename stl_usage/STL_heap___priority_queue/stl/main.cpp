/*
	STL֮heap������Ϊ������������Ϊ�㷨ʹ�á��ǻ������е���ȫ���������ۣ���ˣ��������飬vector��queue�ȴ洢����
				1����ʼ������vector--->void make_heap(first,end),����vector�����Ѻ��ԷŻ�ԭ����ԭvector��
				2.���ѣ�make_heap():ʱ�临�Ӷ�ΪO(log n)
				3.��ȡ���С��Ԫ�أ�����ȡ�Ѷ�=vector�ĵ�һ��Ԫ�ء�
				4.�����Ѷ���pop_heap(first,last); ʣ������Զ���ԭ���򽨶ѣ���������Ԫ�ط�����ԭ�����һ�����ĺ��棬��1,5,4,8.7.6--->4,6,5,8,7/1
							�º���Ҫ�ֶ�ɾ���õ���Ԫ�أ�vecForHeap.pop_back();//�����ֶ�ɾ��
				5.����һ��Ԫ�أ�push_heap(type value);
						   ��ǰ����Ҫ��vectorĩβ����Ԫ�أ�vecForHeap.push_back(12);//�����ֶ�����
				6.������soft_heap()����󷵻�ԭvector��
				7.Ĭ���ǽ������ѣ�Ĭ����������������ֻ����������С��ֻ���ǽ���
				8.������С�ѣ�make_heap(vecForHeap.begin(), vecForHeap.end(), greater<int>());
				9.�������򣺱�������С�ѵĻ����ϣ���sort_heap(vecForHeap.begin(),vecForHeap.end(),greater<int>());
	STL֮priority_queue:���������������ǻ��ڶ�ʵ�ֵģ�Ĭ�ϵ�������vector��û�е��������Լ�begin(),end()
				1.��ʼ����Ĭ�����ѣ�priority_queue<int> prioQueue(vecForHeap.begin(), vecForHeap.end());
							����Ϊ��С�ѣ�priority_queue<int,vector<int>, greater<int>> prioQueue(vecForHeap.begin(), vecForHeap.end());
				2.ֻ�ܽ�����ȡ�Ѷ�Ԫ�أ�����ջ��������Ԫ�صȲ�������û�е��������Լ�begin(),end()�ȣ���ˣ����ɽ�����ز������������
				3.��ȡ�Ѷ���priority_queue.top();
				4.�����Ѷ�Ԫ�أ�priority_queue.pop();
				5.����Ԫ�أ�priority_queue.push();
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

void print(int i)
{
	cout << i << " ";
}
/*------------------------------------------------------
							STL֮heap��ʹ�á�

Ĭ���ǽ������ѣ�Ĭ����������������make_heap(vecForHeap.begin(), vecForHeap.end(), greater<int>());�Լ�sort_heap(vecForHeap.begin(),vecForHeap.end(),greater<int>())������С�Ѳ���������
 ��ʵ�ǣ�����ֻ����������С��ֻ���ǽ���
-----------------------------------------------------*/
//int main()
//{
//	//����(��С��)
//	vector<int> vecForHeap = {2,0,4,55,78,11,1};
//	make_heap(vecForHeap.begin(), vecForHeap.end(), greater<int>());
//	for_each(vecForHeap.begin(), vecForHeap.end(), print);
//	cout << endl;
//
//	//�����򣨽��򣩡�����ֻ����������С��ֻ���ǽ���
//	sort_heap(vecForHeap.begin(),vecForHeap.end(),greater<int>());
//	for_each(vecForHeap.begin(),vecForHeap.end(),print);
//	cout << endl;
//
//	//��ȡ�Ѷ���
//	cout << vecForHeap[0]<< endl;
//	//�����Ѷ�����С�ѣ���pop_heap(vecForHeap.begin(), vecForHeap.end())������ȽϺ�����ʣ������Զ���ԭ���򽨶ѣ���������Ԫ�ط�����ԭ�����һ�����ĺ��棬��1,5,4,8.7.6--->4,6,5,8,7/1
//	pop_heap(vecForHeap.begin(), vecForHeap.end());
//	vecForHeap.pop_back();//�����ֶ�ɾ��
//	for_each(vecForHeap.begin(), vecForHeap.end(), print);
//	cout << endl;
//
//	//����һ��Ԫ��(��С��)��vecForHeap.push_back(12)����vector��ĩβ���룬Ȼ��push_heap(vecForHeap.begin(),vecForHeap.end())������ȽϺ��������е����Զ���ԭ���򽨶ѡ�
//	vecForHeap.push_back(12);//�����ֶ�����
//	push_heap(vecForHeap.begin(),vecForHeap.end());
//	for_each(vecForHeap.begin(), vecForHeap.end(), print);
//
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

int main()
{
	//�������ȶ��У���ʹ�ù��캯����ʼ��
	vector<int> vecForHeap = { 2, 0, 77, 44, 32, 4, 0, 2 };
	//priority_queue<int> prioQueue(vecForHeap.begin(),vecForHeap.end());
	priority_queue<int,vector<int>, greater<int>> prioQueue(vecForHeap.begin(), vecForHeap.end());
	//��ȡ�Զ�
	cout << prioQueue.top() << endl;
	//����Ԫ��
	prioQueue.push(76);
	cout << prioQueue.top() << endl;
	prioQueue.push(78);
	cout << prioQueue.top() << endl;
	//�����Ѷ�

	int num = prioQueue.size();
	for (int i = 0; i < num; i++)//������for (int i = 0; i < prioQueue.size() ; i++)��������Ϊ��prioQueue.size() ÿ��ѭ�����仯��
	{
		cout << prioQueue.top() << " ";
		prioQueue.pop();
	}
	cout << endl;
	cout << prioQueue.size() << endl;
	cout << endl;
	//�޵�������ֻ�ɷ��ʼ�ɾ���Ѷ�Ԫ�غͲ���Ԫ�أ���������
	
	//priority_queue<int> prioQueue(vecForHeap.begin(),vecForHeap.end());

	
	system("pause");
	return 0;
}