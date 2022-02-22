#include<signal.h>//signal();
#include<stdio.h>
#include<unistd.h>//sleep();
sigset_t oldset;
sigset_t pendingset;

void printsigset(const sigset_t *set)
{
	int i;
	for (i = 1; i < 32; i++)
		if (sigismember(set, i) == 1)
			putchar('1');
		else
			putchar('0');
	puts("");
}
void sigintHandler(int sig){
    printf("handling signal: %d\n",sig);
    sigemptyset(&oldset);
    sigprocmask(SIG_BLOCK,0,&oldset);
    sigpending(&pendingset);
    printf("oldset = ");
    printsigset(&oldset);
    printf("pendingset = ");
    printsigset(&pendingset);
    printf("signal handled out!");
    sleep(3);
    sigpending(&pendingset);
    printf("pendingset = ");
    printsigset(&pendingset);
}
int main(){

    signal(SIGINT,sigintHandler);
    while(1);
    return 0;
}
