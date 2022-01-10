//
// Created by tahel on 07/01/2022.
//

#include "Graph.h"

#ifndef EX4_C_NODE_H
#define EX4_C_NODE_H

pnode node_alloc(int id, pnode *head);
pnode get_node(int id, pnode head);
void delete_all_out_ages(pnode node);
void delete_ages_in(pnode node, int id);


#endif //EX4_C_NODE_H
