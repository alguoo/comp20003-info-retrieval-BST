#ifndef BST3H
#define BST3H

#define COL_SIZE 15
#define FIELD_SIZE 128

/* info_t will be the array in which the contents of
each line of the CSV file will be held. */
typedef char info_t[COL_SIZE][FIELD_SIZE+1];

/* data will be a pointer to strings which will be dynamically allocated
   as per the string length, to be space-efficient */
typedef char *data_t[COL_SIZE];

/* This is the struct that will be each node on the BST.
It includes pointers to the left and right children, a name as key for
the dictionary, data. */
struct bst {
    struct bst *left;
    struct bst *right;
	char name[FIELD_SIZE+1];
	data_t data;
};

void infoCopyToData(data_t bstData, info_t csvData);
struct bst *bstInsert(struct bst *parent, info_t data);
void freeTree(struct bst *parent);
void freeData(data_t var);

#endif
