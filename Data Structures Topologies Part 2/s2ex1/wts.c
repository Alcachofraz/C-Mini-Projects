#include <stdio.h>

#include "search.h"

int main(int argc, char *argv[]) {	
	char aux[SIZE]={' '};
	printf("\n");
	if (argc > 1) {
		searchStart(argc-1, (const char**)(argv+1));		/// Começa a procura
		printf("-> Palavra a procurar: ");		
		while (scanf("%s", aux) != EOF) {						/// Loop para procurar várias palavras
			printf("\n");
			searchWord(aux);								/// Função de procura
			
			printf("-> Palavra a procurar: ");
		}
		searchEnd();
	}
	else {
		printf("Sem ficheiros de pesquisa!");
	}
	printf("\n\n");
	
	return 0;
}
