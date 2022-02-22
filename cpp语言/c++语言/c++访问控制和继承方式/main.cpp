/*
# public:
    > 类成员的访问控制：
        × public成员可以被类所有的成员(类内)访问。
        × 类的实例(类外)可以访问该pubic成员
	> 继承为public方式：
        × 基类public--->囊括到派生的public,
		× 基类protected----->囊括到派生的protected
		× 基类private----->根本不囊括到派生类。
		× 派生类的成员可以访问，基类的public和protected，肯定不能访问基类的private
		× 派生类的实例，只能访问基类的public
		×（类外）可以通过派生类的友元函数和友元类访问该public派生类的基类的protected
# protected:
    > 基类成员的访问控制：
        × 同private
	> 继承为protected方式：
        × 基类public--->囊括到派生的protected,
		× 基类protected----->囊括到派生的protected
		× 基类private----->根本不囊括到派生类。
							 
#private:<类访问控制和类继承方式的默认值 >
    > 基类成员的访问控制：
        × private成员可以被类所有的成员(类内)访问.(事实上是所以基类成员可以访问其他
          基类的成员）
		× 类的实例(类外)不可以访问该private成员，只能通过定义在该基类的友元函数
          和友元类访问该private(和protected)
		× private成员和protected成员的区别，体现在继承上，protected被囊括的派生类！
          而private成员就根本不囊括的派生类。
	> 继承为private方式：
        × 即基类public--->囊括到派生的private,
		× 基类protected----->囊括到派生的private
	    × 基类private----->根本不囊括到派生类。
*/


#include<iostream>

using namespace std;
//class Btest
//{
//	friend void fri_Btest_fun();
//	friend class fri_Btest_class;
//private:
//	int priv_i=1;
//	void pri_fun()
//	{
//		cout << "---类的private可以访问protected和public---" << endl;
//		cout << pub_i << endl;
//	}
//	
//protected:
//	int prot_i = 2;
//	void prot_fun()
//	{}
//public:
//	int pub_i = 3;
//	void pub_fun()
//	{
//		cout << ""<< endl;
//	}
//	void pub_fun_()
//	{
//		cout << "---类的实例可以访问该pubic成员---" << endl;
//		cout << "---类的成员可以访问其他成员---" << endl;
//		cout << priv_i << ' ' << prot_i << ' ' << pub_i << endl;
//	}
//
//};
//
//void fri_Btest_fun()
//{
//	cout << "------------测试：使用基类的友元函数访问该基类的private成员和protected成员-------" << endl;
//	Btest x;
//	cout << "---使用基类的友元函数访问该基类的private成员函数和数据成员" << endl;
//	x.pri_fun();
//	cout << x.priv_i;
//	cout << "---使用基类的友元函数访问该基类的protected成员函数和数据成员" << endl;
//	x.prot_fun();
//	cout << x.prot_i;
//	cout << "----------------------------------------------------------------------------------" << endl;
//}
//
//class fri_Btest_class
//{
//public:
//	void fri_Btest_clas()
//	{
//		cout << "------------测试：使用基类的友元类访问该基类的private成员和protected成员-------" << endl;
//		Btest x;
//		cout << "---使用基类的友元类访问该基类的private成员函数和数据成员" << endl;
//		x.pri_fun();
//		cout << x.priv_i;
//		cout << "---使用基类的友元类访问该基类的protected成员函数和数据成员" << endl;
//		x.prot_fun();
//		cout << x.prot_i;
//		cout << "----------------------------------------------------------------------------------" << endl;
//	}
//};
//int main()
//{
//	//测试public成员
//	Btest x;
//	x.pub_fun_();
//	//测试protected成员
//	fri_Btest_fun();
//	//测试private成员
//	fri_Btest_class y;
//	y.fri_Btest_clas();
//	system("pause");
//}
class Btest
{
	friend void fri_Btest_fun();
	friend class fri_Btest_class;
private:
	int priv_i = 1;
	void pri_fun()
	{
		cout << "---类的private可以访问protected和public---" << endl;
		cout << pub_i << endl;
	}

protected:
	int prot_i = 2;
	void prot_fun()
	{}
public:
	int pub_i = 3;
	void pub_fun()
	{
		cout << "" << endl;
	}
	void pub_fun_()
	{
		cout << "---类的实例可以访问该pubic成员---" << endl;
		cout << "---类的成员可以访问其他成员---" << endl;
		cout << priv_i << ' ' << prot_i << ' ' << pub_i << endl;
	}

};

void fri_Btest_fun()
{
	cout << "------------测试：使用基类的友元函数访问该基类的private成员和protected成员-------" << endl;
	Btest x;
	cout << "---使用基类的友元函数访问该基类的private成员函数和数据成员" << endl;
	x.pri_fun();
	cout << x.priv_i;
	cout << "---使用基类的友元函数访问该基类的protected成员函数和数据成员" << endl;
	x.prot_fun();
	cout << x.prot_i;
	cout << "----------------------------------------------------------------------------------" << endl;
}

class fri_Btest_class:protected Btest
{
	friend class fri_Btest_;
public:
	void fri_Btest_clas()
	{
		
	}
};
class fri_Btest_
	{
	public:
		void fri_Btest_c()
		{
			fri_Btest_class x;
			x.prot_fun();
			x.pub_fun_();
		}
};
int main()
{
	////测试public成员
	//Btest x;
	//x.pub_fun_();
	////测试protected成员
	//fri_Btest_fun();
	////测试private成员
	//fri_Btest_class y;
	//y.fri_Btest_clas();
	//system("pause");
	fri_Btest_ x;
	x.fri_Btest_c();
	system("pause");
}
