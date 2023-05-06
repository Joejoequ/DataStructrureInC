//
// Created by QuJunqiao on 2020/10/30.
//
#include <stdlib.h>
#include "bintree.h"
#include "string.h"
#include <stdio.h>

BinaryTree *bintree_initialize(int itemSize, char *type, int (*compare)(void *, void *), void (*print)(void *)) {

        BinaryTree *tree = malloc(sizeof(BinaryTree));
        tree->top = NULL;
        tree->type = type;
        tree->itemSize = itemSize;
        tree->print = print;
        tree->compare = compare;
        return tree;

}

BinaryTreeNode *bintree_create_node(int dataSize, void *data) {
    if (data != NULL) {
        BinaryTreeNode *node = malloc(sizeof(BinaryTreeNode));
        node->left = NULL;
        node->right = NULL;
        void *p = (void *) malloc(dataSize * sizeof(char));
        memcpy(p, data, dataSize * sizeof(char));
        node->data = p;
        return node;
    }

}

bool bintree_insert(BinaryTree *tree, void *data) {
    if (tree != NULL && data != NULL) {
        BinaryTreeNode *node = bintree_create_node(tree->itemSize, data);
        if (tree->top == NULL) {
            tree->top = node;

        } else {
            return _bintree_insert_recursive(tree,tree->top,data);
        }
        return true;
    } else {
        return false;
    }
}
bool _bintree_insert_recursive(BinaryTree * tree, BinaryTreeNode * node, void * data) {

        BinaryTreeNode *next;
        if (tree->compare(data,node->data) <= 0) {
            next = node->right;
        } else {
            next = node->left;
        }
        if (next == NULL) {
            BinaryTreeNode *add_node = bintree_create_node(tree->itemSize, data);
            if (tree->compare(data,node->data) <= 0) {
               node->right = add_node;
            } else {
                node->left= add_node;
            }
            return true;
        } else {
            _bintree_insert_recursive(tree,next, data);
        }


}



bool bintree_search(BinaryTree * tree, void * data) {
    if (tree != NULL && data != NULL) {
        if (tree->top == NULL) {
            return false;
        } else {
            return _bintree_search_recursive(tree,tree->top,data);
        }

    } else {
        return false;
    }

}
bool _bintree_search_recursive(BinaryTree * tree, BinaryTreeNode * node, void * data) {

        BinaryTreeNode *next;
        if (tree->compare(data,node->data) < 0) {
            next = node->right;
        }
        if (tree->compare(data,node->data) > 0){
            next = node->left;
        }
        if(tree->compare(data,node->data) == 0){
            return true;
        }
        if (next == NULL) {
            return false;
        } else {
            _bintree_search_recursive(tree,next, data);
        }



}
void bintree_print_in_order(BinaryTree * tree) {
    if (tree&&tree->top!=NULL){
        _bintree_in_order_recursive(tree,tree->top);
    }
}

void bintree_print_pre_order(BinaryTree * tree) {
    if (tree&&tree->top!=NULL){
_bintree_pre_order_recursive(tree,tree->top);
}}

void bintree_print_post_order(BinaryTree * tree) {
    if (tree&&tree->top!=NULL){
        _bintree_post_order_recursive(tree,tree->top);
    }
}

void bintree_print_reverse_order(BinaryTree * tree) {
    if (tree&&tree->top!=NULL){
        _bintree_reverse_order_recursive(tree,tree->top);
    }
}


void _bintree_in_order_recursive(BinaryTree * tree, BinaryTreeNode * node) {
    if(node != NULL)
    {

        _bintree_in_order_recursive(tree,node->left);
        tree->print(node->data);
        _bintree_in_order_recursive(tree,node->right);
    }
}

void _bintree_pre_order_recursive(BinaryTree *tree, BinaryTreeNode *node) {

    if(node != NULL)
    {
        tree->print(node->data);
        _bintree_pre_order_recursive(tree,node->left);
        _bintree_pre_order_recursive(tree,node->right);
    }

}

void _bintree_post_order_recursive(BinaryTree * tree, BinaryTreeNode *node) {
    if(node != NULL)
    {

        _bintree_post_order_recursive(tree,node->left);
        _bintree_post_order_recursive(tree,node->right);
        tree->print(node->data);
    }
}

void _bintree_reverse_order_recursive(BinaryTree *tree, BinaryTreeNode *node) {
    if(node != NULL)
    {
        _bintree_reverse_order_recursive(tree,node->right);
        tree->print(node->data);
        _bintree_reverse_order_recursive(tree,node->left);
    }
}