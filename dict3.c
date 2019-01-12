/* dict3.c: Assigment 1, Olympic Datasets
 *
 * This program seeks to implement information retrieval using binary
 * search trees. Given a formatted CSV file of Olympic athlete data,
 * this program will read the file, and create a dictionary in the form
 * of a binary search tree, using the athletes' names as the key.
 * The program allows for searching in this dictionary, outputting information
 * on the athlete (if found, or otherwise a not-found message) to a file.
 * On the terminal, the number of comparisons for each search is also shown.
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

#include "dict3.h"
#include "reader3.h"
#include "bst3.h"

/* This file in particular details the main function of dict1. */
int
main(int argc, char *argv[]) {

	char key[FIELD_SIZE+1];
	/* Creates an empty BST, and inserts the data from the CSV file into it. */
	struct bst* bst = NULL;
	bst = csvScanner(argv[1], bst);

	/* Clears the output file of existing content. */
	overwriter(argv[2]);

	/* Creates an infinite loop, awaiting for a key to be searched with,
	and returning information on the key to a specified output file
	and in stdout. */
	while(fgets(key, FIELD_SIZE+1, stdin)){
		/* Takes care of new-line character(s) is taken from the input. */
		if (key[strlen(key) - 1] == '\n'){
			key[strlen(key) - 1] = '\0';
		}
		if (key[strlen(key) - 1] == '\r'){
			key[strlen(key) - 1] = '\0';
		}
		keySearch(key, bst, 0, argv[2], 0);
	}

	/* The tree is freed, once it is no longer of use. */
	freeTree(bst);
	return 0;
}
