#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h> 
#include <Windows.h>

int position[5][5]={
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0}
};
int line1, line2, line3, line4, line5;
bool win=false;
bool again=false;

int generateRand(int min, int max);
void generateBoard();
void printBoard();
void gameStart();
void checkWin();

int generateRand(int min, int max) {
	int r = (rand()%(max-min+1))+min;
	return r;
}	

void generateBoard() {
	line1 = (generateRand(1, 5)-1);
linha2:
	line2 = (generateRand(1, 5)-1);
	if (line1 == line2) goto linha2;
linha3:
	line3 = (generateRand(1, 5)-1);
	if ((line3 == line1)||(line3 == line2)) goto linha3;
linha4:
	line4 = (generateRand(1, 5)-1);
	if ((line4 == line1)||(line4 == line2)||(line4 == line3)) goto linha4;
linha5:
	line5 = (generateRand(1, 5)-1);
	if ((line5 == line1)||(line5 == line2)||(line5 == line3)||(line5 == line4)) goto linha5;
	
	position[0][line1]=generateRand(1, 5);
	position[1][line2]=generateRand(1, 5);
	position[2][line3]=generateRand(1, 5);
	position[3][line4]=generateRand(1, 5);
	position[4][line5]=generateRand(1, 5);
}

void printBoard() {
	for (int i=0;i<5;i++) {
		printf("\n");
		for (int j=0;j<5;j++) {
			if (((i==0)&&(j==line1)) || ((i==1)&&(j==line2)) || ((i==2)&&(j==line3)) || ((i==3)&&(j==line4)) || ((i==4)&&(j==line5))) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				printf("  %i", position[i][j]);
			}
			else {
				if (position[i][j]!=0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf("  %i", position[i][j]);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					printf("  *");
				}	
			}
		}
	}
	printf("\n\n");
}

void gameStart() {
	
	int l, c, v;
	int ct=0;
	while (win==false) {
		start:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("Linha:");
		scanf("%i", &l);
		printf("Coluna:");
		scanf("%i", &c);
		printf("Valor:");
		scanf("%i", &v);
		
		if ((l==1) || (l==2) || (l==3) || (l==4) || (l==5)) ct++;
		if ((c==1) || (c==2) || (c==3) || (c==4) || (c==5)) ct++;
		if ((v==1) || (v==2) || (v==3) || (v==4) || (v==5)) ct++;
		if (ct!=3) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("\nINSERE VALORES DE 1 A 5!\n\n");
			ct=0;
			goto start;
		}
		
		if (((l==1)&&((line1+1)==c)) || ((l==2)&&((line2+1)==c)) || ((l==3)&&((line3+1)==c)) || ((l==4)&&((line4+1)==c)) || ((l==5)&&((line5+1)==c))) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("\nNAO PODES ALTERAR ESTE VALOR!\n\n");
			ct=0;
			goto start;
		}
		
		position[l-1][c-1]=v;
		
		system("cls");
		
		printBoard();
		checkWin();
		ct=0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("MUITO BEM! GANHASTE!");
}

void checkWin() {
	int ct=0; 
	int ctf=0;
	int cte=0;
	for (int i=0;i<5;i++) {
		for (int j=0;j<5;j++) {
			ct = position[i][j]+ct;
		}
		if (ct!=15) ctf++;
		ct=0;
	}
	if (ctf==0) {
		for (int i=0;i<5;i++) {
			for (int j=0;j<5;j++) {
				ct = position[j][i]+ct;
			}
			if (ct!=15) ctf++;
			ct=0;
		}
		if (ctf==0) {
			for (int i=0;i<5;i++) {
				for (int j=1;j<5;j++) {
					if (position[i][0]==position[i][j]) cte++;
				}
			}
			for (int i=0;i<5;i++) {
				for (int j=2;j<5;j++) {
					if (position[i][1]==position[i][j]) cte++;
				}
			}
			for (int i=0;i<5;i++) {
				for (int j=3;j<5;j++) {
					if (position[i][2]==position[i][j]) cte++;
				}
			}
			for (int i=0;i<5;i++) {
				for (int j=4;j<5;j++) {
					if (position[i][3]==position[i][j]) cte++;
				}
			}
			if(cte==0) win=true;
		}
	}
}
	
int main (void) {
	char a[3];
	init:
	srand(time(0)); 
	generateBoard();
	printBoard();
	gameStart();
	printf("\nQueres jogar outra vez?");
	scanf("%s", a);
	if (strcmp(a,"sim")==0) again=true;
	if (again==true) goto init;
	return 0;
}





	
