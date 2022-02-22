//Test类实现
#include <iostream>
#include <string>
#include<cstring>
#include"Test.h" //自定义头文件Test.h对应的源文件也必须包含该头文件
using namespace std; //
Test::Test(int i, string s) :size(i), name(s){
		arrPtr = new int[size];
		for (int i =0; i <size; i++) {
			arrPtr[i] = size - 1 -i;

		}
			

		cout << "default constructor：" << endl;

	}
	//类成员函数可以访问其同类对象的private成员。
Test::Test(const Test& other) : size(other.size), name(other.name){
		
		arrPtr = new int[size];
		memcpy(arrPtr, other.arrPtr, size*(sizeof(int)));
		cout<< "(deep copy) copy constructor:" << endl;
	}
Test& Test::operator=(const Test& other){
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
Test::Test(Test&& other):size(other.size),arrPtr(other.arrPtr),name(std::move(other.name)) {
        other.size = 0;
		other.arrPtr = nullptr;
		cout << "shallow copy) move constructor:" << endl;
	}
Test& Test::operator=(Test&& other){
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
Test::~Test(){
        cout << size <<"--decontructor:" << endl;
		delete[] arrPtr;
	}
void Test::setName(string str){
        name = str;
}
