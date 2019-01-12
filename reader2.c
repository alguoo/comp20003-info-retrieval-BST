/* reader2.c:
 * Functions for reading to and writing from the BST dictionary described
 * in bst2.c. These include reading from CSV files, searching the tree,
 * outputting search results.
 *
 *
 * Code written in August 2018, for COMP20003
 * by Alan Guo, student ID: 831747, student code: guoa1
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "reader2.h"
#include "bst2.h"
#include "list.h"

/* Reads from a CSV file, and inserts each line of file as a node
   into the dictionary BST defined in bst.c.
   Returns the root of the tree (the first entry of the dictionary).*/
struct bst* csvScanner(char *fileName, struct bst *head) {
	info_t info;
	char line[INPUT_MAX_LEN+1];
	char *token;
	int i = 0;

	FILE * pFile;
	pFile = fopen(fileName, "r");

	/* Reads each line of the file, separates the data by the
	   SEPARATOR delimiter */
	while( fgets(line, INPUT_MAX_LEN+1, pFile)!=NULL ) {
		i = 0;
		/* Removes the newline character */
		token = strtok(line, "\n");
		token = strtok(line, SEPARATOR);

		/* Copies the data into the info_t variable, and finally inserts it
		   into the BST as a new node. */
		while(token!=NULL) {
			strcpy(info[i], token);
			i+=1;
			token = strtok(NULL, SEPARATOR);
		}
		head = bstInsert(head, info);
	}
	fclose(pFile);
	return head;
}

/* Serves to clear the file of existing contents. */
void overwriter(char *outputFile) {
	FILE* pFile;
	pFile = fopen(outputFile, "w");
	fclose(pFile);
}

/* Appends a file with a string of one's choosing. */
void outputPrinter(char *outputFile, char *outputString) {
	FILE* pFile;
	pFile = fopen(outputFile, "a");
	fprintf(pFile, outputString);
	fclose(pFile);
}

/* Appends a file with an athlete's data recorded in the BST, according
   to the format required. */
void outputPrinterAthlete(char *outputFile, data_t data) {
	FILE* pFile;
	pFile = fopen(outputFile, "a");

	fprintf(pFile,
	"%s --> ID: %s Sex: %s || Age: %s || Height: %s || Weight: %s || Team: %s || NOC: %s || Games: %s || Year: %s || Season: %s || City: %s || Sport: %s || Event: %s || Medal: %s ||\n",
	data[1],
	data[0],
	data[2],
	data[3],
	data[4],
	data[5],
	data[6],
	data[7],
	data[8],
	data[9],
	data[10],
	data[11],
	data[12],
	data[13],
	data[14]);

	fclose(pFile);

}

/* Traverses through the list to print athlete data. */
void outputListPrinter(char *outputFile, node_t* head) {
	if(head != NULL) {
		while(head->next != NULL) {
			outputPrinterAthlete(outputFile, head->data);
			head = head->next;
		}
		outputPrinterAthlete(outputFile, head->data);
	}
}

/* Searches a BST dictionary to match the key string provided.
   If found, the output file is appended with the data of the matched node.
   If not, the outputfile is appended with a message.
   In both cases, the number of comparisons taken will be printed (to stout) */
void keySearch(char *name, struct bst* parent,
	char *outputFile, int counter) {

	/* Once reached end of tree in the search, print the number
	   of comparisons. If not found, append the outputfile as required.*/
	if (!parent) {
		printf("%s --> %d\n", name, counter);
		outputPrinter(outputFile, NOTFOUND_MESSAGE);
		return;
	}

	/* Otherwise, compare key with node name, to continue the binary
	   search, and update the count of comparisons. */
	int outcome = strcmp(name, parent->name);
	counter += 1;
	if (outcome > 0) {
		return keySearch(name, parent->right, outputFile, counter);
	} else if (outcome < 0) {
		return keySearch(name, parent->left, outputFile, counter);
	} else {
		/* Search ends when match is found. */
		outputPrinterAthlete(outputFile, parent->data);
		outputListPrinter(outputFile, parent->head);
		printf("%s --> %d\n", name, counter);
	}
}
