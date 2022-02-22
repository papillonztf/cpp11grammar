#include"dp.h"
#include<algorithm>
#include<vector>
using namespace std;
/*递归dp，直接爆cpu，草
int dp(int n)
{   
    int ret=0;//for递归
    if(n<0)
      exit(1);
    else if(n>0)
    {
        if((n==1)||(n==3)||(n==5))
          ret=1;
        else if(n<3)
          ret=dp(n-1)+1;
        else if((n>3)&&(n<5))
          ret=((dp(n-1)<dp(n-3))?dp(n-1):dp(n-3))+1;
        else if(n>=5)
          ret=min(min(dp(n-1),dp(n-3)),dp(n-5))+1;

    }
    return ret;
}*/

int dpleaststep(int n,int types[],int count)
{
    vector<int> 

    

}

