#ifndef READER2H
#define READER2H

#define INPUT_MAX_LEN 512
#define SEPARATOR ","
#define NOTFOUND_MESSAGE "NOTFOUND\n"

#include "bst2.h"
#include "list.h"

struct bst* csvScanner(char *fileName, struct bst *head);

void overwriter(char *outputFile);
void outputPrinter(char *outputFile, char *outputString);
void outputPrinterAthlete(char *outputFile, data_t data);
void outputListPrinter(char *outputFile, node_t* head);

void keySearch(char *name, struct bst* parent, char *outputFile, int counter);


#endif
