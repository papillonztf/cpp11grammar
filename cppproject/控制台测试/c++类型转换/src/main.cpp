/*
 类型安全即内存安全?
 两个层次类型安全：
    语言层面：
        语言是否允许编译层面的类型转换
        如c、c++ 是弱类型，允许隐性类型转换
        如java是强类型，不允许隐性类型转换。在没强制类型转换时，是类型安全的
    代码层面：
        根据语言提供的类型转换规则，进行有把握的类型转换
#编译器的一些检查：
  a.提示overflow警告:
    char c1 = 256;//编译器提示overflow警告--因为能编译其确定其值
    char c2 = 255+1;//不提示--运行时才确定c2等于256
  b.提示cant convert和invalid convert 错误
    char× cp1 = ip;//提示cant convert int* to char*错误---需强制转换
    char* cp2 = vp;//提示invalid convert void* to char*错误---需强制转换
  d.编译器不提是数组访问越界
    int iarry[3] = {1,2,3};
    int i1 = iarry[3];//不提示越界
    int i2 = iarry[2+1];//不提示越界
    
    
#内置类型：算术类型、void类型的转换
gcc编译给signed char sch =128;溢出警告;但signed char sch=127;sch++;却不警告。
gcc编译器char实现为unsiged char。
char-->int:补码高位补0-->绝对没问题
int--->char:截取补码的低字节-->当int取值为负或或大于char的最大值255,出问题。
-------
unsigned int<-->int: 2^32-1<-->-1,2^31<-->-2^31,补码一样，但解释不一样
---------------
unsigned int --->short int:截取补码低字节-->unsigned int取值大于short的最大值，出问题
short int---->unsigned int:补码高位补符号位-->short取值为负数，出问题
-------------
int-->float:int值加.000000.但int较大时，转换出问题;
float-->int:取float值整数部分
int-->double:所有的int都可以转换成int.0000
double-->int:所有的double值都能正确的截取整数部分。
----------
复合类型：指针、引用、const的转换
总的来说：
a.指针可有底层const和顶层const;引用只有底层const
  1.底层const不可以通过(隐式转换)删除
    int i = 1;
    const int* const ip1 = &i ;//正确。
    int* ip2 = ip1;//编译错误，删除了底层const。
    //
    const int ci = 1;//顶层const
    int i1 = ci;//正确，可以删除顶层const
    //
    const int& cir = &ci;//正确
    int& ir = ci;//编译错误，删除了底层const，绑定非常量对象的引用绑定了常量对象
    int* ip3 = &ci;//编译错误，删除了底层const,指向非常量对象的指针指向常量对象
b.非void指针类型的转换：
  1.非void指针转换需要强制转换。
    char× cp = ip;//编译错误-can't convert
    char* cp = (char*)ip;//正确
c.void指针：
  1.任意指向非常量对象的指针可隐式转换为void×;任意指向任意对象的指针可隐式转换为const void×
  int i = 1;
  int* ip =&i;
  void* vp = ip;//正确
  2.void指针转换为非void指针需强制转换
  char ch = 'a';
  void* vp = &ch;
  char* cp = vp;//编译错误。invalid convert
  char* cp = (char*)vp;//正确.为了避免出现运行未定义，
                       //应保证转换后的类型(char*)就是指针(vp)所指类型(char*)
  3.void指针使用非常有限，一般用于函数参数、函数返回值、指针比较、赋给另一个void指针。
    因为void指针指向的对象类型不知道，因此无法*vp获取void指针指向的对象(vp->自然也不行)、也
    无法对void指针进行++vp等地址运算。
    int i = 1;
    int* ip = &i;
    void* vp =ip;
    char* cp = (char*)vp;//虽然编译通过，但void指针前后指向的对象类型不一致。应避免这种转换。
d.数组名可以隐性转换为指针类型。
  int iarr[3] = {1,2,3};
  int* ip = iarr;//数组名隐式转换为int指针。ip指向一维数组的首元素的地址。
  --
  函数名隐形转换为函数指针
  ------
  //以下情况，数组名不会隐式转换为指针类型
  1.数组名作decltype类型指示符的参数。
    decltype(iarr) iarry1;//iarry1是'int [3]'类型，是个3个元素的一维数组。
    decltype(ip)  ip1;    //是int*类型
  2.数组名作sizeof运算符的参数
    sizeof(iarr);//求得是iarr数组的长度3×4=12，
    sizeof(ip);  //求得是int指针长度8,
  3.数组名作&运算符的参数
    int (*p)[3] = &iarr;//p是数组指针'int (*)[3]'类型,p++增加一个数组长度，*p是数组首元素的地址。
    int*p = &iarr;//编译错误，cant convert int（*)[3] to int*
  4.数组名作typeid运算符的参数
    const char*p1 = typeid(iarr).name();//类型为"A3_i"即"int [3]"数组类型
    const char*p2 = typeid(ip).name();//类型为"int*"
  5.数组名用来初始化数组引用
    int (&rarry)[3] = iarry ;//引用绑定的是数组而不是int指针
    int* &rip = ip;//引用绑定的是int指针ip
------
类类型定义的转换：
  1.字符串常量隐式转换为string类型：
    string str = "hello";// 自动调用string类定义const char×构造函数。字符串常量(const char*)
    str = "hi";//自动调用string类定义的const char×赋值函数。
  2.while(cin>>str) //最后一次输入成功，返回1,输入失败返回0.
--------
类类型对象及其指针、引用的转换：
  a.子类对象可以隐式转换为父类对象:!!前提是子类是public继承父类!!
  Derived d;  
  Base b = d;//正确--只用了子类对象d的父类部分--本质基于父类引用可指向子类对象
  b.父类对象不可转换为子类对象
  Derived d1 = b;//编译错误。父类对象不可显式或隐式转换为子类对象
  Derived d2 = (derived)b;//编译错误同上。但是，如果子类定义了以const& Base为参数的复制构造则能
  c.子类指针可隐式转换为父类指针;子类的对象可隐式转换为父类引用。
  Derived d;
  Base* bp = &d; //正确。bp的静态类型是Base*,动态类型是Deived*。
  Base& br = d;//正确。br的静态类型是Base&,动态类型是Derived。
  //set print object on ”设为on，才能通过p bp ,p *bp打印父类指针bp和*bp的实际类型(动态类型)
    1.若父类一个虚函数都没有,指向子类对象的父类指针bp的静态类型和动态类型都是父类指针类型(Base*)
      也就是说父类指针bp实际类型(动态类型)就是Base*类型。
      也同时表明*bp是Base类对象。
      也就是说bp->虚函数的调用是静态绑定，编译期就确定是Base的该虚函数。
      1.1如果子类也一个虚函数没有.
          p bp "动态类型是Base*,即便绑定的是子类对象
          p *bp "动态类型是Base
          那此时子类对象d也就没有虚函数表指针，此时p bp打印的地址和p &d打印的一样
      1.2如果子类有至少一个虚函数
          p bp "动态类型是Base*,即便绑定的是子类对象
          p *bp "动态类型是Base
          那此时，子类对象d有虚函数表指针，但是p bp打印的地址是&d+8(注意Base*bp =&d)
    2.若父类有至少一个虚函数，无论子类是否有相应的虚函数overide，还是子类压根就没虚函数，
      父类指针bp的静态类型是Base*,而动态类型则在运行时确定(如果指向子类对象，那就是Derived*类型)
      也就是说bp的实际类型(动态类型)是运行时确定的.(如果指向子类对象，那就是Derived*类型)
      也同时说明*bp的实际类型(动态类型)是运行时确定的(如果指向子类对象，那就是Derived*类型)
      但是也不能确定bp->虚函数的调用是动态绑定，只有继承时有虚函数override，对这个虚函数的绑定
      才会动态绑定。
       2.1 如果父类有虚函数、而子类一个虚函数都没有
           p bp     "动态类型是Derived*
           p *bp    "动态类型是Derived
           没有虚函数的调用会进行动态绑定
       2.2 如果父类有虚函数、子类也有虚函数，但没有虚函数override
           p bp     "动--D
           p *bp    "动--D
           没有虚函数的调用会进行动态绑定
       2.3 如果父类有虚函数、而子类也有虚函数，并且有虚函数override
           p bp     "动--D
           p *bp    "动--D
           只有对继承时override的虚函数的调用才会动态绑定。
  d.父类指针可以显式转换为子类指针--但不建议这么干，除非能保证转换后所得类型就是指针所指类型
  Base b;
  Derived d;
  Base* bpb = &b;
  Base* bpd = &d;
  Derived* dp = (Derived*)bpb;//编译正确，但可能发生运行时错误
  Derived* dp =(Derived*)bpd;//编译正确.这个保证转换后所得类型就是指针所指类型。
  e:非继承类指针不可以相互转换：
     Base1 b1;
     Base1* b1p =&b1;
     Base2* b2p1 = b1p;//编译错误。不能转换
     Base2* b2p2 = (Base1*) b1p;//编译错误。不能转换


# c++提供四个类型(显式)转换运算符:

  >dynamic_cast<T*|T&|T&&> 

 */
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

