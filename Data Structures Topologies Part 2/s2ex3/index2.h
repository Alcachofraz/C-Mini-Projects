#define BLOCO 42

typedef struct {
int fileIdx;
int line;
long offset;
} Occurence;

typedef struct {
char *word;
int count;
Occurence *occur;
} Word;

typedef struct {
Word *words;
int used;
int allocated;
} Index;

Index * i;

int compareSearch(const void * a, const void * b);

int compareSort(const void * key, const void * w);

void indexStart(void);

void indexAddOccur(Word *w, int fileIdx, int line, long offset);

Word *indexFindWord(char *data);

void indexAddWord(char *data, int fileIdx, int line, long offset);

void indexEnd(void);
