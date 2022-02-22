/* randnumgeneration
 *
 * */
#ifndef __RANDNUMGENERATION_H_//条件编译，防止编译时的重定义
#define __RANDNUMGENERATION_H_
int randomint();//随机数生成函数
unsigned long randomlong();//随机数扩大生成函数

int* randomseq(int* seq,int n);//随机n序列生成函数
int* randomseqdiff(int*seq, int n);//随机n不重复数序列生成函数
int* randomseqdiff(int*seq,int m,int n ,int num);//n-m+1>>num==>随机等概率输出num个不同数

void showElement(int i);

#endif
