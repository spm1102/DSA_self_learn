#ifndef GRAPH_H
#define GRAPH_H

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_VERTICES 100

struct edge_t {
    int dest;
    int weight;
    struct edge_t* next;
};

typedef struct edge_t edge_t;

struct vertex_t {
    int visited;
    int total_dist;
    int preVertex;
    edge_t* edge;
};
typedef struct vertex_t vertex_t;

struct graph_t {
    int numVertices;
    vertex_t vertices[MAX_VERTICES];
};

typedef struct graph_t graph_t;


static graph_t* GRAPH_Create(int numVertices);
static void GRAPH_Free(graph_t* p_graph);
static void EDGE_Add(graph_t* p_graph, int src, int dest, int weight);
static void EDGE_Free(edge_t* p_edge);


inline graph_t* GRAPH_Create(int numVertices) {
    graph_t* p_graph = (graph_t*)malloc(sizeof(graph_t));

    p_graph->numVertices = numVertices;
    for(int i = 0; i < numVertices; i++) {
        p_graph->vertices[i].visited = 0;
        p_graph->vertices[i].total_dist = INT_MAX;
        p_graph->vertices[i].preVertex = -1;
        p_graph->vertices[i].edge =NULL;
    }

    return p_graph;
}

void GRAPH_Free(graph_t* p_graph) {
    free(p_graph);
}

inline void EDGE_Add(graph_t* p_graph, int src, int dest, int weight) {
    edge_t* p_edge_src = (edge_t*)malloc(sizeof(edge_t));
    p_edge_src->dest = dest;
    p_edge_src->weight = weight;
    p_edge_src->next = p_graph->vertices[src].edge;
    p_graph->vertices[src].edge = p_edge_src;

    edge_t* p_edge_dest = (edge_t*)malloc(sizeof(edge_t));
    p_edge_dest->dest = src;
    p_edge_dest->weight = weight;
    p_edge_dest->next = p_graph->vertices[dest].edge;
    p_graph->vertices[dest].edge = p_edge_dest;
}

inline void EDGE_Free(edge_t* p_edge) {
    free(p_edge);
}



#endif