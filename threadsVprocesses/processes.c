#include <stdio.h>
#include <unistd.h>

int n = 5;

int main(){
	sleep(2);
	if(!fork()) wait(NULL);
	else n++;
	printf("%d\n",n);
	return 0;
}
		
