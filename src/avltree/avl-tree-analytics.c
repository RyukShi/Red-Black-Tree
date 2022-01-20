/**
 * @file avl-tree-analytics.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#include "avl-tree.h"

int main(int argc, char const *argv[])
{
    FILE *fptr = a_begin("avl-analytics");

    for (size_t i = 0; i < 100; i++) // boucle 100 fois sur la création et l'insertion de 10 nodes
    {
        clock_t t1;

        t1 = a_start_register();

        for (size_t i = 0; i < 10; i++)
        {
            root = insert_node(root, random_data());
        }

        a_end_register(fptr, t1);

        root = NULL;
    }

    printf("node(s) créé(s) %d\n", count);

    a_stop(fptr); // close file

    return EXIT_SUCCESS;
}
