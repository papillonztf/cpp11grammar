/*动态规划--取硬币问题
0. 硬币集合 Ui={U1,U2,……},i=1,2…… ,Ui=N+
1. 状态转移方程：
    f(x)=min{f(x-Ui)}+1 ,x>=min(Ui)  ，x=N+
2. 状态：
    ×状态：到达某个点的最小步数。
     显然，状态值分为：不可达和最小步数(可达就一定
     有最小步数)。y=f(x),y=NOTREACH,N+
    ×状态集合：所有点的状态的集合Y={y(x)}={f(x)}
     ,x=1,2,3,……
    ×状态链：到达某个点的最小步数路径的点的有序集
     合。显然，某个点的状态链在具体的实现细节前提
     下，是唯一的。
3. 分析状态转移：自上而下
    f(x(i))=g({f(x(j))}),j<i且集合{f(x(j))}有限
    即任意一个点的状态是由其之前某些点的状态是根
    据某个固定的依赖关系转换而来的。
4. 实现：自下而上
    根据初始状态(首点)，应用转换关系可以求得之后
    的状态，重复迭代可以求得整个状态集合，自然可
    以知道集合中的某个点的状态。
     f(0)=0--初始状态
   
 */


#include<iostream>
#include"dp.h"
using namespace std;
/*int  dpleaststep(int n,int types[])
{
    int 
    cout<<types<<endl;
    cout<<*types<<endl;
}
*/

int main()
{
    int n;
    int TYPEC=0;
    //全0
    cout<<"please input step type count:";
    cin>>TYPEC;
    int* pTypes=new int[TYPEC]();//()调用默认int初始化函数初始化为0

    cout<<"please input "<<TYPEC<<" step types(eg: 1 2 3): "<<endl;
    int i=0;
    while(i<TYPEC)
    {
      cin>>pTypes[i];
      i++;
    }
    cout<<"------------"<<endl<<"your input result: "<<endl;
    cout<<TYPEC<<" types:";

    for(int i=0;i<TYPEC;i++)
    cout<<pTypes[i]<<"  ";//new int 动态数组的下标操作
    cout<<endl; 
    cout<<pTypes<<endl;
    dpleaststep(n,pTypes,TPEYC);

    delete []pTypes;//释放动态内存
    return 0;
}   


