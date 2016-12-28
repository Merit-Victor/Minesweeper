#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

extern int flag;
extern int numOfPlayers,numOfMoves,Q,F,numOfMines;
extern float time1;

void opening(int r, int c, char user[][col], char map[][col], char visited[][col])
{
    if(user[r][c]=='X')
    {
        if(map[r][c]=='*')
        {
           LOSE(r,c,map,user,visited);
           exit(0);
        }
        else if(map[r][c]==' ')
        {
            user[r][c]=map[r][c];
            DFS(r, c, map, user, visited);
            printing(row, col, user);
        }
        else
        {
            user[r][c]=map[r][c];
            visited[r][c]='1';
            printing(row, col,user);
        }
    }
    else if(user[r][c]=='f' || user[r][c]=='?')
    {
        SetColor(4);
        printf("Can't open, choose another one.\n");
    }
    else //already opened
    {
        if(user[r][c]==' ')
        {
            SetColor(4);
            printf("Choose another one.\n");
        }
        else
        {
            int numOfFlags=0;
            char num;
            numOfFlags=counting(r, c, numOfFlags, user,'f');
            num=numOfFlags+'0';
            if(user[r][c]==num)
                opencell(r, c, user, map, visited);
            else
            {
                SetColor(4);
                printf("Can't open, choose another one.\n");
            }
        }
    }
}
void opencell(int rowCounter, int colCounter,char user[][col], char map[][col], char visited[][col])
{
    int o,q;
    for(o=rowCounter-1; o<rowCounter+2; o++)
    {
        if(o<0)
            o++;
        if(o==row)
            break;
        for(q=colCounter-1; q<colCounter+2; q++)
        {
            if(q<0)
                q++;
            if(q==col)
                break;
            if(user[o][q]!='f')
            {
                if(map[o][q]=='*')
                {
                   LOSE(o,q,map,user,visited);
                   exit(0);
                }
                else if(map[o][q]==' ')
                {
                    user[o][q]=map[o][q];
                    DFS(o, q, map, user, visited);
                }
                else
                {
                    user[o][q]=map[o][q];
                    visited[o][q]='1';
                }
            }
        }
    }
    printing(row, col, user);
}

int mark(int r, int c, char user[][col], char x,int P)
{
    if(user[r][c]==x)
    {
        user[r][c]='X';                         //UNMARK
        printing(row, col, user);
        P--;
    }
    else if(user[r][c]=='X')
    {
        user[r][c]=x;
        printing(row, col, user);
        P++;
    }
    else
    {
        SetColor(4);
        printf("choose another one.\n");
    }
    return P;
}