class Base{
    public:
        virtual int get(){ return ibase;}
    private:
        int ibase;
};
class Base1{
    public:
        //virtual int get(){ return ibase;}
    private:
        int ibase;
};
class Derived:public Base{ //子类和父类有虚函数override
    public:
        virtual int get(){return iderived;}
    private:
        int iderived;
};
class Derived1:public Base1{//子类和父类没有虚函数override且均也都没有虚函数
    public:
        int get(){return iderived;}
    private:
        int iderived;
};
class Derived2:public Base{//子类和父类没有虚函数override且父类有而子类没有虚函数
    public:
        int d2get(){return iderived;}
    private:
        int iderived;
};
class Derived3:public Base1{//子类和父类没有虚函数overide且父类没有而子类有虚函数
    public:
        virtual int d3get(){return iderived;}
    private:
        int iderived;
};

class Derived4:public Base{//子类和父类没有虚函数overide且也都有虚函数
    public:
        virtual int d4get(){return iderived;}
    private:
        int iderived;
};


int main(){
   
   char ch1 = 'a';
   int  i1;
   i1 = ch1;

   int i2 = 256;
   char ch2 = i2;
   int i3 = -1;
   char ch3 = i3;
   int i4 = 257;
   char ch4;
   ch4 = i4;
   int i5 = -2;
   char ch5 = i5;
    float f1 =1.1;
    int   if1 =f1;
    signed char sch1 = 128;
    signed char sch2 =256;
    signed char sch3=257;
    signed char sch4 =255;
    sch4++;
    //
    int i =1;
    int* ip = &i;
    //char* cp1 = ip; //编译错误-不可隐式地指针转换
    char* cp2 = (char*)ip;
    //char* cp3 =ip;//同上
    
    void* vp1 = ip;
    void* vp2 = (void*)ip;
    //char* cp3 = vp1;
    //char* cp4 = vp2;
    char* cp3 = (char*)vp1;
    char* cp4 = (char*)vp2;
    //
    int iarry[] = {1,2,3};
    int* ip2 = iarry;
    // int* p  = &iarry; //编译错误，cant convert int (*)[3] to int*
    int (*p)[3] = &iarry;//正确。数组指针p
    ip2++;//+1个int长度
    p++;//+1个数组长度
    decltype(iarry) iarry1;
    int size1 = sizeof(iarry1);
    decltype(ip2)   ip3;
    int size2 =sizeof(ip3);
    const char* cptype = typeid(iarry).name();
    string str = typeid(iarry).name();
    //
    char* cp00 = "nihao";
    char c00 = 'c';
    char* cp01 = &c00;
    const char* ccp00 = typeid(cp00).name();//"Pc"--char*
    const char* ccp01 = typeid(cp01).name();//同上
    int i00 = iarry[3];//编译器检查不出数组越界
    int i01 = iarry[sizeof(iarry)];//同上
    int i02 = iarry[2+1];//同上
    //类:
    //Base-Derived之间有虚函数override
    Base b1;
    //Derived d1 = b;//编译错误
    //Derived d2 = (Derived)b;//编译错误
    //1.1父子类有虚函数override
    Derived d;
    Base* bp = &d;
    //
    Derived* dp = (Derived*)bp;//正确。转换后指针类型与指针指向的类型一致。
    
    Base* bp2 = &b1;
   // Derived* dp2 = bp1; //编译错误。应该显式转换
    Derived* dp2 = (Derived*)bp2;//正确。不建议这么干.类型不一致。

    //2.1父类-子类之间没有虚函数override+也都没虚函数
    Derived1 d11;
    Base1* bp11 =&d11;
    //2.2父类-子类之间没有虚函数override+父类有虚函数而子类没有虚函数
    Derived2 d22;
    Base* bp22 = &d22;
    //2.3父类-子类之间没有虚函数override+父类没有虚函数且子类有虚函数
    Derived3 d33;
    Base1* bp33 = &d33;
    Derived3* dp33 = (Derived3*)bp33;
    //2.4父类-子类之间没有虚函数override+也都有虚函数。
    Derived4 d44;
    Base* bp44 = &d44;
    //非继承类指针转换
    Base bb;
    Base* bbp = &bb;
    //Base1 bb1p = bbp;//编译错误
    //Base1 bb2p = (Base1)bbp;//编译错误
    

    return 0;
}
