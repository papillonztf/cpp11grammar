/*const和引用变量必须初始化，而不是通过赋值。因为只有初始化时才能分配内存并确定其值
		1.一般const和引用变量：
				const char i= ‘1’；正确
				const char i；
				i=‘1’；错误
				int i=1;
				int & j=i;正确
				int & j；
				j=i；错误，引用只能在初始化，一定确定就不能修改，
		2.构造函数内，引用和常量必须是初始化列表进行初始化，而不能在函数体内进行赋值。
			class classA
			{
			public:
			classA(int i,const int j,int&k):mem_j(j),mem_k(k)//正确，引用和常量必须是初始化列表进行初始化
			{
			mem_i=i;
			}
			//classA(int i,const int j,int&k)//错误，
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