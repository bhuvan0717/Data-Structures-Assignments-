#include <stdio.h>
#include <stdlib.h>
struct post_test
{
    int sno;
    int marks;

}pt[100];

void read_marks(struct post_test[],int );
void find_even(struct post_test[],int );
void find_odd(struct post_test[],int );
void find_cent(struct post_test[] , int);



int main()
{
    int n;
    printf("\n Enter the number of students : \t ");
    scanf("%d",&n);
    read_marks(pt,n);
    find_even(pt,n);
    find_odd(pt,n);
    find_cent(pt,n);
    return 0;
}
void read_marks(struct post_test pt[],int b)
{
    int i,j;

    for(i=0,j=1;i<b;i++,j++)
    {
        printf("\nEnter the marks of student %d : ",j);
        scanf("%d",&pt[i].marks);
        pt[i].sno = j;
    }
}
void find_even(struct post_test pt[] ,int b)
{
    int i;
    int even;
    printf("\nThe students scoring even marks are : \n ");
    for(i=0;i<b;i++)
    {
        if(pt[i].marks % 2 == 0)
        {
            even = pt[i].sno;
            printf("\n Student number : %d \t marks : %d ",even, pt[i].marks);
        }
    }
}
void find_odd(struct post_test pt[] ,int b)
{
    int i;
    int odd;
    printf("\nThe students scoring odd marks are : \n");
    for(i=0;i<b;i++)
    {
        if(pt[i].marks % 2 != 0)
        {
            odd = pt[i].sno;
            printf("\n Student number : %d \t marks : %d ",odd, pt[i].marks);
        }
    }
}
void find_cent(struct post_test pt[],int b)
{
    int i;
    int count = 0;
    printf("\nStudents scoring 100 percent are : \n");
    for(i=0;i<b;i++)
    {
        if(pt[i].marks == 10)
        {
            printf("\n Student number : %d ",pt[i].sno);
            count++;
        }
    }
    printf("\n Congrats ! <3 \n");
    printf("\n The total number of students who scored 100 percent  is : %d ",count);


}
