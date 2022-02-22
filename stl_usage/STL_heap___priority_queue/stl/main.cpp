/*
	STL之heap：不作为容器，而是作为算法使用。是基于现有的完全二叉树理论，因此，常把数组，vector，queue等存储容器
				1。初始化：即vector--->void make_heap(first,end),基于vector，建堆后仍放回原处（原vector）
				2.建堆：make_heap():时间复杂度为O(log n)
				3.提取最大（小）元素：即提取堆顶=vector的第一个元素。
				4.弹出堆顶：pop_heap(first,last); 剩余的数自动按原规则建堆，而弹出的元素废弃在原来最后一个数的后面，，1,5,4,8.7.6--->4,6,5,8,7/1
							事后，需要手动删除该弹出元素：vecForHeap.pop_back();//还得手动删除
				5.插入一个元素：push_heap(type value);
						   事前，需要在vector末尾插入元素：vecForHeap.push_back(12);//还得手动插入
				6.堆排序：soft_heap()排序后返回原vector。
				7.默认是建立最大堆，默认是升序排序。最大堆只能是升序，最小堆只能是降序
				8.建立最小堆，make_heap(vecForHeap.begin(), vecForHeap.end(), greater<int>());
				9.降序排序：必须在最小堆的基础上，再sort_heap(vecForHeap.begin(),vecForHeap.end(),greater<int>());
	STL之priority_queue:是容器适配器，是基于堆实现的，默认的容器是vector，没有迭代器，以及begin(),end()
				1.初始化：默认最大堆：priority_queue<int> prioQueue(vecForHeap.begin(), vecForHeap.end());
							设置为最小堆：priority_queue<int,vector<int>, greater<int>> prioQueue(vecForHeap.begin(), vecForHeap.end());
				2.只能进行提取堆顶元素，弹出栈顶，插入元素等操作。无没有迭代器，以及begin(),end()等，因此，不可进行相关操作，如遍历。
				3.提取堆顶：priority_queue.top();
				4.弹出堆顶元素：priority_queue.pop();
				5.插入元素：priority_queue.push();
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
							STL之heap的使用。

默认是建立最大堆，默认是升序排序。这里make_heap(vecForHeap.begin(), vecForHeap.end(), greater<int>());以及sort_heap(vecForHeap.begin(),vecForHeap.end(),greater<int>())建立最小堆并降序排序
 事实是，最大堆只能是升序，最小堆只能是降序
-----------------------------------------------------*/
//int main()
//{
//	//建堆(最小堆)
//	vector<int> vecForHeap = {2,0,4,55,78,11,1};
//	make_heap(vecForHeap.begin(), vecForHeap.end(), greater<int>());
//	for_each(vecForHeap.begin(), vecForHeap.end(), print);
//	cout << endl;
//
//	//堆排序（降序）。最大堆只能是升序，最小堆只能是降序
//	sort_heap(vecForHeap.begin(),vecForHeap.end(),greater<int>());
//	for_each(vecForHeap.begin(),vecForHeap.end(),print);
//	cout << endl;
//
//	//提取堆顶：
//	cout << vecForHeap[0]<< endl;
//	//弹出堆顶（最小堆）：pop_heap(vecForHeap.begin(), vecForHeap.end())，不需比较函数，剩余的数自动按原规则建堆，而弹出的元素废弃在原来最后一个数的后面，，1,5,4,8.7.6--->4,6,5,8,7/1
//	pop_heap(vecForHeap.begin(), vecForHeap.end());
//	vecForHeap.pop_back();//还得手动删除
//	for_each(vecForHeap.begin(), vecForHeap.end(), print);
//	cout << endl;
//
//	//插入一个元素(最小堆)：vecForHeap.push_back(12)，在vector的末尾插入，然后push_heap(vecForHeap.begin(),vecForHeap.end())，不需比较函数，所有的数自动按原规则建堆。
//	vecForHeap.push_back(12);//还得手动插入
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
	//建立优先队列：即使用构造函数初始化
	vector<int> vecForHeap = { 2, 0, 77, 44, 32, 4, 0, 2 };
	//priority_queue<int> prioQueue(vecForHeap.begin(),vecForHeap.end());
	priority_queue<int,vector<int>, greater<int>> prioQueue(vecForHeap.begin(), vecForHeap.end());
	//提取对顶
	cout << prioQueue.top() << endl;
	//插入元素
	prioQueue.push(76);
	cout << prioQueue.top() << endl;
	prioQueue.push(78);
	cout << prioQueue.top() << endl;
	//弹出堆顶

	int num = prioQueue.size();
	for (int i = 0; i < num; i++)//！！！for (int i = 0; i < prioQueue.size() ; i++)，错误。因为，prioQueue.size() 每次循环都变化。
	{
		cout << prioQueue.top() << " ";
		prioQueue.pop();
	}
	cout << endl;
	cout << prioQueue.size() << endl;
	cout << endl;
	//无迭代器，只可访问及删除堆顶元素和插入元素，不可排序
	
	//priority_queue<int> prioQueue(vecForHeap.begin(),vecForHeap.end());

	
	system("pause");
	return 0;
}