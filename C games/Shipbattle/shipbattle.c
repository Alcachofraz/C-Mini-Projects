#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h> 
#include <Windows.h>

int board1[10][10]={
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int board2[10][10]={
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int test1[10][10]={
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int test2[10][10]={
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


int playerTurn=0;
int intercepted1[10][10];
int intercepted2[10][10];
int winnerIndicator=0;
int contador=0;
int ship5[2][5], ship4[2][4], ship32[2][3], ship31[2][3], ship2[2][2]; //linha 1 -> coordenada x //linha 2 -> coordenada y
int ship5_2[2][5], ship4_2[2][4], ship32_2[2][3], ship31_2[2][3], ship2_2[2][2]; //linha 1 -> coordenada x //linha 2 -> coordenada y
char player1[50];
char player2[50];
char winner[50];
bool enableGame=false;
bool playAgain;
bool enable5, enable4, enable32, enable31, enable2;
bool enable5_2, enable4_2, enable32_2, enable31_2, enable2_2;


void playerNames ();
void gameStart ();
void holdOn ();
void shipsPlayer1 ();
void shipsPlayer2 ();
void gameWin ();
void interceptArrays ();
void printBoard (int board[10][10], int test[10][10]);
void textWhite();
void textRed();
void textGreen();
int writeBoard(int test[10][10], int board[10][10]);
int whichLetter (char ans[]);
int convertString (char string[], int position);
bool verifyCoord (char coord[]);
bool checkWin ();


void textWhite() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


void textRed() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}


void textGreen() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}


void playerNames() {
	textWhite();
	printf("Jogador 1, insere o teu nome:");
	scanf("%s", player1);
	textWhite();
	printf("\n\nJogador 2, insere o teu nome:");
	scanf("%s", player2);
	system("cls");
}


int convertString (char string[], int position) {
	return (string[position]-48);
}


void interceptArrays () {
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			if ((test1[i][j]==1)&&(board1[i][j]==1)) intercepted1[i][j]=1;
			else intercepted1[i][j]=0;
		}
	}
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			if ((test2[i][j]==1)&&(board2[i][j]==1)) intercepted2[i][j]=1;
			else intercepted2[i][j]=0;
		}
	}
}	


