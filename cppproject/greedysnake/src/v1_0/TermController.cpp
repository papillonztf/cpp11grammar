#include"TermController.h"
#include<stdio.h>
TermController::TermController(){
}

TermController::~TermController(){
}
void TermController::_InitTerm(){
    //初始化终端选项:不回显&不规范输入&1-0.（标准输出流仍是规范的）
    tcgetattr(0,&old_termios);
    new_termios = old_termios;//终端属性:选项=|标志+特素字符数组
    new_termios.c_lflag &= ~(ECHO|ICANON);//非规范模式不处理换行,eof按键输入
    new_termios.c_cc[VMIN] = 1;//read读取[vmin,nsize]，可能一直阻塞
    new_termios.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_termios);
    //初始化终端大小
    /*
    termSize.ws_row =24;
    termSize.ws_col =80;
    ioctl(0,TIOCSWINSZ,(char*)&termSize);
    */
    //初始化终端名
     printf("\e]2;贪吃蛇\a");//\e] osc 控制序列 以\a结束。
     fflush(stdout);

    }
 
void TermController::_ UninitTerm(){
    tcsetattr(0, TCSANOW, &old_termios);
}
