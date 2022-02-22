/*
1.不可以取空vector的迭代器！！！！
#vector:
>实现：
    和string类类似，都是基于动态数组实现的，因此具有类似的特性和操作函数
    但是，vector存储的元素类型无限制，是string类的泛化。
>特点：
    × 基于(动态)数组->线性且连续->可以数组下标随机访问
    × 删除和插入均是采用数组移位算法+可随机访问 ->便于尾部的插入和删除
    × 可扩容->插入(插入、赋值、连接)可使得vector自动扩容
      ==>效率低下(内存的释放和分配+构造和析构函数调用)+指针/引用/迭代器失效
      !!最后初始化后手动.reserve预留足够大的容量+迭代器失效的处理
  

>成员函数操作 ；
    × 构造函数：
	    vector<type> object_Vec;//size=0;capacity=0;string类capacity>0
		vector<type> object_Vec(int n);//string类没有该构造函数
		vector<type> object_Vec(int n,type m);
    	vector<type> object_Vec{val1,val2，……};
	    vector<type> object_Vec={val1,val2,……};

    	vector<type> object_Vec(int n,type m);
	    vector<type> object_Vec(int n,type m);

        vector<type> object_Vec(vector<type> other);//！仅复制源vector的size==>结果size=capacity=other.size()。赋值操作也是！
        ?vector<type> object_Vec(vector<type> other,iterator iter);
        ?vector<type> object_Vec(vector<type> other,iterator iter,int len);
	    vector<type> object_Vec(InputIterator first, InputIterator last);		 
        
    ×尺寸函数：string类也有下述的四个尺寸函数及其特性
        empty:返回true或false
		size():
		capacity():
		resize():一定重置size！
            × 非成员修改元素的函数(如copy())，使用之前必须.resize()确保目的vector的size足够大
            （而不是说capacity足够大就可以了）
		reserve():
            ×!对于vector，若当前capacity小于要重置的capacity，才会实际的释放-再分配capacity
            ×一般vector初始化后，就应reserve足够大的空间--以免后续的插入操作频繁再分配capavity
            × 使用 vector<type> (intVec).swap(intVec):释放空闲空间
    × 插入函数：内部自动修改size数据成员--从而.end()根据size自动更新--但应该注意迭代器的失效
	    Vec1.push_back()：尾部插入一个元素
        Vec2.insert(lociter, Vec3.begin(), Vec3.end())；//指定迭代器处插入一或多个元素
		   
	× 删除函数：同上
		Vec1.pop_back();//尾部删除一个元素
		Vec1.erase( string1_Vec3.begin(), string1_Vec3.end());//删除一或多个元素
    × 访问元素：
	    string1_Vec3[0];//数组下标--vector基于数组所以一定支持随机
		*(iter + 3);//迭代器--vector迭代器可支持随机
		string1_Vec3.at(0)//成员函数
	× 修改元素：
		x指定元素修改：
		    string1_Vec3[0] = "努力";//基于数组，因此vector支持下标访问和修改
			*(iter + 3) = "日狗";//因为vector是非常量迭代器，因此可通过迭代器修改。
        ×区间修改：
            copy;.insert等
        *清空：
            vec.clear();//size=0;capacity不变化

	× 赋值：以下均有vec1.size()=vec1.capacity=vec2.size()!!
        vec1=vec2;//src只能是对象
        void vec1.assign(vec2.begin(),vec2.end());//src只能是对象的一段或者n个val
    × 交换：
        void vector.swap(vector&)//以capacity区间交换！即size段互换，capacity段也互换。
            eg: vector<int> (intVec).swap(intVec)==>！调用.swap()删除intvec的空闲capacity
>非成员函数：
    × 查找：find--O(n)
        iterator find(RAiterator fistiter,RAiterator last,const T &val);//[first,last)查找第一个vali,成功返回范围1内第一个匹配的迭代器，失败返回end();
        iterator find_if(Vec1.begin(),Vec1.begin() + 10,func)//在[first，last)查找，符合一元判别式的的第一个元素。找的，则返回位置。
	    iterator find_first_of(first1, end1, first2, end2,[func]);//在范围1内查找范围2任意元素.
    × 排序：//sort--O(nlog2(n))
        void sort(RAiterator fistiter,RAiterator last)//默认用元素的<运算符(升序)
        void sort(RAiterator fistiter,RAiterator last,cmp)//使用自定义的cmp函数排序
    × 复制：
      outputiter copy(first,last,lociterator);//(覆盖)复制后的<=size--以免截断，应预先resize，确保size足够,返回目的容器已复制的下一个元素迭代器
	× 反转：
        void reverse(Vec1.begin(), Vec1.end()-10);
   

				    
		         
*/
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<algorithm>

