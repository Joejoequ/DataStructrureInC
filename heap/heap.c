//
// Created by QuJunqiao on 2020/11/19.
//

#include "heap.h"
#include "stdlib.h"

Heap *heap_initialize(int typeSize, char *type, int (*compare)(void *, void *), void (*print)(void *)) {
    if (type != NULL && compare != NULL && print != NULL) {
        Heap *h = malloc(sizeof(Heap));
        h->list = alist_initialize(10, typeSize, type);
        h->compare = compare;
        h->print = print;
        return h;
    }
}

bool heap_insert(Heap *h, void *data) {
    if (h && data) {
        alist_add(h->list, data);
        _heapify_up(h, heap_size(h) - 1);
    }
}

void *heap_remove(Heap *h) {
    if (h) {
        void *pop;
        if (heap_size(h) == 0) {
            return NULL;
        }
        pop = h->list->arr[0];
        h->list->arr[0] = h->list->arr[heap_size(h) - 1];
        alist_remove(h->list, heap_size(h) - 1);
        _heapify(h, 0);
        return pop;
    }
}

void *heap_peek(Heap *h) {
    if (h) {
        void *pop;
        if (heap_size(h) == 0) {
            return NULL;
        }
        pop = h->list->arr[0];
        return pop;
    }
}

int heap_size(Heap *h) {
    if (h) {
        return h->list->size;
    } else {
        return -1;
    }
}

bool heap_contains(Heap *h, void *data) {
    if (h && data) {
        if (alist_index_of(h->list, data) != -1) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool _heapify(Heap *h, int parent) {
    if (h && parent >= 0) {
        int left = parent * 2 + 1;
        int right = parent * 2 + 2;
        int top = parent;

        if (left < heap_size(h) && h->compare(h->list->arr[left], h->list->arr[top]) > 0) {
            top = left;
        }

        if (right < heap_size(h) && h->compare(h->list->arr[right], h->list->arr[top]) > 0) {
            top = right;
        }

        if (top != parent) {
            void *temp;
            temp = h->list->arr[top];
            h->list->arr[top] = h->list->arr[parent];
            h->list->arr[parent] = temp;
            _heapify(h, top);
            return true;
        }
    }
}


bool _heapify_up(Heap *h, int index) {
    if (h && index >= 0) {
        void *temp;
        int parent = (index - 1) / 2;
        if (h && h->compare(h->list->arr[parent], h->list->arr[index]) < 0) {
            temp = h->list->arr[parent];
            h->list->arr[parent] = h->list->arr[index];
            h->list->arr[index] = temp;
            _heapify_up(h, parent);
            return true;

        } else {
            return false;
        }

    }
}

