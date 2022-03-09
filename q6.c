#include <stdio.h>
#include <stdlib.h>

struct kle_tech
{
    int ranks;
    int sno;

}st[100];
void read_rankings(struct kle_tech [] , int);
void ascending_ranks(struct kle_tech [] ,int );
void display_highest_lowest(struct kle_tech[], int );


int main()
{
    int n;

    printf("\n Enter the total number of students whose rank is to be entered : \t ");
    scanf("%d",&n);
    read_rankings(st,n);
    ascending_ranks(st,n);
    display_highest_lowest(st,n);
    return 0;
}
void read_rankings(struct kle_tech st[],int b)
{
    int i,j;
    for(i=0,j=1;i<b;i++,j++)
    {
        printf("\n Enter rank of student %d   \t",j);
        scanf("%d",&st[i].ranks);
        st[i].sno = j;
    }
}
void ascending_ranks(struct kle_tech st[] , int b)
{
    int i,j;
    int temp_ranks,temp_no;
    for(i=0;i<b;i++)
    {
        for(j=i+1;j<b;j++)
        {
            if(st[i].ranks > st[j].ranks)
            {
                temp_ranks = st[i].ranks;
                temp_no = st[i].sno;

                st[i].ranks = st[j].ranks;
                st[i].sno = st[j].sno;
                st[j].ranks = temp_ranks;
                st[j].sno = temp_no;

            }
        }
    }
    printf("\nThe ascending order of the ranks are  : \n ");
    for(i=0;i<b;i++)
    {
        printf("\n Rank number : %d \n Student number : %d \n",st[i].ranks,st[i].sno);

    }
}
void display_highest_lowest(struct kle_tech st[],int b)
{
    int i;
    int lowest, highest;
    int lno,hno;

    highest = lowest = st[0].ranks;
    hno = lno = st[0].sno;

    for(i=0;i<b;i++)
    {
        if(st[i].ranks > lowest)
        {
            lowest = st[i].ranks;
            lno = st[i].sno;

        }
        if(st[i].ranks < highest )
        {
            highest = st[i].ranks;
            hno = st[i].sno;

        }
    }
    printf("\n Highest rank = %d  \t \t Student number : %d \n",highest,hno);
    printf("\n Lowest rank = %d \t \t Student number : %d \n",lowest,lno);

}

