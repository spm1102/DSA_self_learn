#include"a_star.h"
#define MAX_PATH_LENGTH 100

void print_shortest_path(graph_t* p_graph, int src, int dest);

int main() {
    graph_t* p_graph = NULL;
    p_graph = GRAPH_Create(6);
    EDGE_Add(p_graph, 0, 1, 4);
    EDGE_Add(p_graph, 0, 2, 2);
    EDGE_Add(p_graph, 1, 2, 3);
    EDGE_Add(p_graph, 1, 3, 2);
    EDGE_Add(p_graph, 1, 4, 3);
    EDGE_Add(p_graph, 1, 5, 3);
    EDGE_Add(p_graph, 2, 4, 1);
    EDGE_Add(p_graph, 2, 3, 4);
    EDGE_Add(p_graph, 3, 4, 5);
    EDGE_Add(p_graph, 4, 5, 3);

    int source, dest;
    printf("\nEnter source and destination: ");
    scanf("%d%d", &source, &dest);
    a_star_queue(p_graph, source, dest);
    print_shortest_path(p_graph, source, dest);
    GRAPH_Free(p_graph);

    return 0;
}
void print_shortest_path(graph_t* p_graph, int src, int dest){
    if(p_graph->vertices[dest].total_dist_to_src == INT_MAX) {
        printf("\nThere is no path from %d to %d", src, dest);
        return;
    }
    else{
        int currVertex = dest;
        int pathLength = 0;
        int path[MAX_PATH_LENGTH];
        while(currVertex != src){
            path[pathLength++] = currVertex;
            currVertex = p_graph->vertices[currVertex].preVertex;
        }
        
        printf("\nShortest path from vertex %d to %d: ", src, dest);
        printf("%d ", src);
        for(int i = pathLength - 1; i >= 0; i--){
            printf("%d ", path[i]);
        }
        printf("\nDistance: %d\n", p_graph->vertices[dest].total_dist_to_src);
    }
}