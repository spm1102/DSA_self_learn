#ifndef GRAPH_H
#define GRAPH_H

#include"BFS_vertex.h"


struct graph_t {
    unsigned int numVertices;
    int** adjMatrix;
};

typedef struct graph_t graph_t;

static graph_t* GRAPH_Create(unsigned int vertices);
static void GRAPH_addEdge(graph_t* p_graph, unsigned int s, unsigned int d);
static void GRAPH_Free(graph_t* p_graph);


inline graph_t *GRAPH_Create(unsigned int vertices) {
    graph_t* p_graph = (graph_t*)malloc(sizeof(graph_t));
    p_graph->numVertices = vertices;
    p_graph->adjMatrix = (int**)calloc(vertices, sizeof(int*));


    for(unsigned int i = 0; i < vertices; i++) {
        p_graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    return p_graph;
}

inline void GRAPH_addEdge(graph_t* p_graph, unsigned int src, unsigned int des) {
    p_graph->adjMatrix[src][des] = 1;
    p_graph->adjMatrix[des][src] = 1;
}


inline void GRAPH_Free(graph_t* p_graph){
    unsigned int i = 0;
    vertex_t* temp = p_graph->adjMatrix[i];
    while(i < p_graph->numVertices){
        temp = p_graph->adjMatrix[i++];
        free(temp);
    }
    free(p_graph->adjMatrix);
    free(p_graph);
}


#endif