#include "randnumgeneration.h"

#include <iostream>
#include<stdlib.h>//RAND_MAX;rand();srand()
#include<time.h>//time();clock();CLOCKS_PER_EC
#include<algorithm>//find()
#include<iomanip>//io格式
using namespace std;



int randomint()
{
int* p=NULL;
//cout<<"本机系统位数: "<<sizeof(p)*8<<" signed long 字节："<<sizeof(long)<<endl;
//cout<<"默认rand产生long integer随机数范围0～RAND_MAX： "<<"0~"<<RAND_MAX<<"( 即最大的signed int 2^31-1)"<<endl;
return rand();
}

unsigned long randomlong()
{
    unsigned long i;
   
    if(sizeof(long)==8)
    {
        i=(
            (((unsigned long)rand()<<48 ) &0xffff000000000000ul)
           |(((unsigned long)rand()<<32 ) &0x0000ffff00000000ul)
           |(((unsigned long)rand()<<16 ) &0x00000000ffff0000ul)
           |(((unsigned long)rand()     ) &0x000000000000fffful)
          );
        cout<<"long :"<<8<<"字节"<<"最大ulong 随机数";
        cout<<endl<<(unsigned long)(-1)<<endl; 

    }
    else if(sizeof(long)==4)
    {
         i=(
            (((unsigned long)rand()<<16 ) &0xffff0000ul)
           |(((unsigned long)rand()     ) &0x0000fffful)
           
        
          );
    }
    return i;
}

int* randomseq(int *seq,int n)
//动态内存指针：值-结果传递
{
    int *p=seq;
    clock_t startticks,stopticks;
    startticks=clock();
        
    while(n--)
    {
        *(p++)=rand();
    
    }
    stopticks=clock();
    cout<<__FUNCTION__<<" 运行时间: "<<setiosflags(ios::fixed)<<setprecision(6)<<
        (double)(stopticks-startticks)/CLOCKS_PER_SEC<<" s"<<endl;
    //gcc 宏定义__func__或FUNCTION__获取函数名
    //c++ cout setiodflags()设置io格式;
    //ios::fixed标志以定点格式显示浮点数值
    //setprecision(),有效位数，如0012.0900==>有效位数为6位
   return seq;
}

//随机生成n个不同数
int* randomseqdiff(int* seq,int n)
{
    int *p=seq;
    clock_t startticks,stopticks;
    startticks=clock();
       
    while(n<1)
    {
        if(find(seq,p,rand())!=p);
        {
            *p++=rand();
            --n;
        }
    
    }
    stopticks=clock();
    cout<<__FUNCTION__<<" 运行时间: "<<setiosflags(ios::fixed)<<setprecision(6)<<
        (double)(stopticks-startticks)/CLOCKS_PER_SEC<<" s"<<endl;
     return seq;
}

int* randomseqdiff(int*seq ,int m,int n,int num)//n-m+1>>num==>[m,n]等概率随机输出num个数
{
    if((n>m)&&(m>=0)&&(seq!=NULL))
    {
    int *p=seq;
    clock_t startticks,stopticks;
    startticks=clock();
    for(int i=m;i<=n;i++)
    {
        if(rand()%(n-i)<num)
        {
            *p++=i;
            num--;
        
        }
    
    }


    stopticks=clock();
    cout<<__FUNCTION__<<" 运行时间: "<<setiosflags(ios::fixed)<<setprecision(6)<<
        (double)(stopticks-startticks)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    else
      seq=NULL;
     return seq;
}

void showElement(int i)
{
    cout<<i<<"  ";

}
