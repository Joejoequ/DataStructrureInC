//
// Created by QuJunqiao on 2020/11/26.
//

#ifndef LAB9_POOL_H
#define LAB9_POOL_H
#include <stdbool.h>
#include "array_list.h"
#include "queue.h"
typedef struct _Operation{
    int (*op)(int,int);
    int a;
    int b;
}Operation;
typedef struct _Args{
    Operation *operation;
    bool is_complete;
}Args;

void* compute(void*);
bool read_operations(char*, Queue*);
ArrayList* execute_thread_pool(char*, int);
void print_sorted(ArrayList*);
int mul(int , int );
int sub(int , int );
int add(int , int );
#endif //LAB9_POOL_H
