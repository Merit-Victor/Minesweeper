#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

int flag;
int numOfPlayers,numOfMoves,Q,F,numOfMines;
float time1;

void WIN(float time, int numOfMoves, int numOfPlayers, char map[][col])
{
    int i,j;
    SetColor(5);
    printf("\t\t\t\tYou win !\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(map[i][j]=='*')
                map[i][j]='F';
        }
    }
    printing(row, col, map);
    printf("Number of moves =%d\n",numOfMoves);
    printf("Number of flags= %d\n",F);
    printf("Number of questions= %d\n", Q);
    time1+=(float)(end-start)/ CLOCKS_PER_SEC;
    sec=(int)time1%60;
    min=time1/60;
    mil=(time1-(sec+min*60))*1000;
    printf("time: %d:%d:%d\n", min,sec,mil);
    int score;
    FILE *rank;
    char name[20];
    score =((pow(row, 4)*pow(col, 4))/((time)*numOfMoves));
    SetColor(5);
    printf("Please enter your name:");
    scanf("%s", name);
    for (i=0; i<strlen(name)+1; i++)
    {
        if(name[i]>='A'&&name[i]<='Z')
        {
            name[i]='a'+(name[i]-'A');
        }
    }
    numOfPlayers++;
    numOfPlayers=leaderboard(array1,numOfPlayers, name, score);
    rank=fopen("nomofplayers.txt","w");
    fprintf(rank,"%d",numOfPlayers);
    fclose(rank);

    int index = searching(name,array1,numOfPlayers);
    printf("\nyour current score = %d\n",array1[index].score);
    printf("your current rank = %d\n",index+1);
    printf("Press 'A' to play again.. 'B' to see the leader board\n");
    char c;
    scanf("%s", &c);
    if(c=='b'||c=='B')
        leader();
    else if(c=='a'||c=='A')
        beforeStartGame();
    else
        return;
}

void LOSE (int r,int c,char map[][col],char user[][col],char visited[][col])
{
    map[r][c]='!';
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(map[i][j]=='*'&&user[i][j]=='f')
                map[i][j]='*';
            else if(user[i][j]=='f'&&map[i][j]!='*')
                map[i][j]='_';
            else if(map[i][j]=='*'&&visited[i][j]=='0')
                map[i][j]='M';
        }
    }
    printing(row, col, map);
    SetColor(4);
    printf("\t\t\tGame over!..\n");
    flag =1;
    printf("Press 'A' to play again.. 'B' to see the leader board\n");
    char a;
    scanf("%s", &a);
    if(a=='a'||a=='A')
    {
        flag=0;
        beforeStartGame();
    }
    else if(a=='b'||a=='B')
        leader();
    else
    {
        SetColor(0);
        return;
    }
}
