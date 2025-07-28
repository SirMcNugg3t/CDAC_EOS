#include <stdio.h>
#include <unistd.h>


int main(){
	int fd[2]; // 0 (READ) 1(WRITE)
	pipe(fd);

	
	if(fork()){
		close(fd[0]);
		int x;
		printf("Number:");
		scanf("%d",&x);
		write(fd[1],&x,sizeof(int));
		close(fd[1]);
	} else{
		close(fd[1]);
		int y;
		read(fd[0],&y,sizeof(int));
		printf("From Child: %d\n",y);
		close(fd[0]);
	}
	return 0;
}