int whichLetter (char ans[]) {
	int y;
	char letter=ans[0];
	
	if ((letter=='a')||(letter=='A')) y=0;
	if ((letter=='b')||(letter=='B')) y=1;
	if ((letter=='c')||(letter=='C')) y=2;
	if ((letter=='d')||(letter=='D')) y=3;
	if ((letter=='e')||(letter=='E')) y=4;
	if ((letter=='f')||(letter=='F')) y=5;
	if ((letter=='g')||(letter=='G')) y=6;
	if ((letter=='h')||(letter=='H')) y=7;
	if ((letter=='i')||(letter=='I')) y=8;
	if ((letter=='j')||(letter=='J')) y=9;
	return y;
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


void printBoard (int board[10][10], int test[10][10]) {
	playAgain=false;
	textWhite();
	printf ("     A  B  C  D  E  F  G  H  I  J");
	for (int i=0;i<10;i++) {
		textWhite();
		printf("\n");
		if(i==0) printf("  1");
		if(i==1) printf("  2");
		if(i==2) printf("  3");
		if(i==3) printf("  4");
		if(i==4) printf("  5");
		if(i==5) printf("  6");
		if(i==6) printf("  7");
		if(i==7) printf("  8");
		if(i==8) printf("  9");
		if(i==9) printf(" 10");
		for (int j=0;j<10;j++) {
			if ((board[i][j]==1)&&(enableGame==false)) {
				textWhite();
				printf("  X");
			}
			else {
				if ((board[i][j]==0)&&(test[i][j]==1)&&(enableGame==true)) {
					textWhite();
					printf("  X");
				}
				else {
					if ((board[i][j]==1)&&(test[i][j]==1)&&(enableGame==true)) {
						if (((((i==ship5[0][0])&&(j==ship5[1][0]))||((i==ship5[0][1])&&(j==ship5[1][1]))||((i==ship5[0][2])&&(j==ship5[1][2]))||((i==ship5[0][3])&&(j==ship5[1][3]))||((i==ship5[0][4])&&(j==ship5[1][4])))&&((test[ship5[0][0]][ship5[1][0]]==1)&&(test[ship5[0][1]][ship5[1][1]]==1)&&(test[ship5[0][2]][ship5[1][2]]==1)&&(test[ship5[0][3]][ship5[1][3]]==1)&&(test[ship5[0][4]][ship5[1][4]]==1)))&&(playerTurn==2)) {
							textRed();
							printf("  O");
						}	
						else {
							if (((((i==ship4[0][0])&&(j==ship4[1][0]))||((i==ship4[0][1])&&(j==ship4[1][1]))||((i==ship4[0][2])&&(j==ship4[1][2]))||((i==ship4[0][3])&&(j==ship4[1][3])))&&((test[ship4[0][0]][ship4[1][0]]==1)&&(test[ship4[0][1]][ship4[1][1]]==1)&&(test[ship4[0][2]][ship4[1][2]]==1)&&(test[ship4[0][3]][ship4[1][3]]==1)))&&(playerTurn==2)) {
								textRed();
								printf("  O");
							}
							else {
								if (((((i==ship32[0][0])&&(j==ship32[1][0]))||((i==ship32[0][1])&&(j==ship32[1][1]))||((i==ship32[0][2])&&(j==ship32[1][2])))&&((test[ship32[0][0]][ship32[1][0]]==1)&&(test[ship32[0][1]][ship32[1][1]]==1)&&(test[ship32[0][2]][ship32[1][2]]==1)))&&(playerTurn==2)) {
									textRed();
									printf("  O");
								}
								else {
									if (((((i==ship31[0][0])&&(j==ship31[1][0]))||((i==ship31[0][1])&&(j==ship31[1][1]))||((i==ship31[0][2])&&(j==ship31[1][2])))&&((test[ship31[0][0]][ship31[1][0]]==1)&&(test[ship31[0][1]][ship31[1][1]]==1)&&(test[ship31[0][2]][ship31[1][2]]==1)))&&(playerTurn==2)) {
										textRed();
										printf("  O");
									}
									else {
										if (((((i==ship2[0][0])&&(j==ship2[1][0]))||((i==ship2[0][1])&&(j==ship2[1][1])))&&((test[ship2[0][0]][ship2[1][0]]==1)&&(test[ship2[0][1]][ship2[1][1]]==1)))&&(playerTurn==2)) {
											textRed();
											printf("  O");
										}
										else {
											/////////
											if (((((i==ship5_2[0][0])&&(j==ship5_2[1][0]))||((i==ship5_2[0][1])&&(j==ship5_2[1][1]))||((i==ship5_2[0][2])&&(j==ship5_2[1][2]))||((i==ship5_2[0][3])&&(j==ship5_2[1][3]))||((i==ship5_2[0][4])&&(j==ship5_2[1][4])))&&((test[ship5_2[0][0]][ship5_2[1][0]]==1)&&(test[ship5_2[0][1]][ship5_2[1][1]]==1)&&(test[ship5_2[0][2]][ship5_2[1][2]]==1)&&(test[ship5_2[0][3]][ship5_2[1][3]]==1)&&(test[ship5_2[0][4]][ship5_2[1][4]]==1)))&&(playerTurn==1)) {
												textRed();
												printf("  O");
											}	
											else {
												if (((((i==ship4_2[0][0])&&(j==ship4_2[1][0]))||((i==ship4_2[0][1])&&(j==ship4_2[1][1]))||((i==ship4_2[0][2])&&(j==ship4_2[1][2]))||((i==ship4_2[0][3])&&(j==ship4_2[1][3])))&&((test[ship4_2[0][0]][ship4_2[1][0]]==1)&&(test[ship4_2[0][1]][ship4_2[1][1]]==1)&&(test[ship4_2[0][2]][ship4_2[1][2]]==1)&&(test[ship4_2[0][3]][ship4_2[1][3]]==1)))&&(playerTurn==1)) {
													textRed();
													printf("  O");
												}
												else {
													if (((((i==ship32_2[0][0])&&(j==ship32_2[1][0]))||((i==ship32_2[0][1])&&(j==ship32_2[1][1]))||((i==ship32_2[0][2])&&(j==ship32_2[1][2])))&&((test[ship32_2[0][0]][ship32_2[1][0]]==1)&&(test[ship32_2[0][1]][ship32_2[1][1]]==1)&&(test[ship32_2[0][2]][ship32_2[1][2]]==1)))&&(playerTurn==1)) {
														textRed();
														printf("  O");
													}
													else {
														if (((((i==ship31_2[0][0])&&(j==ship31_2[1][0]))||((i==ship31_2[0][1])&&(j==ship31_2[1][1]))||((i==ship31_2[0][2])&&(j==ship31_2[1][2])))&&((test[ship31_2[0][0]][ship31_2[1][0]]==1)&&(test[ship31_2[0][1]][ship31_2[1][1]]==1)&&(test[ship31_2[0][2]][ship31_2[1][2]]==1)))&&(playerTurn==1)) {
															textRed();
															printf("  O");
														}
														else {
															if (((((i==ship2_2[0][0])&&(j==ship2_2[1][0]))||((i==ship2_2[0][1])&&(j==ship2_2[1][1])))&&((test[ship2_2[0][0]][ship2_2[1][0]]==1)&&(test[ship2_2[0][1]][ship2_2[1][1]]==1)))&&(playerTurn==1)) {
																textRed();
																printf("  O");
															}
															else {
																textWhite();
																printf("  O");
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
					}			
					else {
						textWhite();
						printf("  -");
					}	
				}
			}
		}
	}
}


int writeBoard(int test[10][10], int board[10][10]) {
	int y, x, reg;
	char coord[3];
coord:
	textWhite();
	printf("\n\nCoordenada:");
	scanf(" %s", coord);

	if (verifyCoord (coord)==false) {
		textRed();
		printf ("\nInsere a coordenada corretamente!");
		goto coord;
	}
			
	x=convertString(coord, 1);
	y=whichLetter(coord);
		
	if ((x==1)&&(coord[2]=='0')) x=10;
	if ((x==1)&&(coord[2]=='\0')) x=1;
		
	reg=test[x-1][y];
	test[x-1][y]=1;
	
	if (enableGame==true) {
		if (board[x-1][y]==1) playAgain=true;
	}
	else playAgain=false;
	
	if (reg!=test[x-1][y]) {
		if (enable5==true) {
			ship5[0][contador] = (x-1);
			ship5[1][contador] = (y);
		}
		if (enable4==true) {
			ship4[0][contador-5] = (x-1);
			ship4[1][contador-5] = (y);
		}
		if (enable32==true) {
			ship32[0][contador-9] = (x-1);
			ship32[1][contador-9] = (y);
		}
		if (enable31==true) {
			ship31[0][contador-12] = (x-1);
			ship31[1][contador-12] = (y);
		}
		if (enable2==true) {
			ship2[0][contador-15] = (x-1);
			ship2[1][contador-15] = (y);
		}
		if (enable5_2==true) {
			ship5_2[0][contador] = (x-1);
			ship5_2[1][contador] = (y);
		}
		if (enable4_2==true) {
			ship4_2[0][contador-5] = (x-1);
			ship4_2[1][contador-5] = (y);
		}
		if (enable32_2==true) {
			ship32_2[0][contador-9] = (x-1);
			ship32_2[1][contador-9] = (y);
		}
		if (enable31_2==true) {
			ship31_2[0][contador-12] = (x-1);
			ship31_2[1][contador-12] = (y);
		}
		if (enable2_2==true) {
			ship2_2[0][contador-15] = (x-1);
			ship2_2[1][contador-15] = (y);
		}	
		contador++;
		return 1;
	}
	else return 0;
	
}


void shipsPlayer1 () {
	int ct5=0;
	int ct4=0;
	int ct32=0;
	int ct31=0;
	int ct2=0;
	
	while (ct5!=5) {
		enable5=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player1);
		printBoard (board1, test1);
		textWhite();
		printf ("\n\nBarco de 5:");
		ct5 = (ct5+writeBoard (board1, test1));
		system("cls");
	}
	enable5=false;
	while (ct4!=4) {
		enable4=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player1);
		printBoard (board1, test1);
		textWhite();
		printf ("\n\nBarco de 4:");
		ct4 = (ct4+writeBoard (board1, test1));
		system("cls");
	}
	enable4=false;
	while (ct32!=3) {
		enable32=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player1);
		printBoard (board1, test1);
		textWhite();
		printf ("\n\nBarco de 3 (1/2):");
		ct32 = (ct32+writeBoard (board1, test1));
		system("cls");
	}
	enable32=false;
	while (ct31!=3) {
		enable31=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player1);
		printBoard (board1, test1);
		textWhite();
		printf ("\n\nBarco de 3 (2/2):");
		ct31 = (ct31+writeBoard (board1, test1));
		system("cls");
	}
	enable31=false;
	while (ct2!=2) {
		enable2=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player1);
		printBoard (board1, test1);
		textWhite();
		printf ("\n\nBarco de 2:");
		ct2 = (ct2+writeBoard (board1, test1));
		system("cls");
	}
	enable2=false;
}


void shipsPlayer2 () {
	int ct5=0;
	int ct4=0;
	int ct32=0;
	int ct31=0;
	int ct2=0;
	contador=0;
	
	while (ct5!=5) {
		enable5_2=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player2);
		printBoard (board2, test2);
		textWhite();
		printf ("\n\nBarco de 5:");
		ct5 = (ct5+writeBoard (board2, test2));
		system("cls");
	}
	enable5_2=false;
	while (ct4!=4) {
		enable4_2=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player2);
		printBoard (board2, test2);
		textWhite();
		printf ("\n\nBarco de 4:");
		ct4 = (ct4+writeBoard (board2, test2));
		system("cls");
	}
	enable4_2=false;
	while (ct32!=3) {
		enable32_2=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player2);
		printBoard (board2, test2);
		textWhite();
		printf ("\n\nBarco de 3 (1/2):");
		ct32 = (ct32+writeBoard (board2, test2));
		system("cls");
	}
	enable32_2=false;
	while (ct31!=3) {
		enable31_2=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player2);
		printBoard (board2, test2);
		textWhite();
		printf ("\n\nBarco de 3 (2/2):");
		ct31 = (ct31+writeBoard (board2, test2));
		system("cls");
	}
	enable31_2=false;
	while (ct2!=2) {
		enable2_2=true;
		textWhite();
		printf ("%s, posiciona os teus barcos:\n\n", player2);
		printBoard (board2, test2);
		textWhite();
		printf ("\n\nBarco de 2:");
		ct2 = (ct2+writeBoard (board2, test2));
		system("cls");
	}
	enable2_2=false;
}


void holdOn () {
	char c;
	bool cond=false;
	while (cond!=true) {
		textWhite();
		printf("Clica 'enter' para continuar!");
		c=fgetc(stdin);
		if (c==10) cond=true;
		c=getchar();
	}
}


void gameStart () {
	while(true) {
repeat2:
		playerTurn=1;
		system("cls");
		textWhite();
		printf("%s, %c a tua vez de atacar!\n\n", player1, 130);
		printBoard(board2, test2);
		while (writeBoard(test2, board2)==0) {
			textRed();
			printf("\nJá atacaste esta coordenada!");
		}
		if (checkWin ()==true) break;
		if (playAgain==true) goto repeat2;
		system("cls");
		textWhite();
		printf("%s, %c a tua vez de atacar!\n\n", player1, 130);
		printBoard(board2, test2);
		textWhite();
		printf("\n\n");
		holdOn ();
repeat3:
		playerTurn=2;
		system("cls");
		textWhite();
		printf("%s, %c a tua vez de atacar!\n\n", player2, 130);
		printBoard(board1, test1);
		while (writeBoard(test1, board1)==0) {
			textRed();
			printf("\nJá atacaste esta coordenada!");
		}
		if (checkWin ()==true) break;
		if (playAgain==true) goto repeat3;
		system("cls");
		textWhite();
		printf("%s, %c a tua vez de atacar!\n\n", player2, 130);
		printBoard(board1, test1);
		textWhite();
		printf("\n\n");
		holdOn ();
	}
}


bool checkWin () {
	interceptArrays ();
		
	if (memcmp(board1, intercepted1, sizeof(board1))==0) {
		strcpy(winner, player2);
		winnerIndicator=2;
		return true;
	}
	else {
		if (memcmp(board2, intercepted2, sizeof(board2))==0) {
			strcpy(winner, player1);
			winnerIndicator=1;	
			return true;
		}
		else return false;
	}
}


void gameWin () {
	system("cls");
	if (winnerIndicator==1) {
		textWhite();
		printf("%s, %c a tua vez de atacar!\n\n", player1, 130);
		printBoard(board2,test2);
		textGreen();
		printf("\n\nMUITO BEM, %s! GANHASTE!\n", player1);
	}
	else {
		if (winnerIndicator==2) {
			textWhite();
			printf("%s, %c a tua vez de atacar!\n\n", player2, 130);
			printBoard(board1,test1);
			textGreen();
			printf("\n\nMUITO BEM, %s! GANHASTE!\n", player2);
		}
		else {
			textRed();
			printf("O programa bugou! xD -> %i", winnerIndicator);
		}
	}
}


int main (void) {
	playerNames ();
	shipsPlayer1 ();
		textWhite();
		printf ("%s, posiciona os teus barcos (2, 3, 3, 4, 5):\n\n", player1);
		printBoard (board1, test1);
		printf("\n\n");
		holdOn ();
		system("cls");
	shipsPlayer2 ();
		textWhite();
		printf ("%s, posiciona os teus barcos (2, 3, 3, 4, 5):\n\n", player2);
		printBoard (board2, test2);
		printf("\n\n");
		holdOn ();
		system("cls");
	enableGame=true;
	gameStart ();
	gameWin ();
	textWhite ();
	return 0;
}


