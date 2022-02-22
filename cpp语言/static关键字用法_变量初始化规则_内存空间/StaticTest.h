//头文件声明变量，函数，类；源文件进行相应的定义。这样防止连接阶段的重定义。
//extern和static都是声明关键词,作用是声明下这个变量是否在该处可用，因此先static int i或static void fun（）声明后，相应的定义就不用在写上该static关键字
//静态数据成员的定义应该放在类外：为了保证静态数据成员只定义一次。
//静态数据成员的定义必须类外定义并且得放在源文件中定义：若放在头文件的类声明的类外定义，会引起重定义

#ifndef _STATICTEST_H_//条件编译，避免同一文件的头文件重编译，这样防止编译阶段的重定义
#define  _STATICTEST_H_

extern int iGlobVar;//头文件中应变量声明，不应变量定义
//extern static int isStatGlobVar;//static 全局变量，不能再用extern修饰

void TestStatLocVar();//函数声明
static void TestStatFunc();

class StatTest//类的声明（一般变量定义和函数的声明，函数的定义在源文件中进行，）
{
private:
	int iVar;
	static int isVar;
	//static int isVar=0;
public:
	//类一般的格式：包含构造函数，析构函数，复制构造函数。详见类的四大成员函数详解。

	//StatTest();//构造函数用于给（除静态数据成员之外）数据数据成员初始化。
	//~StatTest();//释放变量所占内存
	//StatTest(const StatTest & original);//用于
	//const StatTest & operator =(const StatTest & rightValue);//重载运算符

	//操作函数
	void Fun();
	static void StatFun();
};

//int StatTest::isVar = 1;//静态数据成员

#endif