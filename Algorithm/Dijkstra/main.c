
#include"dijkstra.h"
#define MAX_PATH_LENGTH 100

void printShortestPath(graph_t* p_graph, int startVertex, int numVertices);

int main(){
    graph_t* p_graph = NULL;
    p_graph = GRAPH_Create(5);
    EDGE_Add(p_graph, 0, 1, 4);
    EDGE_Add(p_graph, 0, 2, 2);
    EDGE_Add(p_graph, 1, 2, 3);
    EDGE_Add(p_graph, 1, 3, 2);
    EDGE_Add(p_graph, 1, 4, 3);
    EDGE_Add(p_graph, 2, 4, 1);
    EDGE_Add(p_graph, 2, 3, 4);
    EDGE_Add(p_graph, 3, 4, 5);

    int startVertex;
    scanf("%d", &startVertex);
    dijkstra(p_graph, startVertex);
    printShortestPath(p_graph, startVertex, 5);  

    GRAPH_Free(p_graph);

    return 0;
}

void printShortestPath(graph_t* p_graph, int startVertex, int numVertices) {
    printf("\nShortest path from vertex %d:", startVertex);

    for(int i = 0; i < numVertices; i++){
        if(i != startVertex){
            if(p_graph->vertices[i].total_dist == INT_MAX){
                printf("\nThere is no path from %d to %d", startVertex, i);
            }
            else{
                int path[MAX_PATH_LENGTH];
                int pathLength = 0;
                int u = i;

                while(u != startVertex){
                    path[pathLength++] = u;
                    u = p_graph->vertices[u].preVertex;
                }
                printf("\nPath from %d to %d: ", startVertex, i);
                printf("%d ", startVertex);
                for(int j = pathLength - 1; j >= 0; j--) {
                    printf("%d ", path[j]);
                }
                printf("\nDistance: %d\n", p_graph->vertices[i].total_dist);
            }
        }
    }
}
    
