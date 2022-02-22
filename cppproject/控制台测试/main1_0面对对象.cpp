///#define _REENTRANT  //多线程可重入：线程errorno 
#include <queue> //c++
#include <stack>
#include <utility> //pair
#include <stdio.h> //perror()
#include <stdlib.h> //exit;
#include<errno.h> //errorno
#include<string.h> //strerror()
#include<termios.h>//struct termios
#include<unistd.h>//read;sleep
#include<fcntl.h>
#include<sys/ioctl.h>//ioctl;
#include <signal.h>//signal();
#include <pthread.h> //
using namespace std;

class GameRuler{};
class Snake{};
class Food{};

static struct termios old_termios,new_termios;

void InitTerm(){
    //初始化终端选项:不回显&不规范输入&1-0.（标准输出流仍是规范的）
    tcgetattr(0,&old_termios);
    new_termios = old_termios;//终端属性:选项=|标志+特素字符数组
    new_termios.c_lflag &= ~(ECHO|ICANON);//非规范模式不处理换行,eof按键输入
    new_termios.c_cc[VMIN] = 1;//read读取[vmin,nsize]，可能一直阻塞
    new_termios.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_termios);
    //初始化终端大小
    struct  winsize termSize;
    termSize.ws_row =24;
    termSize.ws_col =80;
    ioctl(0,TIOCSWINSZ,(char*)&termSize);
    //初始化终端名
     printf("\e]2;贪吃蛇\a");//窗口标题\a为OSC控制码序列\e]2;的终止码
     fflush(stdout);

    }
 
void UnintTerm(){
    tcsetattr(0, TCSANOW, &old_termios);
}

void SigChgWinSize(int signal){
    struct winsize termSize;
    ioctl(0,TIOCGWINSZ,(char*)&termSize);
    int winRowByte = termSize.ws_row;
    int winColByte = termSize.ws_col;
    //printf("ROW：%d,COL：%d\n", winRowByte, winColByte);
}
void* KBProc(void* argsPtr){
    char keyBuf;
    queue<char>* keyQueuePtr = (queue<char>*)argsPtr;
    while(read(0,&keyBuf,sizeof(keybuf))){
        //printf("\033[47;31m\033[5m char: %c\033[0m\n",keybuf);
        keyQueuePtr->push(keyBuf);
    }
    //线程终止：可以返回结构体等指针，但不应是线程的局部变量
    pthread_exit((void*)0);//这里没什么需要返回的--所以返回0指针即可
}

int GUIRender(){
    char wallElem[8] = "▨ ";
    char objectElem[8] = "● ";
    int winRowByte, winColByte;
    int wallXElemN, wallYElemN;
    //不可用。g-t -x cmd 会改变继承的环境变量。
    //winRowByte = atoi(getenv("LINES"));
    //winColByte = atoi(getenv("COLUMNS"));
    //获取终端设备路径名
    //char* termFileName;
    //termFileName = ttyname(1);//相当于tty命令获取终端路径名。

    struct  winsize termSize;
    ioctl(0, TIOCGWINSZ, (char*)&termSize);
    winRowByte = termSize.ws_row;
    winColByte = termSize.ws_col;
    wallXElemN = 2 * (winColByte / strlen(wallElem));
    wallYElemN = winRowByte;
    
    for(int j =1 ;j <=wallYElemN;j++ ){
        if((j == 1) || (j == wallYElemN)) {
            for(int i = 1; i <= wallXElemN; i++) {
                printf("%s", wallElem); 
            }
            //fflush(stdout);

        }
        else {
            printf("%s",wallElem);
            printf("\e[%dC",winColByte);//光标在列79
            printf("\e[%ldD",strlen(wallElem)/2-1);//光标在列78                                                                            
            printf("%s",wallElem);
            //fflush(stdout);

        }
        if( j != wallYElemN)//不对第24行换下一行操作，因为光标换到了24行1列?
          printf("\e[1E");//光标定位到下行的第1列
    }
    //读光标位置也要非规范模式,因为光标位置\e[y;xR没有换行符(不是输入行装配)
    printf("\e[6n");//将光标位置放至终端的输入队列，下面的read(fd=0)会读到
    fflush(stdout);//鼠标在24行80列
    return 0;
}

int main(){
    signal(SIGWINCH, SigChgWinSize);//信号处理函数仍被安装
    thread_t kbProcTid, guiRenderTid;
    int ret;
    void* thdRet;
    queue<char>*  keyQueuePtr = new queue<char>;//默认构造函数
    queue<pair<int,int>>*    snakeCoords;
    pair<int ,int>*          foodCoord;
    char key;
    //1.初始化本程序所使用的终端
    InitTerm();    
    //2.键盘输入线程创建并运行
    ret = pthread_create(&kbProcTid,NULL，KBProc,NULL);  
    if(ret != 0){
        fprintf(stderr,"%s:%s:%d, %s, kb线程创建失败\
                    \n",_FILE_,_FUNCTION_,_LINE_,strerror(errorno));
        exit(1); 
    }
    //3.窗口渲染线程：绘制界面
    ret = pthread_create(&guiRenderTid,NULL，GUIRender,NULL);  
    if(ret != 0){
        fprintf(stderr,"%s:%s:%d, %s, gui线程创建失败 \
                    \n",_FILE_,_FUNCTION_,_LINE_,strerror(errorno));
        exit(1); 
    }

    //4.主线程：界面数据处理+规则判定
    while(1){
        if(keyQueuePtr->size() != 0){
            key = keyQueuePtr->front();
            keyQueuePtr->pop();
            switch(key){
                case 'j':
                    SnakeTurnLeft();
                    break;
                case 'k':
                    SnakeTurnLeft();

                    break;
                 case 'h':
                    SnakeTurnLeft();

                    break;
                case 'l':
                    SnakeTurnLeft();
                    break;
                case ' ':
                    SnakePauseMove();
                    break;
                case 'q':
                    GameExit();
                    break;
                case 'r':
                    GameReboot();
                    break;
                case 'm':
                    GameMenu();
                    break;
                default:
                    break;
            }
        }
        else
          SnakeStepOne(snakeCoords);
    }
    //5.阻塞等待键盘输入线程终止并获取其线程终止状态和清理该线程
    ret = pthread_join(kbProcTid,&thdRet);
    if(ret != 0){
        fprintf(stderr,"kb线程join失败,tid = %lu\n",(unsigned long)kbProcTid);
        exit(1); 
    }
    
    printf("键盘输入线程join返回值:thdRet = %ld\n",(long)thdRet);
    ret = pthread_join(guiRenderTid,&thdRet);
    if(ret != 0){
        fprintf(stderr,"gui线程join失败，tid = %lu\n",(unsigned long)guiRenderTid);
        exit(1); 
    }
    printf("gui渲染线程join返回值:thdRet = %ld\n",(long)thdRet);
   //6.反初始化本程序所使用的终端，即恢复到默认的终端属性。
    UnintTerm();//实际没必要这个步骤，因为程序终止后终端也就关闭了。
    return 0;
}
