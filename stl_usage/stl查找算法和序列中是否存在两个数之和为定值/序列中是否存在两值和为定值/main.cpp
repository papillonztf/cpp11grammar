/*

	一。问题分析：1.100万有序数，数量巨大，查找算法---效率性
	          2.两个数和为定值k。
						穷举法：两个循环，求每一对的和，时间复杂度为O(N^2)
						首尾发（针对有序序列）：--->O(N)
						sum-a：即查找是否序列中存在一个数a_j，等于sum-a_i------>for() 查找(假设为二分法查找);时间复杂度为O(N*logN),
						交集发：原始序列A与B={sum-a_i}交集,，若交集中有元素则说明存在。
						递归法：该方法可用于序列中是否存在三（n）个数使得和为定值k
	二.查找：
		循环查找：遍历n次-->O(n)
		二分查找:前提有序，--->O(log n)
		分块查找：如有序序列的首尾法
		bst查找：o(log n)--->avl树---->rb树，如set，map
		哈希表：0(1)，如hash_set,hash_map
		算法	功能
		find	返回第一个等价于给定值的元素的迭代器
		find_if	返回第一个使得 一元谓词返回为ture 的元素的迭代器
		find_if_not	返回第一个值不满足给定条件(一元谓词返回false)的元素的迭代器。
		find_first_of	!!!查找范围 A 中第一个与范围 B 中任一元素满足条件的元素的位置。
		find_end	!!!在范围A中找 范围B最后一次出现的位置
		search	!!在范围A中 找 范围B 第一次出现的位置
		search_n	!!!在范围中 找连续出现VAL的N次位置的迭代器
		adjacent_find	查找满足条件的 相邻两个元素的位置
		count	查找等于给定值的元素个数
		count_if	查找满足谓词条件的元素个数


	三.STL list：是双向链表,不是循环链表，也不知道结点类结构

*/
#include<iostream>
#include<list>
using namespace std;
int main()
{
	const int n =6 ;
	bool  isfound = false;
	list<int> testList = {1,2,3,6};
	list<int>::iterator iter = testList.begin();
	list<int>::reverse_iterator riter = testList.rbegin();
	int i = 1;
	int j =testList.size() ;
	while (1)
	{
		
		if (i==j)
			break;
		if ((*iter + *riter) == n)
		{
			isfound = true;
			break;
		}
		else
		if ((*iter + *riter) >n)
		{
			riter++;
			i++;
		}
		else
		{
			iter++;
			j--;
		}
		
	}
	cout << isfound<< endl;
	system("pause");

	return 0;

}