/**
 * @file test-getters-setters.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "avl-tree.h"

int main(void)
{
    Node *root = new_node(0);

    assert(get_key(root) == 0);
    set_key(root, 1);
    assert(get_key(root) == 1);

    assert(get_height(root) == 1);

    destroy_node(root);

    return EXIT_SUCCESS;
}
