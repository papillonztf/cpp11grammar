#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
// cout<<copy(str2.begin(),)
   cout<<str1<<endl;
   //copy(str2.begin(),str2.end(),str1.begin()+3);
   str1.replace(str1.begin(),str1.end(),"1234512345123456");//与size无关;capacity自动复制扩大
   cout<<str1<<endl;
   
    string s,t;
    char ret='0';
    cin>>s>>t;
    cout<<s.size()<<" "<<t.size()<<endl;
    cout<<s<<" "<<t<<endl;
    ret=findTheDifference(s,t);
    cout<<ret<<endl;
        
        
    return 0;
}

char findTheDifference(string s, string t) 
{
    bool isfind;
    int i,j;
    char ret='0';
    for(i=0;i<t.size();i++)
   {
    isfind=false;
    for(j=0;j<s.size();j++)
    {
        if(t[i]==s[j])
        {
          isfind=true;
          s[j]='0';
          break;
        }
    }
    if(isfind==false)
    {        
        ret=t[i];
        //cout<<i<<"  nihao!!"<<endl;
        break;
    }
    }
    return ret;
}

