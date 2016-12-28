#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

int flag;
int numOfPlayers,numOfMoves,Q,F,numOfMines;
float time1;

void startgame(char user[][col],char map[][col],char visited[][col])
{
    int i,j;
    clock_t start=clock();
    counter=0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(visited[i][j]=='0')
            {
                counter++;
            }
        }
    }
    if(counter==n)
    {
        WIN( time1, numOfMoves, numOfPlayers, map);
        exit(0);
    }
    SetColor(1);
    printf("Action: {'o' for open..'f' for flag(mark/unmark)..'?' question(mark/unmark)..'s' for saving game}:");
    scanf("%s",&action);
    if(action=='s')
    {
        saving(user,visited,numOfMoves,F,Q,min,sec,time1,n);
        exit(0);
    }
    printf("Enter row number:");
    scanf("%d", &r);
    printf("Column number:");
    scanf("%d", &c);
    numOfMoves++;
    switch(action)
    {
    case 'o':
        opening(r, c, user, map, visited);
        break;
    case 'f':
        F=mark(r, c, user, 'f',F);
        break;
    case '?':
        Q=mark(r, c, user, '?',Q);
        break;
    default:
        SetColor(4);
        printf("Not valid\n");
        break;
    }
    clock_t end=clock();
    SetColor(0);
    printf("Number of moves =%d\n",numOfMoves);
    printf("Number of flags= %d\n",F);
    printf("Number of questions= %d\n", Q);
    time1+=(float)(end-start)/ CLOCKS_PER_SEC;
    sec=(int)time1%60;
    min=time1/60;
    mil=(time1-(sec+min*60))*1000;
    printf("time: %d:%d:%d\n\n", min, sec, mil);

}

void beforeStartGame()
{
    int i, j;
    F=0, Q=0;
    numOfMoves=0;
    SetColor(1);
    printf("Please enter size of grid:\n");
    scanf("%d %d", &row, &col);
    if(row<2&&col<2)
    {
        SetColor(4);
        printf("Grid is too small!\n");
        beforeStartGame();
    }
    if(row>100&&col>100)
    {
        SetColor(4);
        printf("Grid is too large!\n");
        beforeStartGame();
    }
    //making visited
    char visited[row][col];
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            visited[i][j]='0';
        }
    }
    // printing for player
    char user[row][col];
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
            user[i][j]='X';
    }
    printing(row, col, user);
    // making map
    n=1+(row*col)/10; //number of mines
    char map [row][col];
    makingMap(map, n);
    //taking the first index
    SetColor(1);
    printf("Action: {'o' for open..'f' for flag(mark/unmark)..'?' for question(mark/unmark)}:\n");
    scanf("%s",&action);
    if (action=='s')
    {
        saving(user,visited,numOfMoves,F,Q,min,sec,time1,n);
        exit(0);
    }
    printf("Enter row number:\n");
    scanf("%d",&r);
    printf("Column number:\n");
    scanf("%d",&c);
    numOfMoves++;
    clock_t start=clock();
    if (action == 'o'&&map[r][c]=='*')
    {
        do
        {
            makingMap(map, n);                   //remaking map until the first index not egual mine
        }
        while (map[r][c]=='*');
        opening(r, c, user, map, visited);
    }
    else if (action=='o'&&map[r][c]!='*')     opening(r,c,user,map, visited);
    else if (action=='f')                     F=mark(r,c,user,'f',F);
    else if (action=='?')                     Q=mark(r,c,user,'?',Q);
    else
    {
        SetColor(4);
        printf("\t\tNot valid !!\n");
    }
    clock_t end=clock();
    SetColor(0);
    printf("Number of moves =%d\n",numOfMoves);
    printf("Number of flags= %d\n",F);
    printf("Number of questions= %d\n", Q);
    time1=0;
    time1 +=(float)(end-start)/ CLOCKS_PER_SEC;
    sec=(int)time1%60;
    min=time1/60;
    mil=(time1-(sec+min*60))*1000;
    printf("time: %d:%d:%d\n\n", min, sec, mil);
    MAP(map, 1, 'm');
    MAP(map, 0, 'm');
    //the game loop
    while(flag!=1)
    {
        startgame(user,map,visited);
    }
}
