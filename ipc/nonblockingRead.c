#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    char buff[100];
    int fd = open("input.txt",O_NONBLOCK | O_RDWR);
    if(fd < 0) perror("Open failed ...\n");

    int n = read(fd, buff,sizeof(buff));
    if(n<0) perror("Read Failed ...\n");
    else write(1,buff,n);

    return 0;
}

//is this blocking or non blocking ? demonstrate both 