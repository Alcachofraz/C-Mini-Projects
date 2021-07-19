#include <stdio.h>

#include "textread.h"

static FILE* fp;

int textStart(char *fileName) {
	fp = fopen(fileName, "r");			/// Abre o ficheiro
	if (fp == NULL) return 0;
	return 1;
}

char *textLine(long *storeOffset) {
	if(storeOffset != NULL) *storeOffset = ftell(fp);
	return fgets(line, SIZE, fp);
}

void textEnd(void) {
	fclose(fp);							/// Fecha o fiheiro
}

char *textLocatedLine(long offset) {
	fseek(fp, offset, SEEK_SET);
	return fgets(line, SIZE, fp);
}
