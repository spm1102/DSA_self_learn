#include<stdio.h>

#ifdef TEST_QUEUE_ARRAY
#define TEST_QUEUE_ARRAY
#include"queue_array.h"

void QUEUE_ARRAY_Print(queue_array_t* p_queue) {
    for(unsigned int i = 0; i < p_queue->size; i++){
        printf("\n%d", p_queue->queue[p_queue->front + p_queue->size - i]);
    }
}

int main(){
    queue_array_t queue;
    
    QUEUE_ARRAY_Constructor(&queue);
    QUEUE_ARRAY_Put(&queue, 1);
    printf("HELP");
    QUEUE_ARRAY_Put(&queue, 2);
    QUEUE_ARRAY_Put(&queue, 3);

    QUEUE_ARRAY_Get(&queue);

    QUEUE_ARRAY_Put(&queue, 4);
    QUEUE_ARRAY_Get(&queue);

    QUEUE_ARRAY_Print(&queue);    


    QUEUE_ARRAY_Destructor(&queue);
}
#endif

#ifdef TEST_GRAPH
#define TEST_GRAPH

#include"node.h"
#include"graph.h"

void GRAPH_Print(graph_t* p_graph) {
    unsigned int numVer;
    for(numVer = 0; numVer < p_graph->numVertices; numVer++){
        vertex_t* temp = p_graph->adjLists[numVer];
        printf("\nVertex %d\n", numVer);
        while(temp){
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main() {
    graph_t* p_graph = GRAPH_Create(6);
    GRAPH_addEdge(p_graph, 0, 1);
    GRAPH_addEdge(p_graph, 0, 2);
    GRAPH_addEdge(p_graph, 1, 3);
    GRAPH_addEdge(p_graph, 2, 4);
    GRAPH_addEdge(p_graph, 2, 5);
    GRAPH_addEdge(p_graph, 3, 4);
    GRAPH_addEdge(p_graph, 3, 5);
    GRAPH_addEdge(p_graph, 4, 5);

    GRAPH_Print(p_graph);



    GRAPH_Free(p_graph);
   
    return 0;

}

#endif

#ifndef TEST_BFS_H
#define TEST_BFS_H

#include"BFS.h"

void GRAPH_Print(graph_t* p_graph) {
    unsigned int numVer;
    for(numVer = 0; numVer < p_graph->numVertices; numVer++){
        vertex_t* temp = p_graph->adjLists[numVer];
        printf("\nVertex %d\n", numVer);
        while(temp){
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    graph_t* p_graph = GRAPH_Create(6);
    GRAPH_addEdge(p_graph, 0, 1, 0, 0, 1, 1);
    GRAPH_addEdge(p_graph, 0, 2, 0, 0, 2, 2);
    GRAPH_addEdge(p_graph, 0, 5, 0, 0, 5, 5);
    GRAPH_addEdge(p_graph, 1, 3, 1, 1, 3, 3);
    GRAPH_addEdge(p_graph, 1, 4, 1, 1, 4, 4);
    GRAPH_addEdge(p_graph, 2, 4, 2, 2, 4, 4);
    GRAPH_addEdge(p_graph, 2, 5, 2, 2, 5, 5);
    GRAPH_addEdge(p_graph, 3, 4, 3, 3, 4, 4);
    GRAPH_addEdge(p_graph, 3, 5, 3, 3, 5, 5);
    GRAPH_addEdge(p_graph, 4, 5, 4, 4, 5, 5);

    unsigned int startVertex;
    int destination;
    scanf("%u%d", &startVertex, &destination);
    BFS(p_graph, startVertex, destination);

    GRAPH_Free(p_graph);
    return 0;
}



#endif
