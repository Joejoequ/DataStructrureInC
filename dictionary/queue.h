//
// Created by QuJunqiao on 2020/10/29.
//

#ifndef LAB7_QUEUE_H
#define LAB7_QUEUE_H
#include <stdbool.h>

typedef struct _Queue{
    void** arr;
    int size;
    int front;
    int rear;
    char* type;
    int typeSize;
   int maxSize;}Queue;
Queue* queue_initialize(int, char*);
bool queue_enqueue(Queue*, void*);
void* queue_dequeue(Queue*);
void* queue_peek(Queue*);
int queue_size(Queue*);
bool queue_contains(Queue*, void*);
bool queue_destroy(Queue*);

#endif //LAB7_QUEUE_H
