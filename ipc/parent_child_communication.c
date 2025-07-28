#include <stdio.h>
#include <unistd.h>
#include <string.h>
//NOT WORKING !!
//learn how to  clear a buffer

int main(){
    int fd[2];
    char buff[20]; 
    char buff2[20];

    pipe(fd);

    if(fork()==0){
        close(fd[0]);
        write(fd[1],"Hi from Child\n",strlen("Hi from Child\n"));
        write(fd[1],buffer,sizeof(buffer));
        
    }else {
        close(fd[1]);
        read(fd[1],buff,sizeof(buff));
        read(fd[1],buff2,sizeof(buff2));

        printf("%s",buff);
    }
    return 0;

}
