/*
#动态内存：
    >使用动态内存的三种原因:
        ×程序不知道自己需要使用多少对象：如容器类new数据成员
        ×程序不知道所需对象的确切类型:如new多态
        ×程序的多个对象间共享数据:
            如类的new数据成员多个实例对象共享(浅复制、浅析构)
#直接管理动态内存:
    >方法：使用new-delete管理内置指针指向的动态内存
        ×缺点：
            1.内存泄露:---share_ptr自动释放动态内存
                未手动delete动态内存，导致memory leak
                eg：
                a.c++类的析构函数未负责delete类的new数据成员，造成内存泄露
                b.调用函数返回指向new分配动态内存的指针，而调用者却未
                  delete该指针，造成内存泄露
            2.空悬指针:---share_ptr也会遇到该问题-weak_ptr能解决
                即使用已释放过的动态内存的指针
                eg:
                a.内置指针传递给share_ptr型参，函数调用结束后该shar_ptr
                  析构并由于use_count=0而释放内置指针指向的动态内存。
                  造成内置指针dangling
                b.share_ptr<T>::get()传递给内置指针型参，函数调用内部delete
                  该内置指针造成share_ptr变量dangling
                c.share_ptr<T>::get()给内置指针赋值或初始化，而随后又将
                  该内置指值初始化(p)和reset(p)另一个同类型share_ptr
                  造成两个相互独立但管理同一动态内存的shar_ptr,其中一个
                  share_ptr析构而释放内存造成另一个share_ptr变量dangling

            3.重复delete同一指针:未定义的行为---share_ptr能解决该问题
                eg：
                a.多个内置指针指向同一块动态内存

            4.delete非动态内存：未定义的行为
            5.利用new-delete实现动态资源数据成员共享和raii是低效、繁杂的。
            6.异常无法执行delete：
                程序异常时，调用函数可以中途返回，而未按计划执行delete.
#share_ptr：
    > share_ptr：
        允许多个share_ptr对象
        管理(核心就是提供计数器和use_count=0时自动释放动态内存)和
        使用(*,->)
        同一动态内存。
    > share_ptr特点:
        ×共享动态内存所有权:
            多个share_ptr管理同一块动态内存，不仅影响计数器，还能
            管理和使用(*,->)该共享内存(变量/对象)
        ×自动释放其管理的动态内存：
            当其use_count=0时，share_ptr调用析构器(默认是delete)释放动态
            内存。但是:
            1.share_ptr的析构不一定释放其管理的动态内存，因为此时use_count
               任>0
            2.share_ptr管理的动态内存被释放，该share_ptr不一定析构，
              如sp.reset(new int(1));如 sp=sp0。其中sp管理的动态内存被释放
              但sp对象未被析构。
        × 但无法确定动态内存是否被释放：
            严格使用share_ptr能避免空悬指针问题，但由于share_ptr实际是
            共享动态内存所有权，增加计数器，控制动态内存生存周期
            这增加管理成本、内存成本以解决空悬指针无疑是低效、冗余的。
            只有结合weak_ptr才能轻便解决dangling pointer问题
    >share_ptr使用方法:
        ×构造函数:
            支持:
                1.默认构造:此外管理对象为nullptr
                2.复制构造:
                    支持临时share_ptr对象:sp(share_ptr<int>(1))
                    支持sp对象：sp(sp0);sp=sp0
                    支持make_share<T>:sp(make_share<int>());sp=make_share
                    unique不支持复制构造
                3.含参构造:
                    支持new指针：sp(new int(1));sp(p)
                    不支持：share_ptr<int> sp=p;//这个涉及类型转换而上面没有
                4.unique传递移动构造:
                    share_ptr<int> sp=up;
        × 赋值函数：
            sp=sp0;
            sp=make_share<int>(1);
            sp=new int;//错误，不可转换
            sp.reset();
            sp.reset(new int(1));
            sp.reset(p);//不建议混用
    >share_ptr使用原则：
        × 不可将new 内置指针类型转换为share_ptr:
            如上述的构造函数和复制函数中不允许new指针转换(=)为share_ptr
            如new实参不允许转换为share型参
        × 不可与new混用:
            1.new-->share_ptr：
                只允许临时new变量去初始化share_ptr（见上构造函数)以及
                作为实参传递给share_ptr类型的型参
                切忌将指向动态内存的内置指针初始化、reset给(多个)
                share_ptr管理，
                
            2.share_ptr-->new:
                只允许在被调用函数参数是内置指针类型
                share_ptr::get()传递的内置指针时使用。
                切忌被调用函数内部delete传递来的share_ptr::get()以及
                将指针初始化、reset给其他share_ptr对象，拒绝形成多个独立
                share_ptr。
                注意get()指针也能失效.
    > share_ptr 应用与问题：
        share_ptr能解决内置指针管理动态内存的部分问题
        share_ptr也会产生新的问题。
        × 解决部分内置指针管理动态内存产生的问题:
            1.解决内存泄露：利用其use_count=0时自动释放动态内存的特点
            2.解决多次delete:同上
            3.解决delete非动态内存:？？
            3.解决new-delete实现共享数据成员和Raii(delete数据成员依赖析构)
              的低效:
                share_ptr本身的复制构造和赋值成员函数就是浅拷贝--共享
                share_ptr本身的析构函数默认支持delete，且浅析构，
                只在use_count=0时释放动态内存--raii
            4.结合weak_ptr才可解决空悬指针问题：
            5.异常时，share_ptr也能正常析构，避免内存泄露：

        × share_ptr也会遇到问题：
            1.share_ptr是强引用:
                当我们只需要对管理的动态内存进行信息查询时，应选择
                不增加计数器和不影响其生们周期的弱引用--weak_ptr
            2.share_ptr循环引用导致内存泄露:
                类似两个锁锁定区域倒置叠加可能死锁，
                两个share_ptr对象相互作为对方的数据成员会导致
                计数器不能归为0，从而导致内存泄露i

#unique_ptr：
    unique_ptr就是对share_ptr功能的约束----只允许任意时刻最多一个unique_ptr
    指向动态内存:
    >unique_ptr特点与使用：
        ×不可共享：
            1.不支持复制构造、赋值操作但值返回unique_ptr对象除外：
                无论是移动或复制构造和赋值，都会在同一时刻存在两个unique_ptr
                指向同一块动态内存，这时有悖于unique_ptr本质的。
                值返回unique_ptr对象除外，因为编译器执行特殊拷贝。
        ×可转移所有权:
            1.up.release():返回其管理的动态内存指针并up置为空nullptr。
                unique_ptr<int> up(up0.release());
                up.reset(up1.release());
                share_ptr<int> sp(up3.release())
        ×重置管理对象：三种智能指针都有该函数
            1.up.reset();
            2.up.reset(new int(1));

#weak_ptr:
    相比于强引用share_ptr，weak_ptr是弱引用，虽指向动态内存，但不增加
    计数器、不共享和不管理动态内存。
    >weak_ptr特点与使用：
        ×不可将new指针、unique_ptr对象初始化、赋值给weak_ptr：
            weak_ptr<int> wp(sp);//正确
            weak_ptr<int> wp(up);//错误
            waek_ptr<int> wp(new int) ;//错误
        ×最重要的作用是判断是否还有指向某个共享资源的share_ptr:
         近乎等价于判断动态内存释放被释放(有前提)
            up.expired();//是否use_count=0
            up.use_count();//
            up.lock();//use_count>0,返回一个不为空的share_ptr;否则返回空的
    >weak_ptr用途：
        × 结合share_ptr高效解决空悬指针：
        × 解决share_ptr产生的循环引用导致的内存泄露：
 */
