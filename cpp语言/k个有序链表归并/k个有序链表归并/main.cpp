/*
			法一：基于2list归并和klist分治思想。时间复杂度为T(k) = 2T(k/2) + O(nk),很简单可以推导得到算法复杂度为O（nklogk）
				0.//！！！因为是根据初始的size固定整个内循环过程的各个元素位置。因此，不能再该循环中进行删除（size会动态变化，从而位置也动态变化）
							通过污染源数据的引用反向传递子函数的结果！list1=list3，list1的内容和list3一样。
							通过不污染源数据的引用反向传递子函数的结果，但必须形参中多一个专门用于反向传递的形参
				1.基于2list归并：可使用自定义MergeTwoSeqLists或者结点型容器自带的list1.merge(list2)
				2.klist分治思想:即嵌套循环实现，vector<list <int>*>& list2D，01,23,45--->024-->04--》0
			法二：基于最小堆：O（nklogk）
			    1.使用容器适配器priority_queue或heap实现
				2.算法：初始最小堆为大小为k，即每条链表的首元素，先pop处最小元素，然后再插入该最小元素所在链表的第下一个元素，再pop出最小元素，~~~~
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

//通过引用反向传递子函数的结果！list1=list3，list1的内容和list3一样。
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
	//k个链表的对数，可能余1，后续考虑
	if (list2D.size()<2)
	{
		return listAll = *list2D[0];
	}
	while (list2D.size()>1)
	{
		//m每次循环初始条件。
		int size = list2D.size();
		int count = 0;
		while (count < size / 2)
		{
			//！！！因为是根据初始的size固定整个内循环过程的位置。因此，不能再该循环中进行删除（size会变化，从而位置也动态变化）
			MergeTwoSeqLists(*list2D[count * 2], *list2D[count * 2 + 1]);
			count++;
		}
		count = 0;
		while (count < size / 2)
		{
			//！！因为是根据初始的size固定整个内循环过程的位置。因此，不能再该循环中进行删除（size会变化，从而位置也动态变化）
			list2D.erase(list2D.begin() + count  + 1);//不可以list2D.begin() + count* 2 + 1-count，因为计算list2D.begin() + count* 2 + 1这个是已经超过size-1了
			count++;
		}
	}
	return listAll = *list2D[0];

}
int main()//！！！因为是根据初始的size固定整个内循环过程的各个元素位置。因此，不能再该循环中进行删除（size会动态变化，从而位置也动态变化）
{			////通过引用反向传递子函数的结果！list1=list3，list1的内容和list3一样。
	list < int > list1 = {2,1,3,2,4};
	list < int > list2 = { 8, 2, 3, 6, 7, 5, 0 };
	list < int > list3 = { 2,3,6,33,44,1};
	list < int > list4 = { 16, 37, 25, 10 };
	list < int > list5 = { 18, 12, 13,16, 17, 15, 10 };
	list < int > list6 = { 28, 32, 33,26, 27, 45, 20 };
	//list < int > list7 = {38, 42, 53, 66, 67, 45, 40 };
	vector<list <int>*> list2D = { &list1, &list2, &list3, &list4, &list5, &list6 };
	list < int > listAll;

	//合并两个有序链表

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

	//merge(list1.begin(),list1.end(),list2.begin(),list2.end(),list3.end());//错误，结点型容器，不能使用sort，merge算法。必须使用自带的。
	
	//MergeTwoSeqLists(list1,list2);//等价于//list1.merge(list2);
	for_each(list1.begin(), list1.end(), print);
	cout << endl;

	//合并k个有序链表
	//listAll=MergeKSeqLists(list2D,listAll);
	//for_each(listAll.begin(), listAll.end(), print);
	//cout << endl;

	system("pause");
	return 0;
}