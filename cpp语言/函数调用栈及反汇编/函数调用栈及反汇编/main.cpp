
	#include<stdio.h>
	#include<stdlib.h>
	int sum(int a, int b)
	{
		int tmp = 0;
		tmp = a + b;
		return tmp;
	}

	int main()
	{
		int a = 10;
		int b = 20;
		int ret = 0;

		ret = sum(a, b);
		printf("ret=%d\n", ret);
		system("pause");
	return 0;
}
