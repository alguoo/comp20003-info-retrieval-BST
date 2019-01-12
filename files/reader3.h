#ifndef READER3H
#define READER3H

#define INPUT_MAX_LEN 512
#define SEPARATOR ","
#define NOTFOUND_MESSAGE "NOTFOUND\n"

#include "bst3.h"

struct bst* csvScanner(char *fileName, struct bst *head);

void overwriter(char *outputFile);
void outputPrinter(char *outputFile, char *outputString);
void outputPrinterAthlete(char *outputFile, data_t data);

void keySearch(char *name, struct bst* parent, int found, char *outputFile, int counter);


#endif
