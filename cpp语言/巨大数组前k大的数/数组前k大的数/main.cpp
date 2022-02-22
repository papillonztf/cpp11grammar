/*���޴������е�ǰk����
		���������1.�޴�������������⣬O(N*log N)���ţ����ţ��鲢..O(N^2)��ѡ������ð�����򣬲��������Լ�hash_set,hash_map
		
		���˼·��
				  0.
				  1.����O(N*log N)����ģ�ǰk��---->O(N*log N+k)
				  2.����O(N*log N)��ѡ���ð�����������ǰk��---->O(N*k)
				  3.����STL�е�void nth_element(start, start+k, end) -->���ڿ���˼���--->ʹ��[a_0,a_k-1]<=a_k<=[a_k+1,a_n]-->O��N��
				  4.����STL�е�void partial_sort(beg,mid,end)-->������Сk��˼��-->��ǰ[beg,mid)�ĸ���СԪ�أ�����÷ŵ�[beg,mid)λ��--->O(n*log k)
				  4.����vector-make_heap--heap_sort--->���ڶ������---��O(logn+N*log N)
				  5.����hash_map
				
*/
#include<iostream>
#include<vector>
#include<hash_map>
#include<algorithm>
#include<functional>//greater<int>(),less<>()
using namespace std;
void print(int x)//�ԣ�����ÿ��Ԫ��ֵ�Ĳ�����cmpҲ�ǡ�
{
	cout << x<< " ";
}
bool bigger(int a, int b)//�Զ���ȽϺ���
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
	//����STL�е�void nth_element(start, start+k, end) -->���ڿ���˼���--->ʹ��[a_0,a_k-1]<=a_k<=[a_k+1,a_n]-->O��N��

	nth_element(nth_elementVec.begin(),nth_elementVec.begin()+k-1,nth_elementVec.end()-1);
	for_each(nth_elementVec.begin(), nth_elementVec.end() ,print);
	cout << endl;

	//����STL�е�void partial_sort(beg,mid,end)-->������Сk��˼��-->��ǰ[beg,mid)�ĸ���СԪ�أ�����÷ŵ�[beg,mid)λ��--->O(n*log k)
	
	//partial_sort(partial_sortVec.begin(), partial_sortVec.begin() + k, partial_sortVec.end(),bigger);//bigger,�Զ���ȽϺ�����ǰһ��Ԫ��ֵ>��һ��Ԫ��ֵ
	partial_sort(partial_sortVec.begin(), partial_sortVec.begin() + k, partial_sortVec.end(), greater<int> ());//function��ıȽϺ���
	for_each(partial_sortVec.begin(), partial_sortVec.end(), print);
	cout << endl;

	//����vector-make_heap--heap_sort--->���ڶ������---��O(logn+N*log N)
	make_heap(heapVec.begin(), heapVec.end());
	for_each(heapVec.begin(), heapVec.end(), print);
	cout << endl;
	sort_heap(heapVec.begin(), heapVec.end());
	for_each(heapVec.rbegin(), heapVec.rend(),print);
	cout << endl;

	// 5.����hash_map
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