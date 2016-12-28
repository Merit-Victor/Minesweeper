#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "header.h"

int leaderboard(struct player array1[], int n, char name[], int score)
{
    int  j, found;
        found=searching(name,array1,n); //where n is the number of players.
        if(found!=-1) // player already exists
        {
            n--;
           array1[found].score = score+array1[found].score;
        }
        else
        {
            strcpy(array1[n-1].name, name);
            array1[n-1].score = score;
        }
    sorting(array1,n);//n is the number of players, sorting the array
    FILE* rank;
    rank= fopen("leaderboard.txt","w");
    //sorting the file
    for (j=0; j<n; j++)
    {
        fprintf(rank,"%s ",array1[j].name);
        fprintf(rank,"%d",array1[j].score);
        fprintf(rank,"\n");
    }
    fclose(rank);
    return n;
}

int searching(char x[], struct player array1[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if (strcmp(array1[i].name,x)==0)
        {
            return i; // returns the position where the player exists in the sorted array
        }
    }
    return -1;
}

void sorting (struct player array1[],int n)
{
    int c, d, position, swap;
    char temp[20];
    for ( c = 0 ; c < ( n - 1 ) ; c++ )
    {
        position = c;
        for ( d = c + 1 ; d < n ; d++ )
        {
            if ( array1[position].score < array1[d].score )
                position = d;
        }
        if ( position != c )
        {
            swap = array1[c].score;
            array1[c].score = array1[position].score;
            array1[position].score = swap;
            strcpy(temp,array1[c].name);
            strcpy(array1[c].name,array1[position].name);
            strcpy(array1[position].name,temp);
        }
    }

}

void leader() //function to show the leader board
{
    int num, i;
    FILE*rank;
    rank=fopen("nomofplayers.txt","r");
    fscanf(rank,"%d",&num);
    fclose(rank);
    SetColor(14);
    printf("rank\tname\tscore\n");
    for(i=0; i<num; i++)
    {
        SetColor(14);
        printf("%d>>",i+1);
        SetColor(0);
        printf("\t%s\t%d\n",array1[i].name,array1[i].score);
    }
    printf("Click 'B' to go back to the main menu");
    char c; scanf("%s", &c);
    if(c=='B'||c=='b')
       {
           main();
       }
}

