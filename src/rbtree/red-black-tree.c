/**
 * @file red-black-tree.c
 *
 * @author     RyukShi
 * @date       2022
 * @copyright  BSD 3-Clause License
 **/

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "./red-black-tree.h"

/*** Getters and Setters ***/

COLOR get_color(Node *node)
{
    assert(node != NULL);
    if (node)
    {
        return node->color;
    }
    return (COLOR)NULL;
}

bool set_color(Node *node, COLOR color)
{
    assert(node != NULL);
    if (node)
    {
        node->color = color;
        return true;
    }
    return false;
}

void *get_data(Node *node)
{
    assert(node != NULL);
    if (node)
    {
        return node->data;
    }
    return NULL;
}

bool set_data(Node *node, const void *data, size_t data_size)
{
    assert(node != NULL);
    if (node)
    {
        memcpy(node->data, data, data_size);
        return true;
    }
    return false;
}

int random_data(void)
{
    return rand();
}

Node *get_left(Node *node)
{
    assert(node != NULL);
    if (node)
    {
        return node->left;
    }
    return NULL;
}

Node *get_right(Node *node)
{
    assert(node != NULL);
    if (node)
    {
        return node->right;
    }
    return NULL;
}

Node *get_parent(Node *node)
{
    assert(node != NULL);
    if (node)
    {
        return node->parent;
    }
    return NULL;
}

/*** Functions ***/

Node *create_node(const void *data, size_t data_size)
{
    Node *node = (Node *)malloc(sizeof(Node));
    assert(node != NULL);

    if (node == NULL)
    {
        return NULL;
    }

    node->left = node->right = node->parent = NULL;
    set_color(node, RED);

    node->data = malloc(data_size);
    assert(node->data != NULL);

    if (node->data == NULL)
    {
        free(node);
        return NULL;
    }
    memcpy(node->data, data, data_size);
    count++;
    return node;
}

void insert_node(Node *node)
{
    root = binary_search_tree(root, node);
    fix_up(root, node);
}

void destroy_node(Node *node)
{
    if (node != NULL)
    {
        if (node->data != NULL)
        {
            free(node->data);
        }
        free(node);
    }
}

Node *binary_search_tree(Node *root, Node *node)
{
    if (root == NULL)
    {
        return node;
    }

    // cast pour la comparaison
    if (*(int *)get_data(node) < *(int *)get_data(root))
    {
        root->left = binary_search_tree(get_left(root), node);
        root->left->parent = root;
    }
    else if (*(int *)get_data(node) > *(int *)get_data(root))
    {
        root->right = binary_search_tree(get_right(root), node);
        root->right->parent = root;
    }
    return root;
}

void right_rotate(Node *node)
{
    Node *left = get_left(node);
    node->left = get_right(left);

    if (get_left(node))
    {
        node->left->parent = node;
    }
    left->parent = get_parent(node);

    if (!get_parent(node))
    {
        root = left;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = left;
    }
    else
    {
        node->parent->right = left;
    }
    left->right = node;
    node->parent = left;
}

void left_rotate(Node *node)
{
    Node *right = get_right(node);
    node->right = get_left(right);

    if (get_right(node))
    {
        node->right->parent = node;
    }
    right->parent = get_parent(node);

    if (!get_parent(node))
    {
        root = right;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = right;
    }
    else
    {
        node->parent->right = right;
    }
    right->left = node;
    node->parent = right;
}

void fix_up(Node *root, Node *node)
{
    Node *parent_node = NULL;
    Node *grand_parent_node = NULL;

    while ((node != root) && (get_color(node) != BLACK) && (get_color(node->parent) == RED))
    {
        parent_node = get_parent(node);
        grand_parent_node = get_parent(parent_node);

        if (parent_node == get_left(grand_parent_node))
        {
            Node *uncle_node = get_right(grand_parent_node);

            if ((uncle_node != NULL) && (get_color(uncle_node) == RED))
            {
                set_color(grand_parent_node, RED);
                set_color(parent_node, BLACK);
                set_color(uncle_node, BLACK);
                node = grand_parent_node;
            }
            else if (node == get_right(parent_node))
            {
                left_rotate(parent_node);
                node = parent_node;
                parent_node = get_parent(node);
            }
            else
            {
                right_rotate(grand_parent_node);
                swapping_colors(parent_node, grand_parent_node);
                node = parent_node;
            }
        }
        else
        {
            Node *uncle_node = get_left(grand_parent_node);

            if ((uncle_node != NULL) && (get_color(uncle_node) == RED))
            {
                set_color(grand_parent_node, RED);
                set_color(parent_node, BLACK);
                set_color(uncle_node, BLACK);
                node = grand_parent_node;
            }
            else if (node == get_left(parent_node))
            {
                right_rotate(parent_node);
                node = parent_node;
                parent_node = get_parent(node);
            }
            else
            {
                left_rotate(grand_parent_node);
                swapping_colors(parent_node, grand_parent_node);
                node = parent_node;
            }
        }
    }
    set_color(root, BLACK);
}

void swapping_colors(Node *n1, Node *n2)
{
    COLOR save = get_color(n1);
    set_color(n1, get_color(n2));
    set_color(n2, save);
}

void in_order(Node *root, void (*to_string)(Node *))
{
    if (root)
    {
        in_order(get_left(root), to_string);
        to_string(root);
        in_order(get_right(root), to_string);
    }
}

void pre_order(Node *root, void (*to_string)(Node *))
{
    if (root)
    {
        to_string(root);
        pre_order(get_left(root), to_string);
        pre_order(get_right(root), to_string);
    }
}

void post_order(Node *root, void (*to_string)(Node *))
{
    if (root)
    {
        pre_order(get_left(root), to_string);
        pre_order(get_right(root), to_string);
        to_string(root);
    }
}
