#include"task.h"

template<class T>
void ConcreteTask::Concrete(T fun){
    m_pFun=fun;
}


template<class T>
void ConcreteTask::run(){
    m_pFun();
}
/*
T:无参无返回值的类似函数指针类型
> function<void()>:通用多态函数封装器
    × 凡是void返回值且无参一般函数、成员函数、仿函数，lambada函数:
      可直接赋值给或初始化function<void()>。
      (仿函数对象应使用function<void()> f=ref(functorclass),使用仿函数对象的引用)
    × 凡是void返回值且有参:
      可以间接通过bind()函数绑定包装成function<void()>
2.仿函数类：
    × 在非void返回值函数情况时，可以创建对应仿函数类，参数和结果都可以通过
    仿函数的数据成员进行传递和保存。
    class Functor{
        public:
            Functor(int arg1,int arg2):m_arg1(arg1),m_arg2(arg2){}
            void operator()(){
                m_result=m_arg1+m_arg2;
            }
            int GetResult(){
                return m_result;
            }
        private:
            int m_arg1;
            int m_arg2;
            int m_result;
     };
3.返回值为void且无参的函数指针类型
    typedef void (*FUN)()//FUN类型
    
    void (*fun)()//decltype(fun)类型
    }
*/
