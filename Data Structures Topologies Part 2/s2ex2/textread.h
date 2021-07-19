#define SIZE 256

char line[SIZE];

int textStart(char *fileName);

char *textLine(long *storeOffset);

void textEnd(void);

char *textLocatedLine(long offset);
