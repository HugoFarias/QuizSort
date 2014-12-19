#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* genAns(){
	
	return "funcionando";
}

int main(int argc, char **argv){
	FILE* file = fopen(argv[1], "r");
	if(!(long)file) return 1;
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
					printf("PERGUNTA (%d): %s\n\n", cnt, genAns());
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