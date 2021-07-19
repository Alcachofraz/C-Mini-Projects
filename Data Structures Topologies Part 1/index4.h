#define HASHSIZE 306949 /// número de palavras existentes na língua portuguesa (o que não cobre tudo, devido aos nomes próprios por exemplo)

typedef struct Occurence Occurence;

typedef struct Occurence {
	int fileIdx;
	int line;
	long offset;
} Occurence;

typedef struct Elem Elem;

typedef struct Elem {
	char *word;
	Elem *next;
	int count;
	Occurence *occur;
} Elem;

static Elem *hashtable[HASHSIZE];

unsigned int hash(char *s);

void indexStart(void);

void indexAddOccur(Elem *aux, int fileIdx, int line, long offset);

Elem *indexFindWord(char *data);

void indexAddWord(char *data, int fileIdx, int line, long offset);

void indexEnd();



