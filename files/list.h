#ifndef LISTH
#define LISTH

#define COL_SIZE 15
#define FIELD_SIZE 128

/* info_t will be the array in which the contents of
each line of the CSV file will be held. */
typedef char info_t[COL_SIZE][FIELD_SIZE+1];

/* data will be a pointer to strings which will be dynamically allocated
   as per the string length, to be space-efficient */
typedef char *data_t[COL_SIZE];

/* This defines the node of a linked list, which holds key name, data, and
 points to the next element of the list. */
typedef struct node node_t;
struct node {
	char name[FIELD_SIZE+1];
	data_t data;
	node_t* next;
};

void infoCopyToData(data_t bstData, info_t csvData);
node_t* insertNode(node_t* head, info_t fileData);
void freeList(node_t* head);
void freeData(data_t var);

#endif
