#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

int flag;
int numOfPlayers,numOfMoves,Q,F,numOfMines;
float time1;

void saving(char user[][col],char visited[][col], int numOfMoves,int F,int Q,float min,float sec,float time, int n)
{
    int i,j;
    FILE*rank=fopen("save.txt","w");
    fprintf(rank,"\n");
    fprintf(rank,"   ");

    for(i=0; i<col; i++)
        fprintf(rank,"%d ", i);
    fprintf(rank,"\n");
    for(i=0; i<row; i++)
    {
        fprintf(rank,"%d ",i);
        if (i<=9)
            fprintf(rank," ");
        for(j=0; j<col; j++)
        {
            if (j>9)
            {
                fprintf(rank," ");
            }
            fprintf(rank,"%c|",user[i][j]);
        }
        fprintf(rank,"\n");
    }
    fprintf(rank,"\nNumber of moves = %d",numOfMoves);
    fprintf(rank,"\nNumber of flags= %d",F);
    fprintf(rank,"\nNumber of questions= %d",Q);
    fprintf(rank,"\ntime: %.0f:%.0f:%d\n", min, sec, mil);
    fclose(rank);

    rank=fopen("rcmfqtm.txt","w");
    fprintf(rank,"%d\n",row);
    fprintf(rank,"%d\n",col);
    fprintf(rank,"%d\n",numOfMoves);
    fprintf(rank,"%d\n",F);
    fprintf(rank,"%d\n",Q);
    fprintf(rank,"%f\n", time);
    fprintf(rank,"%d",n);
    fclose(rank);

    MAP(user,0,'u');
    MAP(visited,0,'v');
}

void MAP(char map[][col],int k, char x)
{
    FILE* m; int i, j;
    if(k==1)
        {
            m=fopen("map1.txt", "w");
                    for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                fprintf(m,"%c ",map[i][j]);
            }
            fprintf(m,"\n");
        }
        fclose(m);
        }
    else
        {
            switch(x)
            {
                case 'm':m=fopen("map.txt", "w");break;
                case 'u':m=fopen("user.txt", "w");break;
                case 'v':m=fopen("visited.txt","w");break;
            }
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    fprintf(m,"%c",map[i][j]);
                }
            }
            fclose(m);
        }
}
