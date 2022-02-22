/*--------------------------------
---------------------------------
Test fun1(){                                                                                      
    Test tem(1,"1个元素");          a. Test test = fun1();           
                                       tem.setName("#1个元素#");
    return tem;
    }                               b. Test test(2,"2个元素");
                                       test =fun1();
#################
USE_NONRVO = 0
USE_SWITCH = 0 :Test test = fun1()
--------------
default constructor：
1--decontructor:
#################
USE_NONRVO = 0
USE_SWITCH = 1 :test = fun1()
--------------
default constructor：
default constructor：
shallow assign) move assignment:
0--decontructor:
1--decontructor:
#################
USE_NONRVO = 1
USE_SWITCH = 0 :Test test = fun1()
--------------
default constructor：
shallow copy) move constructor:
0--decontructor:
shallow copy) move constructor:
0--decontructor:
1--decontructor:
#################
USE_NONRVO = 1
USE_SWITCH = 1 :test = fun1()
--------------
default constructor：
default constructor：
shallow copy) move constructor:
0--decontructor:
shallow assign) move assignment:
0--decontructor:
1--decontructor:
#####################
*/
#include<iostream>
#include"Test.h"
using namespace std;
Test fun1(){
    Test tem(1, "1个元素");
    tem.setName("###一个元素");
    return tem;
}
int main(){
    
    cout<<"--------------"<<endl;
    //a.rvo-nonrvo =0-1
    #ifdef USE_NONRVO
        cout<< "USE_NONRVO = "<<USE_NONRVO<<endl;   
    #else
        cout<<"USE_NONRVO = 0"<<endl;
    #endif
    //b.构造-赋值 = 0-1
    #ifdef USE_SWITCH
    #if USE_SWITCH ==0
        cout<<"USE_SWITCH = "<<USE_SWITCH<<" :Test test = fun1()"<<endl;
        cout<<"--------------"<<endl;
        Test test = fun1();
    #elif USE_SWITCH ==1
        cout<<"USE_SWITCH = " <<USE_SWITCH <<" :test = fun1()"<<endl; 
        cout<<"--------------"<<endl;      
        Test test(10,"十个元素");
        test = fun1();
    #endif
    #endif
    
       //b.
    return 0;
}
