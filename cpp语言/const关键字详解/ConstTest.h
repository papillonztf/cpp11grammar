//ͷ�ļ������������������ࣻԴ�ļ�������Ӧ�Ķ��塣������ֹ���ӽ׶ε��ض��塣


#ifndef _CONSTTEST_H_//�������룬����ͬһ�ļ���ͷ�ļ��ر��룬������ֹ����׶ε��ض���
#define _CONSTTEST_H_

//const ������Թ��̳������ʱ��������
//1.���ڱ���
extern int iGlobVar;//ͷ�ļ���Ӧ������������Ӧ��������
extern const int CONSTINT = 1;
extern const int* CONSTINTPRT = &iGlobVar;
extern int * const INTCONSTPRT = &iGlobVar;
extern const int*const CONSTINTCONSTPRT = &iGlobVar;
extern const int & CONSTINTREF = iGlobVar;
//2.���ں���
void Fun1(const int i);//�β�i�ڸú����ڲ����޸�
const int Fun2();//�ú�����������ֵ
//3.���ں������ء������������ͬ�����Կ��Ժ�������
void Fun(int i);
void Fun(const int i);

//const ������Զ���������ʱ��������
class ConstTest//���������һ���������ͺ����������������Ķ�����Դ�ļ��н��У���
{
//1.�������ݳ�Ա.�����ڹ��캯����ʼ���б���г�ʼ�����������ڹ��캯�����ڳ�ʼ����
private:
	int m_Intvar;
	const int m_ConstIntVar;
	
public:
	//��һ��ĸ�ʽ���������캯�����������������ƹ��캯�����������Ĵ��Ա������⡣

	ConstTest(int i ,int j);//���캯�����ڸ�������̬���ݳ�Ա֮�⣩�������ݳ�Ա��ʼ����
	//~StatTest();//�ͷű�����ռ�ڴ�
	//StatTest(const StatTest & original);//����
	//const StatTest & operator =(const StatTest & rightValue);//���������

	//��������
//2.���ڳ�Ա����
	void m_Fun();
	void m_FunConst() const; //�ó�Ա�����˲������޸��κ����ݳ�Ա��Ҳ���ɷ��ʷ�const������Ա
//3.���ڳ�Ա�������ء�
	void m_OverrideFun();
	void m_OverrideFun() const;
};

extern ConstTest Object;

#endif