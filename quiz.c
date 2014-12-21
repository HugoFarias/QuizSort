#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "quiz.h"

int nLinFl = 0;
short *usedQst;

int getNLinFl(){
	return nLinFl;
}

void increaseNLinFl(){
	nLinFl++;
}

void zero_short(short *array, int size){
	int i;
	for(i = 0; i<size; i++)
		array[i] = 0;
}

int emptyQst(){
	int i;
	for (i = 0; i < getNLinFl(); i++){
		if(usedQst[i]==0) return 0;
	}
	return 1;
}

void countLines(FILE* f){
	char* aux = malloc(sizeof(char)*MAXSZ_QST);
	while(!feof(f)){
		fgets(aux, MAXSZ_QST, f);
		increaseNLinFl();
	}
	free(aux);
}

char* genQst(FILE* fl){
	/*
	**returns one random questions
	**from the file .qz charged
	*/
	if (emptyQst()) return NULL;
	rewind(fl);
	char *ans = malloc(sizeof(char)*MAXSZ_QST);
	srand((unsigned)time(NULL));
	int i, nQst;
	do{
		nQst = rand()%(getNLinFl());
	} while (usedQst[nQst]);
	usedQst[nQst] = 1;
	for (i = 0; i < nQst; i++){
		fgets(ans, MAXSZ_QST, fl);
	}
	fgets(ans, MAXSZ_QST, fl);
	return ans;
}

FILE* chargeFile(char* nameFile){
	/*
	**returns the pointer to file
	**and initializes the global variables
	*/
	FILE* file = fopen(nameFile, "r");
	if(!(long)file) return NULL;
	countLines(file);
	usedQst = malloc(sizeof(short)*getNLinFl());
	zero_short(usedQst, getNLinFl());
	return file;
}
