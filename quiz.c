#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "quiz.h"

int nLinFl = 0;
short *usedQst;
Tqst *currQst;

int getNLinFl(){
	return nLinFl;
}

int getNQst(){
	return nLinFl/5;
}

void increaseNLinFl(){
	nLinFl++;
}

void inline zero_short(short *array, int size){ //the compiler copy this code and put in the function call
	int i;
	for(i = 0; i<size; i++)
		array[i] = 0;
}

int emptyQst(){
	int i;
	for (i = 0; i < getNQst(); i++){
		if(usedQst[i]==0) return 0;
	}
	return 1;
}

void inline countLines(FILE* f){
	char* aux = (char*) calloc(MAXSZ_QST,sizeof(char));
	while(!feof(f)){
		fgets(aux, MAXSZ_QST, f);
		increaseNLinFl();
	}
	free(aux);
}

short* getOrder(int size){
	/*
	**returns an array wich elements are only and in [0,size)
	*/
	srand((unsigned)time(NULL));
	int i;
	short *order = (short*) calloc(size,sizeof(short));
	for (i = 0; i < size; i++)
		order[i] = -1;
	i = 0;
	while (i < size){
		short aux = rand()%size;
		int j, notChoosed = 1;
		for (j = 0; j < i; j++){
			if (order[j] == aux){
				notChoosed = 0;
			}
		}
		if(notChoosed){
			order[i] = aux;
			i++;
		}
	}
	return order;
}

char* genQst(FILE* fl){
	/*
	**generate one random question
	**from the file .qz charged
	**returns the interrogative part
	*/
	if (emptyQst()) return NULL;
	rewind(fl);
	srand((unsigned)time(NULL));
	int i, nQst;
	do{
		nQst = rand()%(getNQst());
	} while (usedQst[nQst]);
	usedQst[nQst] = 1;

	short *order = getOrder(4);
	for (i = 0; i <= nQst; i++){
		fgets(currQst->qst, MAXSZ_QST, fl);
		fgets(currQst->ans[order[0]], MAXSZ_QST, fl);
		fgets(currQst->ans[order[1]], MAXSZ_QST, fl);
		fgets(currQst->ans[order[2]], MAXSZ_QST, fl);
		fgets(currQst->ans[order[3]], MAXSZ_QST, fl);
	}
	currQst->rightAns = order[0];
	free(order);
	return currQst->qst;
}

char* getAns(){
	/*
	**returns the current anwers
	*/
	char *ans = calloc(MAXSZ_QST*4+11,sizeof(char)); //4 answer plus the other chars in ans
	sprintf(ans, "a) %sb) %sc) %sd) %s", currQst->ans[0], currQst->ans[1], currQst->ans[2], currQst->ans[3]);
	return ans;
}

char* rightAns(){
	return currQst->ans[currQst->rightAns];
}

char nRightAns(){
	return (char) (currQst->rightAns + 97); // (char)97 == a
}

FILE* chargeFile(char* nameFile){
	/*
	**returns the pointer to file
	**and initializes the global variables
	*/
	FILE* file = fopen(nameFile, "r");
	if(!(long)file) return NULL;
	countLines(file);
	usedQst = (short*) calloc(getNQst(),sizeof(short));
	zero_short(usedQst, getNQst());
	currQst = (Tqst*) malloc(sizeof(Tqst));
	return file;
}

void finish(){
	free(usedQst);
	free(currQst);
}