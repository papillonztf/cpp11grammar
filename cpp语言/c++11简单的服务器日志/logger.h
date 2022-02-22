/** * 日志类头文件, Logger.h * zhangyl 2017.02.28 **/
/*日志类：
    ×日志线程：
    ×日志线程启动：
    ×日志线程终止：
    ×日志队列：
    ×增加日志至日志队列：
    ×读取日志队列的日志至文件：
 *
 * */
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>

//struct FILE;
//宏函数：将含有固定参数函数表达式简化，以便调用
//可变参数宏__VA_ARGS__:用可变参数...(>=1个参数)替代该宏
//__FUNCTION__:函数名，g++/vs
//__PRETTY_FUNCTION__:详细(返回值类型 [类名::]成员函数名 参数类型 )函数名宏，g++
#define LogInfo(...) Logger::GetInstance().AddToQueue("INFO", __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define LogWarning(...) Logger::GetInstance().AddToQueue("WARNING", __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)
#define LogError(...) Logger::GetInstance().AddToQueue("ERROR", __FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)

class Logger
{
public:
    static Logger& GetInstance();

    void SetFileName(const char* filename);
    bool Start();
    void Stop();

    void AddToQueue(const char* pszLevel, const char* pszFile, int lineNo, const char* pszFuncSig, char* pszFmt, ...);

private:
    Logger() = default;
    Logger(const Logger& rhs) = delete;
    Logger& operator =(Logger& rhs) = delete;

    void threadfunc();


private:
    std::string                     filename_;
    FILE*                           fp_{};
    std::shared_ptr<std::thread>    spthread_;
    std::mutex                      mutex_;
    std::condition_variable         cv_;            //有新的日志到来的标识
    bool                            exit_{false};
    std::list<std::string>          queue_;
};

#endif //!__LOGGER_H__

