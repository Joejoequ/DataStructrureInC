//
// Created by QuJunqiao on 2020/11/10.
//

#ifndef LAB7_DICTIONARY_H
#define LAB7_DICTIONARY_H
#include <stdbool.h>
#include "bintree.h"
#include "array_list.h"

typedef struct _Pair {
    void*  first;
    void* second;
  }Pair;

typedef struct _Dictionary {
    BinaryTree* tree;
}Dictionary;
Dictionary* dict_initialize(int (*)(void*, void*), void (*)(void*));
bool dict_insert(Dictionary*, void*, void*);
void* dict_get(Dictionary*, void*);
ArrayList* dict_key_list(Dictionary*, int);
bool _dict_insert_recursive(BinaryTree *, BinaryTreeNode *, void *);
bool dict_contains(Dictionary*, void*);
void* _dict_get_recursive(BinaryTree *, BinaryTreeNode *, void *);


#endif //LAB7_DICTIONARY_H
