#include <stdio.h>
#include <unistd.h>

int main(){
	int id = fork();
	printf("ID : %d\n",id);
	if(!id){
		printf("Child\t%d\t%d\n",getpid(),getppid());
	}
	if(id){
	
		printf("Parent\t%d\t%d\n",getpid(),getppid());
	
	}
	
	return 0;
}
