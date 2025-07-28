#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

//lock in same order to avoid deadlock 


pthread_mutex_t lock1,lock2;

void thread1_fuc(void){
	pthread_mutex_lock(&lock1);
	sleep(3);
	pthread_mutex_lock(&lock2);
	printf("T1 acquired both locks sucesfully\n");
	pthread_mutex_unlock(&lock2);
	pthread_mutex_unlock(&lock1);
	printf("T1 released both locks sucesfully\n");
}

void thread2_fuc(void){
	pthread_mutex_lock(&lock2);
	sleep(3);
	pthread_mutex_lock(&lock1);
	printf("T2 acquired both locks sucesfully\n");
	pthread_mutex_unlock(&lock2);
	pthread_mutex_unlock(&lock1);
	printf("T2 released both locks sucesfully\n");
}

int main(){
	pthread_t t1, t2;
	pthread_mutex_init(&lock1,NULL);
	pthread_mutex_init(&lock2,NULL);

	pthread_create(&t1,NULL,thread1_fuc,NULL);
	pthread_create(&t2,NULL,thread2_fuc,NULL);	

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock1);

    return 0;
}
