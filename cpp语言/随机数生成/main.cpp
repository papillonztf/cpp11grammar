#include<iostream>
#include"randnumgeneration.h"
#include<stdlib.h>//srand();
#include<algorithm>//for_each()
using namespace std;

int main()
{
    int n=10;
    cin>>n;//空格/tab等之前为止，且这些分隔符不进入流，但是enter进入流作为下一个cin。
    int*seq=new int[n];
    int*seqDiff=new int[n];//采用动态内存作为值-结果传递
    int*seqDiffRange=new int[n];

    srand((unsigned int)time(0));
    for(int i=0;i<n;i++)
      cout<<randomint()<<" ";
    cout<<endl;

    srand((unsigned int)time(0)+1);
    for(int i=0;i<n;i++)
      cout<<randomlong()<<" ";
    cout<<endl;

    srand((unsigned int)time(0)+2);
    randomseq(seq,n);
    for_each(seq,seq+n,showElement);
    cout<<endl;

    srand((unsigned int)time(0)+3);
    randomseqdiff(seqDiff,n);
    for_each(seqDiff,seqDiff+n,showElement);
    cout<<endl;

    srand((unsigned int)time(0)+4);
    randomseqdiff(seqDiffRange,3,100000,n);
    for_each(seqDiffRange,seqDiffRange+n,showElement);
    cout<<endl;



    randomseq(seq,n);
    delete []seq;
    delete []seqDiff;
    delete []seqDiffRange;
return 0;
}
