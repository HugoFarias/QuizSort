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

/*int main(int argc, char **argv){
	file = chargeFile(argv[1]);
	if(!(long)file) return 1; //if null file return error
	printf("%s aberto!\n%d perguntas carregadas\nPara ajuda digite: help\n\n", argv[1], getNLinFl);

	int cnt = 1;
	char *cmd = malloc(sizeof(char)*4);
	while(1){
		printf(">>");
		scanf("%s", cmd);
		printf("\n");

		if (!strcmp(cmd, "exit")){
			break;
		}else{
			if(!strcmp(cmd, "help")){
				printf("Ajuda: help\nGerar pergunta: qst\nSair: exit\n\n");
			}else{
				if (!strcmp(cmd, "qst")){
					char *qst = genQst(file);
					if(!(long)qst){
						printf("FIM DE JOGO!!!\n");
						break;
					}
					else{
						printf("PERGUNTA (%d): %s\n", cnt, qst);
						cnt++;
						free(qst);
					}
				}else{
					continue;
				}
			}
		}
	}

	free(cmd);
	fclose(file);
	return 0;
}
*/