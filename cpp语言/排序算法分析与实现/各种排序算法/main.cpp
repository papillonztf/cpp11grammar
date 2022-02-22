/*
cin：以空格隔开，但不包括空格，以换行符结束，但不包括换行符，且换行符放入输入流中，供下次输入使用，下次输入遇到换行符，则结束，进而导致下次输入不提示。
cin.getline():输入指定size（大的抛弃多余，也不继续放入流中，少的就少吧）的字符串，可包括空格，以换行符结束，但不包括换行符且将换行符抛弃到输入流外。
cin.get():输入指定size（大的抛弃多余，也不继续放入流中，少的就少吧）的字符串，可包括空格，以换行符结束，但不包括换行符且将换行符放到到输入流中
具体的：cin.getline()和cin.get（）区别，还未发现
各种排序算的实现原理、特点、应用
1.冒泡排序：
		原理：内循环，冒出当前范围最大值。外循环，冒出前k-1个大的数
		特点：稳定，平均O(n^2).最坏O(n^2)，最好O(n)
		应用：少量数据排序
		优化：
			思路一：记录一趟中最后发生比较的位置（这一趟仍得比较完），作为下一趟比较的终点，
			思路二：记录一趟是否进行比较（这一趟仍得比较完），若该趟未发生比较，则表示已经是有序的了，不要在比较接下来的任意一趟，即终止比较


2.快排：
	 原理：
	   step1:
			实现分割：即0--k--（n-1），
	   step2：
			实现递归到size=1或非递归

	
*/
#include<iostream>
#include<stack>
using namespace std;
void BubbleSort(int * b,int n)//指针传递，反向修改，但是不安全，指针值可变
{
	//外循环n-1次，冒出前n-1大的
	int tem;
	int* p;
	int* nextp;
	for (int i = 1; i < n;i++)
	{
		//内循环，未排序范围内，两两比较，冒泡，
		p = b;//指针不能被破坏
		for (int j = 0; j < (n - i);j++)
		{
			nextp = p + 1;
			if (*p>*nextp)
			{
				tem = *p;
				*p = *nextp;
				*nextp = tem;
			}
			p = nextp;
		}
	}
	//指针不可被破坏
}

void partion(int * left, int * right,int **split)
{
	//如果区间只有一个元素即right-left=0，不用分割了。
	

	//否则分割
		//循环，bigleft>smallright选第一个元素为基准.不可能出现bigleft=smallright情况。
	//!!!!输入归一化。
	int* bigleft = left;//！！！！！但temptr从left+1开始到right
	int* smallright = right + 1;//！！！！但temptr从right开始到left+1
	//
	int* refptr = left;
	int* temptr = NULL;
	int tem = 0;
	while (bigleft<smallright)
	{
		//0-->找出最近bigleft
		temptr = bigleft;
		while (temptr<right)
		{
			temptr++;
			if (*temptr > *refptr)
			{
				bigleft = temptr;
				break;
			}
		}

		//<---n-1找出最近smallright
		temptr = smallright-1;
		while (temptr >left)
		{
			
			if (*temptr <= *refptr)
			{
				smallright = temptr;
				break;
			}
				
			temptr--;
			
		}
		//!!!!输出归一化，除了以下两种情况，一般认为smallright是分割点，
		//特殊情况1，基准<
		if ((bigleft==left+1)&&(smallright==right+1))
		{
			*split = left;
			break;
		}
		//特殊情况2，基准>
		if ((bigleft == left) && (smallright == right))
		{
			tem = *smallright;
			*smallright = *refptr;
			*refptr = tem;
			*split = right;
			break;
		}
		//若bigleft<smallright，则交换指针所指向的元素。若bigleft不小于smallright，那只能bigleft比smallright大1，不能等于。
		if (bigleft<smallright)
		{
			tem = *bigleft;
			*bigleft = *smallright;
			*smallright = tem;
		}
		//否则bigleft>smallright（只可能相差1），但是分割点就为smallright，基准元素与分割点元素交换，
		else
		{
			tem = *smallright;
			*smallright = *refptr;
			*refptr = tem;
			*split = smallright;
		}
		
		
	}
	//end循环。	
	
}

void  QSort(int * left,int * right)
{
	//递归实现快排。

	if (right >left)//递归终止条件
	{
		//初始化二级指针split，使用动态内存new分配，一点记得delete释放！！
		int** split=new(nothrow) int*;//希望split不变，而分割点的地址值*split通过反向传递变化，
		partion(left, right, split);//*split反向传递地址值
		QSort(left, *split-1);
		QSort(*split+1, right);
		delete split;
	}
	
}

void  QSort(int * l, int * r)
{
	//非递归实现快排。
	stack<int*>s;
	int*left = l;
	int*right = r;
	while ()
	{
		while (left<right)
		{
			int** split = new(nothrow) int*;
			partion(left, right, split);
			s.push(*split);
			delete split;
			right = *split - 1;
		}
		if (s.empty()!=true)
		{
			left = s.top();
			s.pop();
			right = s.top();
		}
		
	}
}

int main()
{
	//（编译器检查）变量使用前必须初始化，不使用则可以不初始化、
	int array[10] = { 1,3,2,2,9 };
	int* p = array;
	//冒泡排序
	//BubbleSort(p,5);
	//int n = 5;
	//while (n--)
	//{
	//	cout << *p++ << " ";
	//}
	//快排
	QSort(p, p+4);
	int n = 5;
	while (n--)
	{
		cout << *p++ << " ";
	}
	_CrtDumpMemoryLeaks();
	return 0;
	
}