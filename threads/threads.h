//
// Created by QuJunqiao on 2020/11/26.
//

#ifndef LAB9_THREADS_H
#define LAB9_THREADS_H
typedef struct _Args{
    int* arr;
    int start;
    int end;
}Args;
void*  fill(void*);
void  fill_memory(int*, int);
#endif //LAB9_THREADS_H
