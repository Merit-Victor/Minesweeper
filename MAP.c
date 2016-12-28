#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

int counting (int rowCounter, int colCounter, int numOf, char array[][col], char x)
{
    numOf=0;
    int o, q;
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
            if(array[o][q]==x)
                numOf++;
        }
    }
    return numOf;
}

void makingMap(char map[][col], int n ) //where n is the number of mines
{
    int i, j, numOfMines=0, a, b;
    for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
                map[i][j]=' ';
        }
        srand(time(NULL));
        for(i=0; i<n; i++)
        {
            a=rand()%row;
            b=rand()%col;
            if(map[a][b]=='*')
                i--;
            else
                map[a][b]='*';
        }
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                while(map[i][j]!='*')
                {
                    numOfMines=counting(i, j, numOfMines, map,'*');
                    while(numOfMines!=0)
                    {
                        map[i][j]=numOfMines+'0';
                        numOfMines=0;
                    }
                    break;
                }
            }
        }
}
