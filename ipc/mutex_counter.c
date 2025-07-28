#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_t t1,t2;

void* inc(){
    long long int i = -1;
    for(i = 0 ; i < 1000000000; ++i){
        counter++;
    }

}

// this shoudnt return 

void main(){
    pthread_create(&t1,NULL,inc,NULL);
    pthread_create(&t2,NULL,inc,NULL);
    printf("%lld\n",counter);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("%lld\n",counter);
}