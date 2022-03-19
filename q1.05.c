#include <stdio.h>
#include <stdlib.h>
struct book_return
{
    int sno;
    int due_days;
    int penalty;
}st[100];


void read_student_return(struct book_return st[],int b)
{
    int i,j;
    j = 1;

    for(i=0;i<b;i++,j++)
    {
        printf("\n Enter number of  due days of student %d\t",j);
        scanf("%d",&st[i].due_days);
        st[i].sno = j;

    }
}
void calc_penalty(struct book_return st[], int b)
{
    int i ;
    for(i=0;i<b;i++)
    {
        st[i].penalty = st[i].due_days * 2 ;
        printf("\n The penalty for student %d is : %d ",st[i].sno,st[i].penalty);

    }
}
void find_average_penalty_and_sum(struct book_return st[], int b)
{
    int sum = 0;
    float average=0;

    int i;
    for(i=0;i<b;i++)
    {
        sum = sum + st[i].penalty ;

    }
    average = (float)sum/b;
    printf("\n The total penalty collected was : %d ",sum);
    printf("\n The average penalty collected is %0.2f",average);

}
void find_largest_penalty(struct book_return st[], int b)
{
   int largest;
    int i,snumb;
    largest = st[0].penalty;
    for(i=0;i<b;i++)
    {
        if(st[i].penalty > largest)
        {
            largest = st[i].penalty;
            snumb = st[i].sno;
        }

    }
    printf("\nThe maximum  penalty collected was %d rupees from student number %d ",largest ,snumb);




}
void find_lowest_penalty(struct book_return st[], int b)
{
    int lowest;
    int i,snum;
    lowest = st[0].penalty;
    for(i=0;i<b;i++)
    {
        if(st[i].penalty < lowest)
        {
            lowest = st[i].penalty;
            snum = st[i].sno;
        }

    }
    printf("\nThe minimum  penalty collected was %d rupees from student number %d ",lowest ,snum);


}

int main()
{
    int n;
    printf("\nEnter the total numbers of students whose due date is to be entered : ");
    scanf("%d",&n);
    read_student_return(st,n);
    calc_penalty(st,n);
    find_average_penalty_and_sum(st,n);
    find_largest_penalty(st,n);
    find_lowest_penalty(st,n);

    return 0;
}
