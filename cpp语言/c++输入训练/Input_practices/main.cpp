/*字母字符串中从头到尾顺序查找数字单词
1.从头到尾顺序查找查找数字英文单词，查找不到报错。
2.什么数据结构存储字符串？以便于后续操作。
3.怎么切割？
4.怎么查找匹配？时间复杂度&空间复杂度。
5.查找到的单词用什么存储？
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<int, string> numbers;

}





/*#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	
	string phoneNumber;
	getline(cin,phoneNumber);

	cout <<phoneNumber.size()<<" "<< phoneNumber;
	system("pause");

	map<string, string> mapNumber;
	mapNumber.insert(pair<string, string>("Zero", "Ling"));
	mapNumber.insert(pair<string, string>("Two", "Er"));
	mapNumber.insert(pair<string, string>("Three", "San"));
	mapNumber.insert(pair<string, string>("Four", "Si"));
	mapNumber.insert(pair<string, string>("Five", "Wu"));
	mapNumber.insert(pair<string, string>("Six", "Ling"));
	mapNumber.insert(pair<string, string>("Seven", "Ling"));
	mapNumber.insert(pair<string, string>("Eight", "Ling"));
	mapNumber.insert(pair<string, string>("Nine", "Ling"));
	mapNumber.insert(pair<string, string>("double", "Next")sss 	while (phoneNumber.size()!=0)
	{
		phoneNumber.find();
	}
}*/





/*char s[11][7] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","double"};

cout << strlen(*(s+l));
system("pause");
return 1;*/


//题目描述
//请您编写一个拼音与英文转换的函数，如果输入的电话号码是英文单词，输出对应的电话号码的中文拼音，如果输入的电话号码是中文拼音，输出对应的电话号码的英文单词。例如，输入“OneZeroDoubleThree”，则输出YiLingSanSan。拼音、英文读法见下表：
//Yi Er San Si Wu Liu Qi Ba Jiu Ling
//One Two Three Four Five Six Seven Eight Nine Zero
//注意：
//1、 每个单词均为首字母大写，遇到连续两个相同数字，输入可以前面加Double，输出不可以加Double。
//输入描述 :
//由首字母大写组成的字符串，表示一个电话号码的英文单词或者中文读法。字符输入范围为数字 0、1、2、3、4、5、6、7、8、9的英文单词或者中文拼音。
//输出描述 :
//输出：
//根据输入的，输出对应的电话号码字符串。如果输入的电话号码是英文单词，输出对应的电话号码的中文拼音；如果输入的电话号码是中文拼音，输出对应的电话号码的英文单词。若输入非法，输出字符串“ERROR”。
//
//注意：最终交付的函数代码中不要向控制台打印输出无关任何信息。
//示例1
//输入
//
//OneTwoThreeFourFiveSixSevenEightNineZero
//输出
//
//YiErSanSiWuLiuQiBaJiuLing
//
//
//在某种场景下，开发人员决定使用字母来表示一个正整数，该方法利用英文的小写字母表示，映射规则很简单，按字母顺序每一个字母都代表一个值。如下所示列表中的部分内容。
//字母表示 对应十进制
//a 1
//b 2
//...
//z 26
//aa 27
//ab 28
//...
//huawei 104680767
//...
//输入描述:
//函数原型：
//void  convertTo26(const char *input, char *output);
//输入参数input为一个ASCII编码的字符串。输入的字母表示的数最少一位(即最少1个字母，不用考虑输入NULL的情况)，最多6位(即最多6个字母，不用考虑多于6个字母的情况)，且字母只能使用小写字母。输入十进制数不超过32位整数的最大值。
//对于C / C++, output为输出参数，可以假定为存放结果分配了足够的空间。
//判断输入字符串的有效性，如果无效则输出全大写字母的“ERROR”字符串。
//输出描述 :
//Java通过返回值输出，C / C++通过输出参数output输出。
//输入十进制数，返回字母表示的数，输入字母表示的数，则返回十进制数。
//示例1
//输入
//
//ab
//输出
//
//28
//
//
//1, 给定代码片段A：
//int add(int x, int y) {
//	int sum = 0;
//	sum = x + y;
//	return sum;
//}
//2, 编写程序，接受一段代码片段文本输入(字符类型仅限于代码片段A中出现过的字符类型，如字母 / 数字 / 空格 / TAB / 小括号 / 花括号 / 分号 / 回车)，判断此代码片段与代码片段A在功能 / 结构上是否一致，函数 / 变量名可以不同，格式(即换行 / 缩进 / 不影响功能的位置变化)可以不同。 一致返回1，不一致返回0 一致代码片段样例：
//int newadd(int m, int y) {
//	int sum = 0;      sum = m + y;
//	return sum;
//}
//int newadd(int x, int y) {
//	int sum = 0;      sum = y + x;
//	return sum;
//}
//不一致代码片段：
//int add(int x, int y) {
//	int sum = 0;
//	sum = x - y;
//	return sum;
//}
//不一致代码片段：
//int add(int x, int y) {
//	int sum;
//	sum = x + y;
//	return sum;
//}
//输入描述:
//一段代码片段，字符数少于255，字符类型仅限于代码片段A中出现过的字符类型
//输出描述 :
//1或者0
//示例1
//输入
//
//int newadd(int m, int y) { int sum = 0; sum = m + y;    return sum; }
//输出
//
//1
//收起答题卡
//例1
//例2
//1
//2
//3
//C / C++(clang++ 3.3)
//
//1
//​
