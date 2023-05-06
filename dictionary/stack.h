//
// Created by QuJunqiao on 2020/10/30.
//

#ifndef LAB7_STACK_H
#define LAB7_STACK_H
#include <stdbool.h>
typedef struct _Stack {
    void **arr;
    int size;
    int top;
    char *type;
    int typeSize;
    int maxSize;
} Stack;

Stack *stack_initialize(int, char *);

bool stack_push(Stack *, void *);

void *stack_pop(Stack *);

void *stack_peek(Stack *);

int stack_size(Stack *);

bool stack_contains(Stack *, void *);

bool stack_destroy(Stack *);

void print_stack(Stack *);

#endif //LAB7_STACK_H
