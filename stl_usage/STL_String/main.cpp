/*
1.不可以取空string的迭代器！！！！
#string:
> 特点：
    1.基于动态数组实现，因此，当进行改变string对象中数据操作时
      如复制构造函数、赋值操作，连接，增加字符。这时，若capacity不够，
      则会自动的清空-扩容。这个开销比较大。
    2.因为是基于数组(静态和动态)，所以可以支持数组下标随机访问
     (string1[i]),也支持迭代器操作string::iterator iter=striing1.begin()
    3.便于随机访问、尾部的快速插入和删除。不便于大量的随机插入和删除
    
> 成员函数操作：
	× 构造函数：
	    string str;//size=0;capacity=N.string1.
        #string str(int n);//错误，无该构造函数
		string str(int n,char m);

        string str(char* cStr);//str=null,则初始化为size=0的空字符串
        #string str(char* cstr,int len);//必须等于len，因此可能出错。不建议使用。
        string str(char* cstr,int index ,int len);//index下标处开始的<=len
        string str(char* begin,char* end);//[begin,end)区间的字符

        string str(string other);//复制构造函数,不像vector的拷贝构造函数size=capacity
        string str(string other,int index);//index下标开始的到首个'\0'为止<=len
        string str(string other ,int index,int len);)//index开始s <=len
        string str(InputIterator first, InputIterator last);//迭代器
				
	× 输入函数：终端键入 123 45 6再按回车建，结果见测试代码
		cin>>str;                                   //清空-空格/tab/enter的之前的输入--换行符会进入流中(空格，tab直接丢弃）
                                                    //---调用cin.ignore()丢弃换行符避免后续cin读入，如后续的getline读入该换行符
		getline(cin，str);                          //清空，读入一行，包括空格但是最后的换行符不读入但进入流中
		istringsstream is（“12 45 79”);is>>s1>>s2;  //将包括空格的字符串，输入istringssrtream，在以空格为间断
                                                    //但不包括空格，分别输给s1，s2，s3,size均为2

	× 输出函数：
		cout<<s1<<s2;                               //单个输出
		ostringstream os;os<<s1<<s2;cout<<os.str(); //将多个string首尾连接成一个string.
	× 尺寸函数：
		max_size():最大的可申请的内存容量
		size():实际所用的字节数，即首个'\0'之前的字节。string类会自动的数据的末尾添加一个结束符。
		capacity():当前可存储的容量
		resize():copy（）调用resize()以保证size足够。
		reserve():insert保证capacity足够。提前申请足够的容量，避免后续容量不过，反复的释放-申请动态内存
	× 插入函数：
		string1.push_back();若迭代器初入待删除的尾部，则该操作后，iterator不会自动更新，此时该迭代器必须手动更新，否则出错。
	    string1.insert(string1_Vec2.end(), Vec3.begin(), Vec3.end())；insert()设置capacity足够大，以避免开销

	× 删除函数：
        string1.pop_back();返回值为void，若迭代器初入待删除的尾部，则该操作后，iterator不会自动更新，
		string1.erase( string1.begin(), string1.end())。删除[first，last)成功，返回迭代器指向last
    * 访问函数：
		string1[0]
		*(iter + 3)
		string1.at(0)
    * 赋值：！不像vec的赋值一样vec1.size=vec.capacity=vec2.size
        =;//只能整体
        string1.assign();//可以string对象整体(vectoc.assig不行)，一段，n-value
	× 转换函数：
		× string--->char*:
             str.c_str();//返回string的首个结束字符为止的const字符数组---.size()+1
             str.data();//同上
             str.copy();//复制<=len 且首个结束字符之前的字符串给char*,应手动添加结束字符到char*
		× string--->int:
            strtol/strtoll/strtoul/strtoull(const char*p,char**endptr,int base);--<stdlib.h>
                eg:strtol("  123abc",endptr,1o);==>返回值为123
                    strtol("  abc123",endptr,10);==>返回0,即转换失败 cout<<endptr;==>abc123
            atoi(const char*p);//原理同上但只能十进制--<stdlib.h>,不建议使用！
            stoi(const &string,size_t *idx,int base )//strtol，但是stoi可以使用string类

		× int---->string:
            snprinft();//<stdio.h>--
            to_string();//<string>--
>非成员函数：include<algorithm>包含：sort；reverse；find；copy等
			子串：s4 = s2.substr(0,10);
				
		
		
			连接：	string1_Vec2.insert(string1_Vec2.end(), string1_Vec3.begin(), string1_Vec3.end());
					copy(string1_Vec3.begin(), string1_Vec3.end(), back_inserter(string1_Vec2));
			修改：
				string.replace替换:无论被替换部分的替换部分大小关系，只要不超过max_size都能通过自动申请内存，清除该区域再进行修改。
					1.string.replace(n,m,):
					2.string.replace(firstptr,lastptr,):
				范围修改：
					1.使用copy():copy是覆盖性复制；若目的区间size小于源区间size，会产生截断复制
						string1_Vec2.resize(string1_Vec3.size());//使用copy前，必须手动确保copy目的区间size大于等于源区间size
											//否则会截断复制
						copy(string1_Vec3.begin(), string1_Vec3.end(), string1_Vec2.begin());
				指定元素修改：
					1.string1_Vec3[0] = "努力";
					2.*(iter + 3) = "日狗";
			反转：reverse(string1_Vec1.begin(), string1_Vec1.end()-10);
			
					交换：void vector.swap(vector&):交换两个同类型,只需保证max_size的相同即可，size，capacity不同没事。
            比较


			*/
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<time.h>
#include<algorithm>

