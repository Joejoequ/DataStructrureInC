//
// Created by QuJunqiao on 2020/11/26.
//

#include "unsafe.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void*  counting(void* args){
    Count* arg=args;
    while (arg->count<1000){
        arg->count++;
        printf("%d\n",arg->count);
    }
    return NULL;
}
void   count_variable(int thread){
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
