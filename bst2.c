/* bst2.c: to be linked to reader2.c and dict2.c
 * Defines a modified binary search tree, which is to be used as a dictionary
 * of athletes' data, with multiple data added to a linked list, rather
 * than in the tree.
 * Describes functions which facilitate the use of the tree, such as
 * inserting data and freeing the tree.
 *
 * Code written in August 2018, for COMP20003
 * by Alan Guo, student ID: 831747, student code: guoa1
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bst2.h"
#include "list.h"

/* Inserts a new node into a (potentially empty) BST, copying
   an info_t variable into the 'data' and 'name' components.
   Returns the root of the tree (the first entry). */
struct bst *bstInsert(struct bst *parent, info_t fileData) {
	/* If reached the end of a tree,
	 allocates memory for a new	node, and copies the data. */
	if (parent == NULL) {
    	struct bst *leaf = (struct bst *)malloc(sizeof(struct bst));
		assert(leaf);
    	leaf->left = NULL;
    	leaf->right = NULL;
    	infoCopyToData(leaf->data, fileData);
		strcpy(leaf->name, fileData[1]);
		leaf->head = NULL;
    	return leaf;
	}

	int outcome = strcmp(parent->name, fileData[1]);
    if (outcome < 0) {
		parent->right = bstInsert(parent->right, fileData);
    } else if (outcome > 0) {
    	parent->left = bstInsert(parent->left, fileData);
	}
	/* When adding data of an existing athlete of the dictionary,
	   the data is added to a linked list for the athlete. */
	else {
		parent->head = insertNode(parent->head, fileData);
	}
	return parent;
}

/* Frees a BST recursively, from the leaves first. */
void freeTree(struct bst *parent) {
    if(! parent) {
        return;
    }
	freeTree(parent->left);
	freeTree(parent->right);
	/* Supposed a linked list exists for an athlete, then it is
	   freed first. */
	if (parent->head != NULL) {
		freeList(parent->head);
	}
	freeData(parent->data);
	free(parent);
}
