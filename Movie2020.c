#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct moviedetail
{
    char movie_name[20];
    int year,collection;
}MOVIE;

void read(FILE *,int);
void display(FILE *,int);
void collectionof2020(FILE *,int);

void main()
{
    int n;
    printf("ENTER THE NUMBER OF MOVIES:\n");
    scanf("%d",&n);
    FILE *fp;
    read(fp,n);
    display(fp,n);
    collectionof2020(fp,n);
}
void read(FILE *fp,int n)
{
    MOVIE s[20];
    int i;
    fp=fopen("producedmovies.txt","w");
    for(i=0;i<n;i++)
    {
        printf("\nENTER MOVIE NAME, YEAR & COLLECTION OF %d MOVIE:\n", i+1);
        scanf("%s\t%d\t%d",s[i].movie_name,&s[i].year,&s[i].collection);
        fprintf(fp,"%s\t%d\t%d\n",s[i].movie_name,s[i].year,s[i].collection);
    }
    fclose(fp);
}
void display(FILE *fp,int n)
{
    int i;
    MOVIE s[20];
    fp=fopen("producedmovies.txt","r");
    while(!feof(fp))
    {
    fscanf(fp,"%s\t%d\t%d",s[i].movie_name,&s[i].year,&s[i].collection);
    i++;
    }
    printf("\nMOVIE DETAILS ARE:\n");
    for(i=0; i<n; i++)
    {
            printf("\n\nMOVIE NAME:\t");
            printf("%s",s[i].movie_name);
            printf("\nMOVIE YEAR:\t");
            printf("%d",s[i].year);
    }
    fclose(fp);
}
void collectionof2020(FILE *fp,int n)
{
     int sum=0;
     MOVIE m[20];
     for(int i=0;i<n;i++)
     {
         if((m[i].year)==2020)
         sum=sum+(m[i].collection);
     }
     printf("\n\nCOLLECTION OF YEAR 2020 IS %d",sum);
}
