#include <stdio.h>
#include <stdlib.h>

int count =0;

int main(){
	fork();
	fork();
	fork();
	printf("%d\n",getpid());
	return 0;
}
