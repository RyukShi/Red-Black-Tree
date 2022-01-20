/**
 * @file test-getters-setters.c
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
    int data = 100;
    Node *racine = create_node(&data, sizeof(int));

    assert(get_color(racine) == RED);
    set_color(racine, BLACK);
    assert(get_color(racine) == BLACK);
    assert(*(int *)get_data(racine) == 100);
    int new_data = 50;
    set_data(racine, &new_data, sizeof(int));
    assert(*(int *)get_data(racine) == 50);

    destroy_node(racine);

    return EXIT_SUCCESS;
}
