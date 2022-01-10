//
// Created by tahel on 07/01/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Graph.h"
#include "Node.h"

//typedef struct edge_ {
//    int weight;
//    pnode dest_node;
//    struct edge_ *next;
//} edge, *pedge;

//allocate new edge in the graph:
pedge edge_alloc(int weight,pnode src_node, pnode dest_node)
{
    pedge new_edge_pointer = (pedge)malloc(sizeof(edge));
    if (new_edge_pointer == NULL)
    {
        printf("ERROR");
        exit(0);
    }
    new_edge_pointer -> weight = weight;
    new_edge_pointer -> dest_node = dest_node;
    new_edge_pointer -> next = src_node->edges;
    src_node->edges = new_edge_pointer;
    return new_edge_pointer;
}

//pedge insert_first_edge(int weight,pnode dest_node, pedge edge) {
//    //create a new node
//    pedge new_edge = creat_new_edge(weight, dest_node, edge);
//    return new_edge;
//}