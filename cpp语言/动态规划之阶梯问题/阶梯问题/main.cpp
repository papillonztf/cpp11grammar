/*
		1.动态规划的分析是自顶向下，而实现则是自底向上。使用的是链表list.push_back(),list.pop_front(),最后list.back()输出。
		2.递归算法的分析是自底向上，实现则是自顶向下。使用栈来暂存数据，因此时间，内存开销很大。当n很大时，复杂度非常大。
		3.阶段：每一个阶梯就是一个阶段，
		4.状态及状态方程：f(n)=f(n-1)+f(n-2),n>2
		5.边界：n=0,1,2时，即<=最大步长的状态必须列举出来，而不是通过状态方程求解
		6.存储用到的阶段的数据：阶段递增（自底向下),使用size为最大步长的链表进行存储要用到的阶段的数据
*/
#include<iostream>
#include<list>
using namespace std;
int main()
{	//存储变量
	list<int> twoNodeList;
	//边界
	twoNodeList.push_back(1);
	twoNodeList.push_back(2);
	int n = 4;
	
	
	list<int> ::iterator iter = twoNodeList.begin();
	//阶段
	for (int i = 3; i <= n; i++)
	{
		iter = twoNodeList.begin();
		//动态规划，自底向上。
			//状态转移方程
		twoNodeList.push_back(*(iter++)+1 + *(iter)+1);//先计算了++iter，iter++
		twoNodeList.pop_front();
	}
	cout << twoNodeList.back();
	
	

	system("pause");
	return 0;

}