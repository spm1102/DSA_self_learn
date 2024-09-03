#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include<stdbool.h>

#define QUEUE_ARRAY_MAX_SIZE        50

typedef struct {
    int queue[QUEUE_ARRAY_MAX_SIZE];
    unsigned int size;
    unsigned int front;
} queue_array_t;



static void QUEUE_ARRAY_Constructor(queue_array_t* p_queue);
static void QUEUE_ARRAY_Destructor(queue_array_t* p_queue);

static bool QUEUE_ARRAY_IsEmpty(queue_array_t* p_queue);
static bool QUEUE_ARRAY_IsFull(queue_array_t* p_queue);

static void QUEUE_ARRAY_Put(queue_array_t* p_queue, int value);
static int QUEUE_ARRAY_Get(queue_array_t* p_queue);


inline void QUEUE_ARRAY_Constructor(queue_array_t* p_queue){
    p_queue->size = 0;
    p_queue->front = QUEUE_ARRAY_MAX_SIZE - 1;
}

inline void QUEUE_ARRAY_Destructor(queue_array_t* p_queue) {
    p_queue->size = 0;
    p_queue->front = QUEUE_ARRAY_MAX_SIZE - 1;
}

inline bool QUEUE_ARRAY_IsEmpty(queue_array_t* p_queue) {
    return (p_queue->size == 0);
}

inline bool QUEUE_ARRAY_IsFull(queue_array_t* p_queue) {
    return (p_queue->size == QUEUE_ARRAY_MAX_SIZE);
}

inline void QUEUE_ARRAY_Put(queue_array_t* p_queue, int value) {
    if (QUEUE_ARRAY_IsFull(p_queue)) return;

    p_queue->queue[p_queue->front--] = value;
    p_queue->size++;
}

inline int QUEUE_ARRAY_Get(queue_array_t* p_queue) {
    if (QUEUE_ARRAY_IsEmpty(p_queue)) return 0;

    int b = p_queue->queue[p_queue->front + p_queue->size];
    p_queue->size--;
    return b;
}

#endif