#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h> 
#include <Windows.h>
#include <Winuser.h>
#include <conio.h>
#include <ctype.h>

FILE * fhs;

char empty_map[15][29]={"# # # # # # # # # # # # # # #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"#                           #",
						"# # # # # # # # # # # # # # #"};

char current_map[15][29];
int test[15][29];

int nodes[4][100]; //x(0) y(1) previous_direction(2) direction(3)
int node_counter;
int changed;

int size;
int direction; //north(1) east(2) south(3) west(4) 
int previous_direction;

int score;
int highest_score;

bool lost;
bool again=false;

struct coord {
	int x;
	int y;
};

struct coord coord_snake;
struct coord coord_food;

void setGlobal ();
void textWhite ();
void textRed ();
void textGreen ();
void textBlue ();
void emptyMap ();
void delay ();
void holdOn ();
int getRand(int min, int max);
void lose ();
bool checkLose ();
void eliminateNode ();
void getNode ();
void snakeMove ();
void getDirection ();
void spawnFood ();
void writeMap ();
void printMap ();
void startGame ();


void setGlobal () {
	node_counter=0;
	changed=0;
	size=4;
	direction=2;
	score=-1;
	lost=false;
	
	coord_food.x=-1;
	coord_food.y=-1;
	coord_snake.x=4;
	coord_snake.y=9;
	coord_snake.x=coord_snake.x*2;
	
	if ((fhs = fopen("snakeHighestScore.txt", "r"))==NULL) highest_score=0;
	else fscanf(fhs, "%i", &highest_score);
	fclose(fhs);
}