using namespace std;

bool func( string &x)
{
	string::iterator iter=x.begin();
	cout << x << ' ' << *iter << endl;
	return ((*iter) >=65)&& ((*iter)<=97);
}
bool Bigger(const string& a, const string& b)
{
	return a.compare(b) > 0 ? 0 : 1;

}

int main()
{
    //测试capacity扩容和复制类操作复制的的size还是capacity

    vector<int> intVec1;//size=0;capacity=0;
    cout <<"intVec1()"<<"  "<< intVec1.size() << ' ' << intVec1.capacity() << endl;
  
    vector<int> intVec2{1,2,3};
    intVec2.reserve(5);
    cout <<"intVec2{1,2,3}"<<" "<< intVec2.size() << ' ' << intVec2.capacity() << endl;
    //测试复制构造函数和= ，只复制size段--vec2.size()=vec2.capacity=vec1.size()
    vector<int> intVec3(intVec2);
    cout <<"intVec3(intVec2)"<<"  "<< intVec3.size() << ' ' << intVec3.capacity() << endl;

    vector<int> intVec4;
    //intVec4=intVec2;
    intVec4.assign(intVec2.begin(),intVec2.end());
    cout <<"intVec4=intVec2"<<"  "<< intVec4.size() << ' ' << intVec4.capacity() << endl;
    //测试.swap()，交换capacity段而不只是size段---清空空闲空间
    vector<int> intVec5={7,8,9};
    intVec5.reserve(7);
    intVec5.swap(intVec2);
    intVec5.resize(2);
    cout << "intVec5.swap(intVec2)"<<"  "<< intVec5.size() << ' ' << intVec5.capacity() << endl;
   //测试copy(),(覆盖)复制后的<=size--以免截断，应预先resize，确保size足够
    vector<int> intVec6={1,2,3};
    intVec6.reserve(4);
    cout << "intVec6{1,2,3}"<<"  "<< intVec6.size() << ' ' << intVec6.capacity() << endl;
    vector<int> intVec7={4,5,6,7};
    intVec7.reserve(5);
    cout << "intVec7{1,2,3}"<<"  "<< intVec7.size() << ' ' << intVec7.capacity() << endl;
    intVec6.resize(intVec6.size()+intVec7.size());
    cout << "intVec6: "<<"  "<< intVec6.size() << ' ' << intVec6.capacity() <<" "<< *copy(intVec7.begin(),intVec7.end(),intVec6.begin()+1)<< endl;
    intVec7.clear();
    cout << "intVec7.clear()"<<"  "<< intVec7.size() << ' ' << intVec7.capacity() << endl;
    





  	//vector<string> string1_Vec4(string1_Vec3.begin(), string1_Vec3.begin() + 4);//复制string1_Vec3的前四个，总之，长度不可超过string1_Vec3的size。
	//vector<string>::iterator iter;

	//cout << string1_Vec2.size() << ' ' << string1_Vec2.capacity() << endl;
	//string1_Vec2.push_back("ztf");

	//cout << string1_Vec2.size() << ' ' << string1_Vec2.capacity() << endl;//初始时候size=capacity=5，但是随着插入的元素越多，capcity>size；
	//for (iter = string1_Vec2.begin(); iter != string1_Vec2.end(); iter++)
	//{
	//	cout << iter->compare("") << ' ';
	//	cout << *iter << endl;
	//}
	//cout << endl;

	//reserve()预定足够的存储空间
	//string1_Vec2.reserve(100);
	//cout << string1_Vec2.size() << ' ' << string1_Vec2.capacity() << endl;//初始时候size=capacity=0，但是随着插入的元素越多，capcity>size；
	//string1_Vec2.push_back("ztf");
	//cout << string1_Vec2.size() << ' ' << string1_Vec2.capacity() << endl; 
	//for (iter = string1_Vec2.begin(); iter != string1_Vec2.end(); iter++)
	//{
	//	cout << iter->compare("") << ' ';
	//	cout << *iter << endl;
	//}
	//cout << endl;

	//采用insert连接两vector
	//clock_t t1 = clock();
	//string1_Vec2.insert(string1_Vec2.end(), string1_Vec3.begin(), string1_Vec3.end());//vec3接入vec2后面
	//clock_t t2 = clock();
	//cout << "采用vector<>.insert函数的链接时间: " << (double)(t2 - t1) / CLOCKS_PER_SEC << "s" << endl;
	////system("pause");


	//采用insert在指定处之前，插入一段范围元素。

	//string1_Vec2.insert(string1_Vec2.begin(), string1_Vec3.begin(), string1_Vec3.end());
	/*string1_Vec2.resize(string1_Vec3.size());
	copy(string1_Vec3.begin(), string1_Vec3.end(), string1_Vec2.begin());*/

	//采用copy连接

	//clock_t t1 = clock();
	//copy(string1_Vec3.begin(), string1_Vec3.end(), back_inserter(string1_Vec2));//必须是back_inserter（de_vec）
	//clock_t t2 = clock();
	//cout << "采用std::copy函数的链接时间: " << (double)(t2 - t1) / CLOCKS_PER_SEC << "s" << endl;
	//system("pause");

	//采用copy修改指定范围.之前必须指定size。
	/*string1_Vec2.resize(string1_Vec3.size());
	copy(string1_Vec3.begin(), string1_Vec3.end(), string1_Vec2.begin());*/
	
	//修改指定元素。
	//iter = string1_Vec3.begin();
	//string1_Vec3[0] = "努力";
	//*(iter + 3) = "日狗";

	////访问。
	////下标访问:
	//cout << "string1_Vec3[0] =  " << string1_Vec3[0] << "   string1_Vec3[3] =  " << string1_Vec3[3] << endl;
	////引用访问
	//cout << "string1_Vec3.at(0) = " << string1_Vec3.at(0) << "string1_Vec3.at(3) = " << string1_Vec3.at(3) << endl;
	////迭代器
	//
	//cout << "iter begin() = " << *iter << "string1_Vec3 begin()+3 = " << *(iter+3) << endl;

	
	//查找。
	//在指定范围查找，某一个元素
	/*iter = find(string1_Vec1.begin(), string1_Vec1.begin()+20," ");
	if (iter != string1_Vec1.end())
	{
		*iter = "成功";
		cout << *iter<< endl;
	}
	else
	{
		cout << "未查找到！！" << endl;
	}*/

	//在指定范围内查找，符合一元判别式的的第一个元素。找的，则返回位置。
	//iter = find_if(string1_Vec1.begin(), string1_Vec1.end(),func);
	//if (iter != string1_Vec1.end())
	//{
	//	
	//	cout <<"查找成功："<< *iter << endl;
	//}
	//else
	//{
	//	cout << "未查找到！！" << endl;
	//}

	////翻转
	//reverse(string1_Vec1.begin(), string1_Vec1.end()-10);
	//cout << string1_Vec1.size() << ' ' << string1_Vec1.capacity() << endl;//初始时候size=capacity=0，但是随着插入的元素越多，capcity>size；
	//for (iter = string1_Vec1.begin(); iter != string1_Vec1.end(); iter++)
	//{
	//	cout << iter->compare("") << ' ';
	//	cout << *iter << endl;
	//}
	//cout << endl;

	////排序
	//sort(string1_Vec1.begin(), string1_Vec1.end(),Bigger);

	//cout << string1_Vec1.size() << ' ' << string1_Vec1.capacity() << endl;

	//string1_Vec1.reserve(20);

	////尾部循环插入。
	//
	//for (int i = 1; i <=string1_Vec1.capacity(); i++)
	//{
	//	string1_Vec1.push_back(to_string(i));
	//}

	//cout << string1_Vec1.size() << ' ' << string1_Vec1.capacity() << endl;
	//vector<string>::iterator iter = string1_Vec1.begin();
	//
	//
	//
	//string1_Vec1.pop_back();
	//
	//iter=string1_Vec1.erase(iter,iter+4);
	//cout << *iter<< endl;
	//cout << string1_Vec1.size() << ' ' << string1_Vec1.capacity() << endl;//初始时候size=capacity=0，但是随着插入的元素越多，capcity>size；
	//for (iter = string1_Vec1.begin(); iter != string1_Vec1.end(); iter++)
	//{
	//	cout << iter->compare("") << ' ';
	//	cout << stoi(*iter) << endl;
	//}
	//cout << endl;
//	system("pause");
	
return 0;
}
















