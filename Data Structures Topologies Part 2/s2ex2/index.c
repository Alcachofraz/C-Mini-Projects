#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "index.h"

void indexStart(void) {
	Index init = { malloc(BLOCO*sizeof(Word)) , 0, BLOCO};
	i = malloc(sizeof(*i));
	*i = init;
}

void indexAddOccur(Word *w, int fileIdx, int line, long offset) {
	int k;
	for (k = 0; k < w->count; k++)			/// Percorre todas as ocorrências da palavra recebida
		if (w->occur[k].fileIdx == fileIdx && w->occur[k].line == line) {		/// Verifica se já existe uma ocorrência na mesma linha do mesmo ficheiro
			return;
		}

	if (w->count == 0) {
		w->occur = malloc(sizeof(Occurence));		/// Cria a primeira posição do array occur
	}
	else {
		w->occur = realloc(w->occur, (w->count+1)*sizeof(Occurence));		/// Acrescenta mais uma posição ao array occur
	}
	
	w->occur[w->count].fileIdx = fileIdx;		/// Índice de ficheiro da nova ocorrência
	w->occur[w->count].line = line;			/// Linha da nova ocorrência
	w->occur[w->count++].offset = offset;		/// Offset da nova ocorrência
}

Word *indexFindWord(char *data) {
	int k;
	for (k = 0; k < i->used; k++) {		/// Percorre todas as palavras
		if (strcmp(i->words[k].word, data) == 0){
			return &i->words[k];			/// Se encontrar, retorna o endereço da estrutura Word respetiva
		}
	}
	return NULL;		/// Se não encontrar, retorna NULL
}

void indexAddWord(char *data, int fileIdx, int line, long offset) {
	Word *found = indexFindWord(data);
	if (found != NULL) {			/// Verifica se a palavra recebida já foi registada
		indexAddOccur(found, fileIdx, line, offset);		/// Se já, adiciona a nova ocorrência
		return;
	}
	
	if (i->used==i->allocated) {			///	Verifica se há memória alocada para uma nova palavra
		i->words=realloc(i->words, i->used*sizeof(Word) + BLOCO*sizeof(Word));		/// Se não, realoca um bloco de memória a mais
		i->allocated+=BLOCO;
	}
	
	int count=0;		///Como a palavra recebida está a ser registada pela primeira vez, o número de ocorrências será iniciado a zero
	
	i->words[i->used].word=strdup(data);			/// Nova palavra
	i->words[i->used].count=count;			/// Número de occorrências

	indexAddOccur(&i->words[i->used++], fileIdx, line, offset);		/// Adicionar ocorrência
}

void indexEnd(void) {
	int k;
	for (k = 0; k < i->used; k++) {
		free(i->words[k].word);			/// Libertar a memória ocupada string
		free(i->words[k].occur);		/// Libertar a memória ocupada pelo array de ocorrências
	}
	free(i->words);			/// Libertar a memória ocupada pelo array de palavras
	free(i);		/// Libertar a memória ocupada pelo descritor para o índice de palavras 
}
