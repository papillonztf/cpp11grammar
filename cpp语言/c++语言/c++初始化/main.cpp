/*
 **************c++初始化**************
#必须初始化的情况:
    引用：
    常变量：
    静态数据成员：必须初始化且必须在类外进行初始化

#必须类列表初始化的情况:
     a.类数据成员如果是引用、常变量，由于他们必须初始化而构造函数内部
       是赋值，因此必须通过列表初始化(这才是真正的初始化而不是赋值)
     b.类数据成员是类以及类的基类。
        如果他们不在类列表进行初始化，那么编译器会指定他们类的默认构造函数
        进行初始化。而他们的默认构造函数可能不符合预期或者已经被带参构造函数
        覆盖，这可能导致运行时错误.
#初始化方式区别：
    > 默认初始化：
        a.对于内置类型变量:其默认初始化的值跟它的定义的位置还有关系
            int intGlobal; //定义在函数体之外，默认初始化为0
            int intLocal;   //定义在函数体之内，默认初始化值不确定
        b.对于类变量：默认初始化取决于它的默认构造函数(如果没有则会出错)
            Base myBase; //取决于它的默认构造函数
    > 值初始化：
        值初始化是值使用了初始化器（即使用了圆括号或花括号）
        但却没有提供初始值的情况.
        对于类变量，如果你自定义了构造函数，但为了能够值初始化,
        必须使用default指定默认构造函数使用编译器生成的默认构造函数
        eg:
        int *pi=new int;         // 默认初始化， *pi的值为未定义。  
        int *pi=new int();       // 值初始化为0，*pi的值为0  
        string *ps=new string;   // 默认初始化 *ps的值为空string  
        string *ps=new string(); // 值初始化为空string
        vector<string> vec(10);  //值初始化，10个空string的vector，
        int a=int();            //默认初始化，a值为0,int a()则是错误的。
    > 直接初始化：
        直接初始化使用指定初始值的初始化器进行初始化。
        对于类变量应使用直接初始化而不是拷贝初始化，因为
        a.高效，省去了构造临时对象
        b.如果构造函数指定explicit限定符，那就不能使用拷贝初始化，因为
          explicit限定不能进行隐形类型转换。
        eg:
        --直接初始--
        int a(12);
        Sales_data myData(para);
        vector<int> ivec(ivec2);
        string s("123456");
        ---拷贝初始化---
        strig str="1234";
        string str=string("1234");
        Base myBase=("ztf",24);
    > 拷贝初始化：
       拷贝初始化(使用等于号=，)是先调用构造函数构造一个
       临时对象(隐形类型转换)，再调用拷贝构造函数对变量进行初始化。
       
 * */
