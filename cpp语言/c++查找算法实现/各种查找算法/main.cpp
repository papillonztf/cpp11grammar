/*
几种查找算法原理---复杂度---应用场合
		1.折半查找：只针对于有序的序列，若有重复值，返回的索引并不是第一个value的索引，如0,1,2,2,2,3,3,4,5,6,时间复杂度为O(log n)
						可基于链表或者数组，循环或递归实现。
*/

//数组版：
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
	//循环，while(first>=0且还为找到
	cin >> value;
	while ((first <= last) && (isFound == false))
	{
		//取[first,last]得中间值，
		middle = (first + last) / 2 - (first + last) % 2;
		middleValue = array[(first + last) / 2 - (first + last) %2];
		//判断该中间值与查询目标的比较,if(array[middle]==value)
		if (value == middleValue)
		{
			//等于，则找到，退返回索引。return退出函数;
			isFound = true;
			cout << middle;

		}
		else if (value > middleValue)//else if 大于，则下一个查找区间是中间值的右边，
		{
			// first = middle + 1，last不变
			first = middle + 1;
			last = last;
		}
		
		else//else小于，则下一个查找区间是中间值的左边，
		{
			//first不变，last=middle-1
			first = first;
			last = middle - 1;
		}
		
	}
		
	system("pause");
	return 0;

}


//链表版本：