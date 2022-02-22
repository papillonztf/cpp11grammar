/*
# 子类的哪些成员不被继承:
   默认构造(无参的构造);复制构造;析构;赋值函数-------即所有的默认合成成员函数(4+2)
   如果子类没
# 四大合成函数
    > 构造函数：
        × 构造函数不可为虚函数：
            因为虚函数存放在vtable虚函数表，而虚函数表是存放在类实例--
            对象的内存空间中构造函数若为虚函数，则需要虚函数表，而此时
            构造函数还未调用，导致对象未被创建，这就导致前后矛盾。
            此外，虚函数往往用于多态(指向子类对象的父类指针)，构造函数只是
            用于对象创建根本不会由父类指针取调用，因此构造函数为虚函数
            毫无意义。
        × 子类的父类、类类型的数据成员必须在初始化列表中调用其自身提供
          的(默认或含参)构造函数进行初始化.
          (若为显式在初始化列表调用子类的父类、类类型数据成员的构造函数，则
          会自动调用其对应默认构造函数，若其没有默认构造函数，则报错)
          构造函数调用顺序：
          父类构造->父类的类类型数据成员构造(不能调用其的非public构造函数)-
          ->子类的构造(不能调用父类的private构造函数)
         
    > 析构函数：
        × 建议(父类的)析构函数为虚函数：
            因为当涉及到delete 指向子类对象的父类指针时，若析构函数不为虚函
            数，delete 父类指针 只会调用父类的析构函数析构子类对象的父类部
            分，造成子类对象析构不完全从而内存泄露。
            若父类的析构函数为虚函数，调用的子类析构函数之后会自动调用父类
            的析构函数。析构函数调用顺序：
            先调用子类析构-->子类的类类型数据成员的析构--->父类的析构。
    > 复制构造函数：
        × 子类的复制构造函数必须在其初始化列表中显式调用父类的复制构造
          函数，否则就会隐式调用父类默认构造函数，这就会导致子类对象的父类 
          部分是初始化得来的，而其他部分则是拷贝过来的。
        × 复制构造函数，一定要记得防止浅拷贝，即一定要拷贝指针所指向内存
          的值。
    > 赋值运算符函数重载：
        × 子类的赋值运算符重载一定要在该函数内部显式调用父类的赋值运算符
          重载函数。而父类的赋值运算符重载函数的调用会使得父类对象的子类
          部分先释放已有资源再拷贝右侧子类对象的父类部分
        × 赋值运算符重载函数会
    
 2.哪些情况必须调用初始化列表进行初始化？
   × const常变量和引用两个数据成员必须初始化列表初始化---因为这两个必须初始化且不能被赋值
   × 类数据成员最好初始化列表初始化---类数据成员如果不在初始化列表初始化，则自动调用该类数据成员的 
     默认构造函数初始化.但很可能发生错误，如下。
     注意：
     1.若只存在自定义非默认构造函数(默认构造函数被覆盖)，则编译器找不到该类数据的默认构造函数而报错
     2.若存在自定义默认构造函数， 则编译器调用该类自定义默认构造函数对该类数据成员进行初始化。
     3.若该类未有任何自定义构造函数， 则编译器调用该类的合成默认构造函数对该类数据成员进行初始化
   × 类继承时，子类的构造函数最好在初始化列表初始化父类(调用父类构造函数)--同上
 
 */

#include<iostream>
using namespace std;

class Aclass{
    public:
        Aclass(){
            cout<<"调用Aclass类默认构造函数"<<endl;
        }
        ~Aclass(){
            cout<<"调用Aclass类的析构函数"<<endl;
        }
    //protected:子类的构造函数初始化列表无法调用其类类型数据成员的非public构造函数--->本质是非public不能类外访问    
        Aclass(int i){
        
            cout<<"调用Aclass类的含参构造函数"<<endl;
        }
       };

class Base
{
    public:
         Base(){
             cout<<"调用Base类的构造函数"<<endl;
         }
    
        virtual ~Base(){
            cout<<"调用Base类的析构函数"<<endl;
        }

    ///private:子类的构造函数的初始化列表不能调用其父类的private构造函数--->本质是父类的private根本就不继承到子类
         Base(int i){
             cout<<"调用Base类的含参构造函数"<<endl;
         }

        
};


class Derived:public Base
{
    public:
        Derived()
        {
            cout<<"调用Derived类的不含初始化列表初始化父类和类类型数据成员的构造函数"<<endl;
        }
    
        Derived(int i):Base(i),m_Aclass(Aclass(i)){   //m_Aclass(i)等价于mAclass(Aclass(i))
            cout<<"调用derived类的含初始化列表初始化父类和类类型数据成员的构造函数"<<endl;
        }

        ~Derived(){
            cout<<"调用derived类的析构函数"<<endl;
        }
    private:
        Aclass m_Aclass;

};

int main()
{
    cout<<"-----测试单重继承中构造函数调用顺序和调用规则"<<endl;
    Base* p1=new Derived();
    delete p1;
    cout<<"---"<<endl;
    Base* p2=new Derived(1);
    delete p2;

return 0;
}
