//map采用红黑树，可存储成对的元素，及key（唯一）---value。其查找很快，时间复杂度为log n。
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
						map({type1，type2}，{type1，type2}，{{type1，type2});
						map(const map& m) // 拷贝其他同类型map<>对象构造函数
						map(iterator begin, iterator end );  //区间构造函数
						//map(iterator begin, iterator end, cmp) //带比较谓词的构造函数，即map<int,int,greater<int>>
						map(iterator begin, iterator end, const traits& _compare, const allocator& all) //带分配器
				2.尺寸函数：
						size() :当前map中元素的个数。
						maxsize():map可存储元素的最大个数
						无resize(),reserve(),
				3.插入函数：1.size变长了。2.只能map.insert().3不可指定插入位置
					插入单个元素：
						mapObject.insert(pair<type1,type2>(type1 a,type2 b));插入现有的key，即便现有的key对应value为空值，都不能插入。
						mapObject.insert(map<type1,type2>：：value_type(type1 a,type2 b));
						mapObject[key]=valu;若当前不存在该key，则插入该元素。存在则是修改该key的value。mymap["abc"] = 1-->mymap["abc"] = 2
					插入范围元素;
						mapObject.insert( InputIt first, InputIt last );
						void insert( std::initializer_list<value_type> ilist );如mymap.insert( { {7, "seven"}, {8, "eight"}, {9, "nine"} } );
						

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
					指定元素修改(修改value)：
						1.mapObject[key1] = value1;如mymap["abc"] = 1-->mymap["abc"] = 2
						2.不可以*iter = { 10, "222" };//map不可以通过迭代器修改y元素，只能修改其value
						2.iter->second="www";
					指定范围修改：
						1.使用copy() : string1_Vec2.resize(string1_Vec3.size());//使用copy必须指定拷贝到区域的size，而insert只需考虑capacity。
						//copy是覆盖性复制到string1_Vec3（其size内），复制少时会覆盖一部分size，复制多时则需要指定更大的size，而insert只需考虑capacity。
						copy(string1_Vec3.begin(), string1_Vec3.end(), string1_Vec2.begin());
						
				7.其他函数：include<algorithm>包含：sort；reverse；find；copy等
					查找：只能查找关键值key
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

*/
#include<iostream>
#include<set>
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

template<class T>
void showElement(T element)//元素而不是其迭代器--普通函数作为泛型算法for_each的第三个参数
{
    cout<<element<<" ";
}
template<class T1,class T2>
class ShowElement
{
    public:
    void operator()(T1 i)
    {
        cout<<i<<" ";
    
    }
    //ShowElement(){}
   // ShowElement(T2 i):var(i){}

    private:
    T2 var;
};

class Score
{

    private:
        
        int score;
    public:
        Score(int i):score(i){};
};

class ScoreName
{

    private:
        string studentname;
        int score;
    public:
        ScoreName(string name,int i):studentname(name),score(i){};
};
int g_int;

int main()
{
//set初始化：
     int i;
    cout<<"----------set初始化："<<endl;
    cout<<"列表初始化："<<endl;
    set<int> intSet1{6,3,1,4,2,5};//等价于={1,2,3};重复元素初始化值只取一个
    cout<<"intSet1={,,,}"<<" "<<intSet1.size()<<":{";
    for_each(intSet1.begin(),intSet1.end(),showElement<int>);//普通函数(实例而不是模板)作为for_each的第三个参数(必须是一元函数)--函数模板显式实例化--
    cout<<"}"<<"--for_each+普通函数模板"<<endl;
    cout<<"intSet1={,,,}"<<" "<<intSet1.size()<<":{";
    for_each(intSet1.begin(),intSet1.end(),ShowElement<int,string>());//仿函数(实例而不是模板)作为for_each的第三个参数(必须是一元函数)--仿函数(类)显式实例化()--
    cout<<"}"<<"--for_each+仿函数模板"<<endl;

    cout<<"对象初始化："<<endl;
    set<int> intSet2;//空对象-默认构造函数
    cout<<"intSet2;"<<" "<<intSet2.size()<<"{";
    for_each(intSet2.begin(),intSet2.end(),showElement<int>);//普通函数(实例而不是模板)作为for_each的第三个参数(必须是一元函数)--函数模板显式实例化--
    cout<<"}"<<endl;

    set<int> intSet3=intSet1;//拷贝构造
    cout<<"intSet3=inSet1;"<<" "<<intSet3.size()<<":{";
    for_each(intSet3.begin(),intSet3.end(),showElement<int>);//普通函数(实例而不是模板)作为for_each的第三个参数(必须是一元函数)--函数模板显式实例化--
    cout<<"}"<<endl;
   
    cout<<"迭代器或指针范围初始化"<<endl;
    set<int> intSet4(intSet1.begin(),intSet1.end());//迭代器范围
    cout<<"intSet4(intSet1.begin(),intSet1.begin()+2);"<<" "<<intSet4.size()<<":{";
    for_each(intSet4.begin(),intSet4.end(),showElement<int>);//普通函数(实例而不是模板)作为for_each的第三个参数(必须是一元函数)--函数模板显式实例化--
    cout<<"}"<<endl;

    vector<int> intVec={1,2,6,5,4,-1};
    set<int> intSet5(intVec.begin(),intVec.begin()+4);//迭代器范围
    cout<<"intVec={1,2,6,5,4,-1}"<<intVec.size()<<":{";
    for_each(intVec.begin(),intVec.end(),ShowElement<int,string>());
    cout<<"}"<<endl;
    cout<<"intSet5(intVec.begin(),intVec.begin()+4);"<<" "<<intSet5.size()<<":{";
    for_each(intSet5.begin(),intSet5.end(),showElement<int>);//普通函数(实例而不是模板)作为for_each的第三个参数(必须是一元函数)--函数模板显式实例化--
    cout<<"}"<<endl;
    
    set<int> intSetcmp1{1,3,2,5,4};
    cout<<"set<int> intSetcmp1;-->采用默认的less<T>仿函数类型(升序)作为比较规则"<<endl;
    cout<<"{";
    for_each(intSetcmp1.begin(),intSetcmp1.end(),showElement<int>);//普通函数(实例而不是模板)作为for_each的第三个参数(必须是一元函数)--函数模板显式实例化--
    cout<<"}"<<endl;

    set<int,greater<int>> intSetcmp2={1,3,2,5,4};
    cout<<"set<int,greater<int>> intSetcmp2;-->采用greater<T>仿函数类型(降序)作为比较规则"<<endl;
    cout<<"{";
    for_each(intSetcmp2.begin(),intSetcmp2.end(),showElement<int>);//普通函数(实例而不是模板)作为for_each的第三个参数(必须是一元函数)--函数模板显式实例化--
    cout<<"}"<<endl;

    vector<Score> scoreVec1={1,2,3};//Score::Score(int i):score(i){}
    ScoreName snVar={"nihao",1};
    vector<ScoreName> scoreNameVec1={{"nihao",1},{"joe",2},{"mark",3},{"jack",0}};//初始化列表
    set<ScoreName> ScoreNameSet1(scoreNameVec1.begin,scoreNameVec1.end())
    for_
   
        

    

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
	
	////排序。1.map默认以key排序（默认升序）2.在此实现按map-value排序（默认的升序）
	//
	//vector<PAIR> phoneNumber_vec(phoneNumber.begin(), phoneNumber.end());//将map复制到vector,模板参数必须是PAIR（pair<int,string>）
	//sort(phoneNumber_vec.begin(), phoneNumber_vec.end(),cmp);//使用算法中的sort对vector排序，此时，定义比较函数cmp，确定比较规则。
	//for (vector<PAIR>::iterator iter = phoneNumber_vec.begin(); iter != phoneNumber_vec.end(); iter++)
	//{
	//	cout << iter->second << ' ';
	//	
	//}
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
	return 1;
}

