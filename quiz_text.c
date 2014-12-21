#include "quiz.h"

int main(int argc, char **argv){
	FILE *file = chargeFile(argv[1]);
	if(!(long)file) return 1; //if null file return error
	printf("%s aberto!\n%d perguntas carregadas\nPara ajuda digite: help\n\n", argv[1], getNLinFl());

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