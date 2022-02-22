/*
 线程池基本组成：
 ×工作线程：即线程池创建(如通过循环pthread_create())的多个线程-->线程池类的threadid指针(如pthread_t* tids)数据成员。
    ×线程池的线程往往前期通过互斥锁+条件变量主动地去获取任务队列的任务。
     一旦获取到任务，就释放互斥锁，接着去执行任务。
    ×线程池的线程也往往while(1)循环执行任务，也就是该线程一般创建后不会在
     一个任务结束后就销毁该线程，而是继续主动地去获取并执行任务
    ×因此，线程池的线程可分为：
        空闲线程：线程阻塞于条件变量(任务队列为空)
                  此时，线程会临时释放其占用的互斥锁，线程池的其他线程可争夺该互斥锁。
        工作线程：线程获取到任务后，释放互斥锁，接着执行所获取到的任务。

 ×线程池管理器：创建，销毁，管理线程池。
    ×创建线程池中的线程：
        在线程池中创建多个线程-->线程池类的的create(int threapnum)成员函数
    ×销毁线程池中的线程：
        即让线程池中的线程终止结束(一般还应pthread_join()d等待线程结束以及反初始化destroy相关互斥锁和条件变量).-->线程池类中destory()成员函数
        而正常情况是线程池创建好线程，会循环：等待任务--执行任务,而不会执行一个任务就终止该线程。
        那想销毁线程池中线程则将线程结束标志置为true(可某个线程或所有线程)，相应线程就会终止返回。
        
 ×任务队列：利用队列或链表作为存放任务指针的容器，并将容器作为线程池类的数据成员。
        × 任务应是一定规则的类，见下。
        × 只能在任务队列末尾插入新任务-->线程池类中的addTask()成员函数
        × 只能在任务队列的首端删除(提取)任务-->线程池中线程会提取。
 × 任务接口：任务应提供统一的调用接口以便线程池的线程取提取运行，做到线程池与与任务无关-->如任务类中run()成员函数
 * */
int main(){



    return 0;
}
