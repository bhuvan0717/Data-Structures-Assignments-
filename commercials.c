#include<stdio.h>
#include<stdlib.h>

struct commercials
{
    int year,number;
    struct commercials *next;
};

typedef struct commercials *NODE;

NODE getnode()
{
    NODE new;
    new=(NODE)malloc(sizeof(struct commercials));
    if(new==NULL)
    {
        exit(0);
    }
    new->next=NULL;
    return new;
}

NODE read_details()
{
    NODE temp;
    temp=getnode();
    scanf("%d %d",&temp->year,&temp->number);
    return temp;
}

NODE insert_end(NODE head)
{
    NODE newn=NULL, cur=NULL;
    newn = read_details();
    if(head == NULL)
    {
        return newn;
    }
    else
    {
        cur=head;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = newn;
    }
    return head;
}

void display(NODE head)
{
    NODE cur=NULL;
    if(head==NULL)
    {
        exit(0);
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d %d ",cur->year,cur->number);
            cur=cur->next;
        }
    }
    printf("\n");
}

int count(NODE head)
{
    NODE temp;
    temp=head;
    int cnt=0;
    if(temp == NULL)
    {
       return 0;
    }
    else
    {
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
    }
    return cnt;
}

NODE split(NODE head,NODE second,int count)
{
    int i=0;
    NODE cur,prev;
    if(head==NULL)
    {
        return head;
    }
    cur=head;
    prev=NULL;
    while(i!=count/2)
    {
        prev=cur;
        cur=cur->next;
        i++;
    }
    prev->next=NULL;
    second=cur;
    return second;
}

int percentage(NODE head)
{
    NODE cur=head;
    int sum=0;
    while(cur!=NULL)
    {
        sum+=cur->number;
        cur=cur->next;
    }
    return sum;
}

int main()
{
    int i=0;
    NODE head=NULL, second=NULL;
    int n,cnt,p1,p2;
    float t1,t2;
    scanf("%d",&n);
    if(n%2==0)
    {
        for(i=0;i<n;i++)
        {
            head=insert_end(head);
        }
        cnt=count(head);
        second=split(head,second,cnt);
        p1=percentage(head);
        p2=percentage(second);
        t1=((float)p1/(p1+p2))*100;
        t2=((float)p2/(p1+p2))*100;
        printf("Group 1: ");
        display(head);
        printf("Percentage of commercials in first group = %0.2f\n",t1);
        printf("Group 2: ");
        display(second);
        printf("Percentage of commercials in second group = %0.2f\n",t2);
        if(t1>t2)
        {
            printf("The first group has more percentage of commercials made.");
        }
        else if(t1<t2)
        {
            printf("The second group has more percentage of commercials made.");
        }
        else
        {
            printf("Both group have same percentage of commercials made.");
        }
    }
    else
    {
        printf("Cannot perform analysis.");
    }
    return 0;
}