using namespace std;

int main()
{
    
    //----构造函数--------------------------
    string s1;
	//string s2(5); //错误，string类没有该构造函数
    string s3(40,'1');

	string s4("123nihao");
    string s5="123nihao123456789";

    const char *p={"1234"};//"123nihao"字符串是存储在文本区(只读)的const char*.
	string s6(p,40);
    string s7(p,2,40);
    string s8(s4);
	string s9=s4;
	string s10(s4,2);
    string s11(s4,2,15);
    //构造函数测试：
    cout<<"-------------"<<"测试构造函数和尺寸函数:"<<endl;
    cout<<"string"<<"  "<<"length"<<"  "<<"size"<<"  "<<"capacity"<<"  "<<"max_size"<<endl;
    cout <<"s1: "<<s1<<"  "<<s1.length() << "  " << s1.size() <<"  "<< s1.capacity() <<"  "<< s1.max_size() <<"  "<<endl;
    //cout <<"s2: "<<s2<<"  "<<s2.length() << "  " << s2.size() <<"  "<< s2.capacity() <<"  "<< s2.max_size() <<"  "<<endl;
    cout <<"s3: "<<s3<<"  "<<s3.length() << "  " << s3.size() <<"  "<< s3.capacity() <<"  "<< s3.max_size() <<"  "<<endl;
    cout <<"s4: "<<s4<<"  "<<s4.length() << "  " << s4.size() <<"  "<< s4.capacity() <<"  "<< s4.max_size() <<"  "<<endl;
    cout <<"s5: "<<s5<<"  "<<s5.length() << "  " << s5.size() <<"  "<< s5.capacity() <<"  "<< s5.max_size() <<"  "<<endl;
    cout <<"s6: "<<s6<<"  "<<s6.length() << "  " << s6.size() <<"  "<< s6.capacity() <<"  "<< s6.max_size() <<"  "<<endl;
    cout <<"s7: "<<s7<<"  "<<s7.length() << "  " << s7.size() <<"  "<< s7.capacity() <<"  "<< s7.max_size() <<"  "<<endl;
    cout <<"s8: "<<s8<<"  "<<s8.length() << "  " << s8.size() <<"  "<< s8.capacity() <<"  "<< s8.max_size() <<"  "<<endl;
    cout <<"s9: "<<s9<<"  "<<s9.length() << "  " << s9.size() <<"  "<< s9.capacity() <<"  "<< s9.max_size() <<"  "<<endl;
    cout <<"s10: "<<s10<<"  "<<s10.length() << "  " << s10.size() <<"  "<< s10.capacity() <<"  "<< s10.max_size() <<"  "<<endl;
    cout <<"s11: "<<s11<<"  "<<s11.length() << "  " << s11.size() <<"  "<< s11.capacity() <<"  "<< s11.max_size() <<"  "<<endl;
    //cout<<(void*)&s3<<" "<<sizeof(s3)<<" "<<(void*)&s4<<" "<<sizeof(s4)<<"  "<<(void*)&s5<<" "<<sizeof(s5)<<endl<<endl;

	//string输入输出操作
    cout<<"-----------测试string输入"<<endl;
    string strCin="world";
    cin>>strCin;//空格分段，如键入123 23 4再按enter，strCin="123"
    cin.ignore();//丢弃cin输入后的换行符，避免被下一个输入读入。
    cout<<"cin>>strCin: "<<strCin<<"  "<<strCin.size()<<"  "<<strCin.capacity()<<endl;

    string strGetLine="hello";
    getline(cin,strGetLine);//strGetLine="23 4\n"--把换行符也输入了size=5
    cout<<"getline(strGetLine)): "<<strGetLine<<"  "<<strGetLine.size()<<"  "<<strGetLine.capacity()<<endl;
    
    string strStream="123 45 6";
    cout<<"strStream: "<<strStream<<"  "<<strStream.size()<<"  "<<strStream.capacity()<<endl; 
    string str01("nihao"),str02,str03;
    istringstream iStrStream;
    iStrStream.str(strStream);
    iStrStream>>str01>>str02>>str03;//"123", "45" "6"
    cout<<"str01: "<<str01<<"  "<<str01.size()<<"  "<<str01.capacity()<<endl;
    cout<<"str02: "<<str02<<"  "<<str02.size()<<"  "<<str02.capacity()<<endl; 
    cout<<"str03: "<<str03<<"  "<<str03.size()<<"  "<<str03.capacity()<<endl;

    ostringstream ostr_stream;
    ostr_stream << str01<< str02 << str03<<"ni hao"<<endl;;
	cout << ostr_stream.str();

    //string转换测试：
    cout<<"-------string 转换测试"<<endl;
    string strToCArr="hello world";
    cout<<""<<strlen(strToCArr.data())<<" "<<strToCArr.data()<<endl;
    cout<<""<<strlen(strToCArr.c_str())<<" "<<strToCArr.c_str()<<endl;
    char desCArr[10]="11111111";//不可将内容复制到char× p。
    char*p1=desCArr;
    strToCArr.copy(desCArr,3,2);//string::copy(char*,int len,int pos )
    cout<<p1<<endl;//复制<=len且首个结束字符之前的字符。开发人员应该自己写入结束字符


	//赋值：--不会向vector的赋值一样vec1.size=vec1.capacity=vec2.size
    cout<<"-------------测试string赋值"<<endl;
    string str1{"nihao"};
    str1.reserve(10);
    cout <<"str1: "<<str1<<"  "<<str1.length() << "  " << str1.size() <<"  "<< str1.capacity() <<"  "<< str1.max_size() <<"  "<<endl;
    //string str2{"hello"};
    string str2=str1;
    cout <<"str2: "<<str2<<"  "<<str2.length() << "  " << str2.size() <<"  "<< str2.capacity() <<"  "<< str2.max_size() <<"  "<<endl;
    //str2=str1;
    str2.assign(str1.begin(),str1.begin()+2);
    cout <<"str2: "<<str2<<"  "<<str2.length() << "  " << str2.size() <<"  "<< str2.capacity() <<"  "<< str2.max_size() <<"  "<<endl;
	//clear():--size=0;释放string类内的动态分配内存;capacity不为0;近似等价于析构
    string strclear="nihao";
    cout <<"strclear: "<<strclear<<"  "<<strclear.length() << "  " << strclear.size() <<"  "<< strclear.capacity() <<"  "<< strclear.max_size() <<"  "<<endl;
    strclear.clear();
    cout <<"strclear: "<<strclear<<"  "<<strclear.length() << "  " << strclear.size() <<"  "<< strclear.capacity() <<"  "<< strclear.max_size() <<"  "<<endl;
    //测试匿名对象：
    string strnoname;
    strnoname=string("nimingduixiang");
    cout <<"strnoname: "<<strnoname<<"  "<<strnoname.length() << "  " << strnoname.size() <<"  "<< strnoname.capacity() <<"  "<< strnoname.max_size() <<"  "<<endl;
   	//cout << s2[0] <<' ' <<s2[17] << endl;
	//cout << s2.at(0) << ' ' << s2.at(17) << endl;
	//string::iterator iter = s2.begin();
	//cout << *iter << ' ' << *(iter + 17) << endl;

	////插入
	//s2.push_back('0');
	//cout << s2 << endl;
	//string::iterator iter = s2.begin();
	//s2.insert(iter,30,'1');
	//cout << s2 << endl;
	////s2.pop_back();
	//cout << s2 << endl;
	//s2.erase(iter,iter+1);
	//cout << s2 << endl;
	//system("pause");
	

	//修改。copy（）和string.replace()
	///*string::iterator iter = s2.begin();
	//copy(s4.begin(),s4.end()-1,iter);
	//cout << s2.length() << ' ' << s2.size() << ' ' << s2.capacity() << ' ' << s2.max_size() << ' ' << endl;
	//cout << s2 << endl;
	//
	//s2.replace(0,3,"66" );*/

	//string::iterator iter = s2.begin();
	//s2.replace(iter,iter+4,5,'6');
	//cout << s2.length() << ' ' << s2.size() << ' ' << s2.capacity() << ' ' << s2.max_size() << ' ' << endl;
	//cout << s2 << endl;
	//system("pause");

	//交换。
	/*cout << s2 << endl;
	cout << s4 << endl;
	s2. swap(s4);
	cout <<s2 << endl;
	cout << s4 << endl;*/

	//子串
	//s4 = s2.substr(0,10);
//	cout << s4.length() << ' ' << s4.size() << ' ' << s4.capacity() << ' ' << s4.max_size() << ' ' << endl;
	//cout << s4 << endl;
	//cout << s2.length() << ' ' << s2.size() << ' ' << s2.capacity() << ' ' << s2.max_size() << ' ' << endl;
//	cout << s2 << endl;
//	system("pause");
return 0;

}


	



