#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXSZ_QST 200

int nLinFl = 0;
short *usedQst;

void zero_short(short *array, int size){
	int i;
	for(i = 0; i<size; i++)
		array[i] = 0;
}

int emptyQst(){
	int i;
	for (i = 0; i < nLinFl; i++){
		if(usedQst[i]==0) return 0;
	}
	return 1;
}

void countLines(FILE* f){
	char* aux = malloc(sizeof(char)*MAXSZ_QST);
	while(!feof(f)){
		fgets(aux, MAXSZ_QST, f);
		nLinFl++;
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
		nQst = rand()%(nLinFl);
	} while (usedQst[nQst]);
	usedQst[nQst] = 1;
	for (i = 0; i < nQst; i++){
		fgets(ans, MAXSZ_QST, fl);
	}
	fgets(ans, MAXSZ_QST, fl);
	return ans;
}

int main(int argc, char **argv){
	FILE* file = fopen(argv[1], "r");
	if(!(long)file) return 1;
	countLines(file);
	usedQst = malloc(sizeof(short)*nLinFl);
	zero_short(usedQst, nLinFl);
	printf("%s%s\n\n", argv[1], " aberto!\nPara ajuda digite: help");

	int cnt = 1;
	char *cmd = malloc(sizeof(char)*4);
	while(1){
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
						printf("PERGUNTA (%d): %s\n\n", cnt, qst);
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