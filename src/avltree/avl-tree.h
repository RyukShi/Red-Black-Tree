/**
 * @file avl-tree.h
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <analytics.h>

typedef struct _Node Node;

// racine de l'arbre
Node *root = NULL;
// nombre de node créé(s)
unsigned int count = 0;

struct _Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

extern Node *get_left(Node *node);
extern Node *get_right(Node *node);
extern int get_key(Node *node);
extern bool set_key(Node *node, const int key);
extern int get_height(Node *node);
extern int get_balance(Node *node);

extern int max(int a, int b);
extern void update_height(Node *node);
extern int random_data(void);

extern Node *new_node(int key);
extern void destroy_node(Node *node);
extern Node *insert_node(Node *node, int key);

extern Node *right_rotate(Node *node);
extern Node *left_rotate(Node *node);

extern void pre_order(Node *root);
extern void post_order(Node *root);
extern void in_order(Node *root);

#endif /* _AVL_TREE_H_ */