#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

int flag;
int numOfPlayers,numOfMoves,Q,F,numOfMines;
float time1;

void remakeArray(char array[][col], char x)
{
    int i, j;
    FILE*rank;
    switch(x)
    {
    case 'm':
        rank=fopen("map.txt","r");
        break;
    case 'u':
        rank=fopen("user.txt","r");
        break;
    case 'v':
        rank=fopen("visited.txt","r");
        break;
    }
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
            fscanf(rank,"%c",&array[i][j]);
    }
    fclose(rank);
}

void loading() //function to show the previous game
{
    SetColor(0);
    FILE*rank=fopen("save.txt","r");
    if (rank!= NULL)
    {
        int c;
        while ((c = fgetc(rank)) != EOF)     // read character from file until EOF
        {
            putchar(c);                   // output character
        }
        fclose(rank);
    }
}

void savinginf()
{
     FILE*rank;
        rank=fopen("rcmfqtm.txt","r");
        fscanf(rank,"%d",&row);
        fscanf(rank,"%d",&col);                  //taking information from the saved game
        fscanf(rank,"%d",&numOfMoves);
        fscanf(rank,"%d",&F);
        fscanf(rank,"%d",&Q);
        fscanf(rank,"%f",&time1);
        fscanf(rank,"%d",&n);
        fclose(rank);
}

