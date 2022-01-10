//
// Created by tahel on 06/01/2022.
//

#include <stdio.h>
#include "Graph.h"


char input;

int main() {

    pnode start = NULL;
    pnode *head = &start;
    int src;
    int dest;
    int shortest_path;


    while (1) {

        scanf("%c", &input);

        if (input == 'A')
        {
            build_graph_cmd(head);
        }
        if (input == 'B')
        {
            insert_node_cmd(head);
        }
        if (input == 'D')
        {
            delete_node_cmd(head);
        }
        if(input == 'S')
        {
            scanf("%d", &src);
            scanf("%d", &dest);
            shortest_path =  shortsPath_cmd(head, src, dest);
            printf("Dijsktra shortest path: %d \n", shortest_path);
        }

        if(input == 'T') {
            scanf("%d", &input);
            TSP_cmd(head, input);
        }

        if(input == '\n') {
            deleteGraph_cmd(head);
            break;
        }
    }
    return 0;
}