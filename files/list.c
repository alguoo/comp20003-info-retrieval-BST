/* list.c:
 * Defines a linked list, which is to be used as a structure to store
 * multiple data for the same athlete,
 * and  describes functions which facilitate the use of the linked list,
 * such as inserting data into the list and freeing the list.
 *
 * Code written in August 2018, for COMP20003
 * by Alan Guo, student ID: 831747, student code: guoa1
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "list.h"

void infoCopyToData(data_t bstData, info_t csvData) {
	int i;
	for (i=0; i<COL_SIZE; i++) {
		bstData[i] = (char *)malloc(sizeof(char)*(strlen(csvData[i])+1));
		strcpy(bstData[i], csvData[i]);
	}
}

/* Inserts copied data from a info_t variable, as a node_t, into the linked
   list at the start of the list. */
node_t* insertNode(node_t* head, info_t fileData) {
	node_t* new = (node_t*)malloc(sizeof(node_t));
	assert(new);
	infoCopyToData(new->data, fileData);
	strcpy(new->name, fileData[1]);
	new->next = head;
	return new;
}

/* Given the start of the list, this function frees the list and data
   as it traverses through it. */
void freeList(node_t* head){
	node_t *temp, *previous;
	assert(head != NULL);
	temp = head;
	while (temp != NULL) {
		previous = temp;
		temp = temp->next;
		freeData(previous->data);
		free(previous);
	}
}

/* Frees a data_t variable */
void freeData(data_t var) {
	int i;
	for(i=0; i<COL_SIZE; i++) {
		free(var[i]);
	}
}
