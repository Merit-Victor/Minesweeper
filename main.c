#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "header.h"


int flag=0;
int numOfPlayers=0,numOfMoves=0,Q=0,F=0,numOfMines=0;
float time1=0;
int main()
{
    int i, score;
    char name[20];
    FILE* rank;
    rank=fopen("nomofplayers.txt","r");
    fscanf(rank, "%d",&numOfPlayers );
    fclose(rank);
    rank=fopen("leaderboard.txt","r");
    for(i=0; i<numOfPlayers; i++)
    {
        fscanf(rank,"%s %d\n", &name, &score);
        strcpy(array1[i].name,name);
        array1[i].score=score;
    }
    fclose(rank);
    //Starting Game
    char choose;
    system("COLOR 79");
    SetColor(14);
    printf("\t\t\t\tWELOME\n\t\t\t    THE MAIN MENU\n");
    SetColor(3);
    printf("   N \tfor      NEW GAME \n");
    printf("   L\tfor      LOAD GAME\n");
    printf("   B\tfor      LEADER BOARD\n");
    SetColor(1);
    printf("choose one of above :\n");
    scanf("%s",&choose);

    if (choose=='b'||choose=='B')
    {
        leader();
    }

    else if(choose=='L'||choose=='l')
    {
        savinginf();     //taking the information of saved game
        char visited[row][col];
        remakeArray(visited,'v');
        char user[row][col];
        remakeArray(user, 'u');
        char map[row][col];
        remakeArray(map, 'm');
        loading();
        while(flag!=1)
        {
            startgame(user,map,visited);
        }
    }

    else if (choose=='n'||choose=='N')
    {
        beforeStartGame();
    }

    else
    {
        SetColor(4);
        printf("\t\tYOU DIDN'T CHOOSE ANYTHING FROM THE MAIN MENU\n\n");
        main();
    }
    SetColor(0);
    return 0;
}
