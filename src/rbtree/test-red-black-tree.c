/**
 * @file test-red-black-tree.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include "./red-black-tree.h"

static void node_to_string(Node *node)
{
    printf("{data = %d, color = %d}\n", *(int *)get_data(node), get_color(node));
}

int main(int argc, char const *argv[])
{
    int data = 0;
    Node *racine = create_node(&data, sizeof(int));
    set_color(racine, BLACK);
    printf("0 = BLACK / 1 = RED\n");
    node_to_string(racine);
    destroy_node(racine);

    const int i = 2, j = 37, k = 42, l = 33, m = random_data(), n = 1473767997, o = -1, p = random_data();

    Node *n1 = create_node(&i, sizeof(i));
    Node *n2 = create_node(&j, sizeof(j));
    Node *n3 = create_node(&k, sizeof(k));
    Node *n4 = create_node(&l, sizeof(l));
    Node *n5 = create_node(&m, sizeof(m));
    Node *n6 = create_node(&n, sizeof(n));
    Node *n7 = create_node(&o, sizeof(o));
    Node *n8 = create_node(&p, sizeof(p));

    insert_node(n1);
    insert_node(n2);
    insert_node(n7);
    insert_node(n6);
    insert_node(n3);
    insert_node(n4);
    insert_node(n8);
    insert_node(n5);

    printf("nombre de node(s) : %d\n", count);

    printf("In order : \n");
    in_order(root, node_to_string);

    printf("Pre order : \n");
    pre_order(root, node_to_string);

    printf("Post order : \n");
    post_order(root, node_to_string);

    destroy_node(n1);
    destroy_node(n2);
    destroy_node(n3);
    destroy_node(n4);
    destroy_node(n5);
    destroy_node(n6);
    destroy_node(n7);
    destroy_node(n8);

    return EXIT_SUCCESS;
}
