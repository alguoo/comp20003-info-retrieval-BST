/* bst3.c:
 * Defines a binary search tree, which is to be used as a dictionary
 * of athletes' data,
 * and  describes functions which facilitate the use of the tree, such as
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

#include "bst3.h"

/* Copies strings from info_t variable to data_t variable,
   which dynamically allocates memory. */
void infoCopyToData(data_t bstData, info_t csvData) {
	int i;
	for (i=0; i<COL_SIZE; i++) {
		bstData[i] = (char *)malloc(sizeof(char)*(strlen(csvData[i])+1));
		strcpy(bstData[i], csvData[i]);
	}
}

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
    	return leaf;
	}
	/* Note that when there is a duplicate, the node is placed on the left. */
    if (strcmp(parent->name, fileData[1]) < 0) {
		parent->right = bstInsert(parent->right, fileData);
    } else {
    	parent->left = bstInsert(parent->left, fileData);
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
	freeData(parent->data);
	free(parent);
}

/* Frees a data_t variable */
void freeData(data_t var) {
	int i;
	for(i=0; i<COL_SIZE; i++) {
		free(var[i]);
	}
}
