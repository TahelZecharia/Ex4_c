//
// Created by tahel on 06/01/2022.
//

#ifndef EX4_C_GRAPH_H
#define EX4_C_GRAPH_H

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode dest_node;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int id;
    pedge edges;
    int weight;
    int visit;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
int restart_graph(pnode *head);
pnode get_min_node(pnode *head);
void relax(pnode src, pnode dest, pedge edge_pointer);
int shortsPath_cmd(pnode *head, int src, int dest);
void swap(int *num1, int *num2);
void permutation(pnode *head, int arr[], int size, int n);
void TSP_cmd(pnode *head, int path_length);

#endif //EX4_C_GRAPH_H
