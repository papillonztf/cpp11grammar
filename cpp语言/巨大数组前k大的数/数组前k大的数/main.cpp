/*求解巨大数组中的前k大叔
		问题分析：1.巨大数组的排序问题，O(N*log N)快排，堆排，归并..O(N^2)简单选择排序，冒泡排序，插入排序。以及hash_set,hash_map
		
		解决思路：
				  0.
				  1.基于O(N*log N)排序的，前k大---->O(N*log N+k)
				  2.基于O(N*log N)简单选择和冒泡排序排序出前k大---->O(N*k)
				  3.基于STL中的void nth_element(start, start+k, end) -->基于快排思想的--->使得[a_0,a_k-1]<=a_k<=[a_k+1,a_n]-->O（N）
				  4.基于STL中的void partial_sort(beg,mid,end)-->基于最小k堆思想-->将前[beg,mid)的个最小元素，排序好放到[beg,mid)位置--->O(n*log k)
				  4.基于vector-make_heap--heap_sort--->基于堆排序的---》O(logn+N*log N)
				  5.基于hash_map
				
*/
#include<iostream>
#include<vector>
#include<hash_map>
#include<algorithm>
#include<functional>//greater<int>(),less<>()
using namespace std;
void print(int x)//对！！！每个元素值的操作。cmp也是。
{
	cout << x<< " ";
}
bool bigger(int a, int b)//自定义比较函数
{
	return a > b;
}
int main()
{
	vector<int> origVec = {9,12,5,8,4,3,6,7,1,1,3,2,0,9};
	vector<int> nth_elementVec(origVec);
	vector<int> partial_sortVec(origVec);
	vector<int> heapVec(origVec);
	vector<int> hash_mapVec(origVec);
	int k = 5;
	//基于STL中的void nth_element(start, start+k, end) -->基于快排思想的--->使得[a_0,a_k-1]<=a_k<=[a_k+1,a_n]-->O（N）

	nth_element(nth_elementVec.begin(),nth_elementVec.begin()+k-1,nth_elementVec.end()-1);
	for_each(nth_elementVec.begin(), nth_elementVec.end() ,print);
	cout << endl;

	//基于STL中的void partial_sort(beg,mid,end)-->基于最小k堆思想-->将前[beg,mid)的个最小元素，排序好放到[beg,mid)位置--->O(n*log k)
	
	//partial_sort(partial_sortVec.begin(), partial_sortVec.begin() + k, partial_sortVec.end(),bigger);//bigger,自定义比较函数，前一个元素值>后一个元素值
	partial_sort(partial_sortVec.begin(), partial_sortVec.begin() + k, partial_sortVec.end(), greater<int> ());//function库的比较函数
	for_each(partial_sortVec.begin(), partial_sortVec.end(), print);
	cout << endl;

	//基于vector-make_heap--heap_sort--->基于堆排序的---》O(logn+N*log N)
	make_heap(heapVec.begin(), heapVec.end());
	for_each(heapVec.begin(), heapVec.end(), print);
	cout << endl;
	sort_heap(heapVec.begin(), heapVec.end());
	for_each(heapVec.rbegin(), heapVec.rend(),print);
	cout << endl;

	// 5.基于hash_map
	hash_map<int, int> hm;
	for (vector<int>::iterator iter = origVec.begin(); iter != origVec.end(); iter++)
	{
		if (hm.find(*iter) == hm.end())
		{
			hm.insert(pair<int,int>(*iter,1));
		}
		else
		{
			hm[*iter] = hm[*iter]+1;
		}
	}
	/*hash_map<int, int>::iterator iterhm = hm.begin();
	for (k = 0; k <= 5;k++)
	{
		iterhm->
	}
	*/
	system("pause");
	return 0;
}