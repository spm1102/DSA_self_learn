#ifndef BFS_H
#define BFS_H

#include<stdio.h>
#include"BFS_queue.h"

static void print_parentPath(int parentVertex[], unsigned int vertex, unsigned int startVertex);
static void BFS(graph_t* p_graph, unsigned int startVertex, int destination);

inline void print_parentPath(int parentVertex[], unsigned int vertex, unsigned int startVertex){
    if(parentVertex[vertex] == -1){
        printf("%d ", (int)vertex);
        return;
    }
    
    unsigned int path[MAX_VERTICES];
    unsigned int pathLength = 0;
    
    while(vertex != startVertex){
        path[pathLength++] = vertex;
        vertex = (unsigned int)parentVertex[vertex];
    }

    path[pathLength] = startVertex;
    
    for(int i = (int)pathLength; i >= 0; i--){
        printf("%u ", path[i]);
    }
    printf("\n");
}

inline void BFS(graph_t* p_graph, unsigned int startVertex, int destination) {
    int visited[MAX_VERTICES] = {0};
    int parentVertex[MAX_VERTICES] = {-1};
    queue_t* p_queue = QUEUE_Create();

    visited[startVertex] = 1;
    QUEUE_Put(p_queue, startVertex);

    while(p_queue->front != NULL){
        int currentVertex = QUEUE_Get(p_queue);

        vertex_t* temp = p_graph->adjLists[currentVertex];
        while(temp != NULL){
            unsigned int adjVertex = temp->vertex;

            if(!visited[adjVertex]){
                visited[adjVertex] = 1;
                parentVertex[adjVertex] = currentVertex;
                QUEUE_Put(p_queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("Shortest path from %d to %d: ",startVertex, destination);
    print_parentPath(parentVertex, destination, startVertex);
    printf("\n");


    QUEUE_Free(p_queue);
}



#endif