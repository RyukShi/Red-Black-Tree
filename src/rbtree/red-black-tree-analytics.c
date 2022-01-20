/**
 * @file red-black-tree-analytics.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#include "./red-black-tree.h"

int main(int argc, char const *argv[])
{
    FILE *fptr = a_begin("rb-analytics");

    for (size_t c = 0; c < 100; c++) // boucle 100 fois sur la création et l'insertion de 10 nodes
    {
        clock_t t1;

        t1 = a_start_register();

        const int i = random_data(), j = random_data(), k = random_data(), l = random_data(),
                  m = random_data(), n = random_data(), o = random_data(), p = random_data(),
                  q = random_data(), r = random_data();

        Node *n1 = create_node(&i, sizeof(i));
        Node *n2 = create_node(&j, sizeof(j));
        Node *n3 = create_node(&k, sizeof(k));
        Node *n4 = create_node(&l, sizeof(l));
        Node *n5 = create_node(&m, sizeof(m));
        Node *n6 = create_node(&n, sizeof(n));
        Node *n7 = create_node(&o, sizeof(o));
        Node *n8 = create_node(&p, sizeof(p));
        Node *n9 = create_node(&q, sizeof(q));
        Node *n10 = create_node(&r, sizeof(r));

        insert_node(n1);
        insert_node(n2);
        insert_node(n3);
        insert_node(n4);
        insert_node(n5);
        insert_node(n6);
        insert_node(n7);
        insert_node(n8);
        insert_node(n9);
        insert_node(n10);

        a_end_register(fptr, t1);

        destroy_node(n1);
        destroy_node(n2);
        destroy_node(n3);
        destroy_node(n4);
        destroy_node(n5);
        destroy_node(n6);
        destroy_node(n7);
        destroy_node(n8);
        destroy_node(n9);
        destroy_node(n10);

        root = NULL;
    }

    printf("node(s) créé(s) %d\n", count);

    a_stop(fptr); // close file

    return EXIT_SUCCESS;
}
