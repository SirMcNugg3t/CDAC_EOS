#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int foo(){
	printf("Foo\n");
	sleep(3);
	printf("Done\n");		
	return 0;
}

int main(){
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1,NULL,foo,NULL);
	pthread_create(&t2,NULL,foo,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	return 0;
}
