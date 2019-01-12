#ifndef BST2H
#define BST2H

#include "list.h"

/* This is the struct that will be each node on the BST.
It includes pointers to the left and right children, a name as key for
the dictionary, data, and a pointer to linked list of data with
duplicate name. */
struct bst {
    struct bst *left;
    struct bst *right;
	char name[FIELD_SIZE+1];
	data_t data;
	node_t *head;
};

struct bst *bstInsert(struct bst *parent, info_t data);
void freeTree(struct bst *parent);

#endif
