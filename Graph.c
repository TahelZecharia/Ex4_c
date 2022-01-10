//
// Created by tahel on 06/01/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#define INFI 1000000
static int min_path = INFI;

//A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 B 5 0 4 2 1 B 2 1 3 5 1


void build_graph_cmd(pnode *head)
{
    if (*head != NULL)
    {
        deleteGraph_cmd(head);
    }

    int size = 0;
    scanf("%d", &size);
    char input;

    for (int i = 0; i < size; i++)
    {
        scanf("%c", &input);
        scanf("%c", &input);
        insert_node_cmd(head);
    }
}

void insert_node_cmd(pnode *head)
{
    //insert the node:
    int node_id = -1;
    scanf("%d", &node_id);
    pnode src_node = get_node(node_id, *head);
    if (src_node == NULL) {
        src_node = node_alloc(node_id, head);
    } else {
        delete_all_out_ages(src_node);
    }

    //insert the node's out edges:
    int dest_node_id = -1;
    int edge_weight = -1;
    while (scanf("%d", &dest_node_id) == 1)
        {
        if (scanf("%d", &edge_weight) == 1)
            {
                pnode dest_node = get_node(dest_node_id, *head);
                if (dest_node == NULL) {
                    dest_node = node_alloc(dest_node_id, head);
                }
                edge_alloc(edge_weight, src_node, dest_node);
            }
        }

}

void delete_node_cmd(pnode *head)
{
    int id = -1;
    scanf("%d", &id);
    pnode node_to_remove = get_node(id, *head);

    pnode node = *head;
    pnode prev_node = NULL;
    while (node != NULL)
    {
        if (node->id == id)
        {
            if (prev_node == NULL) {
                *head = node->next;
            }
            else {
                prev_node->next = node->next;
            }
        }
        else {
            delete_ages_in(node, id);
        }
        prev_node = node;
        node = node->next;
    }
    delete_all_out_ages(node_to_remove);
    free(node_to_remove);
}

void printGraph_cmd(pnode head) //for self debug
{
    printf("{ HEAD -> ");
    while (head != NULL)
    {
        printf("[id: %d, ", head->id);
        pedge edge_pointer = head->edges;
        printf("edges: ");
        while (edge_pointer != NULL)
        {
            printf("(dest: %d, weight: %d) -> ", edge_pointer->dest_node->id, edge_pointer->weight);
            edge_pointer = edge_pointer->next;
        }
        printf("(NULL)] -> ");
        head = head->next;
    }
    printf("[NULL] }\n");
}

void deleteGraph_cmd(pnode* head)
{
    pnode node_pointer = *head;

    while(node_pointer != NULL)
    {
        delete_all_out_ages(node_pointer);
        pnode node_to_delete = node_pointer;
        node_pointer = node_pointer->next;
        free(node_to_delete);
    }
}

//The function resets all the vertices of the graph
// and returns the number of vertices in the graph
int restart_graph(pnode *head)
{
    pnode temp_node = *head;
    int num_of_nodes = 0;
    while (temp_node != NULL){
        temp_node->weight = INFI;
        temp_node->visit = 0;
        temp_node = temp_node->next;
        num_of_nodes++;
    }
    return num_of_nodes;
}

pnode get_min_node(pnode *head)
{
    pnode temp_node = *head;
    pnode min_node = NULL;
    int max = INFI;
    while (temp_node != NULL)
    {
        if(temp_node->weight < max)
        {
            if(temp_node->visit == 0){
                max = temp_node->weight;
                min_node = temp_node;
            }
        }
        temp_node=temp_node->next;
    }
    return min_node;
}

void relax(pnode src, pnode dest, pedge edge_pointer)
{
    int edge_weight = edge_pointer->weight;
    int src_weight = src->weight;
    int dest_weight = dest->weight;
    if(dest_weight > src_weight + edge_weight){
        dest->weight = edge_weight + src_weight;
    }
}

int shortsPath_cmd(pnode *head, int src, int dest)
{
    pnode temp_node = get_node(src, *head);
    int num_of_nodes = restart_graph(head);
    temp_node->weight = 0;  //???
    while(num_of_nodes > 0){
        temp_node = get_min_node(head);
        if(temp_node->id == dest){
            return temp_node->weight;
        }
        temp_node->visit = 1;
        pedge temp_edge = temp_node->edges;
        while (temp_edge != NULL){
            relax(temp_node, temp_edge->dest_node, temp_edge);
            temp_edge = temp_edge->next;
        }
        num_of_nodes = num_of_nodes-1;
    }
    return 0;
}

void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


void permutation(pnode *head, int arr[], int size, int n)
{
    if (size == 1){
        int sum = 0;
        for (int j = 0; j < n-1; ++j)
        {
            sum += shortsPath_cmd(head, arr[j], arr[j + 1]);
        }
        if (sum < min_path)
        {
            min_path = sum;
            return;
        }
    }

    for (int i = 0; i < size; i++)
    {
        permutation(head, arr, (size - 1), n);
        if (size % 2 == 1)
            swap(&arr[0], &arr[size - 1]);
        else
            swap(&arr[i], &arr[size - 1]);
    }
}

void TSP_cmd(pnode *head, int path_length)
{
    min_path = INFI;
    int path[path_length];
    int node_id = -1;

    for (int i = 0; i < path_length; i++)
    {
        scanf("%d", &node_id);
        path[i] = node_id;
    }
    permutation(head, path, path_length, path_length);
    if(min_path == INFI)
    {
        min_path = -1;
    }
    printf("TSP shortest path: %d \n", min_path);
}


