//
// Created by QuJunqiao on 2020/10/23.
//
#include <stdlib.h>
#include "array_list.h"
#include <stdio.h>
#include "string.h"

ArrayList *alist_initialize(int maxSize, int itemSize, char *type) {
    ArrayList *list = malloc(sizeof(ArrayList));
    list->arr = (void **) malloc(maxSize * sizeof(void*));
    list->itemSize = itemSize;
    list->maxSize = maxSize;//max item
    list->type = type;
    list->size = 0;
    return list;
}

bool alist_add(ArrayList *list, void *item) {
    if (item) {
        if (list->size == list->maxSize) {
            alist_resize(list);
        }
        void *p = (void *) malloc(  list->itemSize*sizeof(char));
        memcpy(p, item, list->itemSize*sizeof(char));
        list->arr[list->size] = p;
        list->size += 1;
        return true;
    } else {
        return false;
    }
}

bool alist_add_at(ArrayList *list, int index, void *item) {

    if (item && index >= 0 && index <= list->size) {


        if (list->size == list->maxSize) {
            alist_resize(list);
        }
        if (index == list->size) {
            alist_add(list, item);
        } else {
            for (int i = list->size; i >index ; i--) {
                list->arr[i] = list->arr[i-1];
            }
            void *p = (void *) malloc(list->itemSize*sizeof(char));
            memcpy(p, item, list->itemSize*sizeof(char));
            list->arr[index] = p;
            list->size += 1;
            return true;
        }
    } else {
        return false;
    }
}

void alist_clear(ArrayList *list) {
    if (list) {
        for (int i = 0; i < list->size; i++) {
            free(list->arr[i]);
        }
        list->size = 0;
    }
}

void *alist_get(ArrayList *list, int index) {
    if (list && index >= 0 && index < list->size) {
        return list->arr[index];
    }

}

int alist_index_of(ArrayList *list, void *item) {
    if (item) {
        int indexof = -1;
        for (int i = 0; i < list->size; i++) {
            if (memcmp(list->arr[i],item,sizeof(void*))==0) {
                indexof = i;
            }
        }
        return indexof;
    } else {
        return -1;
    }
}

void *alist_remove(ArrayList *list, int index) {
	if (list&&index>=0&&index<list->size){
    void *item = (void*)malloc(sizeof(void*));
    memcpy(item,list->arr[index],list->itemSize*sizeof(char));
    list->arr[index]=NULL;
    for (int i= index; i<list->size-1;i++){
	    list->arr[i]=list->arr[i+1];
    }
    list->size -= 1;
    return item;}

}

bool alist_destroy(ArrayList *list) {
    if (list) {
   for(int i=0;i<list->size;i++){
	   free(list->arr[i]);}
   free(list->arr) ;
  
   free(list);
            
        return true;
    } else {
        return false;
    }

}

bool alist_resize(ArrayList *list) {
    if (list) {
        list->maxSize = list->maxSize * 2;
        list->arr = (void **) realloc(list->arr,  list->maxSize*sizeof(void*));

        return true;
    } else {
        return false;
    }
}

void print(ArrayList *al) {
    for (int i = 0; i < al->size; i++) {
        printf("%d  -  %d\n", i, *(int *) (al->arr[i]));
    }
}
