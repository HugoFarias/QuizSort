#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXSZ_QST 200

int nLinFl = 0;

void countLines(FILE* f){
	char* aux = malloc(sizeof(char)*MAXSZ_QST);
	while(!feof(f)){
		fgets(aux, MAXSZ_QST, f);
		nLinFl++;
	}
	free(aux);
}

char* genQst(FILE* fl){
	rewind(fl);
	char *ans = malloc(sizeof(char)*MAXSZ_QST);
	srand((unsigned)time(NULL));
	int i, nQst = rand()%(nLinFl/*-1*/);
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
				printf("Ajuda: help\nGerar pergunta: ans\nSair: exit\n\n");
			}else{
				if (!strcmp(cmd, "ans")){
					char *qst = genQst(file);
					printf("PERGUNTA (%d): %s\n\n", cnt, qst);
					free(qst);
					cnt++;
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