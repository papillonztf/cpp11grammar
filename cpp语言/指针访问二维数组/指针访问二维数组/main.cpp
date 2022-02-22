/*
指针指向二维数组：此时，任何把二维数组当做一个，一维数组运算
	1.初始化：只能p=arr[0]活p=*arr
	2.指针运算：p+i表示该一维数组的第i个元素，如p+1表示第二个元素的位置，而不是第二行的位置
				p+i*n+j：表示arr[i][j]
				p指向arr[i1][j1],则p+(i2-i1)*n+（j2-j1）指向arr[i2][j2]，其中i2>=i1.
	
*/

#include<iostream>
using namespace std;
int main()
{
	


	return 0;

}