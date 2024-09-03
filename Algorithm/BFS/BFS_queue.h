#ifndef QUEUE_H
#define QUEUE_H

#include"BFS_graph.h"
#include"BFS_node.h"

typedef struct {
    node_t* front;
    node_t* rear;
} queue_t;


static queue_t* QUEUE_Create(void);
static void QUEUE_Put(queue_t* p_queue, unsigned int vertex);
static int QUEUE_Get(queue_t* p_queue);
static void QUEUE_Free(queue_t* p_queue);


inline queue_t* QUEUE_Create(void){
    queue_t* p_queue = (queue_t*)malloc(sizeof(queue_t));
    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}

inline void QUEUE_Put(queue_t* p_queue, unsigned int vertex){
    node_t* p_node = NODE_Create(vertex);
    if(p_queue->rear == NULL){
        p_queue->front = p_node;
        p_queue->rear = p_node;
    }
    else{
        p_queue->rear->next = p_node;
        p_queue->rear = p_node;
    }
}


inline int QUEUE_Get(queue_t* p_queue){
    if(p_queue->front == NULL){
        return -1;
    }
    int vertex = p_queue->front->vertex;
    node_t* temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if(p_queue->front == NULL){
        p_queue->rear = NULL;
    }

    NODE_Free(temp);
    return vertex;
}

inline void QUEUE_Free(queue_t* p_queue){
    p_queue->front = NULL;
    p_queue->rear =NULL;
    free(p_queue);
}

#endif