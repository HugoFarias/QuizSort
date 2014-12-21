#define MAXSZ_QST 200

typedef struct question{
	char qst[MAXSZ_QST], rightAns[MAXSZ_QST], wrongAns[MAXSZ_QST][3];
} Tqst;

int getNLinFl();
int getNQst();
void increaseNLinFl();
void zero_short(short *array, int size);
int emptyQst();
void countLines(FILE* f);
Tqst* genQst(FILE* fl);
FILE* chargeFile(char* nameFile);