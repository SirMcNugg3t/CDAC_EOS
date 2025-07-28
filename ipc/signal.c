#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void nop(int id){};

int count =0;

int main(){
	fork();
	fork();
	fork();
	printf("%d\n",getpid());
	return 0;
}
