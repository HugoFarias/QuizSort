#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXSZ_QST 200

/*int nLinFl = 0;
short *usedQst;*/

int getNLinFl();
void increaseNLinFl();
void zero_short(short *array, int size);
int emptyQst();
void countLines(FILE* f);
char* genQst(FILE* fl);
FILE* chargeFile(char* nameFile);