#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quiz.h"

int main(int argc, char **argv){
	int charged = chargeFile(argv[1]);
	if(charged) return 1; //if error in chargeFile()
	printf("Arquivo <%s> aberto!\n%d perguntas carregadas\nPara ajuda digite: help\n\n", argv[1], getNQst());

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
				printf("Ajuda: help\nGerar pergunta: qst\nGerar pergunta e respostas: fqst\nMostrar respostas: ans\nResposta certa: rans\nSair: exit\n\n");
			}else{
				if (!strcmp(cmd, "qst")){ //question
					char *qst = genQst();
					if(!(long)qst){
						printf("FIM DE JOGO!!!\n");
						break;
					}else{
						printf("PERGUNTA (%d): %s\n", cnt, qst);
						cnt++;
					}
				}else{
					if (!strcmp(cmd, "fqst")){ //full question: question + answers
						char *qst = genQst();
						if(!(long)qst){
							printf("FIM DE JOGO!!!\n");
							break;
						}else{
							char *ans = genAns();
							printf("PERGUNTA (%d): %s%s\n", cnt, qst, ans);
							free(ans);
							cnt++;
						}
					}else{
						if(cnt == 1) continue; //you cannot ask an answer if you haven't got a question
						if (!strcmp(cmd, "ans")){ //answers
							char *ans = genAns();
							printf("%s\n", genAns());
							free(ans);
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
	finish();
	return 0;
}