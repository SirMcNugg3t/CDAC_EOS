#include <stdio.h>
#include <unistd.h>

int main(){
	fork();
	fork();
	printf("Hey\n");
	return 0;
}
