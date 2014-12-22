#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quiz.h"

int main(int argc, char **argv){
	FILE *file = chargeFile(argv[1]);
	if(!(long)file) return 1; //if null file return error
	printf("%s aberto!\n%d perguntas carregadas\nPara ajuda digite: help\n\n", argv[1], getNQst());

	int cnt = 1;
	char *cmd = (char*) calloc(4,sizeof(char));
	while(1){
		printf(">>");
		scanf("%s", cmd);
		printf("\n");

		if (!strcmp(cmd, "exit")){
			break;
		}else{
			if(!strcmp(cmd, "help")){
				printf("Ajuda: help\nGerar pergunta: qst\nSair: exit\nGerar pergunta e respostas: fqst\nGerar respostas: ans\nResposta certa: rans\n\n");
			}else{
				if (!strcmp(cmd, "qst")){ //question
					char *qst = genQst(file);
					if(!(long)qst){
						printf("FIM DE JOGO!!!\n");
						break;
					}else{
						printf("PERGUNTA (%d): %s\n", cnt, qst);
						cnt++;
					}
				}else{
					if (!strcmp(cmd, "fqst")){ //full question: question + answers
						char *qst = genQst(file);
						if(!(long)qst){
							printf("FIM DE JOGO!!!\n");
							break;
						}else{
							printf("PERGUNTA (%d): %s\n%s\n", cnt, qst, getAns());
							cnt++;
						}
					}else{
						if(cnt == 1) continue; //you cannot ask an answer if you haven't got a question
						if (!strcmp(cmd, "ans")){ //answers
							printf("%s\n", getAns());
						}else{
							if (!strcmp(cmd, "rans")){ //right answer
								printf("RESPOSTA: %c) %s\n", nRightAns(), rightAns());
							}else{
								continue;
							}
						}
					}
				}
			}
		}
	}

	free(cmd);
	fclose(file);
	finish();
	return 0;
}