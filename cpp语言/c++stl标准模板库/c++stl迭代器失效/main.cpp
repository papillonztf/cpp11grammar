/*
 -------------c++STL迭代器失效----------------------
# 什么是迭代器失效？
    a.已指定指向容器的元素的迭代器不再指向该元素.
    b.此外删除迭代器也使得该迭代器销毁从而无效。
#使用失效的迭代器会产生什么后果？
    a.产生不符合预期逻辑的执行结果
    b.程序编译没问题，但运行(地址)异常终止
#什么操作会导致迭代器失效
    >插入元素:
     × vector/string:基于动态连续数组
        :插入位置之前的元素的迭代器/指针/引用仍有效(若未重新分配空间)
        :插入位置之后的元素的迭代器/指针/引用均失效(若未重新分配空间)
        :所有位置的元素迭代器/指针/引用均失效(若自动或resever手动重新
         分配空间)

     × deque:基于动态分段连续数组
        :插入位置是首尾位置，则其他元素的迭代器均失效/指针引用仍有效
        :插入位置是非首尾位置，则所有迭代器/引用/指针均失效。
     × list/set/map/mutiset/mutimap/unordered_**:
        :插入后，迭代器/指针/引用均都有效（包括尾后，首前迭代器）
    > 删除元素:
      被删除的元素迭代器/指针/引用均会失效，因为元素删除后就被销毁。
     × vector/string:
        :删除位置之前的元素的迭代器/指针/引用仍有效。
        :删除位置之后的元素的迭代器/指针/引用均失效。
     × deque:
        :删除位置是首/尾元素，则其他位置的迭代器/指针/引用仍有效
        :删除位置是非首尾位置，则所有迭代器/引用/指针均失效。
     × list/set/map/mutiset/mutimap/unordered_**:
        :删除后，其他迭代器/指针/引用均都有效（包括尾后，首前迭代器）

# 怎么避免使用失效的迭代器(/指针/引用)?
    a.迭代器必须有效的代码段最小化
      × 插入后:
        a.对于string/vector/deque：
          iter=vec.insetr();//及时重新定位插入的位置，因为可能重新分配空间
        b.对于list/set/map/××:
          无需获取插入函数返回的迭代器
      × 删除后:
        对于所有容器，由于被删除的元素的迭代器失效了，iter++
        等操作肯定无效，因此，对于所有容器都有。
          iter=vec.erase();
    b.不保存end()等迭代器：
        执行容器的删除和插入操作后事先保存好的迭代器很可能失效(最典型
        的就是end()尾后迭代器)
        
        
 * */

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>//for_each()
using namespace std;
void showElement(int n)
{
 cout<<n<<" ";
}

int main()
{
    /*指针越界测试--越界导致访问错误的数据;也可能导致访问非法内存
    int a=1;
    int*p=&a;
    cout<<(void*)p<<": "<<*p<<endl;
    while(1)
    cout<<(void*)(++p)<<": "<<*(++p)<<endl;
    */

/*//--------------------vector迭代器失效测试：
    vector<int> intVec={1,2,2,3,2,4,2,2,3,2};//默认构造函数，size=0;capacity=0
    vector<int> intVec1;
    intVec1.resize(30);
    intVec=intVec1;//赋值：将源的size段，拷贝至目的地，若源size大于目的capacity才会使得目的换用更大的capacity。

    /*
    //迭代器越界--即访问.end()--导致数据访问出错，也可能访问非法地址导致段错误(异常终止)
    int i=10; 
    vector<int>::iterator iter=intVec.begin();
    while(i--)
    {
    //cout<<iter<<endl;//错误
    cout<<&(*iter)<<" "<<*iter<<endl;
    iter++;
    }
    cout<<&(*(intVec.end()))<<*(intVec.end())<<endl;
    */
    /*
    //vector删除操作----迭代器失效。
    vector<int>::iterator iter=intVec.begin();
    cout<<intVec.size()<<" "<<intVec.capacity()<<endl;
    for_each(intVec.begin(),intVec.end(),showElement);
    cout<<endl;
    for(;iter!=intVec.end();)
    {
        if(*iter==2)
        {
          intVec.erase(iter);
        }
        else 
          iter++;//关键，防止vector删除操作使得迭代器失效。
    }
    cout<<"-----------------------"<<endl;
    cout<<intVec.size()<<" "<<intVec.capacity()<<endl;
    for_each(intVec.begin(),intVec.end(),showElement);
    cout<<endl;
    */
    
    //vector插入操作---迭代器失效测试
    /*
    vector<int> intVec={1,2,3,1,1,1,4,1};
    vector<int>::iterator iter=intVec.begin();
    cout<<intVec.size()<<" "<<intVec.capacity()<<endl;
    for_each(intVec.begin(),intVec.end(),showElement);
    cout<<endl;
    cout<<"测试扩容后的insetr返回值是实时"<<endl;
    cout<<&(*intVec.begin())<<endl;
    cout<<&(*intVec.insert(intVec.begin(),11))<<"  ";
    cout<<&(*intVec.begin())<<endl;
    cout<<intVec.size()<<"  "<<intVec.capacity()<<endl;
    cout<<&(*intVec.begin())<<endl;
    cout<<&(*intVec.insert(intVec.begin(),11))<<"  ";
    cout<<&(*intVec.begin())<<endl;
    cout<<intVec.size()<<"  "<<intVec.capacity()<<endl;

    cout<<"------------------------"<<endl;
    int offset=0;
     for(;iter!=intVec.end();)
    {
        if(*iter==1)
        {
          if(intVec.capacity()==intVec.size())
          {
             intVec.reserve(2*intVec.size());//手动换用更大capacity，以便后续处理vector插入操作使得迭代器失效
             iter=intVec.begin()+offset;
          }
          intVec.insert(iter,0);
          iter=iter+2;
          offset=offset+2;
        }
          
        else
        {
          iter++;
          offset++;
        }
    }
    
    cout<<intVec.size()<<" "<<intVec.capacity()<<endl;
    for_each(intVec.begin(),intVec.end(),showElement);
    cout<<endl;
*/
deque<int> intDeque={1,2,3,4};
deque<int>::iterator iter=intDeque.begin();
cout<<"intDeque:"<<intDeque.size()<<endl;
cout<<"intDeque.begin():"<<&(*iter)<<" "<<*iter<<endl;
intDeque.push_front(0);
cout<<"intDeque:"<<intDeque.size()<<endl;
cout<<"intDeque.begin():"<<&(*iter)<<" "<<*iter<<endl;


        return 0;
}
