#include<stdio.h>
#include<unistd.h>


int main(){
	int n ;
	int id = fork();
	if(id==0) n =1;
	else {
		n=6;
		wait();
	}
	
	
	for(int i = n; i < n + 5; i++){
		printf("%d  ",i);
		fflush(stdout);
	}
	if(id > 0)printf("\n");
	return 0;
	
	
}
