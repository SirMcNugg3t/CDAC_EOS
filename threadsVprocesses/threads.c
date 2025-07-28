#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n = 5;

void foo1(){
	n++;
	sleep(2);
	printf("%d\n",n);
}


void foo2(){
	sleep(2);
	printf("%d\n",n);
}


void main(){
	pthread_t t1,t2;
	pthread_create(&t2,NULL,foo2,NULL);
	
	pthread_create(&t1,NULL,foo1,NULL);
	pthread_join(t2,NULL);
	
	pthread_join(t1,NULL);
		
}
