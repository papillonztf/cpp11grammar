//ͷ�ļ������������������ࣻԴ�ļ�������Ӧ�Ķ��塣������ֹ���ӽ׶ε��ض��塣
//extern��static���������ؼ���,��������������������Ƿ��ڸô����ã������static int i��static void fun������������Ӧ�Ķ���Ͳ�����д�ϸ�static�ؼ���
//��̬���ݳ�Ա�Ķ���Ӧ�÷������⣺Ϊ�˱�֤��̬���ݳ�Աֻ����һ�Ρ�
//��̬���ݳ�Ա�Ķ���������ⶨ�岢�ҵ÷���Դ�ļ��ж��壺������ͷ�ļ��������������ⶨ�壬�������ض���

#ifndef _STATICTEST_H_//�������룬����ͬһ�ļ���ͷ�ļ��ر��룬������ֹ����׶ε��ض���
#define  _STATICTEST_H_

extern int iGlobVar;//ͷ�ļ���Ӧ������������Ӧ��������
//extern static int isStatGlobVar;//static ȫ�ֱ�������������extern����

void TestStatLocVar();//��������
static void TestStatFunc();

class StatTest//���������һ���������ͺ����������������Ķ�����Դ�ļ��н��У���
{
private:
	int iVar;
	static int isVar;
	//static int isVar=0;
public:
	//��һ��ĸ�ʽ���������캯�����������������ƹ��캯�����������Ĵ��Ա������⡣

	//StatTest();//���캯�����ڸ�������̬���ݳ�Ա֮�⣩�������ݳ�Ա��ʼ����
	//~StatTest();//�ͷű�����ռ�ڴ�
	//StatTest(const StatTest & original);//����
	//const StatTest & operator =(const StatTest & rightValue);//���������

	//��������
	void Fun();
	static void StatFun();
};

//int StatTest::isVar = 1;//��̬���ݳ�Ա

#endif