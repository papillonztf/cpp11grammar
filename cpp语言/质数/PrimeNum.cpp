#include"PrimeNum.h"
#include<math.h>
bool isPrimeNum(int n)
{
    /*
     //枚举法--O(n)
    if(n>0)
    {
        for(int i=2;i<n;i++)
          if(!(n%i))
            return false;
            
    
    }
    else
      return false;
    return true;
    */
    //折半枚举法：--O(n^(1/2))

    if(n>0)
    {
        for(int i=2;i<=(int)ceil(sqrt(n));i++)
          if(!(n%i))
            return false;
            
    
    }
    else
      return false;
    return true;

}

int* primeFactor(int n,int* buff)
{
    list<int> intList;//size=0;
    for(int i=2;i<n;)
    {
        if(n%i)
        {
          intList.push_back(i);
          n/=i;
          contiue;
        }
        i++;
    }


}
