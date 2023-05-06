//
// Created by QuJunqiao on 2020/10/29.
//
#include <stdlib.h>
#include "queue.h"
#include <string.h>
#include <stdio.h>
Queue* queue_initialize(int typeSize, char* type){
    Queue *q = malloc(sizeof(Queue));
    q->arr = (void **) malloc(sizeof(void*));
    q->typeSize = typeSize;
    q->type = type;
    q->front=0;
    q->rear=0;
    q->size = 0;
    q->maxSize=0;
    return q;
}
bool queue_enqueue(Queue* q, void* data){
    if (q!=NULL&&data!=NULL) {
        q->arr = (void **) realloc(q->arr,  (q->maxSize+1)*sizeof(void*));

        void *p = (void *) malloc(  q->typeSize*sizeof(char));
        memcpy(p, data, q->typeSize*sizeof(char));
        q->arr[q->rear] = p;
        q->rear += 1 ;
        q->size += 1;
        q->maxSize+=1;
        return true;
    } else {
        return false;
    }
}
void* queue_dequeue(Queue* q){
    if (q!=NULL&&q->size>0) {

        void *p = (void *) malloc(  q->typeSize*sizeof(char));
        memcpy(p, q->arr[q->front], q->typeSize*sizeof(char));
        q->front+=1;
        q->size -= 1;
        return p;
    }

}
void* queue_peek(Queue* q){
    if (q!=NULL&&q->size>0) {

        void *p = (void *) malloc(  q->typeSize*sizeof(char));
        memcpy(p, q->arr[q->front], q->typeSize*sizeof(char));

        return p;
    }
}
int queue_size(Queue* q){
    if (q){
        return q->size;
    }}

bool queue_contains(Queue* q, void* data){
    bool flag=false;
    if (q != NULL && data != NULL ) {
        for (int i=q->front;i<q->rear;i++){
            if(memcmp(q->arr[i],data,sizeof(void*))==0){
                flag=true;
            }
        }
    }
    return flag;

}
bool queue_destroy(Queue* q){
    if (q) {
        for(int i=0;i<q->maxSize;i++){
            free(q->arr[i]);}
        free(q->arr) ;

        free(q);

        return true;
    } else {
        return false;
    }
}
void print(Queue * q) {
    for (int i = q->front; i < q->rear; i++) {
        printf("%d  -  %d\n", i, *(int *) (q->arr[i]));
    }
}
