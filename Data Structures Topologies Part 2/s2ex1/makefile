a.out: wts.o search.o index.o split.o translate.o textread.o
	gcc wts.o search.o index.o split.o translate.o textread.o

wts.o: wts.c search.h
	gcc -c wts.c

search.o: search.c search.h
	gcc -c search.c

split.o: split.c split.h
	gcc -c split.c

translate.o: translate.c translate.h
	gcc -c translate.c

textread.o: textread.c textread.h
	gcc -c textread.c
