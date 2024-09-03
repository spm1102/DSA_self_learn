#ifndef A_STAR_HEAP_H
#define A_STAR_HEAP_H

#include"a_star_graph.h"
#include"min_heap.h"


void print_path(graph_t* p_graph, int dest);
void print_path_to_dest(graph_t* p_graph, int dest);
void a_star_search(graph_t* p_graph, int source, int dest) {
    unsigned int num_vertex = (unsigned int)p_graph->numVertices;
    //int number_edge = num_edge(p_graph);
    min_Heap_t* p_min_heap = HEAP_Create(num_vertex);
    p_graph->vertices[source].total_dist_to_src = 0;
    node_heap_t* src_node = NODE_HEAP_Create(source, 0, 0);
    HEAP_Insert(p_min_heap, src_node);

    while(p_min_heap->num_node != 0) {
        node_heap_t* p_min_node = HEAP_Extract(p_min_heap);
        int currentVertex = p_min_node->vertexName;

        NODE_HEAP_Free(p_min_node);

        edge_t* temp = p_graph->vertices[currentVertex].edge;
        while(temp != NULL) {
            int adj_vertex = temp->dest;
            int weight = temp->weight;
            int distance = p_graph->vertices[currentVertex].total_dist_to_src + weight;

            if(distance < p_graph->vertices[adj_vertex].total_dist_to_src) {
                p_graph->vertices[adj_vertex].total_dist_to_src = distance;
                p_graph->vertices[adj_vertex].preVertex = currentVertex;
                node_heap_t* new_node = NODE_HEAP_Create(adj_vertex, distance, 0);
                HEAP_Insert(p_min_heap, new_node);
            }
            temp = temp->next;
        }
    }
    print_path_to_dest(p_graph, dest);
    HEAP_Free(p_min_heap);
}



void print_path(graph_t* p_graph, int dest) {
    if(p_graph->vertices[dest].preVertex == -1){
        printf("There is no path to %d", dest);
        return;
    }
    print_path(p_graph, p_graph->vertices[dest].preVertex);
    printf("%d", dest);
}


void print_path_to_dest(graph_t* p_graph, int dest) {
    printf("Path from source to destination %d: ", dest);
    print_path(p_graph, dest);
    printf("\nDistance: %d\n", p_graph->vertices[dest].total_dist_to_src);
}
#endif