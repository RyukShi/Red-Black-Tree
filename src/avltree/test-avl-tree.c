/**
 * @file test-avl-tree.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "./avl-tree.h"

static void node_to_string(Node *node)
{
    printf("{key = %d}\n", get_key(node));
}

int main(void)
{
    root = insert_node(root, 1);
    root = insert_node(root, 71);
    root = insert_node(root, 8);
    root = insert_node(root, 9);
    root = insert_node(root, 90);
    root = insert_node(root, 7);

    node_to_string(root);

    printf("node(s) créé(s) %d\n", count);

    printf("In order : \n");
    in_order(root);
    printf("Pre order : \n");
    pre_order(root);
    printf("Post order : \n");
    post_order(root);

    return EXIT_SUCCESS;
}
