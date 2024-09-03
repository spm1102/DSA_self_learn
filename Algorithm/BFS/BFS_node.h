#ifndef NODE_H
#define NODE_H

#include"vertex.h"

struct node_t {
    vertex_t* vertex;
    int cost;
    float heuristic; 
    float total_dist_to_src;
    int visited;
    int parent;
};

typedef struct node_t node_t;


static node_t* NODE_Create(int ver);
static void NODE_Free(node_t* p_node);

inline node_t* NODE_Create(int ver){
    node_t* p_node = (node_t*)malloc(sizeof(node_t));
    p_node->vertex->vertexName = ver;
    
    return p_node;
}

inline void NODE_Free(node_t* p_node){
    free(p_node);
}


#endif