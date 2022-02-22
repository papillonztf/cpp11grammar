#include<algorithm>
#include<string>

#include<iostream>

using namespace std;

char findTheDifference(string s,string t);
int main(){
    string s("abc");
    string t("dcba");
    char ret='0';
    ret=findTheDifference(s,t);
    cout<<ret<<endl;
    return 0;
}


char findTheDifference(string s,string t){
    string st=s;
    char ret=0;
    st.reserve(s.size()+t.size());
    cout<<st<<' '<<st.size()<<endl;
    st.append(t);//在st末尾(st.size()之后)追加t(的size())
    cout<<st<<' '<<st.size()<<endl;
    for(auto ch:st)//auto 元素变量：容器变量/数组名;当需修改元素值时需改为auto& 取引用
      ret^=ch;//c++11：auto自动确定变量类型，如容器的元素变量的类型;基于范围的for
    return ret;
    
}



    
