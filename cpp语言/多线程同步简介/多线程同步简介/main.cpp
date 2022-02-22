/*
简单多线程：
*/

//#include<iostream>
//#include<thread>
//#include<mutex>
//using namespace std;
//int j = 100;
//
//mutex mtx;//互斥元

/*-----------------------------------------
一。线程未同步：导致1.一些输出格式不对，2.同时访问共享内存时，使得共享内存的数据出错。
----------------------------------*/

//void fun1()
//{
//	for (int i = 0; i < 10;i++)
//	cout << "线程1: " << ++j << endl;
//}
//
//void fun2()
//{
//	for (int i = 0; i < 10; i++)
//	cout << "线程2: " << --j<< endl;
//}

//--------------------------------------
/*一。线程同步---互斥锁：
					1.互斥锁作用范围是互斥锁的加锁--解锁。
					2。？？？？一旦某个线程的加锁，该线程与不含该互斥锁的其他线程竞争，而含该互斥锁的其他线程则直接挂起，
					3。？？？解锁后，其他包含噶互斥锁的对象和其他对象，进行竞争。
-----------------------------------------------------------------------------------
*/
//void fun1()
//{
//	
//	for (int i = 0; i < 10; i++)
//	{
//		lock_guard<mutex> mutex_locker(mtx);//加互斥锁对象
//		cout << "线程1: " << ++j << endl;
//		//解锁
//	}
//	
//}
//
//void fun2()
//{
//	//for (int i = 0; i < 1000000000; i++)//解锁的，其他包含该互斥量的线程进行竞争，看谁先运行到加锁处！！
//	//	;
//	for (int i = 0; i < 10; i++)
//	{
//		lock_guard<mutex> mutex_locker(mtx);//加互斥锁对象
//		cout << "线程2: " << ++j << endl;
//		//解锁后
//	}
//}
//void fun3()
//{
//
//	for (int i = 0; i < 10; i++)
//	{
//		lock_guard<mutex> mutex_locker(mtx);//加互斥锁对象
//		cout << "线程3 "  << endl;
//		
//	}
//}
//
////---------------------------------
//int main()
//{
//	thread thrd1(fun1);
//	thread thrd2(fun2);
//	thread thrd3(fun3);
//	thrd1.join();
//	thrd2.join();
//	thrd3.join();
//	system("pause");
//	return 0;
//}




/*----------------------------------------------------------
二，线程同步---条件变量：
		1.基含于互斥锁实现的，因此加锁后其余含该互斥锁的线程是阻塞的，解锁后其余该互斥锁的线程竞争互斥锁
		2.满足条件--->condition_variable.wait()--->condition_variable.notify_one().
		3.对于只有两个包含同一互斥锁的线程A,B,我们知道单纯使用互斥锁，其运行顺序是A-B-A-A或者B-A-B-A
			如何确定开始顺序是A-B-A-呢？---条件变量，
------------------------------------------*/
//#include<iostream>  
//#include<thread>  
//#include<mutex>  
//#include<condition_variable>  
//using namespace std;
//mutex m;
//condition_variable condV;
//char flag = 'A';
//
//void func(char j)
//{
//	for (int i = 0; i < 20; i++)
//	{
//		//lock_guard<mutex> mxt_locker(m);
//		unique_lock<mutex> mxt_ulocker(m);//加锁
//		while (j !=flag)
//			condV.wait(mxt_ulocker);//满足条件，则一直wait(),阻塞该线程，运行其他线程。
//		cout << "线程" << j << endl;
//		flag = (j =='A') ?  'B': 'A';
//		condV.notify_one();
//	}
//}
//
//int main()
//{
//	thread thrdB(func, 'B');
//	thread thrdA(func,'A');
//	
//	thrdA.join();
//	thrdB.join();
//	system("pause");
//	return 0;
//}



//void fun(int num)//访问共享内存（即该函数），必须保证线程同步
//{
//	for (int i = 0; i<50; i++)
//	{
//		unique_lock<mutex> lk(m);
//
//		while (flag != num) //1.如果先来的是主线程（不符合我们的要求，先子线程在主线程），num=100!=flag=10，因此，
//			cond.wait(lk);//调用wait()对该线程进行解锁--阻塞，其他线程(这里其他就只有子线程了)则是竞争该锁，
//						//2.子线程跳过该步，直接到notify_one()使得刚才那个阻塞线程（主线程）恢复到wait()前（即wait()前一句）的状态，即加锁状态（），继续运行.
//						//而该子线程本身则是完成一次循环（肯定循环完一次就解锁了，也不参与下次竞争），
//						//3.但此时，num=100==flag=100，因此，跳过wait(),
//		for (int j = 0; j<num; j++)
//			cout << j << " ";
//		cout << endl;
//		flag = (num == 10) ? 100 : 10;
//		cond.notify_one();//被阻塞的线程唤醒后,恢复到调用wait前的状态 。（应该是，等到正在加锁的线程解锁后再恢复，而不是立马恢复） 
//		//for (int i = 0; i < 1000000000; i++);
//	}
//}
//int main()
//{
//	//如果使用互斥锁，主线程和线程child竞争，看谁先运行加锁处，谁就获得第一个锁，
//	//但是我们强调，必须先子线程再主线程，因此，就要用到条件变量
//	thread child(fun, 10);
//	fun(100);
//	child.join();
//	return 0;
//}

/*------------------------------------------------------------
三。线程同步-----原子操作
			1.保证某个时刻只有一个线程能访问原子变量，结果是确定的，但过程是不确定的。
			2.访问后，该线程又参与下次竞争！而互斥锁则不会，解锁后其他线程参与竞争。
			3.即不确定各线程访问顺序，但确定每只有一个线程访问该全局原子变量，确定总的访问效果是一样的，
			如，线程1对i=0进行100次递减1，线程2对i进行100次递增1，那使用原子变量，总的结果是确定为0，但这个过程加1，减1的顺序是不确定的
------------------------------------------------------------*/

#include<iostream>
#include<thread>
#include<atomic>

using namespace std;



void fun1(int & i)
{
	
	for (int k = 0; k < 1000000; k++)
	{
		++i;
		
	}
	cout << "线程1: " << i << endl;
}
void fun2(int &i)
{

	for (int k = 0; k < 1000000; k++)
	{
		--i;
		
	}
	cout << "线程2: " << i << endl;
}
int main()
{
	int e = 0;
	int i = e;
	int j = e;
	thread thrd1(fun1,ref(i));
	thread thrd2(fun2,ref(j));
	thrd1.join();
	thrd2.join();
	//cout << i << ' ' << j << endl;
	system("pause");
	return 0;
}
