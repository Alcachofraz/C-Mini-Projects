#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h> 
#include <Windows.h>


int state=0;
int test[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char cat[50];
char word[50]="**************************************************";
char reg[7]="yyyyyyy";
bool end=false;


void printHang ();
int sizeWord ();
void decision ();
void checkVic ();
void gameLose ();
void gameWin ();


void printHang () {
	system("cls");
	
	if (state==0) printf("\n      _____________\n     |             |\n     |             |\n     |             |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n  ___|___");
	if (state==1) printf("\n      _____________\n     |             |\n     |             |\n     |             |\n     |            ( )\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n  ___|___");
	if (state==2) printf("\n      _____________\n     |             |\n     |             |\n     |             |\n     |            ( )\n     |           __\n     |          |\n     |          |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n  ___|___");
	if (state==3) printf("\n      _____________\n     |             |\n     |             |\n     |             |\n     |            ( )\n     |           __ __\n     |          |     |\n     |          |     |\n     |\n     |\n     |\n     |\n     |\n     |\n     |\n  ___|___");
	if (state==4) printf("\n      _____________\n     |             |\n     |             |\n     |             |\n     |            ( )\n     |           __ __\n     |          |  |  |\n     |          |  |  |\n     |             |\n     |\n     |\n     |\n     |\n     |\n     |\n  ___|___");
	if (state==5) printf("\n      _____________\n     |             |\n     |             |\n     |             |\n     |            ( )\n     |           __ __\n     |          |  |  |\n     |          |  |  |\n     |            _|\n     |           |\n     |           |\n     |          _|\n     |\n     |\n     |\n  ___|___");
	if (state==6) printf("\n      _____________\n     |             |\n     |             |\n     |             |\n     |            ( )\n     |           __ __\n     |          |  |  |\n     |          |  |  |\n     |            _|_\n     |           |   |\n     |           |   |\n     |          _|   |_\n     |\n     |\n     |\n  ___|___");

	int size=sizeWord();
	
	printf("\n\n       CATEGORIA:  %s", cat);
	printf("                                              ");
	for (int j=0; j<7; j++) {
		if (reg[j]!='y') printf("  %c", reg[j]);
	}
	printf("\n         PALAVRA:  ");
	for (int i=0; i<size; i++) {
		if (word[i]=="*") printf(" ");
		if (test[i]==1) printf("%c", word[i]);
		else printf("*");
	}
	printf("\n");
}



int  sizeWord () {
	int size=-2;
	
	for(int i=0;i<50;i++) {
		if (word[i]=='*') break;
		else size++;
	}
	return size;	
}



void decision() {	
	int size=sizeWord();
	char d;
	printf("\nL -> Letra\nA -> Adivinhar\n");
	scanf (" %c", &d);
	
	if ((d=='l')||(d=='L')) {
		int ct=0;
		char letter;
		printf("\nInsere uma letra:\n");
		scanf (" %c", &letter);		
		for (int i=0;i<size;i++) {
			if(letter==word[i]) {
				test[i]=1;
				ct++;
			}
		}
		if (ct==0) {
			state++;
			if (state!=6) {
				printf("\nExperimenta outra vez!\n");
				reg[state-1]=letter;
			}
			else gameLose();
		}
	}
	
	if ((d=='a')||(d=='A')) {
		int ct=0;
		char guess[50];
		printf("\nInsere a palavra:\n");
		scanf (" %s", guess);
		for (int j=0;j<size;j++) {
			if (guess[j]==word[j]) ct++;
		}
		if (ct==size) gameWin();
		else {
			state++;
			if (state!=6) printf ("\nErrado! Continua a tentar!\n");
			else gameLose();
		}
	}
	
	if ((d!='l')&&(d!='L')&&(d!='a')&&(d!='A')) printf("\nInsere L ou A!\n");
	checkVic ();
}



void checkVic() {
	int size=sizeWord();
	int ct=0;
	for (int i=0;i<size;i++) {
		if (test[i]==1) ct++;
	}
	if (ct==size) gameWin();
}



void gameLose() {
	printHang();
	printf("\nDESASTRE! PERDESTE, SEU IDIOTA!\n");
	end=true;		 			
}



void gameWin() {
	int size=sizeWord();
	for (int i=0;i<size;i++) {
		test[i]=1;
	}
	printHang();
	printf("\nMUITO BEM! ADIVINHASTE!\n");
	end=true;		 			
}



int main (void) {
	printf ("Escolhe uma palavra:\n");
	fgets(word, sizeof(word), stdin);
	printf ("Indica a categoria:\n");
	fgets(cat, sizeof(cat), stdin);
	
	while (end==false) {
		printHang();
		decision();
	}
	return 0;
}



