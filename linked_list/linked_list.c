//
// Created by QuJunqiao on 2020/10/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

LinkedList *llist_initialize(int itemSize, char *type) {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->type = type;
    list->itemSize = itemSize;
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

bool llist_add_at(LinkedList *list, int index, void *data) {


    if (list != NULL && data != NULL && index > 0 && index < list->size) {
        if (index == 0) {
            return llist_add_first(list, data);
        }
        if (index == list->size) {
            return llist_add_last(list, data);
        }

        Node *add = malloc(sizeof(Node));
        add->data = malloc(list->itemSize * sizeof(char));
        memcpy(add->data, data, list->itemSize * sizeof(char));
        Node *n = malloc(sizeof(Node));
        n = list->first;
        for (int i = 0; i < index - 1; i++) {
            n = n->next;
        }
        Node *after = n->next;
        add->prev = n;
        add->next = after;
        n->next = add;
        after->prev = add;
        list->size += 1;
        return true;
    } else {
        return false;
    }

}


bool llist_add_first(LinkedList *list, void *item) {
    if (list != NULL && item != NULL) {
        Node *n = malloc(sizeof(Node));
        n->data = malloc(list->itemSize * sizeof(char));
        memcpy(n->data, item, list->itemSize * sizeof(char));
        if (list->first == NULL) {
            n->prev = NULL;
            n->next = NULL;
            list->first = n;
            list->last = n;
        } else {
            n->prev = NULL;
            n->next = list->first;
            list->first->prev = n;
            list->first = n;
        }
        list->size += 1;
        return true;

    } else {
        return false;
    }
}

bool llist_add_last(LinkedList *list, void *item) {
    if (list != NULL && item != NULL) {
        Node *n = malloc(sizeof(Node));
        n->data = malloc(list->itemSize * sizeof(char));
        memcpy(n->data, item, list->itemSize * sizeof(char));
        if (list->last == NULL) {
            n->prev = NULL;
            n->next = NULL;
            list->first = n;
            list->last = n;
        } else {
            list->last->next = n;

            n->prev = list->last;
            n->next = NULL;
            list->last = n;
        }
        list->size += 1;
        return true;

    } else {
        return false;
    }
}


void *llist_get(LinkedList *list, int index) {
    if (list != NULL && index >= 0 && index < list->size) {
        Node *temp;
        if (index == 0) {
            return list->first->data;

        } else {
            temp = list->first;
            while (index != 0) {
                temp = temp->next;
                index--;
            }

            return temp->data;
        }
    } else {
        return NULL;
    }

}

int llist_index_of(LinkedList *list, void *item) {
    if (item == NULL || list == NULL) {
        return -1;
    } else {
        int index = -1;
        Node *n = malloc(sizeof(Node));
        n = list->first;
        if (memcmp(n->data, item, sizeof(void *)) == 0) {
            index = 0;
        }
        for (int i = 1; i < list->size; i++) {
            n = n->next;
            if (memcmp(n->data, item, sizeof(void *)) == 0) {
                index = i;
                break;
            }
        }
        return index;
    }

}

void *llist_remove(LinkedList *list, int index) {


    if (list != NULL && index > 0 && index < list->size) {
        Node *before = list->first;
        for (int i = 0; i < index - 1; i++) {
            before = before->next;
        }
        Node *curr = before->next;
        Node *after = curr->next;
        void *data = malloc(sizeof(void *));
        memcpy(data, curr->data, list->itemSize * sizeof(char));
        before->next = after;
        after->prev = before;
        list->size -= 1;
        return data;
    } else {
        return NULL;
    }

}

void *llist_remove_first(LinkedList *list) {
    if (list == NULL) {
        return NULL;
    } else {
        if (list->size > 0) {
            Node *temp = list->first;
            Node *second = list->first->next;
            second->prev = NULL;
            list->first = second;
            list->size -= 1;
            return temp->data;
        } else {
            return NULL;
        }
    }
}

void *llist_remove_last(LinkedList *list) {
    if (list == NULL) {
        return NULL;
    } else {
        if (list->size > 0) {
            Node *temp = list->last;
            Node *second_last = list->last->prev;
            second_last->next = NULL;
            list->last = second_last;
            list->size -= 1;
            return temp->data;
        } else {
            return NULL;
        }
    }
}

bool llist_destroy(LinkedList *list) {
    if (list) {
        Node *n = list->first;
        Node *next;
        while (n->next != NULL) {
            free(n->data);
            next = n->next;
            free(n);

            n = next;
        }
        free(list);
        return true;
    } else {
        return false;
    }
}

void printll(LinkedList *list) {
    if (list) {
        Node *temp = malloc(sizeof(Node));
        temp = list->first;
        int count = 0;
        while (count < list->size) {
            printf("%d  -  %d\n", count, *(int *) temp->data);
            if (temp->next == NULL) {
                break;
            } else {
                count++;
                temp = temp->next;
            }
        }
    } else {
        return;
    }

}







