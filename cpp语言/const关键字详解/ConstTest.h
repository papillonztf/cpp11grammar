//头文件声明变量，函数，类；源文件进行相应的定义。这样防止连接阶段的重定义。


#ifndef _CONSTTEST_H_//条件编译，避免同一文件的头文件重编译，这样防止编译阶段的重定义
#define _CONSTTEST_H_

//const 用于面对过程程序设计时，声明。
//1.用于变量
extern int iGlobVar;//头文件中应变量声明，不应变量定义
extern const int CONSTINT = 1;
extern const int* CONSTINTPRT = &iGlobVar;
extern int * const INTCONSTPRT = &iGlobVar;
extern const int*const CONSTINTCONSTPRT = &iGlobVar;
extern const int & CONSTINTREF = iGlobVar;
//2.用于函数
void Fun1(const int i);//形参i在该函数内不可修改
const int Fun2();//该函数不能做左值
//3.用于函数重载。由于其参数不同，所以可以函数重载
void Fun(int i);
void Fun(const int i);

//const 用于面对对象程序设计时，声明。
class ConstTest//类的声明（一般变量定义和函数的声明，函数的定义在源文件中进行，）
{
//1.用于数据成员.必须在构造函数初始化列表进行初始化。而不能在构造函数体内初始化。
private:
	int m_Intvar;
	const int m_ConstIntVar;
	
public:
	//类一般的格式：包含构造函数，析构函数，复制构造函数。详见类的四大成员函数详解。

	ConstTest(int i ,int j);//构造函数用于给（除静态数据成员之外）数据数据成员初始化。
	//~StatTest();//释放变量所占内存
	//StatTest(const StatTest & original);//用于
	//const StatTest & operator =(const StatTest & rightValue);//重载运算符

	//操作函数
//2.用于成员函数
	void m_Fun();
	void m_FunConst() const; //该成员函数了不可有修改任何数据成员，也不可访问非const函数成员
//3.用于成员函数重载。
	void m_OverrideFun();
	void m_OverrideFun() const;
};

extern ConstTest Object;

#endif