#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define THREAD_NUM 7 
sem_t semaphore;

void* foo(void* args){
    sem_wait(&semaphore);
    printf("Hello : %d\n", *(int *)args);
    sleep(1);
    free(args);
    sem_post(&semaphore);
}

void main(){
    pthread_t thread[THREAD_NUM];
    sem_init(&semaphore,0,1);
    for(int i = 0;i < THREAD_NUM;i++){
        int * a = malloc(sizeof(int));
        *a = i+1;
        pthread_create(&thread[i],NULL,foo,a);
        
    }
        for(int i = 0;i < THREAD_NUM;i++){
        pthread_join(thread[i],NULL);
        
    }
    sem_destroy(&semaphore);
} 