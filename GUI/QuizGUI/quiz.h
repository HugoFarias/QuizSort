#ifndef QUIZ_H
#define QUIZ_H

#define MAXSZ_QST 200

typedef struct question{
	char qst[MAXSZ_QST], ans[4][MAXSZ_QST];
	short rightAns;
} Tqst;

int getNLinFl();
int getNQst();
void increaseNLinFl();
void inline zero_short(short *array, int size);
int emptyQst();
void inline countLines();
char* genQst();
char* genAns();
char* rightAns();
char nRightAns();
int chargeFile(char* nameFile);
void finish();

#endif // QUIZ_H
