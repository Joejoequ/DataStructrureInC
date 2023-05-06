//
// Created by qujunqiao on 2020/11/10.
//
#include "dictionary.h"
#include "stdlib.h"
Dictionary* dict_initialize(int (*compare)(void*, void*), void (*print)(void*)){
    Dictionary * dict = malloc(sizeof(Dictionary));
    dict->tree=bintree_initialize(sizeof(Pair),"Pair",compare,print);
    return dict;
}
bool dict_insert(Dictionary* dict, void* key, void* value){

    if (dict != NULL && key != NULL&&value!=NULL) {
        Pair *p = malloc(sizeof(Pair));
        p->first=key;
        p->second=value;
        bintree_insert_replace(dict->tree,p);
        return true;
    } else {
        return false;
    }
}

void* dict_get(Dictionary* dict, void* key){
    if (dict != NULL && key != NULL) {

        if (dict->tree->top == NULL) {
            return NULL;
        } else {
            Pair *p=malloc(sizeof(Pair));
            p->first=key;
            Pair *result=(Pair*)_dict_get_recursive(dict->tree, dict->tree->top, p);
            if (result){
                return result->second;
            }
            else{
                return NULL;
            }
        }

    } else {
        return NULL;
    }
}
void* _dict_get_recursive(BinaryTree *tree, BinaryTreeNode *node, void *data) {

    BinaryTreeNode *next;
    if (tree->compare(data, node->data) < 0) {
        next = node->right;
    }
    if (tree->compare(data, node->data) > 0) {
        next = node->left;
    }
    if (tree->compare(data, node->data) == 0) {
        return node->data;
    }
    if (next == NULL) {
        return NULL;
    } else {
        _dict_get_recursive(tree, next, data);
    }

}
ArrayList* dict_key_list(Dictionary* dict, int size){
    ArrayList *result= alist_initialize(100,size,"String");
    if (dict != NULL&&dict->tree!=NULL) {
        Queue *agenda = queue_initialize(sizeof(BinaryTreeNode), "BinaryTreeNode");
        queue_enqueue(agenda, dict->tree->top);
        while (queue_size(agenda) != 0) {
            BinaryTreeNode *node = queue_peek(agenda);
            Pair* p = node->data;
           alist_add(result,p->first);
            queue_dequeue(agenda);
            if (node->left) {
                queue_enqueue(agenda, node->left);
            }
            if (node->right) {
                queue_enqueue(agenda, node->right);
            }
        }
        return result;
    }
}
bool dict_contains(Dictionary* dict, void* key){
    if (dict != NULL && key != NULL) {

        if (dict->tree->top == NULL) {
            return false;
        } else {
            Pair *p=malloc(sizeof(Pair));
            p->first=key;
            return bintree_search(dict->tree,p);
        }

    } else {
        return false;
    }
}
