/*

	һ�����������1.100���������������޴󣬲����㷨---Ч����
	          2.��������Ϊ��ֵk��
						��ٷ�������ѭ������ÿһ�Եĺͣ�ʱ�临�Ӷ�ΪO(N^2)
						��β��������������У���--->O(N)
						sum-a���������Ƿ������д���һ����a_j������sum-a_i------>for() ����(����Ϊ���ַ�����);ʱ�临�Ӷ�ΪO(N*logN),
						��������ԭʼ����A��B={sum-a_i}����,������������Ԫ����˵�����ڡ�
						�ݹ鷨���÷����������������Ƿ��������n������ʹ�ú�Ϊ��ֵk
	��.���ң�
		ѭ�����ң�����n��-->O(n)
		���ֲ���:ǰ������--->O(log n)
		�ֿ���ң����������е���β��
		bst���ң�o(log n)--->avl��---->rb������set��map
		��ϣ��0(1)����hash_set,hash_map
		�㷨	����
		find	���ص�һ���ȼ��ڸ���ֵ��Ԫ�صĵ�����
		find_if	���ص�һ��ʹ�� һԪν�ʷ���Ϊture ��Ԫ�صĵ�����
		find_if_not	���ص�һ��ֵ�������������(һԪν�ʷ���false)��Ԫ�صĵ�������
		find_first_of	!!!���ҷ�Χ A �е�һ���뷶Χ B ����һԪ������������Ԫ�ص�λ�á�
		find_end	!!!�ڷ�ΧA���� ��ΧB���һ�γ��ֵ�λ��
		search	!!�ڷ�ΧA�� �� ��ΧB ��һ�γ��ֵ�λ��
		search_n	!!!�ڷ�Χ�� ����������VAL��N��λ�õĵ�����
		adjacent_find	�������������� ��������Ԫ�ص�λ��
		count	���ҵ��ڸ���ֵ��Ԫ�ظ���
		count_if	��������ν��������Ԫ�ظ���


	��.STL list����˫������,����ѭ������Ҳ��֪�������ṹ

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