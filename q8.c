#include <stdio.h>
#include <stdlib.h>

struct expend
{
    int months;
    int expenditure;
}exp[12];
void read_expenditure(struct expend []);
void spent_more(struct expend []);
void spent_less(struct expend []);
void spent_ab_35(struct expend []);
void average_expenditure(struct expend []);



int main()
{
    int n;
    read_expenditure(exp);
    spent_more(exp);
    spent_less(exp);
    spent_ab_35(exp);
    average_expenditure(exp);

    return 0;
}
void read_expenditure(struct expend exp[])
{
    int i,j;
    for(i=0,j=1;i<12;i++,j++)
    {
        printf("\nEnter the expenditure of month %d  \t",j);
        scanf("%d",&exp[i].expenditure);
        exp[i].months = j;
    }
}
void spent_more(struct expend exp[])
{
    int i,mno;
    int highest;
    highest = exp[0].expenditure;
    mno = 0;

    for(i=0;i<12;i++)
    {
        if(exp[i].expenditure > highest)
        {
            highest = exp[i].expenditure;
            mno = exp[i].months;
        }

    }
    printf("\n The highest spent month was:  %d \n The expenditure was : %d",mno,highest);


}

void spent_less(struct expend exp[])
{
    int i,mno;
    int lowest;
    lowest = exp[0].expenditure;
    mno = 0;

    for(i=0;i<12;i++)
    {
        if(exp[i].expenditure < lowest)
        {
            lowest = exp[i].expenditure;
            mno = exp[i].months;
        }

    }
    printf("\n The lowest spent month was:  %d \n The expenditure was : %d",mno,lowest);


}
void spent_ab_35(struct expend exp[])
{
    int i,mno;
    mno = 0;
    printf("\n The  months  where the expenditure was above 35000 were : \n ");
    for(i=0;i<12;i++)
    {
        if(exp[i].expenditure > 35000)
        {
            mno = exp[i].months;
            printf("%d\t ",mno);
        }

    }
}
void average_expenditure(struct expend exp[])
{
    int i,sum;
    sum = 0;
    float average = 0;
    for(i=0;i<12;i++)
    {
        sum = sum + exp[i].expenditure;
    }
    average = (float)sum/12;
    printf("\n The total expenditure was : %d ",sum);
    printf("\n The average expenditure was : %0.2f ",average);

}

