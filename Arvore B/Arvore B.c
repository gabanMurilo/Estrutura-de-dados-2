#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 4

struct b_node
{
    int num_keys;
    int keys[MAX_KEYS];
    struct b_node *children[MAX_KEYS + 1];
    bool is_leaf;
};

struct b_node *create_node(bool is_leaf)
{
    struct b_node *new_node = (struct b_node *)malloc(sizeof(struct b_node));
    new_node->num_keys = 0;
    new_node->is_leaf = is_leaf;
    for (int i = 0; i < MAX_KEYS; i++)
    {
        new_node->keys[i] = 0;
        new_node->children[i] = NULL;
    }
    new_node->children[MAX_KEYS] = NULL;
    return new_node;
}

int binary_search(int *arr, int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

void split_child(struct b_node *parent, int i, struct b_node *child)
{
    struct b_node *new_child = create_node(child->is_leaf);
    for (int j = 0; j < MAX_KEYS / 2; j++)
    {
        new_child->keys[j] = child->keys[j + MAX_KEYS / 2];
    }
    if (!child->is_leaf)
    {
        for (int j = 0; j <= MAX_KEYS / 2; j++)
        {
            new_child->children[j] = child->children[j + MAX_KEYS / 2];
        }
    }
    child->num_keys = MAX_KEYS / 2;
    for (int j = parent->num_keys; j > i; j--)
    {
        parent->children[j + 1] = parent->children[j];
        parent->keys[j] = parent->keys[j - 1];
    }
    parent->children[i + 1] = new_child;
    parent->keys[i] = child->keys[MAX_KEYS / 2 - 1];
    parent->num_keys++;
}

void insert_non_full(struct b_node *node, int key)
{
    int i = node->num_keys - 1;
    if (node->is_leaf)
    {
        while (i >= 0 && node->keys[i] > key)
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
    }
    else
    {
        while (i >= 0 && node->keys[i] > key)
        {
            i--;
        }
        if (node->children[i + 1]->num_keys == MAX_KEYS)
        {
            split_child(node, i + 1, node->children[i + 1]);
            if (node->keys[i + 1] < key)
            {
                i++;
            }
        }
        insert_non_full(node->children[i + 1], key);
    }
}

void insert(struct b_node **root, int key)
{
    if (*root == NULL)
    {
        *root = create_node(true);
        (*root)->keys[0] = key;
        (*root)->num_keys++;
    }
    else
    {
        if ((*root)->num_keys == MAX_KEYS)
        {
            struct b_node *new_root = create_node(false);
            new_root->children[0] = *root;
            split_child(new_root, 0, *root);
            int i = binary_search(new_root->keys, new_root->num_keys, key);
            insert_non_full(new_root->children[i + 1], key);
            *root = new_root;
        }
        else
        {
            insert_non_full(*root, key);
        }
    }
}

void traverse(struct b_node *root)
{
    int i;
    for (i = 0; i < root->num_keys; i++)
    {
        if (!root->is_leaf)
        {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }
    if (!root->is_leaf)
    {
        traverse(root->children[i]);
    }
}

int main()
{
    struct b_node *root = NULL;
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 5);
    insert(&root, 7);
    insert(&root, 9);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 10);

    traverse(root);

    return 0;
}