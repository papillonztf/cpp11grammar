/*strcpy:	
	1.����ԭ�ͣ�char* strcpy(char* des,const char char* src)

	2.���ܷ���������ַ�����ʵ�ֽ�src��ַ��ʼ�Ұ��������ַ�'\0'����һ�Σ����Ƶ���des��ͷ������

	3.ʵ�ַ�����
		1.���룺Ϊ����߲�������Ч�ʣ�src��des�������ͱ���Ϊchar*(���ַ�ָ��or�ַ�����or�ַ�������)����src��Ϊconst char *����ʾԴ���ݲ��䡣desָ���ڴ治��գ����Ǹ����Ը��ǡ�
		2.�����Ϊ����߲�������Ч�ʣ�����ָ�룬����desָ�루�Լ������ͺã������Ҫ��desָ�벻�ɱ䣬��ָ������ݱ�Ϊsrc
		3.ʵ�֣�
				�﷨Լ���������ǻ���ָ�루�ڴ��ַ��������뿼�ǣ�
						1.�����ָ���Ƿ�Ϊnull��
						2.���Ƶ������ڴ��Ƿ��ص�
						3.desָ��ĵ�ַ�Ƿ����㹻����ڴ�ռ���src�ڴ档
				����Լ����
						1.ע���ǿ���src��ַ��ʼ��(����)�׸������ַ�'\0'��һ���ڴ档
				ʵ��Լ����
						0.ͨ��assert()������ָ��Ϊnull���쳣��
						1.�����ķ�ʽ������ֽڵģ�ͨ��*p++=ʵ�֡�
						2.ͨ��strlen�����׸�'\0'�����������������ַ���ʵ�ּ����ڴ��С��������sizeof��ʵ�ʷ�����ڴ棬����'\0'��
	4.ʹ�÷�����ʹ��Ҫע��ú����ľ���ʵ�֣��Ա��ⷢ������

		����1.
			void test1()
			{
��			 char string[10];
��			 char* str1 = "0123456789";
��			 strcpy( string, str1 );//desָ���ڴ�ֻ��10��ʵ�ʸ���src���ݴ�СΪ11��������\0����
			}
		����2.

			void test2()
			{
		��		char string[10], str1[10];
		 ��		int i;
		  ��	   for(i=0; i<10; i++)
		   ��		{
			����	  str1[i] = 'a';//srcû�н����ַ���\0��������strcpy����ʱ�����Ȳ�ȷ����
			  ��	}
			   ��strcpy( string, str1 );
					
			}
		����3.

			void test3(char* str1)
			{
		��	  char string[10];
		 ��	  if( strlen( str1 ) <= 10 )
				{
		   ����	 strcpy( string, str1 );//strlen���󳤶��ǲ����������ַ���\0�������µ���strcpy����ʱ��des���Ȳ���
				 }
			 }
*/
#include<iostream>
#include<assert.h>
using namespace std;
char* Mystrcpy(char*des, const char* src)
{
	assert((des&&src) != 0);//�������Ϊ��NULL������stderr��ӡһ��������Ϣ��Ȼ��ͨ������ abort ����ֹ�������С�
	char* dest = des;//����des�ĸ�������Ϊ����ֵ
	while ((*dest++ = *src++) != '\0');//*src����Ϊ��ֵ�������ֵ��*dest��Ϊ��ֵ��src�ټ�1������dest�ټ�1����ֵ����Ľ������!=���㣬
	return des;
}

int main()
{
	char src1[10] = "12345";
	char *src2 = "12345";
	char des1[10]="00000000";
	char *des2 = des1;
	//src�ֱ�Ϊ�ַ�ָ����ַ����飬des�ֱ�Ϊ�ַ�ָ����ַ�����
	Mystrcpy(des1,src1);
	cout << des1 << endl;

	Mystrcpy(des2, src1);
	cout << des2 << endl;

	Mystrcpy(des1, src2);
	cout << des1 << endl;

	Mystrcpy(des2, src2);
	cout << des1 << endl;
	

	return 0;
}
