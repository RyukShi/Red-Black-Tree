/**
 * @file test-swapping-colors.c
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

int main(void)
{
    int a = 0, b = 1;
    Node *node1 = create_node(&a, sizeof(int));
    Node *node2 = create_node(&b, sizeof(int));

    set_color(node1, BLACK);

    swapping_colors(node1, node2);

    assert(get_color(node1) == RED);
    assert(get_color(node2) == BLACK);

    destroy_node(node1);
    destroy_node(node2);

    return EXIT_SUCCESS;
}
