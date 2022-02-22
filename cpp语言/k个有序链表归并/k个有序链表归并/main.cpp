/*
			��һ������2list�鲢��klist����˼�롣ʱ�临�Ӷ�ΪT(k) = 2T(k/2) + O(nk),�ܼ򵥿����Ƶ��õ��㷨���Ӷ�ΪO��nklogk��
				0.//��������Ϊ�Ǹ��ݳ�ʼ��size�̶�������ѭ�����̵ĸ���Ԫ��λ�á���ˣ������ٸ�ѭ���н���ɾ����size�ᶯ̬�仯���Ӷ�λ��Ҳ��̬�仯��
							ͨ����ȾԴ���ݵ����÷��򴫵��Ӻ����Ľ����list1=list3��list1�����ݺ�list3һ����
							ͨ������ȾԴ���ݵ����÷��򴫵��Ӻ����Ľ�����������β��ж�һ��ר�����ڷ��򴫵ݵ��β�
				1.����2list�鲢����ʹ���Զ���MergeTwoSeqLists���߽���������Դ���list1.merge(list2)
				2.klist����˼��:��Ƕ��ѭ��ʵ�֣�vector<list <int>*>& list2D��01,23,45--->024-->04--��0
			������������С�ѣ�O��nklogk��
			    1.ʹ������������priority_queue��heapʵ��
				2.�㷨����ʼ��С��Ϊ��СΪk����ÿ���������Ԫ�أ���pop����СԪ�أ�Ȼ���ٲ������СԪ����������ĵ���һ��Ԫ�أ���pop����СԪ�أ�~~~~
*/
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
void print(int i)
{
	cout << i << " ";
}

//ͨ�����÷��򴫵��Ӻ����Ľ����list1=list3��list1�����ݺ�list3һ����
void MergeTwoSeqLists(list < int >&list1, list < int >&list2)
{
	list < int > list3;
	while ((list1.empty()||list2.empty())!=1)
	{
		list3.push_back(list1.front()<=list2.front()? list1.front():list2.front());
		list1.front() <= list2.front() ? list1.pop_front() : list2.pop_front();
	}
	if (list1.empty() != true)
	{
		list3.insert(list3.end(),list1.begin(),list1.end());
	}
	else
	{
		list3.insert(list3.end(), list2.begin(), list2.end());
	}
	list1 = list3;//!!!
}


list<int>& MergeKSeqLists(vector<list <int>*>& list2D, list<int>& listAll)
{ 
	//k������Ķ�����������1����������
	if (list2D.size()<2)
	{
		return listAll = *list2D[0];
	}
	while (list2D.size()>1)
	{
		//mÿ��ѭ����ʼ������
		int size = list2D.size();
		int count = 0;
		while (count < size / 2)
		{
			//��������Ϊ�Ǹ��ݳ�ʼ��size�̶�������ѭ�����̵�λ�á���ˣ������ٸ�ѭ���н���ɾ����size��仯���Ӷ�λ��Ҳ��̬�仯��
			MergeTwoSeqLists(*list2D[count * 2], *list2D[count * 2 + 1]);
			count++;
		}
		count = 0;
		while (count < size / 2)
		{
			//������Ϊ�Ǹ��ݳ�ʼ��size�̶�������ѭ�����̵�λ�á���ˣ������ٸ�ѭ���н���ɾ����size��仯���Ӷ�λ��Ҳ��̬�仯��
			list2D.erase(list2D.begin() + count  + 1);//������list2D.begin() + count* 2 + 1-count����Ϊ����list2D.begin() + count* 2 + 1������Ѿ�����size-1��
			count++;
		}
	}
	return listAll = *list2D[0];

}
int main()//��������Ϊ�Ǹ��ݳ�ʼ��size�̶�������ѭ�����̵ĸ���Ԫ��λ�á���ˣ������ٸ�ѭ���н���ɾ����size�ᶯ̬�仯���Ӷ�λ��Ҳ��̬�仯��
{			////ͨ�����÷��򴫵��Ӻ����Ľ����list1=list3��list1�����ݺ�list3һ����
	list < int > list1 = {2,1,3,2,4};
	list < int > list2 = { 8, 2, 3, 6, 7, 5, 0 };
	list < int > list3 = { 2,3,6,33,44,1};
	list < int > list4 = { 16, 37, 25, 10 };
	list < int > list5 = { 18, 12, 13,16, 17, 15, 10 };
	list < int > list6 = { 28, 32, 33,26, 27, 45, 20 };
	//list < int > list7 = {38, 42, 53, 66, 67, 45, 40 };
	vector<list <int>*> list2D = { &list1, &list2, &list3, &list4, &list5, &list6 };
	list < int > listAll;

	//�ϲ�������������

	list1.sort();
	for_each(list1.begin(), list1.end(), print);
	cout << endl;
	list2.sort();
	list3.sort();
	list4.sort();
	list5.sort();
	list6.sort();
	
	for_each(list2.begin(), list2.end(), print);
	cout << endl;

	//merge(list1.begin(),list1.end(),list2.begin(),list2.end(),list3.end());//���󣬽��������������ʹ��sort��merge�㷨������ʹ���Դ��ġ�
	
	//MergeTwoSeqLists(list1,list2);//�ȼ���//list1.merge(list2);
	for_each(list1.begin(), list1.end(), print);
	cout << endl;

	//�ϲ�k����������
	//listAll=MergeKSeqLists(list2D,listAll);
	//for_each(listAll.begin(), listAll.end(), print);
	//cout << endl;

	system("pause");
	return 0;
}