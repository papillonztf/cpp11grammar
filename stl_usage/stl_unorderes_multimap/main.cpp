#include<unordered_map>
#include<iostream>

using namespace std;

int main(){
    
    unordered_multimap<int,string> ummap1={{2,"two"},{1,"one"},{3,"three"},{2,"tww"},{2,"two"}};
    for(unordered_multimap<int,string>::iterator iter=ummap1.begin();iter!=ummap1.end();iter++)
      cout<<iter->first<<"--"<<iter->second<<endl;
    return 0;
}
