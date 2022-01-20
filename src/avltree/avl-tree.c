/**
 * @file avl-tree.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "./avl-tree.h"

/*** Getters and Setters ***/

int get_height(Node *node)
{
    if (node)
    {
        return node->height;
    }
    return 0;
}

Node *get_left(Node *node)
{
    if (node)
    {
        return node->left;
    }
    return NULL;
}

Node *get_right(Node *node)
{
    if (node)
    {
        return node->right;
    }
    return NULL;
}

int get_key(Node *node)
{
    if (node)
    {
        return node->key;
    }
    return EXIT_FAILURE;
}

bool set_key(Node *node, const int key)
{
    if (node)
    {
        node->key = key;
        return true;
    }
    return false;
}

int get_balance(Node *node)
{
    if (node)
    {
        return get_height(node->left) - get_height(node->right);
    }
    return 0;
}

/*** Functions ***/

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int random_data(void)
{
    return rand();
}

Node *new_node(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        printf("Malloc a échoué !\n");
        return NULL;
    }

    count++;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void destroy_node(Node *node)
{
    assert(node != NULL);
    if (node)
    {
        free(node);
    }
}

void update_height(Node *node)
{
    if (node)
    {
        node->height = max(get_height(node->left), get_height(node->right)) + 1;
    }
}

Node *right_rotate(Node *node)
{
    Node *left = get_left(node);
    Node *n = left->right;

    left->right = node;
    node->left = n;

    update_height(node);
    update_height(left);

    return left;
}

Node *left_rotate(Node *node)
{
    Node *right = get_right(node);
    Node *n = right->left;

    right->left = node;
    node->right = n;

    update_height(node);
    update_height(right);

    return right;
}

Node *insert_node(Node *node, int key)
{
    if (node == NULL)
    {
        return new_node(key);
    }

    if (key < get_key(node))
    {
        node->left = insert_node(get_left(node), key);
    }
    else if (key > get_key(node))
    {
        node->right = insert_node(get_right(node), key);
    }
    else
    {
        return node;
    }

    // mise à jour de la hauteur
    update_height(node);

    int balance = get_balance(node);

    if (balance > 1 && key < node->left->key)
    {
        return right_rotate(node);
    }
    if (balance < -1 && key > node->right->key)
    {
        return left_rotate(node);
    }
    if (balance > 1 && key > node->left->key)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

void pre_order(Node *root)
{
    if (root != NULL)
    {
        printf("{key = %d}\n", root->key);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(Node *root)
{
    if (root != NULL)
    {
        pre_order(root->left);
        printf("{key = %d}\n", root->key);
        pre_order(root->right);
    }
}

void post_order(Node *root)
{
    if (root != NULL)
    {
        pre_order(root->left);
        pre_order(root->right);
        printf("{key = %d}\n", root->key);
    }
}
