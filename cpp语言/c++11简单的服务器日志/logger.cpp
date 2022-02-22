/** * 日志类实现文件, Logger.cpp * zhangyl 2017.02.28 **/

#include "Logger.h"
#include <time.h>
#include <stdio.h>
#include <memory>//share_ptr<>;
#include <stdarg.h>//ansi c va_list,va_arg,va_begin,va_end可变参数相关宏！

Logger& Logger::GetInstance()//饿汉单例模式：加载慢但线程安全，无需释放动态内存
{
    static Logger logger;//共享一个logger对象
    return logger;
}

void Logger::SetFileName(const char* filename)
{
    filename_ = filename;
}

bool Logger::Start()//线程启动函数：创建文件->创建线程对象(启动线程)
{
    if (filename_.empty())
    {
        time_t now = time(NULL);
        struct tm* t = localtime(&now);
        char timestr[64] = { 0 };
        sprintf(timestr, "%04d%02d%02d%02d%02d%02d.imserver.log", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
        //asctime(tm* ):可直接将localtime()转换为当地时间，无需手动加1900,加1
        //sprintf():输出<=n-1且首个结束符之前，且末尾加结束符，保存至timestr。返回值不包括结束字符。snpritf()更安全。
        filename_ = timestr;
    }

    fp_ = fopen(filename_.c_str(), "wt+");//截断，可读写打开或创建
    if (fp_ == NULL)
        return false;

    spthread_.reset(new std::thread(std::bind(&Logger::threadfunc, this)));
    //c++11:
    //bind()：解决成员函数和其参数绑定问题,返回函数名
    //bind非成员函数：bind(funname,arg1,arg2,..)
    //bind成员函数:bind(&classname::m_funname,classname obj)
    //thread():空构造，线程不执行
    //thread(funcname):传入线程函数名构造，线程执行
    //thread(move(thread otherthread)):move构造，otherthread终止，而该thread从线程函数开始处执行。
    //share_ptr::reset()：重置共享指针，指向新创建的对象。
    return true;
}

//等待线程终止函数：设置终止数据成员->唤醒条件变量等待进程->等待线程(自己)终止(避免僵尸线程)
void Logger::Stop()
{
    exit_ = true;
    cv_.notify_one();

    //等待时间线程结束
    spthread_->join();
    //logger类析构函数负责反初始化互斥锁和条件变量
}

//插入一条日志：合成一条日志content-占用锁-emplace_back日志列表尾部-释放锁-唤醒条件变量
void Logger::AddToQueue(const char* pszLevel, const char* pszFile, int lineNo, const char* pszFuncSig, char* pszFmt, ...)
{
    char msg[256] = { 0 };

    va_list vArgList;//可变参数列表首地址(最左边一个)                        
    va_start(vArgList, pszFmt);//指向...的第一个参数：vArgList=(va_list)(&pszFmt)+sizeof(pszFmt)
    vsnprintf(msg, 256, pszFmt, vArgList);
    va_end(vArgList);//置为0;

    time_t now = time(NULL);
    struct tm* tmstr = localtime(&now);
    char content[512] = { 0 };
    sprintf(content, "[%04d-%02d-%02d %02d:%02d:%02d][%s][0x%04x][%s:%d %s]%s\n",
                tmstr->tm_year + 1900,
                tmstr->tm_mon + 1,
                tmstr->tm_mday,
                tmstr->tm_hour,
                tmstr->tm_min,
                tmstr->tm_sec,//当前时间：可以__date__替代。也可asctime(tm* )替代转换
                pszLevel,
                std::this_thread::get_id(),//获取自身线程id
                pszFile,
                lineNo,
                pszFuncSig,//函数前面
                msg//自定义的格式化消息
                );

    {//插入一条日志
        std::lock_guard<std::mutex> guard(mutex_);//等待-占用互斥锁

        queue_.emplace_back(content);//emplace_**插入操作相比insert更加高效--不产生临时变量
    }//释放互斥锁

    cv_.notify_one();//唤醒条件变量：必须在条件改变且解锁后进行唤醒条件变量
}
//回调函数(使得底层不用关心业务)：日志线程的线程函数=线程启动+互斥锁+条件变量+提取任务+释放锁+执行任务。
void Logger::threadfunc()
{
    if (fp_ == NULL)//冗余保护措施
        return;

    while (!exit_)//线程循环(事件循环)
    {
        //写日志
        std::unique_lock<std::mutex> guard(mutex_);//自动加锁
        //unique_lock:相比于lock_guard更加灵活的加解锁控制成员函数(当然也支持自动加解锁);
        //通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用       
        while (queue_.empty())
        {
            if (exit_)//保护措施：占用互斥锁后，应立即判断当前线程状态标志
                return;

            cv_.wait(guard);//条件变量
        }

        //写日志
        const std::string& str = queue_.front();//提取队列首个日志

        fwrite((void*)str.c_str(), str.length(), 1, fp_);//输出一个日志至日志文件
        fflush(fp_);//标准io写缓存区刷新：此处为全缓冲区,刷新条件-->缓冲区满或fflush或fclose或进程正常终止
        queue_.pop_front();//删除首个日志
    }
}
