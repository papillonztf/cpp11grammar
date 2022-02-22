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
###############c++11RTTI--dynamic_cast<>()和typeid()#################
#静态类型与动态类型：
  静态类型:编译时确认的，是其定义的类型
  动态类型："运行时"确认的，是其实际的类型。
  需要注意的是:
  a.只有针对存在至少一个虚函数的类类型指针/引用,其动态类型可能与静态类型不一致，
    取决于其绑定的对象类型
  b.其他一致的情形，动态类型也是编译期就确认了。
  //规则1：只有类类型指针变量的动态类型才可能不一致
    int i =1 ;//静态-动态类型一致均是int
    int* ip =&i ;//静态-动态类型一致均是int*
    Test test; //一致，均是Test类
    
  //规则2：对规则1进一步约束，只有针对存在至少一个虚函数的类类型指针，其动态类型与静态类型不一致。
    Derived d;
    Base* bp = &d; //1' 如果基类一个虚函数都没有，即使这个基类指针指向派生类
                   //对象，bp、*bp动态类型和静态类型一致
                  //2’ 如果基类存在至少一个虚函数，因为这个基类指针
                  //指向派生类对象，bp动态类型是Derived*
                  //如果此时指向基类对象，则bp的动态类型是Derived

#RTTI运行时类型识别
  正如上所提到的"只有针对至少存在一个虚函数的类类的的指针或引用，其动态类型才可能与静态类型不同"
  "./c++类型转换/src/main.cpp"中测试了继承中虚函数有无与动态类型的关系的5个测试用例,验证了这一点。
> 什么是(什么时候进行)运行时类型识别？
  在/c++类型转换/src/main.cpp 中，我们知道了类类型指针转换规则:
  a.派生类指针可以隐性转换为基类指针(无论基类是否至少有一个虚函数)
  b.基类指针可以显式转换为基类指针
    (为了保证转换后类型安全避免运行时错误，则应保证转换后的类型和指针指向的类型一样）
  c.非继承类之间不可以转换(即显式转换也不可以)。
  !!!只有针对至少存在一个虚函数的类类的的指针或引用，其动态类型才可能与静态类型不同.
  这时如果要确定类指针的动态类型，就必须调用dynamic_cast和typeid运算符运行时根据编译期生成的对象的
  typeinfo*_ZTI****信息(存放在elf文件的.data.rel.ro节)确定类指针的动态类型。
  以下情况，动态类型在编译就可以确定，且与静态类型一致：
    1.类指针没有虚函数，此时该类指针的动态类型就是其静态类型
        Derived d;
        Base* bp =&d; //此时假如基类没有虚函数。即使基类指针指向派生类对象，其动态类型也是Base*
    2.非类的指针和非指针引用对象：
      Base a;//静态-动态类型一致，都是Base类型
      int* i;//同上
> 用途：
  a.诸如根据动态类型判断派生类指针转换为基类指针(下行转换)是否安全
  b.多态中根据基类指针的动态类型进行分发操作。
  

     
>dynamic_cast<T*|T&|T&&>:保证基类指针或引用向下转换为派生类指针或引用的类型安全
 a.问题：
  上述提到向下转换，是可以通过显式转换进行的。
  但是我们得人为保证转换后类型和指针所指类型一致，否则会发生运行时错误。
 b.dynamic_cast的作用：
   dynamic_cast可以运行时进行类型识别，获取类指针(可为空指针)动态类型，并检查和转换的类型是否一致
   如果一致，则转换成功。(换句话说dynamic_cast会进行运行时类型检查)
   否则失败，针对指针转换失败返回0,引用会抛出bad_cast异常
 c.限制：
    1.只适用于类指针或引用
    2.类指针或引用对应的类应该至少有一个虚函数。
      (因为不含虚函数的类型的指针的动态类型是确定的,与其静态类型一致,那向下转换没意义，肯定是错的)
 eg:
    if(Derived* dp = dynamic_cast<Derived*>(bp))
    {//成功向下转换为派生类指针

        //使用派生类指针dp，访问派生类对象的非虚函数成员
    
    }
    else{
        //转换失败
        //使用基类指针bp，访问基类对象的成员
    }
     void f(const Base& b){
        try{
          Derived* dp = dynamic_cast<Derived*>(bp));
          //成功。。。
        catch(bad_cast){
          //失败。。
        }
        
     }
> typeid(表达式/对象)
   获取表达式或对象的类型：
   a.一般规则
    const int a = 1;
    typeid(b).name();//4base，就是静态类型

    Base b;
    typeid(a).name();//int,去掉顶层const

    const int& cir = &a;
    typeid(cir).name;//const int ，返回所引对象的类型(去掉引用&)
   
    int arry[3] = {1,2,3};
    typeid(arry).name;//int [3],返回数组类型(不会对数组名进行隐式转换为指针类型)
    
    int (*arrptr)[3] = &arry;
    typeid(arrptr).name();//int (*)[3],返回数组指针类型
  b.对类类型指针的规则：
      Derived* dp = new Derived;
      Base* bp =dp;     
      1'typeid(类指针)，返回编译期确定的静态类型，*类
      if(typeid(bp) == typeid(Derived)){
          //这里永远不会执行--typeid(指针)返回的是指针的静态类型Base*
      }
      2'typeid(*类指针)，如果该类没有虚函数则返回编译期确定的静态类型:类。否则返回其运行时动态类型
      if(typeid(*bp) == typeid(*dp)){
          //如果bp指针指向类类型有至少一个虚函数，则typeid(*bp)是运行时确定的动态类型Derived。
      
      }
      else{
          //如果bp指针指向类类型没有虚函数，则typeid(*bp)是编译器确定的静态类型Base。
      
      }
      

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
   Base b;
   //const char* cpb = typeid(b).name();
   Derived d;
   //const char* cpd = typeid(d).name();
   Base1 b1;
   //const char* cpb1 = typeid(b1).name();
   Derived1 d1;
   //const char* cpd1 = typeid(d1).name();

   Derived2 d2;
   Derived3 d3;
   Derived4 d4;
   return 0;
}
