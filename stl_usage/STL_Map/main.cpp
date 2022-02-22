//map采用红黑树，可存储成对的元素:key（唯一）---value。其查找很快，时间复杂度为log n。
//驱动程序：插入，删除，查找，排序。
//map的查找时间复杂度为为O（logN），（尾部）删除、插入时间复杂度也为O(logN)
/*map：
				特点：1.存储对象为pair<type1,type2>(key,value)
					  2.key是自动排序的且是唯一的
					  3.适合海量的查询：是基于RB树的，根据key值快速查找记录，查找的复杂度基本是Log(N)，如果有1000个记录，最多查找10次，1,000,000个记录，最多查找20次。
					  4.适合海量的随机插入和删除很好：因此，有insert和erase函数，而无pop_back,push_back
					  4.key不需要排序了
					  5.（链式容器）map的迭代器不可以+k，-k，迭代器相减,=，
					  (1)set使用接引用运算符*取值，而map使用first和second取值。

					  (2)set的迭代器都是常量迭代器，不能用来修改所指向的元素，而map的迭代器是可以修改所指向元素的。

					  (3)set没有重载[]运算符，而map中重载了，因为直接使用[]改变元素值会打乱原本正确的顺序，要改变元素值必须先删除旧元素，则插入新元
				函数操作 ；
				0.运算符：== != < <= > >=

				1.构造函数：（默认按key升序）；map<int,int,greater<int>>则实现降序。
						map();//默认构造函数
						map({type1，type2}，{type1，type2}，{{type1，type2});//c++11列表初始化:={{k1,v1},{k2,v2}};具有通用性
						map(const map& m) //复制构造函数
						map(iterator begin, iterator end );  //区间构造函数
						map(iterator begin, iterator end, cmp) //带比较谓词的构造函数.指定默认仿函数作为cmp，map<int,int,greater<int>>;
                                                               //指定自定义cmp，cmp可为函数模板类型、仿函数类型
						map(iterator begin, iterator end, const traits& _compare, const allocator& all) //带分配器
				2.尺寸函数：
						size() :当前map中元素的个数。
						maxsize():map可存储元素的最大个数
						无resize(),reserve(),
				3.插入函数：1.size变长了。2.只能map.insert().3不可指定插入位置
					插入单个元素：
						mapObject.insert(pair<type1,type2>(type1 a,type2 b));//插入已存在的key无效，即便现有的key对应value为空值，都不能插入。
						mapObject.insert(map<type1,type2>：：value_type(type1 a,type2 b));//value_type为某容器专有数据类型，在此等价pair<>
						mapObject[key]=valu;//插入未存在的key，为插入;否则修改该key的value。如修改mymap["abc"] = 1-->mymap["abc"] = 2
					插入范围元素;
						mapObject.insert( InputIt first, InputIt last );//迭代器range
						void insert( std::initializer_list<value_type> ilist );//列表插入，如mymap.insert( { {7, "seven"}, {8, "eight"}, {9, "nine"} } );
						

				4.删除函数：两者擦除都导致，size变短了。
					删除某一个元素：
						iterator erase（iterator it);//通过迭代器删除
						size_type erase(const Key&key);//通过关键字删除
					删除范围：
						iterator erase（iterator first，iterator last）//删除一个范围
						
						clear()就相当于enumMap.erase(enumMap.begin(),enumMap.end());
				5.访问函数：
						迭代器：前向迭代器map<int, string>:terator iter ；反向迭代器map<int, string>::reverse_iterator iter
								1.iter->first;iter->second;
								2.*iter获得pair<>
						[]:mapObject[key1],如mapObject["ztf"]
				6.修改：只能修改value,不可以*iter = 
					指定元素修改(只可：修改value)：
						1.mapObject[key1] = value1;如mymap["abc"] = 1-->mymap["abc"] = 2
						2.不可以*iter = { 10, "222" };//map不可以通过迭代器修改y元素，只能修改其value
						2.iter->second="www";
					指定范围修改：
						1.使用copy() : string1_Vec2.resize(string1_Vec3.size());//使用copy必须指定拷贝到区域的size，而insert只需考虑capacity。
						//copy是覆盖性复制到string1_Vec3（其size内），复制少时会覆盖一部分size，复制多时则需要指定更大的size，而insert只需考虑capacity。
						copy(string1_Vec3.begin(), string1_Vec3.end(), string1_Vec2.begin());
						
			    7.排序：map基于rb树;map<T1,T2,cmp>，cmp可为基于key比较的函数模板类型或仿函数类型
                        1.默认是自动升序:map<T1,T2>等价于map<T1,T2,less<T1>>)
                        2.自定义自动降序:map<T1,T2,greater<T2>>
                        3.自定义函数模板类型：
                            template<class T>
                            bool funcmp(const T& lkey,const T& rkey) const
                            {
                                return (lkey<rkey);//等价于less<T>升序
                                //lkey>rkey;//降序
                            }

                            map<T1,T2,bool (*)(T,T)> mymap(funccmp)
                        4.自定义仿函数类型：
                            template<class T>
                            class functorcmp
                            {
                                public:
                                    bool operator()(T& rkey,T& lkey)
                                    {
                                        return (lkey<rkey);
                                    }
                            };
                            

				8.查找：只能查找关键值key
						1.map.find(key) : 只能全局查找value，存在则返回对应的位置的迭代器，否则返回end().
						2.map.count(key); 只能全局用来查找map中某个某个键值出现的次数,在map中只能0或1，判断该key出现没出现。
						3.map.lower_bound函数用法，这个函数用来返回要查找关键字的下界[(是一个迭代器)
						4.map.upper_bound函数用法，这个函数用来返回要查找关键字的上界)(是一个迭代器)
					连接：	string1_Vec2.insert(string1_Vec2.end(), string1_Vec3.begin(), string1_Vec3.end());
						copy(string1_Vec3.begin(), string1_Vec3.end(), back_inserter(string1_Vec2));

					反转：map本身是有序的不需要翻转。升序转换为降序：map<int, string,greater<int>> map2(map1.begin(),map1.end());
					排序：map本身就是自动按可以排序的
					赋值：不需要
					交换：void map.swap(map&) : 交换两个同类型向量的数据；l
					map运算符：吧 

         	7.其他函数：include<algorithm>包含：sort；reverse；find；copy等

*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include <functional>
using namespace std;

typedef pair<int, string> PAIR;
bool cmp(const PAIR &x, const PAIR &y)//sort的第三个参数，为比较函数名，因为比较的对象是vector元素--pair<int,string>对象--中的second成员。
{
	return x.second > y.second;
}
 template<class T1,class T2>//T1,T2在此作为容器的元素数据类型(间接数据类型)
    ostream& operator<<(ostream& out,pair<T1,T2> mappair)//<<输出运算符重载,必须作为非成员函数
    {
        cout<<"     "<<mappair.first<<"--"<<mappair.second<<endl;
        return cout;
    }
 template<class T>//函数模板实例(或仿函数)作为for_each的第三个参数，for_each(,,showPair<map<int,string>::value_type>)
	void showPair(T i)
    {
        cout<<i<<endl;
    }
 template<class T>
 class showPairFunctor//仿函数作为for_each第三个参数
{
    public:
    void operator()(const T& i) const
    {
        cout<<i<<endl;
    }
};

template<class Key>
bool fncomp (Key lhs, Key rhs) 
{
    return lhs<rhs;
}
template<class Key>
class classcomp
{
    public:
         bool operator() (const Key& lhs, const Key& rhs) const
        {
            return lhs>rhs;
        }
};
int main()
{
    /*
	map<int, string> phoneNumber;
	map<int, string> map1 = { {2,"222"},{3,"333"},{0,"000"} };
	map<int, string,greater<int>> map2(map1.begin(),map1.end());
	map<int, string> map3= { { 2, "222" }, { 3, "333" }, { 0, "000" } };
	//插入，三种方式。
		//insert插入:当前不存在key则插入。若现存在该key，即便现存在key对应value为空值，都不能插入
	phoneNumber.clear();//
	phoneNumber.insert(pair<int, string>(1, "one"));
	phoneNumber.insert(map<int, string>::value_type(2, "two"));
		//[]://若当前不存在该key，则插入该元素。存在则是修改该key的value。mymap["abc"] = 1-->mymap["abc"] = 2
	phoneNumber[3] = "three";
	phoneNumber[4] = "four";
	phoneNumber[5] = "five";
	phoneNumber[6] = "six";
	phoneNumber[7];//phoneNumber[7] = "eight";//若当前不存在该key，则插入该元素。存在则是修改该key的value。mymap["abc"] = 1-->mymap["abc"] = 2
	phoneNumber[8] = "eight";
	phoneNumber.insert(pair<int, string>(7, "ztf"));//insert插入现存在的key，即便现存在key对应value为空值，都不能插入
	map<int, string> ::iterator iter = phoneNumber.begin();
	for (iter = phoneNumber.begin(); iter != phoneNumber.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}

	//删除：
		//删除某一个元素
	iter = phoneNumber.begin();
	phoneNumber.erase(iter);
	phoneNumber.erase(7);
	for (iter = phoneNumber.begin(); iter != phoneNumber.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}
	
	//map迭代器不可以=；
		//删除范围元素
	iter = phoneNumber.begin();
	phoneNumber.erase(iter,iter);//函数参数方向为右至左。
	for (iter = phoneNumber.begin(); iter != phoneNumber.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}

	//访问：
		//[]访问value :
	cout << phoneNumber[6] << endl;
		//迭代器访问。key和value
	iter = phoneNumber.begin();
	cout << iter->first <<' '<< iter->second<< endl;//cout << *iter << endl,不可以输出pair<>元素

	//修改：
		//[]修改value：
	phoneNumber[6] = "ztf";
	cout << phoneNumber[6] << endl;
		//迭代器只能修改其value
	iter->second = "www";//*iter = { 10, "222" };//map不可以通过迭代器修改y元素，只能修改其value
	cout << iter->first << ' ' << iter->second << endl;

	
	for (iter = phoneNumber.begin(); iter!=phoneNumber.end();iter++)
	{
		cout << iter->first << ' ' << iter->second<<endl;
	}
	//iter等于end（）

	//删除,通过迭代器
	//iter = phoneNumber.begin();
	//++iter;//链表容器，earse通过迭代器擦除后，iter不指向后一个元素。也不指向任何元素。但返回指向下一个元素的指针。
	//iter=phoneNumber.erase(iter);//phoneNumber.erase(iter)则报错。
	////删除，通过关键值
	//phoneNumber.erase(4);//迭代不影响，但若删除当前迭代器指向的元素，则会报错。
	//
	////phoneNumber.erase(phoneNumber.begin(),phoneNumber.begin()+5);//错误，因为除了string和vector的迭代器外，其余的类的迭代器不能加。
	//for (; iter != phoneNumber.end(); iter++)
	//{
	//	cout << iter->first << ' ' << iter->second << endl;
	//}

	//查找。。。整个范围内，查找关键值。map的查找时间复杂度为为O（logN），删除，插入时间复杂度也为O(logN)
		//map.find(key)
	iter = phoneNumber.find(6); //某个关键值，若存在就并返回该关键值的迭代器，不存在就返回end（）
		//map.count(key)
	cout<<phoneNumber.count(6);
	
    //交换：map.swap(map&)
	phoneNumber.swap(map1);
	for (iter = phoneNumber.begin(); iter != phoneNumber.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}

	//翻转
	//reverse(phoneNumber.begin(),phoneNumber.end());
	for (iter = phoneNumber.begin(); iter != phoneNumber.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}
	for (iter = map2.begin(); iter != map2.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}

	//==
	cout << (map3 != map1);
	system("pause");
    */
   
    
    //排序。1.map默认以key排序（默认升序）2.在此实现按map-value排序（默认的升序）
	cout<<"-----测试map排序： "<<endl<<endl;
    cout<<"× map默认以key升序排序："<<endl;
    map<int,string> maptestsort1={{4,"four"},{1,"one"},{3,"three"},{2,"two"}};
    for_each(maptestsort1.begin(),maptestsort1.end(),showPair<map<int,string>::value_type>);
    
    cout<<"× map以key降序排序："<<endl;
    map<int,string,greater<int>> maptestsort2(maptestsort1.begin(),maptestsort1.end());
    for_each(maptestsort2.begin(),maptestsort2.end(),showPair<map<int,string>::value_type>);

    map<int,string,bool(*)(int,int)> maptestsort3(maptestsort1.begin(),maptestsort1.end(),fncomp<int>);//函数指针数据类型等价于std::function<bool(int,int)>等价于typeof bool(*FUN)(int,int)
    cout<<"× map以key升序排序--基于函数指针："<<endl;
    for_each(maptestsort3.begin(),maptestsort3.end(),showPair<map<int,string>::value_type>);

    map<int,string,classcomp<int>> maptestsort4(maptestsort1.begin(),maptestsort1.end());
    cout<<"× map以key降序排序--基于仿函数："<<endl;
    for_each(maptestsort4.begin(),maptestsort4.end(),showPairFunctor<map<int,string>::value_type>());
	return 1;
}

