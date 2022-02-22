/*strcpy:	
	1.函数原型：char* strcpy(char* des,const char char* src)

	2.功能分析：针对字符串，实现将src地址开始且包含结束字符'\0'的这一段，复制到以des开头的区域。

	3.实现分析：
		1.输入：为了提高参数传输效率，src和des数据类型必须为char*(即字符指针or字符数组or字符串常量)，且src的为const char *，表示源数据不变。des指向内存不清空，而是复制性覆盖。
		2.输出：为了提高参数传输效率，返回指针，返回des指针（自己决定就好）。这就要求des指针不可变，而指向的内容变为src
		3.实现：
				语法约束：由于是基于指针（内存地址），则必须考虑：
						1.传入的指针是否为null。
						2.复制的两块内存是否重叠
						3.des指向的地址是否有足够大的内存空间存放src内存。
				功能约束：
						1.注意是拷贝src地址开始至(包括)首个结束字符'\0'这一段内存。
				实现约束：
						0.通过assert()处理传入指针为null的异常。
						1.拷贝的方式是逐个字节的，通过*p++=实现。
						2.通过strlen（以首个'\0'结束但不包括结束字符）实现计算内存大小，区别于sizeof（实际分配的内存，包括'\0'）
	4.使用分析：使用要注意该函数的具体实现，以避免发生错误。

		错误1.
			void test1()
			{
　			 char string[10];
　			 char* str1 = "0123456789";
　			 strcpy( string, str1 );//des指向内存只有10，实际复制src内容大小为11（包括‘\0’）
			}
		错误2.

			void test2()
			{
		　		char string[10], str1[10];
		 　		int i;
		  　	   for(i=0; i<10; i++)
		   　		{
			　　	  str1[i] = 'a';//src没有结束字符‘\0’，导致strcpy复制时，长度不确定。
			  　	}
			   　strcpy( string, str1 );
					
			}
		错误3.

			void test3(char* str1)
			{
		　	  char string[10];
		 　	  if( strlen( str1 ) <= 10 )
				{
		   　　	 strcpy( string, str1 );//strlen所求长度是不包括结束字符‘\0’，导致导致strcpy复制时，des长度不够
				 }
			 }
*/
#include<iostream>
#include<assert.h>
using namespace std;
char* Mystrcpy(char*des, const char* src)
{
	assert((des&&src) != 0);//如果不都为非NULL则，先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行。
	char* dest = des;//保留des的副本，作为返回值
	while ((*dest++ = *src++) != '\0');//*src先作为赋值运算的右值，*dest作为左值，src再加1，接着dest再加1，赋值运算的结果参与!=运算，
	return des;
}

int main()
{
	char src1[10] = "12345";
	char *src2 = "12345";
	char des1[10]="00000000";
	char *des2 = des1;
	//src分别为字符指针和字符数组，des分别为字符指针和字符数组
	Mystrcpy(des1,src1);
	cout << des1 << endl;

	Mystrcpy(des2, src1);
	cout << des2 << endl;

	Mystrcpy(des1, src2);
	cout << des1 << endl;

	Mystrcpy(des2, src2);
	cout << des1 << endl;
	

	return 0;
}
