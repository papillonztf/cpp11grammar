/*探究一二维数组的地址的本质：
一维数组：int arr[5],]，char* p = arr=&arr[0]
	arr     : 数组第一个元素的地址。是个一级指针。因此，arr+1是第二个元素arr[1]的地址。
	&arr[0] : 数组第一个元素的地址，与arr含义一样。是个一级指针。因此，&arr[0]+1=&arr[1]是第二个元素arr[1]的地址。
	----
	&arr    ：数组的地址（值与上面两个相同，但含义不同）。是个二级指针，因此，&arr+1是第二个（同等长度）的数组的地址。
	那么，自然将上述指针赋予某个指针变量p，对p的运算必有要求。
	如：char arr[3]={1,2,3};
		char* p =arr;//=&arr[0]
		char** pp=&arr;
	    cout<<p<<*p;
二维数组：int arr[3][4],char(*p)[4] = arr=arr[0]:
	arr:二维数组的第一行的地址（即第一行一维数组的地址。是一个二级指针。因此，arr+1是第二行一维数组的地址。
	arr[0]:是二维数组的第一行的地址（即第一行一维数组的地址,与arr含义一致。是一个二级指针。因此，arr[1]是第二行一维数组的地址。arr[1]+1是第二行第二个元素的地址。
	*arr：是第一行的第一个元素的地址。（值与上面两个相同，但含义不同）是一个一级地址。因此，*（arr+1）是第二行的第一个元素的地址，*（arr+1）+1是第二行第二个元素的地址。
cout<<p<<*p:
	p指向非字符数组：分别输出p的值，即地址，和p指向的内存单元中的值
	p指向字符数组：分别输出p指向的内存单元且以‘/0’结束的一片内存单元中的值 和p第一个元素的值。此时，输出地址，应cout<<(void*)p.(cout针对字符指针进行重载)
   
*/
#include<iostream>
#define YW 2
using namespace std;
int main()
{
	//一维数组：arr=&arr[0] || &arr
#if YW==1
	char arr[3] = { '1', '2', '\0' };
	char* p = arr;//字符指针p指向一个字符变量，在此具体指向一维数组的第一个元素的地址，因此赋值应是arr或&arr[0]，p+1跨度为一个元素
	cout << " p:" <<p<< "  *p : " << *p<<endl;
	cout << "arr :      "         << (void*)arr         << endl;
	cout << "&arr[0]:   "         << (void*)(&arr[0])   << endl;
	cout << "&arr:      "         << (void*)&arr        << endl;
	cout << "arr+1 :    "         << (void*)(arr+1)     << endl;
	cout << "&arr[0+1] :"         << (void*)(&arr[0+1]) << endl;
	cout << "&arr+1 :   "         << (void*)(&arr+1)    << endl;
#else
	//二维数组：arr=arr[0] || *arr
	char arr[3][4] = { '1', '2', '3', '1', '2', '3', '1', '2', '3' };
	char(*p)[4] = arr;//数组指针p指向一个拥有四个元素的一维数组，在此，具体指向二维数组的第一行，因此赋值应是arr或arr[0],p+1跨度为一行。
	cout << "arr :      " << (void*)arr << endl;
	cout << "&arr[0]:   " << (void*)(&arr[0]) << endl;
	cout << "*arr:      " << (void*)*arr << endl;
	cout << "arr+1 :    " << (void*)(arr + 1) << endl;
	cout << "&arr[0+1] :" << (void*)(&arr[0 + 1]) << endl;
	cout << "*arr+1 :   " << (void*)(*arr + 1) << endl;
#endif

	system("pause");
	return 0;
}