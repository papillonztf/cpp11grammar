/*const�����ñ��������ʼ����������ͨ����ֵ����Ϊֻ�г�ʼ��ʱ���ܷ����ڴ沢ȷ����ֵ
		1.һ��const�����ñ�����
				const char i= ��1������ȷ
				const char i��
				i=��1��������
				int i=1;
				int & j=i;��ȷ
				int & j��
				j=i����������ֻ���ڳ�ʼ����һ��ȷ���Ͳ����޸ģ�
		2.���캯���ڣ����úͳ��������ǳ�ʼ���б���г�ʼ�����������ں������ڽ��и�ֵ��
			class classA
			{
			public:
			classA(int i,const int j,int&k):mem_j(j),mem_k(k)//��ȷ�����úͳ��������ǳ�ʼ���б���г�ʼ��
			{
			mem_i=i;
			}
			//classA(int i,const int j,int&k)//����
			//{
			//mem_j=j;
			//mem_k=k;
			//mem_i=i;
			//}

			private:
			int mem_i;
			const int mem_j;
			int &mem_k;
			}
			
*/