#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

void DFS(int r, int c, char map[][col], char user[][col], char visited[][col])
{
    int i, j;
    for(i=r-1; i<r+2; i++)
    {
        if(i<0)
            i++;
        if(i==row)
            break;
        for(j=c-1; j<c+2; j++)
        {
            if(j<0)
                j++;
            if(j==col)
                break;
            if(visited[i][j]=='0'&&map[i][j]!='*')
            {
                user[i][j]=map[i][j];
                visited[i][j]='1';
                if(map[i][j]==' ')
                {
                    //printf("%d%d"\n);
                    DFS(i, j, map, user, visited);
                }
            }
        }
    }
}
