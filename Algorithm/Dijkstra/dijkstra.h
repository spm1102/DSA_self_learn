#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "GRAPH_GEN.h"
#include "Dijkstra_queue.h"

static void dijkstra(graph_t *p_graph, int startVertex, int destination);

inline void dijkstra(graph_t *p_graph, int startVertex, int destination)
{
    queue_t *p_queue = NULL;
    p_queue = QUEUE_Create();
    p_graph->vertices[startVertex].total_dist = 0;
    QUEUE_Put(p_queue, startVertex, 0);
    while (p_queue->front != NULL)
    {
        node_t *minNode = QUEUE_Get(p_queue);
        int currentVertex = minNode->vertex;
        NODE_Free(minNode);

        if (p_graph->vertices[currentVertex].visited)
        {
            continue;
        }
        p_graph->vertices[currentVertex].visited = 1;

        edge_t *temp = p_graph->vertices[currentVertex].edge;
        while (temp != NULL)
        {
            int nextVertex = temp->dest;
            int weight = temp->weight;

            if (!p_graph->vertices[nextVertex].visited)
            {
                int new_dist = p_graph->vertices[currentVertex].total_dist + weight;
                if (new_dist < p_graph->vertices[nextVertex].total_dist)
                {
                    p_graph->vertices[nextVertex].total_dist = new_dist;
                    p_graph->vertices[nextVertex].preVertex = currentVertex;
                    QUEUE_Put(p_queue, nextVertex, new_dist);
                }
            }
            temp = temp->next;
        }
    }
    QUEUE_Free(p_queue);
}

#endif