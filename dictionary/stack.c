//
// Created by QuJunqiao on 2020/10/30.
//

#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Stack *stack_initialize(int typeSize, char * type){
    Stack *s = malloc(sizeof(Stack));
    s->arr = (void **) malloc(sizeof(void*));
    s->typeSize = typeSize;
    s->type = type;
    s->top=0;
    s->size = 0;
    s->maxSize=0;
    return s;
}

bool stack_push(Stack * s, void * data){
    if (s!=NULL&&data!=NULL) {
        s->arr = (void **) realloc(s->arr,  (s->maxSize+1)*sizeof(void*));
        void *p = (void *) malloc(  s->typeSize*sizeof(char));
        memcpy(p, data, s->typeSize*sizeof(char));
        s->arr[s->top] = p;
        s->top += 1 ;
        s->size += 1;
        s->maxSize+=1;
        return true;
    } else {
        return false;
    }
}

void *stack_pop(Stack * s){
    if (s!=NULL&&s->size>0) {

        void *p = (void *) malloc(  s->typeSize*sizeof(char));
        memcpy(p, s->arr[s->top-1], s->typeSize*sizeof(char));
        s->top-=1;
        s->size -= 1;
        return p;
    }
}

void *stack_peek(Stack * s){
    if (s!=NULL&&s->size>0) {

        void *p = (void *) malloc(  s->typeSize*sizeof(char));
        memcpy(p, s->arr[s->top-1], s->typeSize*sizeof(char));

        return p;
    }
}

int stack_size(Stack * s){
    if (s){
        return s->size;
    }
}

bool stack_contains(Stack * s, void * data){
    bool flag=false;
    if (s != NULL && data != NULL ) {
        for (int i=0;i<s->top;i++){
            if(memcmp(s->arr[i],data,sizeof(void*))==0){
                flag=true;
            }
        }
    }
    return flag;

}

bool stack_destroy(Stack * s){
    if (s) {
        for(int i=0;i<s->maxSize;i++){
            free(s->arr[i]);}
        free(s->arr) ;

        free(s);

        return true;
    } else {
        return false;
    }
}

void print_stack(Stack * s){
    for (int i = 0; i < s->top; i++) {
        printf("%d  -  %d\n", i, *(int *) (s->arr[i]));
    }
}
