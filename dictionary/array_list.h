//
// Created by QuJunqiao on 2020/10/23.
//

#ifndef LAB5_ARRAY_LIST_H
#define LAB5_ARRAY_LIST_H

#include <stdbool.h>

typedef struct _AList{
    void** arr;
    int size;
    int maxSize;
    int itemSize;
    char* type;}ArrayList;

ArrayList* alist_initialize(int, int, char*);
bool alist_add(ArrayList*, void*);
bool alist_add_at(ArrayList*, int, void*);
void alist_clear(ArrayList*);
void* alist_get(ArrayList*, int);
int alist_index_of(ArrayList*, void*);
void* alist_remove(ArrayList*, int);
bool alist_destroy(ArrayList*);
bool alist_resize(ArrayList*);
#endif //LAB5_ARRAY_LIST_H
