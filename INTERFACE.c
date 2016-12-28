#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

void printing(int row, int col, char a[row][col])
{
   // system("MODE 200,200");
    int i, j;
    printf("\t ");
    printf("\n");
    printf("\t   ");
    for(i=0; i<col; i++)
    {
        SetColor(0);
        printf("%d ", i);
    }
    printf("\n");
    for(i=0; i<row; i++)
    {
        printf("\t%d ",i);
        if (i<=9)
            printf(" ");
        for(j=0; j<col; j++)
        {
            if (j>9)
            {
                printf(" ");
            }

            printf("%c|",a[i][j]);
        }
        printf("\n");
    }
}

void SetColor(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
