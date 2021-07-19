a.out: wts5.o search2.o index4.o split.o translate.o textread.o
	gcc wts5.o search2.o index4.o split.o translate.o textread.o

wts3.o: wts5.c search2.h
	gcc -c wts5.c

search2.o: search2.c search2.h
	gcc -c search2.c

index2.o: index4.c index4.h
	gcc -c index4.c

split.o: split.c split.h
	gcc -c split.c

translate.o: translate.c translate.h
	gcc -c translate.c

textread.o: textread.c textread.h
	gcc -c textread.c
