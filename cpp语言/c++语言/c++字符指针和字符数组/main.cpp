/*
# sizeof和strlen：
  > sizeof：
    sizeof是运算符，编译期间确定对象的大小。而计算的对象可以是
    数据类型;变量;指针
    sizeof(charArrPtr) = 8 "计算指针大小
    sizeof(charArr) = char类型大小*元素个数 "计算数组大小
    
  > strlen
    strlen是函数，运行期间确定字符指针或数组名指向字符串的大小
    本质就是计算字符指针指向内存单元开始到第一个'\0'字符的字节数
    strlent(charPtr) = 不确定 ”charptr是一个指向字符的指针
    strlen(charArrPtr) = sizeof(charArr) "charArrPtr指向charArr字符数组。
                       = strlen(charArr)
# 字符指针与字符数组：
  > 字符指针：
    char* charPtr = "你好" "指向存放在代码段的只读字符串常量,等价const char*
    *charPtr = 'a' "错误
    char
  > cout和printf(%s)对字符指针或数组名的处理。
    其实也是输出至’\0‘z之前
    cout<<charPtr<<endl; "很可能不止输出指向的字符
    "输出字符指针指向的字符串空间的值，到'\0'之前
    cout<<charArr<<" "<<charArrPtr<<endl; "输出'\0'之前的字符串
    "输出字符指针的地址
    cout<<(void*)charArrPtr<<" "<< static_cast<const void*>charArrPtr<<endl;


 *
 *
 *
 *
 * 求字符串长度（不包含结束位）
问题一。为什么strlen()计算“12\03”会是3，而不是2？
	解答;\ddd和\xdd都是转义字符，是一个字符，分别表示八进制和十六进制，其十进制值就是相应的ascii值；\用于转义字符和默认修饰符（如“\812"就是"812"）
	如，“12\0125”--->由字符'1'、'2'、'\012'即'\x0A'即ascii值10、‘5’，‘\0’.
	
	类及结构体的大小？

问题：
1.sizeof（）和strlen（）区别：此编译器时32位，所以size（指针）=4
	sizeof(...)：反应的是对象被分配的内存大小，所以，sizeof（"12\0001"）大小是5，即不以'\0'结束，并且大小包括最后一个结束符‘\0’
		是运算符，在头文件中typedef为unsigned int，其值在编译时即计算好了，参数可以是数组、指针、类型、对象、函数等。
		由于在编译时计算，因此sizeof不能用来返回动态分配的内存空间的大小。实际上，用sizeof来返回类型以及静态分配的对象、结构或数组所占的空间，
		返回值跟对象、结构、数组所存储的内容没有关系。
		具体而言，当参数分别如下时，sizeof返回的值表示的含义如下：
		数组——编译时分配的数组空间大小；
		字符串——不以'\0'结束，并且大小包括最后一个结束符‘\0.如，sizeof（"12\0001"）大小是5，
		指针——存储该指针所用的空间大小（存储该指针的地址的长度，是长整型，应该为4）；
		size（*p）和sizeof（*array）------指的是首地址指向内存数据的大小，如sizeof（*pCharArray）=1
		类型——该类型所占的空间大小；（如类和结构体的大小，都是字节对齐的）
		对象——对象的实际占用空间大小；
		函数——函数的返回类型所占的空间大小。函数的返回类型不能是void。
	strlen（）：只能strlen（pchar）或strlen（chararray）或strlen（"123"），都是作用于字符串。
				a.等同于string.size（）,返回字符串的长度。该字符串可能是自己定义的，也可能是内存中随机的，该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，
				  直到遇到结束符NULL。返回的长度大小不包括NULL。
				b.strlen(...)是函数，要在运行时才能计算。参数必须是字符型指针（char*）。当数组名作为参数传入时，实际上数组就退化成指针了。
					只能strlen（pchar）或strlen（chararray）或strlen（"123"）
					
		
# 字符串、char* p、char str[]的区别：
    > 字符串：如const char *p="hello world";(这样只可读)
        × 字符串是存储文本区(只读)，视为const char*，因此，必须const char *p
          而不是const char*p="hello world"
        × 采用char *p=(char*)"hello world";*p=l---虽然语法没错，但是会gcc会发生核心转存储错误
          （因为不可写只读区）
        × const char c='a'; char*p=(char*)&c;*p=A;--语法没错，运行也没错--但不建议修改const常变量
         (const局部变量存放在栈上，物理上是可读写的,因此可通过指针修改其值)
        × sizeof("nihao")=6;strlen("nihao")=5;

	> 字符指针:char arr[]={"nihao"};char *p=arr;(这样可读写)或char*p="nihao";(这样只可读)
        × 字符指针建议如上使用，这样可以方便的读写其指向的数据内容。
        × sizeof(p)=8(指针大小为8);strlen(p)=5;
    
    > 字符数组:char str[]=“123”或={"123"},
        × 其中数组存放在栈，数组内容“123”，可更改
        × sizeof(str)=4;strlen(str)=3
    > char*作为实参形参：本质是char×-->char×
        × 可以是p-str[]=，也可以str-p，反正两个指针值一样
    > strlen():第一个结束符之前的字节数
        char * y = x;
	    while (*y++);//先while（*y），再y++，直到y为/0;
	    return(y-x-1);//地址差值

*/
#include<iostream>
#include<stdio.h>
using  namespace std;
struct struc
{
	char j;
	int i;
	
	int * k;
}struct1;
class test
{
public:

private:
	char j;
	int i;
	int* k;
	static int m;
	
} ;

int GetStringslength(char * x);
int main()
{
    int a=10;
    int * p=&a;
    printf("printf(p):%d\n",(int)voidp);
    cout<<"p: "<<p<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"(void*)p: "<<(void*)p<<endl;
    cout<<"-----------------------------"<<endl;
    char* pstr="nihao";
    cout<<"pstr: "<<pstr<<endl;
    cout<<"*pstr: "<<*pstr<<endl;
    cout<<"(void*)pstr: "<<(void*)pstr<<endl;
    cout<<"-----------------------------"<<endl;


}

//实现strlen（）功能。采用指针传递，对指针操作
int GetStringslength(char * x)
{
	char* y = x;
	while (*y++);


	return y-x-1;
}
