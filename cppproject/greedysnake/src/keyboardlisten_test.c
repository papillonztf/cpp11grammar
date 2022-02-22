#include <linux/input.h>//input_event
#include<fcntl.h> //open()
#include<stdio.h>
#include<unistd.h>//read
struct input_event key_info;
int main(){
    int fd;
    fd=open("/dev/input/event1",O_RDONLY);
    while(1){
        if (read(fd, &key_info, sizeof(struct input_event)) > 0)
        {
	//这是按键事件
	        if (key_info.type == EV_KEY)
		//是哪个按键 及 按键状态
		    printf("按键: %d 状态: %d \n", key_info.code, key_info.value);
        }
    }
    return 0;
}
