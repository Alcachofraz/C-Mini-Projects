#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "search2.h"

static int fileNum;
static const char **nameFile;

void searchStart(int numFiles, const char *fileNames[]) {	/// Prepara o Índice de palavras
	indexStart();
	fileNum = numFiles;
	nameFile = fileNames;
	int k;
	long offset = 0;
	for (k = 0; k < fileNum; k++) {					/// Corre todos os ficheiros a processar
		if (textStart((char*)nameFile[k]) == 0) {
			printf("Erro ao abrir o ficheiro!\n\n");
			exit(1);
		}
		
		int lineNum = 1;							/// Primeira linha do ficheiro
		
		while (textLine(&offset) != NULL) {			/// Lê cada linha do ficheiro
			char lineNorm[SIZE] = {' '};
			char *token;
			
			translate_string(line, lineNorm);		/// Normaliza a linha
			
			token = splitStart(lineNorm);
			
			while (token != NULL) {					/// Corre todas as palavras de cada linha
				indexAddWord(token, k+1, lineNum, offset);
				token = splitNext();				/// Próxima palavra
			}
			splitEnd();
			if(line[strlen(line) - 1] == '\n')
				lineNum++;
		}
		textEnd();
	}
}

void searchWord(char *word) {
	int j;
	char res[SIZE] = {" "};
	translate_string(word, res);
	Word *found = indexFindWord(res);
	if (found != NULL) {
		for (j = 0; j < found->count; j++) {
			textStart((char*)nameFile[found->occur[j].fileIdx - 1]);
			printf("Nome do Ficheiro: %s\n", nameFile[found->occur[j].fileIdx - 1]);
			printf("Número da Linha: %d\n", found->occur[j].line);
			printf("Linha Original: %s\n\n", textLocatedLine(found->occur[j].offset));
			textEnd();
		}
	}
	else
		printf("A palavra '%s' não foi encontrada nos ficheiros disponíveis.\n\n", word);
}

void searchEnd(void) {
	indexEnd();
}
