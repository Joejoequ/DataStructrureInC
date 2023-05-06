//
// Created by QuJunqiao on 2020/11/26.
//

#include "threads.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* fill (void* args){
    Args *arg=args;
    for (int i=arg->start;i<arg->end;i++){
        arg->arr[i]=arg->arr[i]*arg->arr[i];
    }
}

void fill_memory (int* arr,int thread){
    int value_num = 10000000/thread;
    pthread_t threads[thread];
    Args arg[thread];
    for (int i=0;i<thread;i++){
	arg[i].arr=arr;
        arg[i].start=i*value_num;
	if (i==thread-1){
		arg[i].end=10000000;}
	else{
        arg[i].end=(i+1)*value_num;}
        pthread_create(&threads[i],NULL,fill,&arg[i]);
    }
    for (int i=0;i<thread;i++){
        pthread_join(threads[i],NULL);
    }
}
