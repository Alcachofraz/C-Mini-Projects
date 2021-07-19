#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h> 
#include <Windows.h>

int board[28][55]={
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int pos1[2];
int pos2[2];

int whichLetter (char coord[]);
void printBoard ();
bool writeBoard ();
bool verifyCoord (char coord[]);
void textRed ();
void textWhite (); 
void textGreen ();
void getPos (int x, int y, int pos);

void textWhite() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


void textRed() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}


void textGreen() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}


void getPos (int x, int y, int pos) {
	if (pos==1) {
		pos1[0] = 6*(x);
		pos1[1] = 3*(y);
	}
	if (pos==2) {
		pos2[0] = 6*(x);
		pos2[1] = 3*(y);
	}
}

int whichLetter (char coord[]) {
	int y;
	char letter=coord[0];
	
	if ((letter=='a')||(letter=='A')) y=0;
	if ((letter=='b')||(letter=='B')) y=3;
	if ((letter=='c')||(letter=='C')) y=6;
	if ((letter=='d')||(letter=='D')) y=9;
	if ((letter=='e')||(letter=='E')) y=12;
	if ((letter=='f')||(letter=='F')) y=15;
	if ((letter=='g')||(letter=='G')) y=18;
	if ((letter=='h')||(letter=='H')) y=21;
	if ((letter=='i')||(letter=='I')) y=24;
	if ((letter=='j')||(letter=='J')) y=27;
	return y;
}


int convertString (char string[], int position) {
	return (string[position]-48);
}


bool verifyCoord (char coord[]) {
	bool cond1=false;
	bool cond2=false;
	if ((coord[1]=='1')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='2')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='3')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='4')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='5')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='6')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='7')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='8')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='9')&&(coord[2]=='\0')) cond1=true;
	if ((coord[1]=='1')&&(coord[2]=='0')) cond1=true;
	if ((coord[0]=='a')||(coord[0]=='A')) cond2=true;
	if ((coord[0]=='b')||(coord[0]=='B')) cond2=true;
	if ((coord[0]=='c')||(coord[0]=='C')) cond2=true;
	if ((coord[0]=='d')||(coord[0]=='D')) cond2=true;
	if ((coord[0]=='e')||(coord[0]=='E')) cond2=true;
	if ((coord[0]=='f')||(coord[0]=='F')) cond2=true;
	if ((coord[0]=='g')||(coord[0]=='G')) cond2=true;
	if ((coord[0]=='h')||(coord[0]=='H')) cond2=true;
	if ((coord[0]=='i')||(coord[0]=='I')) cond2=true;
	if ((coord[0]=='j')||(coord[0]=='J')) cond2=true;
	
	if ((cond1==true)&&(cond2==true)) return true;
	else return false;
}


void printBoard () {
	system("cls");
	textWhite(); 
	printf("\n");
	printf ("    |  A     B     C     D     E     F     G     H     I     J");
	printf("\n --------------------------------------------------------------");
	for (int i=0;i<28;i++) {
		printf("\n");
		if(i==0) printf("  1 |  ");
		else {
			if(i==3) printf("  2 |  ");
			else {
				if(i==6) printf("  3 |  ");
				else {
					if(i==9) printf("  4 |  ");
					else {
						if(i==12) printf("  5 |  ");
						else {
							if(i==15) printf("  6 |  ");
							else {
								if(i==18) printf("  7 |  ");
								else {
									if(i==21) printf("  8 |  ");
									else {
										if(i==24) printf("  9 |  ");
										else {
											if(i==27) printf(" 10 |  ");
											else {
												printf ("    |  ");
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for (int j=0;j<55;j++) {
			if ((((((j)%6)==0)&&(j!=0))||(j==0))&&((i%3)==0)) printf("O");
			else {
				if (board[i][j]==0) printf(" ");
				if (board[i][j]==1) printf("-");
				if (board[i][j]==2) printf("|");
			}
		}
	}
	printf("\n");
}


bool writeBoard () {
	bool val=true;
	char coord1[3], coord2[3];
coord1:
	textWhite(); 
	printf ("\nCoordenada 1:");
	scanf(" %s", coord1);

	if (verifyCoord (coord1)==false) {
		textRed();
		printf ("\nInsere a coordenada corretamente!");
		goto coord1;
	}

	int y1=convertString(coord1, 1);
	int x1=whichLetter(coord1);
	
	if ((y1==1)&&(coord1[2]=='0')) y1=10;
	if ((y1==1)&&(coord1[2]=='\0')) y1=1;
	y1--;

	getPos(x1, y1, 1);

coord2:
	textWhite(); 
	printf ("\nCoordenada 2:");
	scanf(" %s", coord2);

	if (verifyCoord (coord2)==false) {
		textRed();
		printf ("\nInsere a coordenada corretamente!");
		goto coord2;
	}

	int y2=convertString(coord2, 1);
	int x2=whichLetter(coord2);
	
	if ((y2==1)&&(coord2[2]=='0')) y2=10;
	if ((y2==1)&&(coord2[2]=='\0')) y2=1;
	y2--;

	getPos (x2, y2, 2);

	int reg[28][55];
	for (int i=0; i<28; i++) {
		for (int j=0; j<55; j++) {
			reg[i][j] = board[i][j];
		}
	}
	
	printf("%i %i %i %i", x1,x2,y1,y2);

	if ((x1 == x2) && ((y1==(y2-1))||(y1==(y2+1))||(y2==(y1-1))||(y2==(y1+1)))) {
		if (y2>y1) {
			board[pos2[0]][(pos2[1]-1)]=2;
			board[pos2[0]][(pos2[1]-2)]=2;
		}
		if (y1>y2) {
			board[pos1[0]][(pos1[1]-1)]=2;
			board[pos1[0]][(pos1[1]-2)]=2;
		}
	}
	else {
		if ((y1 == y2) && ((x1==(x2-1))||(x1==(x2+1))||(x2==(x1-1))||(x2==(x1+1)))) {
			if (x2>x1) {
				board[(pos2[0]-1)][pos2[1]]=1;
				board[(pos2[0]-2)][pos2[1]]=1;
			}
			if (x1>x2) {
				board[(pos1[0]-1)][pos1[1]]=1;
				board[(pos1[0]-2)][pos1[1]]=1;
			}
		}
		else val=false;
	}
	
	for (int i=0; i<28; i++) {
		for (int j=0; j<55; j++) {
			if (board[i][j]!=reg[i][j]) val=false;
		}
	}
	return val;
}



int main (void) {
	while (true) {
		printBoard ();
		while (writeBoard()==false) {
			textRed();
			printf("\nInsere coordenadas v%clidas", 160);
		}
	}
	return 0;
}


