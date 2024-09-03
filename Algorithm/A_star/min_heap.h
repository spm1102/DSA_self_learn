#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include"node.h"

struct min_Heap_t {
    int num_node;
    node_heap_t** nodes;
};

typedef struct min_Heap_t min_Heap_t;

static void Heapify(min_Heap_t* p_min_heap, int index);
static min_Heap_t* HEAP_Create(unsigned int capacity);
static void HEAP_Insert(min_Heap_t* p_min_heap, node_heap_t* p_node);
static node_heap_t* HEAP_Extract(min_Heap_t* p_min_heap);
static void HEAP_Free(min_Heap_t* p_min_heap);

void Heapify(min_Heap_t* p_min_heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < p_min_heap->num_node && p_min_heap->nodes[left]->total_dist_to_src < p_min_heap
    ->nodes[smallest]->total_dist_to_src) {
        smallest  = left;
    }

    if(right < p_min_heap->num_node && p_min_heap->nodes[right]->total_dist_to_src < p_min_heap->nodes[smallest]->total_dist_to_src) {
        smallest  = right;
    } 

    if(smallest != index) {
        NODE_Swap(p_min_heap->nodes[smallest], p_min_heap->nodes[index]);
        Heapify(p_min_heap, smallest);
    }
}

min_Heap_t* HEAP_Create(unsigned int capacity) {
    min_Heap_t* p_min_heap = (min_Heap_t*)malloc(sizeof(min_Heap_t));
    p_min_heap->nodes = (node_heap_t**)malloc(capacity * sizeof(node_heap_t*));
    p_min_heap->num_node = 0;
    
    return p_min_heap;
}

void HEAP_Insert(min_Heap_t* p_min_heap, node_heap_t* p_node) {
    p_min_heap->nodes[p_min_heap->num_node] = p_node; 
    int current = p_min_heap->num_node;
    p_min_heap->num_node++;

    while(current != 0 && p_min_heap->nodes[current]->total_dist_to_src < p_min_heap->nodes[(current - 1) / 2]->total_dist_to_src) {
        NODE_Swap(p_min_heap->nodes[current], p_min_heap->nodes[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

node_heap_t* HEAP_Extract(min_Heap_t* p_min_heap) {
    node_heap_t* root = p_min_heap->nodes[0];

    node_heap_t* lastNode = p_min_heap->nodes[p_min_heap->num_node - 1];
    p_min_heap->nodes[0] = lastNode;
    p_min_heap->num_node--;
    Heapify(p_min_heap, 0);
    
    return root;
}

void HEAP_Free(min_Heap_t* p_min_heap){
    free(p_min_heap->nodes);
    free(p_min_heap);
}

#endif