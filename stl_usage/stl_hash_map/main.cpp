#include<hash_map>//std_ext--using namaspace __gnu_cxx
#include<algorithm>//for_each
#include<functional>//仿函数less<T>;std::hash<T>
#include<string>
#include<iostream>

using namespace std;
using namespace __gnu_cxx;

 template<class T1,class T2>//T1,T2在此作为容器的元素数据类型(间接数据类型)
    ostream& operator<<(ostream& out,pair<T1,T2> mappair)//<<输出运算符重载,必须作为非成员函数
    {
        cout<<"  "<<mappair.first<<"--"<<mappair.second<<endl;
        return cout;
    }

 template<class T>//函数模板实例(或仿函数)作为for_each的第三个参数，for_each(,,showPair<map<int,string>::value_type>)
	void showPair(T i)
    {
        cout<<i<<endl;
    
    }

    namespace __gnu_cxx//模板特化必须在该模板的同一命名空间
    {
        template<>//__gnu_cxx::hash<T>模板特化 hash<string>;因为该模板默认不支持hash<string>,而std::hash<T>支持
        class hash<string>
        {
             public:
                 size_t operator()( const string& str) const  //模板特化必须加const两个
             {
                //cout<<"niha`"<<endl;
                return hash<const char*>()(str.c_str());
              }
         };
    }
    
    template<class Key>
    class CmpFunctor
    {
        public:
            bool operator()(Key oldKey,Key newKey)
            {
                return oldKey==newKey;
            }
    };

int main()
{
    //hash_map<string,int> hashmap1;
   
     
  
    cout<<"-----测试hash_map<KEY,VALUE,HASH,KEYEQUL>-----："<<endl;

    cout<<"> hash_map使用默认模板参数："<<endl;
    cout<<"> hash_map<KEY,VALUE>等价于hash_map<KEY,VALUE,hash<KEY>,equal_to<KEY>>"<<endl;//默认模板参数
    hash_map<int,string> hashmap1;//hash_map不支持列表初始化={{}，{}}
    hashmap1[2]="two";
    hashmap1[1]="one";
    hashmap1[3]="three";
    hashmap1.insert(pair<int,string>(4,"four"));
    hashmap1.insert(pair<int,string>(5,"four"));//插入已存在key，无效。  
    
    for_each(hashmap1.begin(),hashmap1.end(),showPair<hash_map<int,string>::value_type>);//for_each+函数指针(函数名或函数指针变量)

    hash_map<string,int,std::hash<string>,CmpFunctor<string>> hashmap2;
    hashmap2["three"]=3;
    hashmap2["one"]=1;
    hashmap2["two"]=2;
    cout<<"> hash_map使用指定模板参数："<<endl;
    cout<<"> hash_map<KEY,VALUE，std::hash<string>,CmpFunctor<string>>>"<<endl;//默认模板参数
    for_each(hashmap2.begin(),hashmap2.end(),showPair<hash_map<string,int>::value_type>);
    return 0;

}

