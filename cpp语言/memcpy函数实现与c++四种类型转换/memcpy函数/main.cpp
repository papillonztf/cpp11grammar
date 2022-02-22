/*
指针的反向传递和指针值不修改
		指针的反向传递：通过指针做形参，在被调用函数内，做形参指向区域进行修改，将会反向传递到实参所指的区域。
		指针值不变：通过局部指针变量保存形参指针的值，通过该局部变量进行运输，保证反向传递，又保证了形参指针不变，可以return 形参。
字符数组：
		1可以不要初始化，但此时必须指定数组的大小，且内容不确定。
		2.字符数组存储用栈
		3.字符数组名a，是char*类型指向该数组的地址，也是其首元素的地址，
		4.cout<<a,输出以/0结束的数组，cout<<(void*)a,表示输出a的值，*a表示第一个元素的值，sizeof（a）表示数组的size位10，strlen（a）表示数组的以‘/0’结尾的实际长度
字符指针：des不能是字符指针因为，des指向字符串不能进行修改！！！重叠时，src也不能是字符指针。！！---》所以只能src字符指针或（重叠时必须是）字符数组，des必须是字符数组
		1.必须初始化，因为不知道字符指针指向的是字符还是字符串.
		2.字符指针指向的字符串是放在静态存储区
		3.字符指针p，表示的是一个指针
		4.cout<<p,输出以/0结束的数组，cout<<(void*)p,表示输出p的值，*p表示第一个元素的值，sizeof（p）表示指针的size为4，strlen（p）表示指向字符串的以‘/0’结尾的实际长度
常量指针，常量变量：
		1.常量变量的值是不能对该常量指针进行赋值等修改操作的，
		2.常量指针所指的值是不能对该常量指针进行赋值等修改的，但是其他非常量指针也指向同一区域，是可以修改的。
const_cast,static_cast,dynamic_cast:
	1.const_cast:，唯一且只能用来去掉类型（常量指针、常量引用）的const或volatile属性，并任指向原来的对象。
			如const int i=1；const int * p=&i;int * p0=const_cast<int*>p；
			  const char c='1'；const char & r=c;char &r0= const_cast<char&>r;
	2.static_cast:编译时检查，主要用于安全地非多态的转换，但没有运行时类型检查来保证转换的安全性。
				a.基本类型转换；如char-->int；int-->enum;这种转换安全靠开发人员保证
				b.void指针(引用)转为任意类型指针（引用）:如void*-->int*,如memcpy（）中对定义为void*未知形参转换为char*。
				c.任意类型转为void类型：如int*-->void*
				d.子类和父类转发：上行转换（子类—>父类）安全；下行转换（父类-->子类），转换失败，任能编译通过，但不安全，；因此，当涉及子类与父类转换最好用dynamic_cast
				e.非const转为cosnt类型：int i=1；const int j=static_cast<const int *>i;
	3.dynamic_cast:运行时检查（用于传入类型不知是子类还是父类），主要用于安全地多态的转换，但耗时较高，使性能下降。
					使用时序满足条件：子类父类之间必须有虚函数。
					1.安全地子类和父类转换：上行转换（子类—>父类）安全；下行转换（父类-->子类），转换失败，返回NULL(若是引用则抛出异常)，
						可使用if else进行选择，所以安全。
					2.安全地同父类的不同子类之间转换：因为转换失败，返回NULL.
memcpy：
	1.函数原型：void* memcpy(void* des,void*src,size_t n)
	2.功能分析：针对内存，无类型的，实现将src的n字节覆盖性拷贝到des的前n字节，
		1.实现将src的n字节覆盖性拷贝到des的前n字节，
		2.要求des有足够的n个字节的空间，以及des指向的初始内容，否则会乱码或得不到想要的结果。
		3.不污染形参des值，因为通过指针反向传递，且返回值为des。
		4.在非重叠情况，不污染src指向的区域值。
	3.实现分析：
		1.非常量指针传递，可以引起反向值传递；并且，为了返回原指针，就可以使用局部变量保存指针，对该局部变量进行操作就可以实现对原始指针指向的内存操作。
		0.void*--->char*,使用（char*）或static_cast<char*>且申请src--》
		1.考虑des==null||src==null
		2.考虑des==src
		3.考虑内存重叠，des>src&&des<src+n
		4.考虑src指针必须不修改以及src指向的内存值在非内存重叠时必须不修改
	4.使用分析：
		1.src是字符指针或（重叠时必须是）字符数组，des必须是字符数组
		2.考虑n值,des的长度，des和src原始内容！！！
		*/
	
#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
using namespace std;

void* mymemcpy(void *des,const void * src,size_t n)//在非重叠情况，不污染src指向的区域值。
{
	//void*-->char*,且另用新变量保存。
	char* pdes = static_cast<char *>(des);//在非重叠情况，不污染src指向的区域值。
	const char* psrc = static_cast<const char *>(src);
	//判断是否为空和是否相同。
	if (pdes == NULL || psrc == NULL)
	{
		return des;
	}
	if (pdes == psrc)
	{
		return des;
	}
	//判断是否内存重叠，是的话，进行后向前复制，不是的话，直接前向后复制
	if ((pdes>psrc)&&(pdes<(psrc+n)))
	{
		psrc = psrc + n - 1;
		pdes = pdes + n - 1;
		while (n--)
		{
			*pdes-- = *psrc--;//先调用*p参与=运算。再-1；
							//pdes,和des是指向同一个区域的不同指针，pdes自身值变化，并且指向的区域也通过pdes发生变化
		}
	}
	else
	{
		while (n--)
		{
			*pdes++ = *psrc++;//先调用*p参与=运算。再-1；
		}
	}
	return des;//des自身值不变，而指向内存的值反向传递了。

}

int main()
{
	//确定des和src的类型，是字符数组还是字符指针还是string类。
	char des[15] = {""};//默认15个'/0'
	char * src="我爱你中国";//字符指针默认就是const char *类型！！！

	//des不能是字符指针，因为字符指针指向的指向的区域是常量字符串不能修改。
		//const char src[15] = { "1234512345" };//默认15个'/0'
		//char * des = "我爱你中国";

	//字符数组与字符指针
	/*cout <<p1<<" "<< sizeof(*p1)<<endl;
	cout <<(void*)p2 << "   " << sizeof(p2)<<" "<<strlen(p2)<<endl;
	cout << *p1 << " " << sizeof(p1) << ' '<<strlen(p1);*/

	//const变量，以及const指针，都不能对齐指向内容进行赋值等修改。
	int a= 10;
	const int *i=&a;
	int *j = &a;
	*j = 100;

	//size_t,就是unsigned int，4字节。
	cout << sizeof(size_t)<<endl;

	//memcpy:1.des和src不重叠情况
	cout << src << endl;
	cout << des << endl;
	memcpy(des,src,strlen(src));//
	cout << src<< endl;
	cout << des << endl;
	cout << strlen(des) << endl;

	//memcpy:2.des和src重叠情况。des在src后面。
	//memcpy(src+2, src, strlen(src));//错误，此时src+2所指区域，长度不够strlen(src)
	memcpy(src + 2, src, strlen(src)-2);
	cout << src << endl;
	cout << des << endl;
	cout << strlen(des) << endl;
	system("pause");
	return 0;
}