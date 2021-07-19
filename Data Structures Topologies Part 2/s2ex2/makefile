a.out: wts2.o search2.o index.o split.o translate.o textread.o
	gcc wts2.o search2.o index.o split.o translate.o textread.o

wts2.o: wts2.c search2.h
	gcc -c wts2.c

search2.o: search2.c search2.h
	gcc -c search2.c

index.o: index.c index.h
	gcc -c index.c

split.o: split.c split.h
	gcc -c split.c

translate.o: translate.c translate.h
	gcc -c translate.c

textread.o: textread.c textread.h
	gcc -c textread.c
