#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
	mkfifo("myfifo",0777);
	int fd = open("myfifo",O_RDWR);
	printf("%d\n",fd);

	int a = 69;
	write(fd,&a,sizeof(int));
	close(fd);

	return 1;
}
