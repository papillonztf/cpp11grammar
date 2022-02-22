#progma once
#include<termios.h>//struct termios;tcget/setattr();
#include<ioctl.h>//struct winsize;
class TermController{
    public:
        TermController();
        ~TermController();
        
    private:
        void _InitTerm();
        void UninitTerm();
        struct termios oldTermios,newTermios;
        struct winsize termSize;
};
