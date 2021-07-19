#include <stdio.h>
#include <string.h>

#include "split.h"

char *splitStart(char *line) {
	return strtok(line, " ");
}

char *splitNext(void) {
	return strtok(NULL, " ");
}

void splitEnd(void) {
}
