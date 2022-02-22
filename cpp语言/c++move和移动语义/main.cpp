/*
#引用：
    int a = 1，b = 2;
    int& aRef = a;//引用必须初始化;引用的初始化就是绑定变量a，即引用aRef是变量a的别名。
    &aRef = b;//引用不能改变绑定对象。
    aRef = 3;
    aRef = b;//引用可以修改值。这时引用及其绑定的变量a都修改了同一值了。
#左值和右值
   左值:是地址、持久
   右值：是值、临时
   a = 2;//a是左值、2是右ii值
   b = a;//b是左值、左值a在这里作右值

 * */

/*
#引用：
int a = 1，b = 2;
int& aRef = a;//引用必须初始化;引用的初始化就是绑定变量a，即引用aRef是变量a的别名。
&aRef = b;//引用不能改变绑定对象。
aRef = 3;
aRef = b;//引用可以修改值。这时引用及其绑定的变量a都修改了同一值了。
#左值和右值
左值:是地址、持久
右值：是值、临时
a = 2;//a是左值、2是右ii值
b = a;//b是左值、左值a在这里作右值

* */

#include <iostream>
#include <string>
#include<cstring>
using namespace std;
class Test{
public:
	Test(int i, string s) :size(i), name(s){
		arrPtr = new int[size];
		for (int i =0; i <size; i++) {
			arrPtr[i] = size - 1 -i;

		}
			

		cout << "default constructor：" << endl;

	}
	//类成员函数可以访问其同类对象的private成员。
	Test(const Test& other) : size(other.size), name(other.name){
		
		arrPtr = new int[size];
		memcpy(arrPtr, other.arrPtr, size*(sizeof(int)));
		cout<< "(deep copy) copy constructor:" << endl;
	}
	Test& operator=(const Test& other){
		if (this == &other)
			return *this;
		delete[] arrPtr;
		size = other.size;
		arrPtr = new int[size];
		memcpy(arrPtr, other.arrPtr, size*(sizeof(int)));
		name = std::move(other.name);
		name = other.name;
		cout << "deep assign) assignment:" << endl;
		return *this;
	}
	Test(Test&& other):size(other.size),arrPtr(other.arrPtr),name(std::move(other.name)) {
        other.size = 0;
		other.arrPtr = nullptr;
		cout << "shallow copy) move constructor:" << endl;
	}
	Test& operator=(Test&& other){
    	if (this == &other)
			return *this;
		delete[] arrPtr;
		size = other.size;
		arrPtr = other.arrPtr;
		name = std::move(other.name);
        other.size = 0;
		other.arrPtr = nullptr;
		cout << "shallow assign) move assignment:" << endl;
		return *this;
	}
	~Test(){
        cout << size <<"--decontructor:" << endl;
		delete[] arrPtr;
	}
private:
	//return:先返回；再(编译器)释放局部变量(对于局部类对象则是先析构内部动态内存、再释放其内部其他变量)；
	int size;
	int* arrPtr;
	string name;


};
Test fun1(){
    Test test(5,"5个元素");
    *((int*)(&test)) = 10;
    return test;
}

int main(){
    //1.测试移动语义;std::move本质是转化为右值
	Test test1(1,"1个元素");
	Test test2(2,"2个元素");
	Test test3(3,"3个元素");
    Test test4(std::move(test1));//移动语义-移动构造函数
	Test&& rref = std::move(test2);//右值引用必须绑定右值，而move()的功能就是将值转为右值
	test2 = std::move(test3);//移动语义-移动赋值函数

	//2.std::move(左值或右值)转为右值"
    int&& rrefint =std::move(1);//将右值转为右值
    cout<< rrefint<<endl;
    //Test&& rref1 = std::move(4,"4个元素");//错误
    //Test&& rref1 = std::move(4,"4个元素");//错误
    Test&& rref1 = std::move(Test(4,"4个元素"));//先调用默认构造函数生成临时对象(右值)
   }
