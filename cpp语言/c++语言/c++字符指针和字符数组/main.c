#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char ch = '1';
    char* charPtr=&ch;
    char* charPtrStr = "你好";
    char  charArr[10] = "世界";

   printf("%d\n", sizeof(charPtrStr));
   printf("%d\n",sizeof(charArr));    
   printf("%s\n",charPtrStr);
   printf("%s\n",charArr);
   cout<<charPtr<<' '<<strlen(charPtr)<<endl;
   cout<<charPtrStr<<endl<<charArr<<endl;
   charPtrStr=charArr;
   printf("%s\n",charPtrStr);
   printf("%s\n",charArr);
   cout<<charPtrStr<<endl<<charArr<<endl;

}
