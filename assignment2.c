#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
  char name[20];
  char type[20];
  char country[20];
  float avg;
  int wickets,age, runs, matches;
  
};

void avg_sort(struct data p[], int n)
{
  struct data p1;
  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      if(p[i].avg < p[j].avg)
      {
        p1 = p[i];
        p[i] = p[j];
        p[j] = p1;
      }
    }
  }
  printf("\nSORTED DATA");
      printf("\nName   Country   Age   Type   Average   Wickets   Runs   Matches\n");
      for(int i=0; i<n; i++)
      {
        printf("%s      %s      %d     %s      %.2f       %d      %d       %d \n", p[i].name, p[i].country, p[i].age, p[i].type, p[i].avg, p[i].wickets, p[i].runs, p[i].matches);
      }
      printf("\n");

}

int main(void) 
{
  struct data p[100];
  int i,n,max1,max2,index1,index2,bat_c,bowl_c,all_c,batsman,bowler,all_rounder,w_keeper;
  char nm[20], c_bat[20], c_bowl[20], c_all[20], c[20];
  printf("\nEnter number of players : \n");
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    printf("\nEnter Name of player %d :  ", i+1);
    scanf("%s", p[i].name);
    printf("\nEnter country of player %d :  ", i+1);
    scanf("%s", p[i].country);
    printf("\nEnter Age of player %d :  ", i+1);
    scanf("%d", &p[i].age);
    printf("\nEnter Type of Player %d :  ", i+1);
    scanf("%s", p[i].type);
    printf("\nEnter average of Player %d :  ", i+1);
    scanf("%f", &p[i].avg);
    printf("\n Wickets Taken by player %d :  ", i+1);
    scanf("%d", &p[i].wickets);
    printf("\n Runs Scored by player %d :  ", i+1);
    scanf("%d", &p[i].runs);
    printf("\n No. of Matches played by player %d :  ", i+1);
    scanf("%d", &p[i].matches);

    printf("\n");
  } 

  int k;
  while(1)
  {
    printf("_____________________________________________");
    printf("\nOPTIONS\n1.Search Player \n2.Sorted data \n3.Display Players data \n4.Types of players\n5. Batsmen of a country\n6.Bowlers of a country\n7.Highest wicket taker\n8.Players of a country\n9.Exit.\nEnter option - ");
    scanf("%d", &k);
     printf("____________________________________________");
    switch(k)
    {
  

      case 1: 
      printf("\nEnter name of the player:\n");
      scanf("%s", nm);
      for(i=0;i<n;i++)
      {
        if(strcmp(nm,p[i].name)==0)
       {
        printf("name: %s\ntype: %s\naverage: %.2f\nwickets: %d\nruns: %d\n", p[i].name,p[i].type,p[i].avg,p[i].wickets,p[i].runs);
       }
      }
      break;
      case 2 : avg_sort(p,n);
      break;
      case 3 :
      printf("\nThe Details of players are : \n");
      printf("\nName        Type       AvgScore        Wickets      Runs\n");
      for(int i=0; i<n; i++)
      {
        printf("%s           %s          %.2f              %d         %d\n", p[i].name, p[i].type, p[i].avg, p[i].wickets, p[i].runs);
      }
      printf("\n");
      break;

      case 4 :
      batsman=0;
      bowler=0;
      all_rounder=0;
      w_keeper=0;
      for(i=0;i<n;i++)
      {
        if(strcmp("Batsman",p[i].type)==0)
        {
          batsman++;
        }
        else if(strcmp("Bowler",p[i].type)==0)
        {
          bowler++;
        }
        else if(strcmp("AllRounder",p[i].type)==0)
        {
          all_rounder++;
        }
        else if(strcmp("WicketKeeper",p[i].type)==0)
        {
          w_keeper++;
        }
      }
      printf("\nNumber of batsman: %d\nNumber of Bowlers: %d\nNumber of all rounders: %d\nNumber of wicket keepers: %d\n",batsman,bowler,all_rounder,w_keeper);
      break;

      case 5 :
      bat_c=0;
      printf("Enter name of a country:\n");
      scanf("%s", c_bat);
      for(i=0;i<n;i++)
      {
        if(strcmp(c_bat,p[i].country)==0)
        {
          if(strcmp("Batsman",p[i].type)==0)
          bat_c++;
        }
      }
      printf("%s has %d batsmen.\n", c_bat, bat_c);
      break;

      case 6 : 
      bowl_c=0;
      printf("Enter name of a country:\n");
      scanf("%s", c_bowl);
      for(i=0;i<n;i++)
      {
        if(strcmp(c_bowl,p[i].country)==0)
        {
          if(strcmp("Bowler",p[i].type)==0)
          {
            bowl_c++; 
          }
          
        }
      }
      printf("%s has %d bowlers.\n", c_bowl, bowl_c);
      break;
      
      
      case 7 :
      max2=0, index1=0;
      for(i=0;i<n;i++)
      {
        if(strcmp("Bowler",p[i].type)==0)
        {
          if(p[i].wickets>max2)
          {
            max1=p[i].wickets;
            index2=i;
          }
        }
      }
      printf("\nHighest wickets taken: %d by %s\n", p[index2].wickets, p[index2].name);
      break;

      case 8 :
      printf("\Enter name of a country:\n");
      scanf("%s", c);
      for(i=0;i<n;i++)
      {
        if(strcmp(c,p[i].country)==0)
        {
          printf("\nName: %s\nAge: %d\nType: %s\nRuns: %d\nWickets: %d\nMatches played: %d\nAverage: %.2f\n",p[i].name,p[i].age,p[i].type,p[i].runs,p[i].wickets,p[i].matches,p[i].avg);
        }
      }
      break;

      case 9 :
      printf("Exited \n");
      return 0; 

      default : 
      printf("\nWRONG INPUT\n");
      break;
    }
  }
  
  return 0;
          }