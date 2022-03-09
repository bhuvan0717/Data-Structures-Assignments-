#include <stdio.h>
#include <stdlib.h>

struct student
{
    int sno;

    int marks;


}st[10];
void read_student(struct student[] ,int);

void find_average(struct student[] ,int );
void find_below_av(struct student[] ,int , float );
void find_above_av(struct student[] ,int, float );


int main()
{

    int n =10;
    read_student(st, n);
    find_average(st,n);
    return 0;


}

void read_student(struct student st[],int b){
    int i;
    int max_marks = 0;
    printf("\n Enter the maximium marks to be obtained  : ");
    scanf("%d",&max_marks);
    for(i=0;i<b;i++)
    {
        st[i].sno = i + 1;

        printf("Enter the marks of student %d : ",i+1);
        scanf("%d",&st[i].marks);
    }
}
void find_average(struct student st[], int b)
{
    int sum = 0;
    float average = 0 ;


    int i;
    for(i=0;i<b;i++)
    {
        sum = sum + st[i].marks;
    }
    average = (float)(sum / b);

    printf("\nThe class average is  %f",average);
    find_above_av(st,b,average);
    find_below_av(st,b,average);
}


void find_below_av(struct student st[] ,int b, float av)
{
    int i ;
    printf("Students scored below average : ");
    for(i = 0; i<b ; i++)
    {
        if(st[i].marks < av)
        {
            printf("\n Student number : %d \n Marks obtained : %d \n",st[i].sno,st[i].marks);
        }
    }
}
void find_above_av(struct student st[] ,int b, float av)
{
    int i ;
    printf("\n \n Students scored above average : ");
    for(i = 0;i<b;i++)
    {
        if(st[i].marks > av)
        {
            printf("\n Student number : %d \n Marks obtained : %d \n",st[i].sno,st[i].marks);
        }
    }
}

