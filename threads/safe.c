//
// Created by QuJunqiao on 2020/11/26.
//

#include "safe.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wait_here;
void*  counting(void* args){
sem_wait (&wait_here);
    Count* arg=args;
    while (arg->count<1000){
        arg->count++;
        printf("%d\n",arg->count);
    }
    sem_post (&wait_here);
}
void   count_variable(int thread){
    sem_init (&wait_here,0,1);
    Count arg;
    arg.count=0;
    pthread_t threads[thread];
    for (int i=0;i<thread;i++){
        pthread_create(&threads[i],NULL,counting,&arg);
    }
    for (int i=0;i<thread;i++){
        pthread_join(threads[i],NULL);
    }
}
