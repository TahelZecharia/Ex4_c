//
// Created by tahel on 07/01/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Graph.h"
#include "Edge.h"

//typedef struct GRAPH_NODE_ {
//    int id;
//    pedge edges;
//    struct GRAPH_NODE_ *next;
//} node, *pnode;

//allocate new node in the graph:
pnode node_alloc(int id, pnode *head)
{
    pnode new_node_pointer = (pnode)malloc(sizeof(node));
    if (new_node_pointer == NULL)
    {
        printf("ERROR");
        exit(0);
    }
    pnode next_node = *head;
    new_node_pointer->id = id;
    new_node_pointer->next = next_node;
    new_node_pointer->edges = NULL;
    new_node_pointer->visit = 0;
    new_node_pointer->weight = INFINITY;
    *head = new_node_pointer;
    return new_node_pointer;
}

//pnode insert_first_node(int id, pnode *head)
//{
//    //create a new node
//    pnode new_node = creat_new_node(id, *head);
//    return new_node;
//}

pnode get_node(int id, pnode head)
{
    while (head != NULL)
    {
        if(head->id == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}


void delete_all_out_ages(pnode node)
{
    while(node->edges != NULL) {
        pedge temp_pointer = node->edges;
        node->edges = node->edges->next;
        free(temp_pointer);
        printf("delete out edges: ");
    }
}

void delete_ages_in(pnode node, int id) {

    pedge edges_pointer = node->edges;
    pedge prev_edge = NULL;

    while (edges_pointer != NULL)
    {
        if (edges_pointer->dest_node->id == id)
        {
            if (prev_edge == NULL)
            {
               node->edges = edges_pointer->next;
            } else {
                prev_edge->next = edges_pointer->next;
            }
            pedge delete_edge = edges_pointer;
            free(delete_edge);
        }
        prev_edge = edges_pointer;
        edges_pointer = edges_pointer->next;
    }
}






