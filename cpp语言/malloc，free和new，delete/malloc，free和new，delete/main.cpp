///*
//	malloc,free��new��delete
//		ʹ���ϣ�
//				0.������malloc,free�ǿ⺯��,�����������ͣ������Զ�������ʱ��malloc�޷����ù��칹�캯����free�޷���������������������ò�Ҫ�����Զ������͡�
//						��Ҳ���ԣ�����һ���޷���ɹ��캯��������������
//				1.��new��delete������ܵ��ù��캯�������������������ֿ������Զ������ͣ����࣬��
//				--------------------------------------------------------------------
//				2.malloc���ٿռ����͵Ĵ�С��Ҫ�ֶ����㣬��new���Զ�����.(int*)malloc(sizeof(int))---int* p_new = new int
//				3.malloc�ķ���ֵ��void*������ǿ��ת��Ϊ��Ӧ���ͣ���new��ֱ�ӷ��ض�Ӧ���͵�ָ��
//				4.malloc���ٿռ䷵��ʧ�ܣ�����NULL����new���ڴ濪��ʧ�ܣ�����׳�bac_allocֱ���˳���
//				5.�����ͷż����ռ䣬freeֻ����ָ�룬��delete�ͷŶ������ʱ�������[].free(p_mallocs)---delete []p_news;
//		�ڲ�ʵ�֣�
//				1.malloc���ܵ��ù��캯����free������������������new�����˹��캯����delete�����������������ǻ���malloc��freeʵ�ֵġ�
//				---------------------------------------------------------------------
//				2.delete��delete[],deleteֻ������һ������������delete[]���鿴�ڴ�Ķ�����������ö����������
//				3.��ˣ������������ͣ����ʱ��delete��delete[]���һ�������Զ������ͣ����ʱ��deleteֻ������һ�������������û���ͷţ�����ڴ�й¶
//				----------------------------------------------------------
//				4.malloc�ģ�ǰ���ǣ�malloc�����������ͣ���delete�ͷ��ǿ��Եġ�
//				--------------------------------------------
//				5.new��ǰ���ǣ�new�������ͣ���free�����ͷš�
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
//	//��������������,malloc��free
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
//	//delete p_malloc;//��ȷ
//	//delete p_mallocs;//��ȷ
//	//delete []p_mallocs;//��ȷ
//	p_malloc = NULL;
//	p_mallocs = NULL;
//
//
//	//��������������,new,delete
//	int* p_new = new int;
//	int* p_news = new int[4];
//	delete p_new;
//	delete []p_news;
//	//delete p_news;//ֻ��new��������ʱ����ȷ��
//	//free(p_new);
//	//free(p_news);//new�ģ�ǰ���ǣ�new�������ͣ���free�����ͷ�
//	
//	p_new = NULL;
//	p_news = NULL;
//
//	//���Զ�����������,malloc��free.���ɵ��ù��캯�����������������Բ�Ҫ�������Զ�������
//	//testclass* class_malloc = (testclass*)malloc(sizeof(testclass));
//	//free(class_malloc);
//
//
//	//���Զ�����������,new,delete
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
		cout<< "�ں�";
	}
};
int main()
{
	A *p = 0;
	p->print();
	system("pause");
}