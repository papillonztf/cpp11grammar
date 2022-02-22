#ifndef __STATIC_ARRAY_LIST_H__
#define __STATIC_ARRAY_LIST_H__

typedef int Type;//typedef声明
//extern const int CAPACITY;//错误.const 全局变量相当于static const全局变量
const int CAPACITY=10;//因此，该const 全局变量只作用于本文件内(本编译单元)，不会引起链接重定义
class StaticArrayList
{
    private:
        Type m_elementArray[CAPACITY];
        int m_size;

    public:
        StaticArrayList();
        StaticArrayList(int n,int i);
        StaticArrayList(const StaticArrayList& other);    
        ~StaticArrayList();
        //const StaticArrayList& operator= (const StaticArrayList& other);   
        Type getSize() const;
        void showDataMember() const;
};
typedef  StaticArrayList SAList;//必须在类之后使用typedef 声明类的别名
#endif

