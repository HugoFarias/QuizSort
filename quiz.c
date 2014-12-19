#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	FILE* file = fopen(argv[1], "r");
	if(!file) return NULL;
	printf("%s\b%s\n", argv[1], "aberto!");

	char* cmd;
	while(1){ //stricmp() compara strings considerando A == a. 0 se iguais.
		scanf("%s", cmd);
		printf("\n");

		if (!stricmp(cmd, "exit")) break;
		else if(!stricmp(cmd, "help")) printf("Insira o comando desejado:\nAjuda: help\nGerar pergunta: ans\nSair: exit");
		else if (!stricmp(cmd, "ans")) printf("%s\n", genAns());
	}

	fclose(file);
	return 0;
}

char* genAns(){
	return "Funcionando\n";
}