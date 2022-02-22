#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
int main()
{

    //printf("0x%08x,0x%llx\n",0x00000001ul,0x10000001ul);
    //printf("%d,%d",rand(),rand());
    int i;
    int*p=&i;
    *(p++)=1;
    cout<<i<<*(--p)<<endl;
return 0 ;
}