void textWhite () {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


void textRed () {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}


void textGreen () {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}


void textBlue () {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}


void emptyMap () {
	for (int i=0; i<15; i++) {
		for (int j=0;j<29;j++) {
			current_map[i][j]=empty_map[i][j];
		}
	}
}


void delay() {
	int milli_seconds = 200; 
	clock_t start_time = clock(); 
	while (clock() < start_time + milli_seconds) {
		if (changed==0) {
			getDirection ();
		}
	}
	changed=0;
}


void holdOn () {
	if (again==true) printf("\n  Clica 'Enter' para jogar mais uma vez!");
	else printf("\n  Clica 'Enter' para come%car!", 135);
	while (getchar() != '\n');
}


int getRand(int min, int max) {
	int r = (rand()%(max-min+1))+min;
	return r;
}


void lose () {
	lost=true;
	again=true;
	printMap ();
	textRed ();
	printf("\n  PERDESTE!\n");
	textWhite ();
}


bool checkLose () {
	bool lose=false;
	int ct=0;
	for (int i=0;i<15;i++) {
		for (int j=0;j<29;j++) {
			if (test[i][j]>1) ct++;
		}
	}
	if (ct!=0) lose=true;
	else {
		if ((coord_snake.x<=0)||(coord_snake.x>=28)||(coord_snake.y<=0)||(coord_snake.y>=14)) lose=true;
		else {
			for (int i=0;i<100;i++) {
				if ((coord_snake.x==nodes[0][i])&&(coord_snake.y==nodes[1][i])) lose=true;
			}
		}
	}	
return lose;	
}


void eliminateNode () {
	for (int i=0;i<4;i++) {
		for (int j=0;j<99;j++) {
			nodes[i][j]=nodes[i][j+1];
		}
	}
	node_counter--;
}	


void getNode () {
	nodes[0][node_counter]=coord_snake.x;
	nodes[1][node_counter]=coord_snake.y;
	nodes[2][node_counter]=previous_direction;
	nodes[3][node_counter]=direction;
	node_counter++;
}	


void snakeMove () {
	if (direction==1) coord_snake.y--;
	if (direction==2) coord_snake.x+=2;
	if (direction==3) coord_snake.y++;
	if (direction==4) coord_snake.x-=2;
}


void getDirection () {
	if((GetAsyncKeyState(VK_UP))&&(direction!=3)) {
		previous_direction=direction;
		direction=1;
		getNode ();
		changed++;
	}
	else {
		if((GetAsyncKeyState(VK_RIGHT))&&(direction!=4)) {
			previous_direction=direction;
			direction=2;
			getNode ();
			changed++;
		}
		else {
			if((GetAsyncKeyState(VK_DOWN))&&(direction!=1)) {
				previous_direction=direction;
				direction=3;
				getNode ();
				changed++;
			}
			else {
				if((GetAsyncKeyState(VK_LEFT))&&(direction!=2)) {
					previous_direction=direction;
					direction=4;
					getNode ();
					changed++;
				}
			}
		}
	}
}


void spawnFood () {
	repeat:
	coord_food.x=getRand(1, 13);
	coord_food.y=getRand(1, 13);
	coord_food.x=coord_food.x*2;
	if ((current_map[coord_food.y][coord_food.x]=='O')||(current_map[coord_food.y][coord_food.x]=='o')) goto repeat;
	score++;
}


void writeMap () {
	for (int i=0;i<15;i++) {
		for (int j=0;j<29;j++) {
			test[i][j]=0;
		}
	}
	int nodeCT=0;
	int snakeX=coord_snake.x;
	int snakeY=coord_snake.y;
	int currentDirection=direction;
	emptyMap ();
	for (int ct=0;ct<size;ct++) {	
		if (currentDirection==1) {
			test[snakeY][snakeX]++;
			if ((ct==0)||(test[snakeY][snakeX]>1)) current_map[snakeY][snakeX]='O'; 
			else current_map[snakeY][snakeX]='o';
			for (int i=0;i<100;i++) {
				if ((nodes[0][i]==snakeX)&&(nodes[1][i]==snakeY)&&(ct!=0)) {
					nodeCT++;
					currentDirection=nodes[2][i];
					if (currentDirection==2) goto if2;
					if (currentDirection==3) goto if3;
					if (currentDirection==4) goto if4;
				}
			}
			if1:
			snakeY++;
		}
		if (currentDirection==2) {
			test[snakeY][snakeX]++;
			if ((ct==0)||(test[snakeY][snakeX]>1)) current_map[snakeY][snakeX]='O'; 
			else current_map[snakeY][snakeX]='o';
			for (int j=0;j<100;j++) {
				if ((nodes[0][j]==snakeX)&&(nodes[1][j]==snakeY)&&(ct!=0)) {
					nodeCT++;
					currentDirection=nodes[2][j];
					if (currentDirection==1) goto if1;
					if (currentDirection==3) goto if3;
					if (currentDirection==4) goto if4;
				}
			}
			if2:
			snakeX-=2;
		}
		if (currentDirection==3) {
			test[snakeY][snakeX]++;
			if ((ct==0)||(test[snakeY][snakeX]>1)) current_map[snakeY][snakeX]='O'; 
			else current_map[snakeY][snakeX]='o';
			for (int h=0;h<100;h++) {
				if ((nodes[0][h]==snakeX)&&(nodes[1][h]==snakeY)&&(ct!=0)) {
					nodeCT++;
					currentDirection=nodes[2][h];
					if (currentDirection==1) goto if1;
					if (currentDirection==2) goto if2;
					if (currentDirection==4) goto if4;
				}
			}
			if3:
			snakeY--;
		}
		if (currentDirection==4) {
			test[snakeY][snakeX]++;
			if ((ct==0)||(test[snakeY][snakeX]>1)) current_map[snakeY][snakeX]='O'; 
			else current_map[snakeY][snakeX]='o';
			for (int k=0;k<100;k++) {
				if ((nodes[0][k]==snakeX)&&(nodes[1][k]==snakeY)&&(ct!=0)) {
					nodeCT++;
					currentDirection=nodes[2][k];
					if (currentDirection==1) goto if1;
					if (currentDirection==2) goto if2;
					if (currentDirection==3) goto if3;
				}
			}
			if4:
			snakeX+=2;
		}
	}
	if ((coord_snake.x==coord_food.x)&&(coord_snake.y==coord_food.y)) {
		spawnFood ();
		size++;
	}
	current_map[coord_food.y][coord_food.x]=64;
	
	if(nodeCT!=node_counter) eliminateNode ();
}	


void printMap () {
	system("cls");
	printf("  _________________________________\n |                                 |\n |  ");
	for (int i=0; i<15; i++) {
		for (int j=0; j<29; j++) {
			if ((lost==true)&&(i==coord_snake.y)&&(j==coord_snake.x)) {	
				textRed ();
				printf("%c", current_map[i][j]);
				textWhite ();
			}
			else {
				if ((i==coord_food.y)&&(j==coord_food.x)) {
					textGreen ();
					printf("%c", current_map[i][j]);
					textWhite ();
				}
				else printf("%c", current_map[i][j]);
			}
		}
		printf("  |\n |  ");
	}
	printf("                               |");
	printf("\n |  Pontua%c%co: ", 135, 198);
	textGreen ();
	if (score<0) {
		printf("0 %c                 ", 64);
		textWhite ();
		printf("|");
	}
	else {
		if ((score<10)&&(score>=0)) {
			printf("%i %c                 ", score, 64);
			textWhite ();
			printf("|");
		}
		else {
			printf("%i %c                ", score, 64);
			textWhite ();
			printf("|");
		}
	}
	textWhite ();
	printf("\n |                                 |\n |  Pontua%c%co mais alta: ", 135, 198);
	textBlue ();
	if ((highest_score<10)&&(highest_score>=0)) {
		printf("%i %c       ", highest_score, 64);
		textWhite ();
		printf("|");
	}
	else {
		if ((highest_score<100)&&(highest_score>=10)) {
			printf("%i %c      ", highest_score, 64);
			textWhite ();
			printf("|");
		}
		else {
			printf("%i %c     ", highest_score, 64);
			textWhite ();
			printf("|");
		}
	}
	textWhite ();
	printf("\n |                                 |\n |_________________________________|\n");
}


void startGame () {
	spawnFood ();
	writeMap ();
	system("cls");
	printMap ();
	while (true) {
		delay ();
		snakeMove ();
		writeMap ();
		if (checkLose ()==true) break;
		printMap ();
	}
	lose ();
	if (score>highest_score) {
		textGreen ();
		printf("\n  Parab%cns! Nova melhor pontua%c%co!\n", 130, 135, 198);
		textWhite ();
		fhs = fopen("snakeHighestScore.txt", "w");
		fprintf(fhs, "%i", score);
		fclose(fhs);
	}
}


int main (void) {
	while (1) {
		for (int i=0;i<4;i++) {
			for (int j=0;j<100;j++) {
				nodes[i][j]=-1;
			}
		}
		setGlobal ();
		srand(time(NULL));
		if (again==false) {
			emptyMap ();
			printMap ();
		}
		holdOn (); 
		startGame ();
	}
	return 0;
}



