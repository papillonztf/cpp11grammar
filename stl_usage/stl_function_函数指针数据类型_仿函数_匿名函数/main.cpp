/*
> 函数指针:指向函数的指针，可为函数指针字面值;函数指针变量;函数指针数据类型
    ×函数指针字面值：
        1.bool cmp(int ri,int li)            //cmp即为函数指针字面值
            {
                return ri<li;
            }

        2.[](int ri,intli)cmp{return ri<rl;} //匿名函数(lambda函数或喇嘛表达表达式)表达式即为函数指针字面值
        3.cmp() //仿函数cmp默认构造函数实例化

    ×函数指针变量：
        
        1.bool (*cmp)(int,int);         //cmp即为函数指针变量
     

    ×函数指针数据类型：
        1.typedef bool(*CMP)(int,int); //CMP为函数指针类型
        2.class cmp                    //仿函数cmp即为函数指针变量类型，c++11仿函数
          {
            public：
                bool operator()(const int ri,const int li)const
                {
                    return ri<li;
                }
          }; 
        2.std::function<bool(int,int)> CMP; //CMP为函数指针类型，c++11 function <functional>
        3.bool(*)(int,int);                 //匿名函数指针类型
        4.auto cmp=函数指针字面值;          //auto根据左值自动推导变量类型，c++11 auto
        5.decltype(函数指针变量) cmp;       //decltype根据函数指针变量自动推导变量类型，c++11 decltype

>函数指针作用：
    1.函数指针字面值或变量作为函数模板参数（实例的实参）：实现基于指定函数参数个数及类型的泛化
        for_each(mymap.begin(),mymap.end(),函数指针值或变量cmp); //值或变量确定for_each函数模板的第三个参数的类型
                                                    //T t（map<T1,T2>::iterator iter）限制函数只能有一个参数
    2.函数指针类型作为类的模板参数：实现基于指定函数参数个数及类型的泛化
        map<int,string,函数指针类CMP>
      如:某模板类，存在一个基于某一具体查找函数的通用查找接口(模板函数接口）。
    

        

 
 
 **/
