#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>//WIF
#include<unistd.h>
extern char** environ;
#define SYSTEM
int main(int argc, char* argv[]){
    //pause();

    #ifdef SYSTEM
    char gtArgv[100]="gnome-terminal --geometry=80x24+600+80 -x "; 
    int index = strlen(gtArgv);
    int status = -1;
    strcpy(gtArgv+index,argv[1]);
    status = system(gtArgv);//返回的是bash -c gnome-terminal进程的终止状态
    /*int winRowByte = atoi(getenv("LINES"));
    int winColByte = atoi(getenv("COLUMNS"));
    printf("ROW：%d,COL：%d\n", winRowByte, winColByte);
    pause();
*/ 
    #else
    //pause();
    execlp("gnome-terminal","--geometry=80x24+600+80" ,"-x",argv[1],(char*)0);
    #endif
    /*
    printf("status: %d\n",status);//返回的其实是gnome-terminal进程的终止状态
    if(WIFEXITED(status)){
        printf("normal terminated:exit status = %d\n",WEXITSTATUS(status));
    }
    else if(WIFSIGNALED(status)){
        printf("abnormal terminated:signal num = %d\n",WTERMSIG(status));      }
    else if(WIFSTOPPED(status)){
        printf("stopped:signal num = %d\n",WSTOPSIG(status));
    }
    */
    return 0;
}
