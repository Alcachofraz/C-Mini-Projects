#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "index4.h"

unsigned int hash(char *s) {
	unsigned hashval;

	for(hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

	return hashval % HASHSIZE; 
}

void indexStart(void) {
	
}

void indexAddOccur(Elem *aux, int fileIdx, int line, long offset) {
	int k;
	for (k = 0; k < aux->count; k++)			/// Percorre todas as ocorrências da palavra recebida
		if (aux->occur[k].fileIdx == fileIdx && aux->occur[k].line == line)			/// Verifica se já existe uma ocorrência na mesma linha do mesmo ficheiro
			return;
			
	if (aux->count == 0)
		aux->occur = malloc(sizeof(Occurence));		/// Cria a primeira posição do array occur
	else
		aux->occur = realloc(aux->occur, (aux->count+1)*sizeof(Occurence));		/// Acrescenta mais uma posição ao array occur
	
	aux->occur[aux->count].fileIdx = fileIdx;		/// Índice de ficheiro da nova ocorrência
	aux->occur[aux->count].line = line;			/// Linha da nova ocorrência
	aux->occur[aux->count++].offset = offset;		/// Offset da nova ocorrência	
}

Elem *indexFindWord(char *data) {
	Elem *aux;
	for(aux = hashtable[hash(data)]; aux != NULL; aux = aux->next) /// Para o caso de haver colisões para este valor de indexação
		if(strcmp(data, aux->word) == 0)
			return aux;
	return NULL;
}

void indexAddWord(char *data, int fileIdx, int line, long offset) {
	
	Elem *aux;
	unsigned long hashval;

	if((aux = indexFindWord(data)) == NULL) {		/// Verifica-se se "data" já existe.
		
		aux = malloc(sizeof(Elem));
		if(aux == NULL)	return;
		
		aux->word = strdup(data);
		if(aux->word == NULL) {
			free(aux);
			return;
		}
		
		hashval = hash(data);			/// Gera-se o índice do array associado a "data".
		aux->next = hashtable[hashval];			/// Para o caso de existir já um ELEM de uma palavra com o mesmo hashval, a variável next do 
												/// novo ELEM aponta para esse ELEM (criando assim uma lista de palavras com o mesmo hashval)
												/// Se for a primeira palavra com esse hashval, a variável next passa a apontar para NULL
		aux->count = 0;									
		hashtable[hashval] = aux;
	} 
	indexAddOccur(aux, fileIdx, line, offset);
}

void indexEnd() {
	
}


