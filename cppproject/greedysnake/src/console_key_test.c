/*#include<stdlib.h>
#include<string.h>

#include<stdio.h>
int main(){
    char spechar[10]="● ";
    printf("● ● ● ● ● ● ● ●  ,%d",(unsigned int)strlen(spechar));

}*/
#include <stdio.h>
#include <termios.h>
#include<unistd.h>
 
static struct termios initial_settings, new_settings;
static int peek_character = -1;
void init_keyboard(void);
void close_keyboard(void);
int kbhit(void);
int readch(void); 
void init_keyboard()
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag |= ICANON;
    new_settings.c_lflag &= !ECHO;
    new_settings.c_lflag |= ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}
 
void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}
 
int kbhit()
{
    unsigned char ch;
    int nread;
 
    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    printf("nread: %d ",nread);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if(nread == 1) 
    {
        peek_character = ch;
        printf("at 1st read:got 1 char!");
        return 1;
    }
    return 0;
}
 
int readch()
{
    char ch;
 
    if(peek_character != -1) 
    {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    printf("at 2st read:got 1 char!");
    return ch;
}
 
int main()
{
    init_keyboard();
    while(1)
    {
        kbhit();
        printf("\n%c\n", readch());
    }
    close_keyboard();
    return 0;
}
