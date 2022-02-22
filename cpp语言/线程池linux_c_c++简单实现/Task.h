#pragma once 
//模板类的定义和实现应在同一头文件而这样做并不会发生链接重定义

#include<string>

//抽像类：
class Task{
public:
    
    Task(string str):m_taskName(str){};
    Task(const Task& other)              = default;
    Task& operator=(const Task& other)   = default;
    virtual ~Task()                              = default;
    virtual void Run()                   = 0;
    //virtual void GetRunResult()          = 0;
    //void         SetTaskName(string str);
    //string       GetTasKName();

private:
    //string   m_taskName;
    //void*    m_result;

};
template<class T>
class ConcreteTask:public Task{
public:
    ConcreteTask(T fun);
    Run();
private:
    T   m_pFun;

}
