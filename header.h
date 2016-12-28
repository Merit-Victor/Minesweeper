#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <time.h>

int row, col, r, c,counter,n;
char action;
clock_t start,end;
int sec, min, mil;

struct player
{
    char name[20];
    int score;
};
struct player array1[100];

void leader();
void remakeArray(char array[][col], char x);
void loading();
void saving(char user[][col], char visited[][col], int numOfMoves,int F,int Q,float min ,float sec,float time, int n);
void sorting (struct player array1[],int n);
int searching(char x[], struct player array1[], int n);
int leaderboard(struct player array1[], int n, char name[], int score);
void printing(int row, int col, char a[row][col]);
void opening(int r, int c, char a[][col], char b[][col], char visited[][col]);
int counting(int rowCounter, int colCounter, int numOf, char array[][col], char x);
void opencell(int rowCounter, int colCounter,char user[][col], char map[][col], char visited[][col]);
int mark(int r, int c, char user[][col], char x,int P);
void DFS(int r, int c, char map[][col], char user[][col], char visited[][col]);
void WIN(float time, int numOfMoves, int numOfPlayers, char map [][col]);
void LOSE (int r ,int c,char map[][col],char user[][col],char visited[][col]);
void MAP(char map[][col],int k, char x);
void makingMap(char map[][col], int n );
void beforeStartGame();
void startgame(char user[][col],char map[][col] ,char visited[][col]);
void savinginf();
void SetColor(int ForgC);
#endif // HEADER_H_INCLUDED
