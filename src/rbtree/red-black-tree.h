/**
 * @file red-black-tree.h
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <analytics.h>

typedef struct _Node Node;

// racine de l'arbre
Node *root = NULL;

// nombre de node créé(s)
unsigned int count = 0;

typedef enum
{
    BLACK,
    RED
} COLOR;

struct _Node
{
    void *data;
    Node *left;
    Node *right;
    Node *parent;
    COLOR color;
};

/*** Getters and Setters ***/

extern COLOR get_color(Node *node);
extern bool set_color(Node *node, COLOR color);

extern void *get_data(Node *node);
extern bool set_data(Node *node, const void *data, size_t data_size);
extern int random_data(void);

extern Node *get_left(Node *node);
extern Node *get_right(Node *node);
extern Node *get_parent(Node *node);

/*** Functions ***/

extern Node *create_node(const void *data, size_t data_size);
extern void destroy_node(Node *node);
extern void insert_node(Node *node);

extern Node *binary_search_tree(Node *root, Node *node);

extern void right_rotate(Node *node);
extern void left_rotate(Node *node);

extern void fix_up(Node *root, Node *node);

extern void swapping_colors(Node *n1, Node *n2);

extern void in_order(Node *root, void (*to_string)(Node *));
extern void pre_order(Node *root, void (*to_string)(Node *));
extern void post_order(Node *root, void (*to_string)(Node *));

#endif /* _RED_BLACK_TREE_H_ */
