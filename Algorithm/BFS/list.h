#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <stdbool.h>

typedef struct {
    node_t* head;
    unsigned int size;
} list_t;


static void LIST_Constructor(list_t* p_list);
static void LIST_Destructor(list_t* p_list);

static bool LIST_IsEmpty(list_t* p_list);

static bool LIST_PushBack(list_t* p_list, int value);
static int LIST_PopBack(list_t* p_list);
static bool LIST_PushFront(list_t* p_list, int value);
static int LIST_PopFront(list_t* p_list);

// bool LIST_Insert(list_t* p_list, int value, unsigned int position);
// bool LIST_Erase(list_t* p_list, unsigned int position);


void LIST_Constructor(list_t* p_list) {
    p_list->head = NULL;
    p_list->size = 0;
}

void LIST_Destructor(list_t* p_list) {
    node_t* p_node = p_list->head;

    while (p_node->to) {
        node_t* p_node_next = p_node->to;
        NODE_Free(p_node);
        p_node = p_node_next;
    }

    p_list->head = NULL;
    p_list->size = 0;
}

bool LIST_IsEmpty(list_t* p_list) {
    return (p_list->size == 0);
}

bool LIST_PushBack(list_t* p_list, int value) {
    node_t* p_node = NODE_Create(value);
    if (!p_node) return false;

    if (!p_list->head) {
        p_list->head = p_node;
    }
    else {
        node_t* tail = p_list->head;
        while (tail->to) {
            tail = tail->to;
        }
        tail->to = p_node;
    }

    p_list->size++;

    return true;
}

int LIST_PopBack(list_t* p_list) {
    node_t* pre_tail = NULL;
    node_t* tail = p_list->head;
    while (tail->next) {
        pre_tail = tail;
        tail = tail->next;
    }

    int value = tail->value;
    NODE_Free(tail);
    pre_tail->next = NULL;
    p_list->size--;
    
    return value;
}

bool LIST_PushFront(list_t* p_list, int value) {
    node_t* p_node = NODE_Create(value);
    if (!p_node) return false;
    
    p_node->next = p_list->head;
    p_list->head = p_node;
    p_list->size++;
    
    return true;
}

int LIST_PopFront(list_t* p_list) {
    node_t* head = p_list->head;
    
    int value = p_list->head->value;
    p_list->head = p_list->head->next;
    NODE_Free(head);
    p_list->size--;
    
    return value;
}



#endif