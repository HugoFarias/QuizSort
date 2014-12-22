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
void inline countLines(FILE* f);
char* genQst(FILE* fl);
char* getAns();
char* rightAns();
FILE* chargeFile(char* nameFile);
void finish();