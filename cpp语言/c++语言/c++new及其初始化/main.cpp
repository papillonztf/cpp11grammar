/*
#初始化和不初始化：
    1.必须初始化：
        × const变量，引用：必须手动初始化
        × static变量：可自动初始化
        × 
#初始化方式：
    1.new初始化:
        对内置类型和类类型的初始化&&单个和动态数组&&三种方式
        a.不加（）或{}：
             × new 内置类型：
                局部变量:不初始化，随机值
                全局变量:值初始化，即int值初始化为0,char为/0，指针为NULL
             × new 类类型:
                值初始化，即自动调用默认类构造函数 Atest::Atest()进行类对象初始化
                ！若自定义的类构造函数会覆盖类默认构造函数，此时会造成
                  Atest × p=new Atest失败，因为此时不存在 Atest::Atest()
         b.加() 调用构造函数：
             × 对应内置类型，值初始化或指定值初始化
                 eg：int × p=new int();//值初始化位0
                     int × p=new int(1);//指定1初始化值
             × 对于类类型：
                自动调用类构造函数，进行初始化。
                 eg:  Atest × p=new Atest;//调用类的默认构造函数Atest::Atest()                    
                      Atest × p=new Atest();//同上
                      Atest × p=new Atest(1,2);//调用自定义构造函数Atest::Atest(int i, int j )        
       
         c.加{} 初始化列表：
            便于用于动态数组的全部初始化。
                eg: int * pnewintsd=new int[3]{1,2,3};//使用初始化列表，可将动态数组一一初始化：
    
        ! 在new数组初始化时：
           × ()不能指定值初始化new数组：
            eg: int* p=new int[2]()//正确，全部为0
                int* p=new int[2](1,2)//错误，()指定值初始化不可用于new数组
                Atest × p=new Atest[2](1,2);//错误,同上
                Atest × p=new Atest[2]();//正确，都调用默认构造函数

           × {}要不就值初始化，要不就全部指定值初始化
            eg: int × p=new int[2]{1};//错误，{}不可部分指定值初始化
                int × p=new int[2]{1,2};//正确，{}全部指定值初始化
                int × p=new int[2]{};//正确，都初始化为0
    2.数组初始化：
        × 局部数组变量：
            int arry1[4]==>2  0  1552682269  21864  
            int arry2[4]={0}==>0  0  0  0  
            int arry3[4]={1,2}==>1  2  0  0  
        × 全局数组变量：
            int g_arry1[4]==>0  0  0  0  
            int g_arry2[4]={0}==>0  0  0  0  
            int g_arry3[4]={1,2}==>1  2  0  0  




*/

#include<iostream>

using namespace std;

class Atest
{
    public:
        Atest(int i,int j)
        {
            a=i;
            b=j;
        }
        int a;
        int b;
};

int g_arry1[4];
int g_arry2[4]={0};
int g_arry3[4]={1,2};
int* g_intp=new int[4];
int main()
{
    
//new内置数据类型的初始化：

int * pnewinta=new int;//new对内置类型，无论单个还是动态数组默认不初始化
int * pnewintb=new int();//new对内置类型，无论单个海海死动态数组，使用（）
                         //显示调用初始化函数，初始化为0
int * pnewintc=new int(1);
int * pnewintsa=new int[3];
int * pnewintsb=new int[3]();
int * pnewintsd=new int[3]{1,2,3};//使用初始化列表，可将动态数组一一初始化：
//int * pnewintsc=new int[3](1); //语法错误,不可对new数组部分初始化
//int * pnewintsd=new int[3](1,2,3);//语法错误,应使用花括号初始化列表对new数组全部初始化

//new 对类类型的初始化

//Atest * p=new Atest;//错误，本类中并未提供::Atest()构造函数(被覆盖了)
//Atest * p1=new Atest();//错误，同上
//Atest * p2=new Atest(1);//错误，

Atest * p2=new Atest(1,2);//正确
Atest * p3=new Atest{1,2};//正确，列表初始化实则是调用::Atest(int i,int j)构造函数

//Atest * p4=new Atest[2];//错误，本类中并未提供::Atest()构造函数(被覆盖了)
//Atest * p5=new Atest[2]();//错误，同上
//Atest * p5=new Atest[2](1,2);//错误，不可对new数组部分初始化

int arry1[4];
int arry2[4]={0};
int arry3[4]={1,2};
cout<<"int arry1[4]==>";
for(int i=0;i<sizeof(arry1)/4;i++)
  cout<<arry1[i]<<"  ";
cout<<endl;

cout<<"int arry2[4]={0}==>";
for(int i=0;i<sizeof(arry2)/4;i++)
  cout<<arry2[i]<<"  ";
cout<<endl;

cout<<"int arry3[4]={1,2}==>";
for(int i=0;i<sizeof(arry3)/4;i++)
  cout<<arry3[i]<<"  ";
cout<<endl;


cout<<"int g_arry1[4]==>";
for(int i=0;i<sizeof(g_arry1)/4;i++)
  cout<<g_arry1[i]<<"  ";
cout<<endl;


cout<<"int g_arry2[4]={0}==>";
for(int i=0;i<sizeof(g_arry2)/4;i++)
  cout<<g_arry2[i]<<"  ";
cout<<endl;


cout<<"int g_arry3[4]={1,2}==>";//1,2,0,0
for(int i=0;i<sizeof(g_arry3)/4;i++)
  cout<<g_arry3[i]<<"  ";
cout<<endl;
int* intp=new int[5];//1,2,0,0,0
cout<<"intp=new int[5]{1,2}==>";
for(int i=0;i<5;i++)
  cout<<intp[i]<<"  ";
cout<<endl;
cout<<"g_intp=new int[4]==>";
for(int i=0;i<5;i++)
  cout<<g_intp[i]<<"  ";
cout<<endl;





return 0;
}

