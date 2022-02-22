///*
//	malloc,free与new，delete
//		使用上：
//				0.！！！malloc,free是库函数,用于内置类型，用于自定义类型时，malloc无法调用构造构造函数，free无法调用析构函数，所以最好不要用于自定义类型。
//						用也可以，就是一定无法完成构造函数和析构函数。
//				1.而new，delete运算符能调用构造函数和析构函数，所以又可用于自定义类型（如类，）
//				--------------------------------------------------------------------
//				2.malloc开辟空间类型的大小需要手动计算，而new是自动计算.(int*)malloc(sizeof(int))---int* p_new = new int
//				3.malloc的返回值是void*，必须强制转换为对应类型，而new是直接返回对应类型的指针
//				4.malloc开辟空间返回失败，返回NULL，而new是内存开辟失败，则会抛出bac_alloc直接退出。
//				5.无论释放几个空间，free只传递指针，而delete释放多个对象时必须加上[].free(p_mallocs)---delete []p_news;
//		内部实现：
//				1.malloc不能调用构造函数，free不调用析构函数，而new调用了构造函数，delete调用了析构函数，是基于malloc，free实现的。
//				---------------------------------------------------------------------
//				2.delete与delete[],delete只调用了一次析构函数，delete[]则会查看内存的对象个数，调用多次析构函数
//				3.因此，当是内置类型，多个时，delete和delete[]结果一样，而自定义类型，多个时，delete只析构了一个对象，其余对象没有释放！造成内存泄露
//				----------------------------------------------------------
//				4.malloc的（前提是，malloc申请内置类型），delete释放是可以的。
//				--------------------------------------------
//				5.new（前提是，new内置类型），free可以释放。
//				----------------------------------------------------------
//*/
//#include<iostream>
//#include<stdlib.h>
//#include <crtdbg.h>
//using namespace std;
//class testclass
//{
//private:
//	int i;
//	char b;
////public:
////	testclass() :i(1), b('a'){}
//};
//int main()
//{
//	//对内置数据类型,malloc，free
//	//_CrtSetBreakAlloc(158);
//	int* p_malloc = (int*)malloc(sizeof(int));
//	if (p_malloc==NULL)
//	{
//		exit(1);
//	}
//	int* p_mallocs = (int*)malloc(sizeof(int)*4);
//	if (p_mallocs == NULL)
//	{
//		exit(1);
//	}
//	free(p_mallocs);
//	free(p_malloc);
//	
//	//delete p_malloc;//正确
//	//delete p_mallocs;//正确
//	//delete []p_mallocs;//正确
//	p_malloc = NULL;
//	p_mallocs = NULL;
//
//
//	//对内置数据类型,new,delete
//	int* p_new = new int;
//	int* p_news = new int[4];
//	delete p_new;
//	delete []p_news;
//	//delete p_news;//只有new内置类型时，正确。
//	//free(p_new);
//	//free(p_news);//new的（前提是，new内置类型），free可以释放
//	
//	p_new = NULL;
//	p_news = NULL;
//
//	//对自定义数据类型,malloc，free.不可调用构造函数和析构函数，所以不要用用于自定义类型
//	//testclass* class_malloc = (testclass*)malloc(sizeof(testclass));
//	//free(class_malloc);
//
//
//	//对自定义数据类型,new,delete
//	testclass* class_new= new testclass;
//	testclass* class_news = new testclass[4];
//	delete class_new;
//	delete[]class_news;
//	_CrtDumpMemoryLeaks();
//	
//}

#include<iostream>
using namespace std;
class A
{
public:
	void print()
	{
		cout<< "内核";
	}
};
int main()
{
	A *p = 0;
	p->print();
	system("pause");
}