//int main()
//{
//	vector<string> string1_Vec1;//创建一个空的vector，size=capacity=0；
//	vector<string> string1_Vec2(5);//创建一个容量为5的，填充默认为空字符串("")("/0")vector，初始时候size=capacity=0，但是随着插入的元素越多，capcity>size；
//									//会自动的，反复的将旧元素拷贝到新分配的内存空间。开销大，耗时。解决：使用reserve()事先申请足够大的容量。
//	vector<string> string1_Vec3(5,"ztf");
//
//	vector<string> string1_Vec4(string1_Vec3.begin(), string1_Vec3.begin()+6);//复制string1_Vec3的前四个，总之，长度不可超过string1_Vec3的size。
//	vector<string>::iterator iter;
//
//	//
//	cout << string1_Vec1.size() << ' ' << string1_Vec1.capacity() << endl;
//	for (iter = string1_Vec1.begin(); iter!=string1_Vec1.end();iter++)
//	{
//		cout << *iter<< endl;
//	}
//	cout << endl;
//
//	//
//	cout << string1_Vec2.size() << ' ' << string1_Vec2.capacity() << endl;
//	string1_Vec2.push_back("ztf");
//
//	cout << string1_Vec2.size() << ' ' << string1_Vec2.capacity() << endl;//初始时候size=capacity=0，但是随着插入的元素越多，capcity>size；
//	for (iter = string1_Vec2.begin(); iter != string1_Vec2.end(); iter++)
//	{
//		cout << iter->compare( "")<<' ';
//		cout << *iter << endl;
//	}
//	cout << endl;
//
//	//
//	cout << string1_Vec3.size() << ' ' << string1_Vec3.capacity() << endl;
//	for (iter = string1_Vec3.begin(); iter != string1_Vec3.end(); iter++)
//	{
//		cout << iter->compare("") << ' ';
//		cout << *iter << endl;
//	}
//	cout << endl;
//
//	//
//	cout << string1_Vec4.size() << ' ' << string1_Vec4.capacity() << endl;
//	for (iter = string1_Vec4.begin(); iter != string1_Vec4.end(); iter++)
//	{
//		cout << iter->compare("") << ' ';
//		cout << *iter << endl;
//	}
//	cout << endl;
//
//	system("pause");
//
//}
