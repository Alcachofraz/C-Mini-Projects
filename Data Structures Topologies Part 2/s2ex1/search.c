#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "search.h"

static int fileNum;
static const char **nameFile;

void searchStart(int numFiles, const char *fileNames[]) {	/// Atribui os valores às variáveis do módulo
	fileNum = numFiles;
	nameFile = fileNames;
}

void searchWord(char *word) {
	int i;
	int found = 0;
	char res[SIZE] = {' '};
	translate_string(word, res);					/// Normaliza a palavra a procurar
	
	for (i = 0; i < fileNum; i++) {					/// Corre todos os ficheiros a processar
		if (textStart((char*)nameFile[i]) == 0) {
			printf("Erro ao abrir o ficheiro!\n\n");
			exit(1);
		}
		
		int lineNum = 1;							/// Primeira linha do ficheiro
		
		while (textLine(NULL) != NULL) {			/// Lê cada linha do ficheiro	
			char lineNorm[SIZE] = {' '};
			char *token;
			
			translate_string(line, lineNorm);		/// Normaliza a linha
			
			token = splitStart(lineNorm);
			
			while (token != NULL) {					/// Corre todas as palavras de cada linha
				if(strcmp(token, res) == 0) {		/// Caso encontre a palavra procurada
					printf("Nome do Ficheiro: %s\n", nameFile[i]);
					printf("Número da Linha: %d\n", lineNum);
					printf("Linha Original: %s\n\n", line);
					found = 1;
					break;							/// Sai do while para analisar as linhas seguintes
				}
				token = splitNext();				/// Próxima palavra
			}
			splitEnd();
			if(line[strlen(line) - 1] == '\n')
				lineNum++;
		}
		textEnd();
	}
	
	if(found == 0)
		printf("A palavra '%s' não foi encontrada nos ficheiros disponíveis.\n\n", word);
}

void searchEnd(void) {
}
